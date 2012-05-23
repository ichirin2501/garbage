#ifndef __PIECETABLE_H__
#define __PIECETABLE_H__

#include <cstdlib>
#include <cassert>
#include <fstream>
#include <list>
#include <vector>
#include <stack>
#include <algorithm>
#include <sys/stat.h>


class PieceTable{
private:
    // operationのラベル
    enum OPE {INSERT, ERASE};
    enum TYPE {ORIGIN, BUFFER};
    /****************************
      struct OperateInfo
      実行した命令の情報
      undo or redo のために使う
    ****************************/
    struct OperateInfo{
        int opeType;         // INSERT or ERASE
        long long cursesIdx; // 全体におけるインデックス値
        long long tableIdx;  // buffer or origin　におけるインデックス値
        int dataType;        // ORIGIN or BUFFER
        OperateInfo(int opeType, long long cursesIdx, long long tableIdx, int dataType)
            : opeType(opeType), cursesIdx(cursesIdx), tableIdx(tableIdx), dataType(dataType) {}
    };
    /**************************************
      struct Piece
      PieceTalbeのリストで格納するデータ
      範囲[始まり, 終わり] = [s, e]　(s,eを含む
      dataTypeはオリジナルかバッファーを示す
    **************************************/
    struct Piece{
        long long s,e; // [s,e]
        int dataType;  // ORIGIN or BUFFER
        Piece(long long s, long long e, int dataType) : s(s), e(e), dataType(dataType) {}
    };

public:
    std::fstream origin;
    std::list<Piece> linkedList;
    std::vector<unsigned char> buffer;
    std::stack<OperateInfo> undoStack, redoStack;
    long long newFileSize; // 新しく保存する現在のファイルサイズ
    
    PieceTable(){}
    PieceTable(char *fileName){
        this->initialize(fileName);
    }
    ~PieceTable(){}

    void initialize(char *fileName);
    void clear();
    void insert(const long long cursesIdx, const char data);
    void _insert(const long long cursesIdx, const long long tableIdx, const int dataType);
    void erase(long long cursesIdx);
    void undo();
    void redo();
    long long getNewFileSize();
    int read(char *buf, int size, const long long PageIdx);
};

void PieceTable::initialize(char *fileName){
    struct stat64 st;

    this->clear();

    if( stat64(fileName, &st) ){
        // 少なくとも存在しない

        // pathが正しいかどうか判定する
        std::string tPath = std::string(fileName);
        size_t p = tPath.rfind("/");
        if( p != std::string::npos ){
            if( stat64(tPath.substr(0, p + 1).c_str(), &st) ){
                // pathも正しくない、よって失敗
                perror("stat64");
                exit(0);
            }
        }

        // この時点で、pathは正しいので新規ファイル確定
        // openした瞬間に作成されるから、:w!, :wq! されたときに保存されるようにするために、最後に行う必要がある
    }
    else{
        // ファイル or ディレクトリが存在する
        if( (st.st_mode & S_IFMT) != S_IFREG ){
            // 通常のファイルではない
            std::cout << "don't normal file" << std::endl;
            exit(0);
        }

        origin.open(fileName, std::ios::in | std::ios::out | std::ios::binary);

        if( origin.fail() ){
            // 書き込みはできない
            
            // 読み込みは可能か
            origin.open(fileName, std::ios::in | std::ios::binary);
            if( origin.fail() ){
                puts("don't read");
                exit(0);
            }
            puts("read only");
            exit(0);
            // read onlyかどうかはhexEditorに情報を持たせたいんだが…
        }

        newFileSize = st.st_size;
        if( st.st_size > 0LL ) linkedList.push_back(Piece(0LL, st.st_size - 1, ORIGIN));
    }
}


void PieceTable::clear(){
    origin.close();
    linkedList.clear();
    buffer.clear();
    newFileSize = 0;

    while( !undoStack.empty() ) undoStack.pop();
    while( !redoStack.empty() ) redoStack.pop();
}




// 通常はbufferに貯めるからこれを使う
void PieceTable::insert(const long long cursesIdx, const char data){
    buffer.push_back(data);
    this->_insert(cursesIdx, (long long)buffer.size()-1, BUFFER);
}

// 直接使うのはundo, redo処理のときだけ
void PieceTable::_insert(const long long cursesIdx, const long long tableIdx, const int dataType){
    long long base = 0;
    
    newFileSize++;

    // 操作すべきリストを調べる
    // ここはカーソル操作時に毎回更新して位置を把握しておけば高速化可
    std::list<Piece>::iterator it;
    for(it = linkedList.begin(); it != linkedList.end(); it++){
        if( base <= cursesIdx && cursesIdx < base + (it->e - it->s + 1) ) break;
        base += (it->e - it->s + 1);
    }

    // 操作すべきリスト = it
    std::list<Piece>::iterator prev = it;

    if( it != linkedList.begin() ) prev--;

    if( it != linkedList.begin() && cursesIdx == base &&
        prev->dataType == dataType && prev->e == tableIdx-1 ) {
        // 手前の末尾と繋げられる

        prev->e++;
        if( it != linkedList.end() && it->dataType == dataType && it->s == tableIdx+1 ){
            // 両側のリストが繋げられるので、まとめる（片方を削除 [prev->s, it->e]
            it->s = prev->s;
            linkedList.erase(prev);
        }
    }
    else if( it != linkedList.end() && it->dataType == dataType && it->s == tableIdx+1 && cursesIdx == base ){
        // 今の先頭に繋げられる
        it->s--;
    }
    else{
        // (行頭 or 行末 or 分割) 挿入する
        std::list<Piece>::iterator tit = linkedList.insert(it, Piece(tableIdx, tableIdx, dataType));
        if( base < cursesIdx && it != linkedList.end() ){
            // 分割
            long long tmp_s = it->s;
            it->s = (cursesIdx - base) + it->s;
            linkedList.insert(tit, Piece(tmp_s, tmp_s + (cursesIdx - base) -1, it->dataType));
        }
    }
    undoStack.push(OperateInfo(INSERT, cursesIdx, tableIdx, dataType));
}


void PieceTable::erase(long long cursesIdx){
    // cursesIdx > 0
    if( cursesIdx <= 0 ) return;
        
    cursesIdx--;
    newFileSize--;

    long long base = 0;
    std::list<Piece>::iterator it;
    // ここはカーソル操作時に毎回更新して位置を把握しておけば高速化可
    for(it = linkedList.begin(); it != linkedList.end(); it++){
        if( base <= cursesIdx && cursesIdx < base + (it->e - it->s + 1) ) break;
        base += (it->e - it->s + 1);
    }

    // error
    assert( it != linkedList.end() );

    long long tmp_s = it->s, tmp_e = it->e;
    int tmp_dataType = it->dataType;
    long long tmp_tableIdx = (cursesIdx - base) + it->s;

    it = linkedList.erase(it); // 一旦削除して、直後をitにする

    /*
      あ、eraseしたときに、繋げられる可能性を忘れてた
      両端（先頭or末尾）を削除する分には連結は発生しない？

      連結が発生するとき、範囲を示す要素が削除されることが前提？
      例えば、要素の前後が変わっただけで、連結は発生するか？
      前後が変わる = 連続してる範囲だから、
      [5,8] --> [6,8] or [5,7]　のどちらかのみだから、絶対に発生しない
      また、要素の中央を削除するとき、
      [4,9] --> {[4,4],[6,9]}, {[4,5],[7,9]},... だから、このときも連結は絶対に発生しない

      よって、連結が発生するのは、要素自体が削除される tmp_s == tmp_e の場合のみである
      
     */
    if( tmp_s != tmp_e ){
        if( cursesIdx == base ){ // 先頭を削除
            linkedList.insert(it, Piece(tmp_s + 1, tmp_e, tmp_dataType));
        }
        else if( cursesIdx == base + (tmp_e - tmp_s) ){ // 末尾を削除
            linkedList.insert(it, Piece(tmp_s, tmp_e - 1, tmp_dataType));
        }
        else{
            long long mid = (cursesIdx - base) + tmp_s;
            it = linkedList.insert(it, Piece(mid + 1, tmp_e, tmp_dataType));
            linkedList.insert(it, Piece(tmp_s, mid - 1, tmp_dataType));
        }
    }
    else{
        // 連結できる場合があるのでちぇっく
        // 既に削除してるので、 it = 削除した要素の直後
        if( it != linkedList.begin() ){
            std::list<Piece>::iterator prev = it;
            prev--;
            if( prev->dataType == it->dataType && prev->e + 1 == it->s ){
                it->s = prev->s;
                linkedList.erase(prev);
            }
        }
    }

    undoStack.push(OperateInfo(ERASE, cursesIdx+1, tmp_tableIdx, tmp_dataType));
}


void PieceTable::undo(){

    if( undoStack.empty() ) return;

    // 反対のことをする必要がある
    switch( undoStack.top().opeType ){
    case INSERT :
        this->erase(undoStack.top().cursesIdx + 1);
        break;
    case ERASE :
        this->_insert(undoStack.top().cursesIdx - 1, undoStack.top().tableIdx, undoStack.top().dataType);
        break;
    default:
        assert(0);
    }
    undoStack.pop(); // 余分に積まれるから削除

    redoStack.push(undoStack.top());
    undoStack.pop();
}


void PieceTable::redo(){
    if( redoStack.empty() ) return;

    switch( redoStack.top().opeType ){
    case INSERT:
        this->_insert(redoStack.top().cursesIdx, redoStack.top().tableIdx, redoStack.top().dataType);
        break;
    case ERASE:
        this->erase(redoStack.top().cursesIdx);
        break;
    default:
        assert(0);
    }
    undoStack.pop(); // 余分に積まれるから削除

    undoStack.push(redoStack.top());
    redoStack.pop();
}

long long PieceTable::getNewFileSize(){
    return newFileSize;
}

int PieceTable::read(char *buf, int size, const long long PageIdx){
    long long j, base = 0;
    int bufCount = 0;
    std::list<Piece>::iterator it;

    for(it = linkedList.begin(); it != linkedList.end(); it++){
        if( base <= PageIdx && PageIdx < base + (it->e - it->s + 1) ) break;
        base += (it->e - it->s + 1);
    }

    // 最初だけ、出力が途中から始まる可能性があるので少し処理が違う

    char *pbuf = buf;
    long long initSum = PageIdx - base;  // 初期における途中から出力する差

    for(; it != linkedList.end(); it++){
        if( it->dataType == ORIGIN ){
            origin.seekg(it->s + initSum, std::ios::beg);

            int len = (int)std::min((long long)size, it->e - (it->s + initSum) + 1LL);
            origin.read(pbuf, len);
            pbuf += len;
            size -= len;
            bufCount += len;

            if( size == 0 ) break;
            if( size < 0 ) assert(0);

            if( origin.fail() ){
                perror("filestream.read");
                exit(0);
            }
        }
        else{
            // BUFFER側の出力
            for(j = it->s + initSum; j <= it->e; j++) {
                if( j >= buffer.size() ) assert(0); // ありえないはず
                //buf[bufCount++] = buffer[(int)j];
                *pbuf++ = buffer[(int)j];
                size--;
                bufCount++;
                if( size == 0 ) break;
                //if( bufCount >= size ) break;
            }
        }
        if( size == 0 ) break;
        //if( bufCount >= size ) break;
        // 2回目以降は不要
        initSum = 0;
    }
    return bufCount;
}


#endif

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <sys/stat.h>
#include <fstream>
#include <cassert>
#include <string>
#include <stack>
using namespace std;

// デバッグのためにグローバル
struct OperateInfo{
    int opeType;         // INSERT or ERASE
    long long cursesIdx; // 全体におけるインデックス値
    long long tableIdx;  // buffer or origin　におけるインデックス値
    int dataType;        // ORIGIN or BUFFER
    OperateInfo(int opeType, long long cursesIdx, long long tableIdx, int dataType) 
        : opeType(opeType), cursesIdx(cursesIdx), tableIdx(tableIdx), dataType(dataType) {}
};

class PieceTable{
private:
    enum TYPE {ORIGIN, BUFFER};
    enum OPE {INSERT, ERASE};

    struct Piece{
        int dataType;   // ORIGIN or BUFFER
        long long s,e;  // [startIndex, endIndex]
        Piece(int dataType, long long s, long long e) : dataType(dataType), s(s), e(e) {}
    };

public:
    std::fstream origin;
    std::list<Piece> linkedList;
    std::vector<unsigned char> buffer;
    std::stack<OperateInfo> undoStack, redoStack;
    long long newFileSize;

    PieceTable(){}

    void initialize(const char *fileName);
    void insert(const long long cursesIdx, const unsigned char data);
    void _insert(const long long cursesIdx, const long long tableIdx, const int dataType);
    void erase(long long cursesIdx);
    
    void undo();
    void redo();


    void clear();

    void allOutput();
    void TestRun(const char *testName);
    void Test_0x00();
    void Test_0x01();
    void Test_0x02();
};


void
PieceTable::initialize(const char *fileName){
    struct stat64 st;

    stat64(fileName, &st);

    // 既に在るファイルを読み書き可能で開く
    this->origin.open(fileName, std::ios::in | std::ios::out | std::ios::binary);
    this->newFileSize = st.st_size;

    if( this->newFileSize > 0LL ){
        this->linkedList.push_back(Piece(ORIGIN, 0LL, this->newFileSize - 1));
    }
}


void
PieceTable::insert(const long long cursesIdx, const unsigned char data){
    this->buffer.push_back(data);
    this->_insert(cursesIdx, (long long)buffer.size() - 1, BUFFER);
}


void
PieceTable::_insert(const long long cursesIdx, const long long tableIdx, const int dataType){
    /**********************************************
      挿入位置(cursesIdx)の範囲を持つPieceを調べる
    ***********************************************/
    long long base = 0;
    std::list<Piece>::iterator it;
    for(it = this->linkedList.begin(); it != this->linkedList.end(); it++){
        if( base <= cursesIdx && cursesIdx < base + (it->e - it->s + 1) ) break;
        base += (it->e - it->s + 1);
    }

    // 挿入情報が揃ったので、先にundoStackに動作情報を積む
    this->undoStack.push(OperateInfo(INSERT, cursesIdx, tableIdx, dataType));


    /**********************************************
      ■ 範囲更新のみが発生する場合を考える
      例：cursesIdx=2 に挿入したい、このときitはPiece[origin, 0, 5]を指している
      Piece[buffer, 0, 1] <-> Piece[origin, 0, 5]
      普通に挿入すると、挿入位置がitの先頭より手前になるので、分割が発生せず新たにPieceが挿入される
      Piece[buffer, 0, 1] <-> Piece[buffer, 2, 2] <-> Piece[origin, 0, 5]
      連結可能かどうかは、itの一つ手前のPieceの状態を見ないといけない
      連結可能なときは、挿入時にitの範囲の先頭位置に対応する箇所であること、
      連結させようとするPiece(prev)と同じデータタイプであること、
      連結させようとするPiece(prev)の範囲から連続していることが条件

      ■ 単純に挿入のみの場合を考える、
      ・itの先頭に挿入
      ・Pieceの末端（現在のデータ列の一番後ろ）に挿入、このときitはlinkedlist.end()と等しい
      のパターンのみ
      
      ■ 範囲を分割してしまう場合を考える
      そのままの意味で、範囲が分割されてしまう場合は対応する範囲に更新するのと、
      新たにPieceを作成して挿入する必要がある
      コンテナのinsertメソッドはinsert(it, Piece())のように、挿入位置を指定すると、
      itが指す状態の手前に挿入処理を行う
      insert(it, Piece())
       -----         ---- 
      | new |  <=>  | it |
       -----         ----

      以下の分割、範囲更新処理の手順は次のようになっている
      1. とりあえず新しい状態を挿入
       ---------         ---- 
      | new(jt) |  <=>  | it |
       ---------         ----
      
      2. 分割される場合
      itの範囲を更新（後半部分にする）、前半部分をjtの手前に新たに挿入
       -----         ----         -----
      | new |  <=>  | jt |  <=>  | it' |
       -----         ----         -----
    **********************************************/

    std::list<Piece>::iterator prev = it;
    if( it != this->linkedList.begin() ) prev--;

    if( it != this->linkedList.begin() &&
        cursesIdx == base &&
        prev->dataType == dataType &&
        prev->e == tableIdx - 1 ){

        prev->e++;
        if( it != this->linkedList.end() &&
            it->dataType == dataType &&
            it->s == tableIdx + 1 ){

            it->s = prev->s;
            this->linkedList.erase(prev);
        }
    }
    else if( it != this->linkedList.end() &&
             it->dataType == dataType &&
             it->s == tableIdx + 1 &&
             cursesIdx == base ){

        it->s--;
    }
    else{
        // 新しい状態が挿入されるのは確定なので、先に挿入する（先頭、末尾、分割）
        std::list<Piece>::iterator jt = this->linkedList.insert(it, Piece(dataType, tableIdx, tableIdx));
        if( base < cursesIdx && it != linkedList.end() ){
            // 範囲が分割される場合
            long long tmp_s = it->s;
            it->s = (cursesIdx - base) + it->s;
            this->linkedList.insert(jt, Piece(it->dataType, tmp_s, tmp_s + (cursesIdx - base) - 1));
        }
    }
}




void
PieceTable::erase(long long cursesIdx){ // バックスペース時の動きを想定
    // カーソルが先頭時には何もしない
    if( cursesIdx <= 0 ) return;
    this->newFileSize--;

    /**********************************************
      バックスペース時の動きを想定すると、削除動作のとき、
      カーソル位置は削除要素より一つ後ろを指していることになる
      ですので、カーソルが指す対象を削除対象にするために1引く
    **********************************************/
    cursesIdx--;
    

    // 削除対象を範囲に含むPieceを調べる
    long long base = 0;
    std::list<Piece>::iterator it;
    for(it = this->linkedList.begin(); it != this->linkedList.end(); it++){
        if( base <= cursesIdx && cursesIdx < base + (it->e - it->s + 1) ) break;
        base += (it->e - it->s + 1);
    }

    // 削除情報が揃ったので、先にundoStackに動作情報を積む
    this->undoStack.push(OperateInfo(ERASE, cursesIdx + 1, (cursesIdx - base) + it->s, it->dataType));


    /**********************************************
      削除対象となるPieceがどのような範囲を持つかをまず考える
      このとき、[4,4]のように、1文字しか持たない場合はそのまま削除
      ただし、そのときに前後のPieceが連結する可能性がある

      ■ 削除対象が先頭、もしくは末尾だった場合
      範囲を更新すればよい

      ■ 分割が生じた場合
      insert時と同じように、範囲を更新しつつ、新たなPieceを挿入

      ■ 1文字Pieceを削除して、前後のPieceが連結する場合
      以下の処理手順は次のようになっている
      削除前 : itは1文字のみのPieceを指している
       ------         ----         ------ 
      | prev |  <=>  | it |  <=>  | next |
      ------         ----         ------
      
      it削除後、後ろ(next)をitとする
       ------         ---------- 
      | prev |  <=>  | next(it) |
      ------         ----------

      prevとnext(it)のデータタイプが同じ、かつ、連続してる場合は、
      next(it)の範囲を更新し、不必要になったprevを削除する
       ----------
      | next(it) |
      ----------

      
      前後が連結する可能性があるのは、1文字Pieceを削除した場合のみである
      複数範囲を持つPieceの先頭or末尾を削除したときに、
      例えば、[5,8] --> 先頭削除[6,8] or 末尾削除[5,7]　のどちらかの状態になる
      このとき、[5,8]の時点で既に前後のPieceと連結されていないので、
      削除されてから連結が発生しない
      また、中央を削除して分割するときは、
      例えば、[4,9] --> {[4,4],[6,9]}, {[4,5],[7,9]},... 
      このとき、変化があったのは中央部分のみで、[4,9]の前後のPieceに影響を与えない
      よって、同様に連結は発生しない
     **********************************************/
    if( it->s != it->e ){
        if( cursesIdx == base ){ // 先頭を削除
            it->s++;
        }
        else if( cursesIdx == base + (it->e - it->s) ){ // 末尾を削除
            it->e--;
        }
        else{
            // 分割が生じた
            long long mid = (cursesIdx - base) + it->s;
            this->linkedList.insert(it, Piece(it->dataType, it->s, mid - 1)); // 前半を新たに手前に挿入
            it->s = mid + 1; // 後半となるPieceの範囲更新
        }
    }
    else{
        it = this->linkedList.erase(it); // 1文字のPieceだからそのまま削除して、直後のPieceをitとする

        if( it != this->linkedList.begin() ){
            // 削除後、前後のPieceが繋がるケースがある
            std::list<Piece>::iterator prev = it;
            prev--;
            if( prev->dataType == it->dataType && prev->e + 1 == it->s ){
                it->s = prev->s;
                this->linkedList.erase(prev);
            }
        }
    }

    
}

void
PieceTable::clear(){
    this->origin.close();
    this->linkedList.clear();
    this->buffer.clear();
    this->newFileSize = 0;

    //while( !undoStack.empty() ) undoStack.pop();
    //while( !redoStack.empty() ) redoStack.pop();
}


void
PieceTable::undo(){

    if( this->undoStack.empty() ) return;

    // 反対のことをする必要がある
    switch( this->undoStack.top().opeType ){
    case INSERT :
        this->erase(this->undoStack.top().cursesIdx + 1);
        break;
    case ERASE :
        this->_insert(this->undoStack.top().cursesIdx - 1, this->undoStack.top().tableIdx, this->undoStack.top().dataType);
        break;
    default:
        assert(0);
    }
    this->undoStack.pop(); // ※余分に積まれるから削除

    this->redoStack.push(this->undoStack.top());
    this->undoStack.pop();
}


void
PieceTable::redo(){
    if( this->redoStack.empty() ) return;

    switch( this->redoStack.top().opeType ){
    case INSERT:
        this->_insert(this->redoStack.top().cursesIdx, this->redoStack.top().tableIdx, this->redoStack.top().dataType);
        break;
    case ERASE:
        this->erase(this->redoStack.top().cursesIdx);
        break;
    default:
        assert(0);
    }
    this->undoStack.pop(); // 余分に積まれるから削除

    this->undoStack.push(this->redoStack.top());
    this->redoStack.pop();
}




int main(){
    PieceTable ptable;

    //ptable.Test_0x01();
    ptable.Test_0x02();
    return 0;
}






// -----------------------------------------------------
/*
  raw.bin : 扱うデータファイル
  in.txt : 操作命令を行う入力データ
  out.txt : allOutput()で出力されるべき正しい出力を記述する

  操作命令の仕様を決める
  1行に1操作を記述する
  数字 : カーソル位置を指定
  i 文字 : insert 文字(大小英字数字記号のみ)
  e : erase
  u : undo
  r : redo

  allOutputの仕様を決める
  いずれも1行で表現
  1行目 : 元々のdata（改行なし）
  2行目 : buffer
  3行目 : 現在のdata（改行なし）
  4行目以降 : PieceTableの状態

  sample:
  itti-kun
  AB
  itti-AkuBn
  [ORIGIN, 0, 4]
  [BUFFER, 0, 0]
  [ORIGIN, 5, 6]
  [BUFFER, 1, 1]
  [ORIGIN, 7, 7]
 */


void
PieceTable::allOutput(){

    // 元々のdataを出力させる
    this->origin.seekg(0, std::ios::beg);
    string in;
    this->origin >> in;
    std::cout << in << std::endl;

    // buffer内部を出力
    for(int i=0; i<(int)this->buffer.size(); i++) printf("%c", this->buffer[i]); puts("");

    // 現在のdataを出力
    char buf[1<<10];
    std::list<Piece>::iterator it;
    for(it = this->linkedList.begin(); it != this->linkedList.end(); it++){
        if( it->dataType == ORIGIN ){
            this->origin.seekg(it->s, std::ios::beg);
            int len = it->e - it->s + 1;
            this->origin.read(buf, len);
            buf[len] = 0;
            std::cout << buf;
        }
        else{
            for(int i = it->s; i <= it->e; i++){
                printf("%c",this->buffer[i]);
            }
        }
    }
    puts("");

    // PieceTableの状態を出力
    printf("PieceTable\n");
    for(it = this->linkedList.begin(); it != this->linkedList.end(); it++){
        printf("    [%s, %lld, %lld]\n", (it->dataType == ORIGIN ? "ORIGIN" : "BUFFER"), it->s, it->e);
    }
    
    // UndoStackの状態を出力
    printf("UndoStack\n");
    std::stack<OperateInfo> tmpUndo = this->undoStack;
    while( !tmpUndo.empty() ){
        OperateInfo op = tmpUndo.top();
        tmpUndo.pop();
        printf("    [%s, %lld, %lld, %s]\n",
               (op.opeType == INSERT ? "INSERT" : "ERASE"),
               op.cursesIdx,
               op.tableIdx,
               (op.dataType == ORIGIN ? "ORIGIN" : "BUFFER"));
    }

    // RedoStackの状態を出力
    printf("RedoStack\n");
    std::stack<OperateInfo> tmpRedo = this->redoStack;
    while( !tmpRedo.empty() ){
        OperateInfo op = tmpRedo.top();
        tmpRedo.pop();
        printf("    [%s, %lld, %lld, %s]\n",
               (op.opeType == INSERT ? "INSERT" : "ERASE"),
               op.cursesIdx,
               op.tableIdx,
               (op.dataType == ORIGIN ? "ORIGIN" : "BUFFER"));
    }
}


bool
isCurses(const char *buf){
    int i = 0;
    do{
        if( !('0' <= buf[i] && buf[i] <= '9') ) return false;
        i++;
    }while( buf[i] != '\0' );

    return true;
}

bool
isInsert(const char *buf){
    if( buf[0] != 'i' ) return false;
    
    for(int i=1; buf[i] != '\0'; i++){
        if( buf[i] == ' ' ) continue;
        if( 0x21 <= buf[i] && buf[i] <= 0x7e ) return true;
        return false;
    }
    return false;
}

bool isErase(const char *buf){ return buf[0] == 'e'; }
bool isUndo(const char *buf){ return buf[0] == 'u'; }
bool isRedo(const char *buf){ return buf[0] == 'r'; }


unsigned char
getByte(const char *buf){
    // isInsertがtrueであることが前提
    for(int i=1; buf[i] != '\0'; i++){
        if( 0x21 <= buf[i] && buf[i] <= 0x7e ) return (unsigned char)buf[i];
    }
    return 0;
}


void PieceTable::Test_0x00(){ this->TestRun("0x00"); }

void PieceTable::Test_0x01(){ this->TestRun("0x01"); }

void PieceTable::Test_0x02(){ this->TestRun("0x02"); }

void
PieceTable::TestRun(const char *testName){
    this->clear();

    // 扱うrawデータ（必須
    string rawFileName = "./TEST/" + string(testName) + "/raw.bin";
    this->initialize(rawFileName.c_str());
    
    // 操作命令を行う入力データ（必須
    string operationFileName = "./TEST/" + string(testName) + "/in.txt";
    std::ifstream ifs(operationFileName.c_str());
    char buf[1<<10];

    int x = 0;

    // 命令通りに処理を行う
    long long cursesIdx;
    while( ifs.getline(buf, 1<<10) ){
        //std::cout << buf << std::endl;
        if( isCurses(buf) ){ // カーソル位置の変更
            cursesIdx = atoi(buf);
        }
        else if( isInsert(buf) ){ // 挿入処理
            unsigned char byte = getByte(buf);
            this->insert(cursesIdx, byte);
            cursesIdx++;
        }
        else if( isErase(buf) ){ // 削除処理, backspaceと一緒
            this->erase(cursesIdx);
            cursesIdx--;
            if( cursesIdx < 0 ) cursesIdx = 0;
        }
        else if( isUndo(buf) ){
            this->undo();
        }
        else if( isRedo(buf) ){
            this->redo();
        }
        else{
            puts("okasina input");
            assert(0);
        }

        printf("### Turn #%d : %s\n", x++, buf);
        printf("cursesIdx = %lld\n",cursesIdx);
        this->allOutput();
        puts("----------------------------------------------\n");
    }
}




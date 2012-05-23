#ifndef __HEXEDITOR_H__
#define __HEXEDITOR_H__


#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <curses.h>
#include <sys/stat.h>
#include "PieceTable.hpp"


#define KEY_ESC 0x1b

static const int xTable[] = {
    18,21,24,27,
    30,33,36,39,
    43,46,49,52,
    55,58,61,64
};
#define xTableSIZE 16



class HexEditor{
private:
    enum MODE {NORMALMODE, INSERTMODE, COMMANDMODE, QUIT};
    void normalMode(int);
    void insertMode(int);
    void commandMode(int);
    bool _genRandomString(char name[], const int len, int rem);
    std::string getTmpFileName();

public:
    PieceTable ptable;
    std::string originPath;
    std::string newFilePath;
    int mode;
    long long PageIdx;   // 現在の1画面における先頭のインデックス値
    long long CursesIdx; // 全体における現在のカーソルのインデックス値

    HexEditor(){}
    HexEditor(char *path){
        this->initialize(path);
    }

    ~HexEditor(){
        endwin();
        if( newFilePath != "" ){
            // 上書き保存がされているので、
            ptable.clear();
            // 元のファイルを削除
            if( remove(originPath.c_str()) ){
                perror("remove");
                exit(0);
            }
            
            // 元のファイル名に変更
            if( rename(newFilePath.c_str(), originPath.c_str()) ){
                perror("rename");
                exit(0);
            }
        }
    }

    
    void initialize(char *path);
    void run();    
    void print();
    void overWrite();
};



void HexEditor::initialize(char *path){
    ptable.initialize(path);

    originPath = std::string(path);
    PageIdx = CursesIdx = 0;
    
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
    // stdscrのまま使う
    ESCDELAY = 25; // グローバル変数として存在してるらしい
    mode = NORMALMODE; // ノーマルモードに設定
}


void HexEditor::normalMode(int key){
    switch( key ){
    case 'k':
    case KEY_UP:
        CursesIdx -= xTableSIZE;
        if( CursesIdx < 0 ) CursesIdx = 0;
        break;
    case 'j':
    case KEY_DOWN:
        CursesIdx += xTableSIZE;
        if( CursesIdx > ptable.getNewFileSize() ) CursesIdx = ptable.getNewFileSize();
        break;
    case 'l':
    case KEY_RIGHT:
        CursesIdx++;
        if( CursesIdx > ptable.getNewFileSize() ) CursesIdx--;
        break;
    case 'h':
    case KEY_LEFT:
        CursesIdx--;
        if( CursesIdx < 0 ) CursesIdx = 0;
        break;
    case KEY_ESC:
        break;
    case KEY_BACKSPACE:
        break;
    case 4: // Ctrl-d -> PageDown
        CursesIdx += xTableSIZE * std::max((LINES - 2) / 2, 1);
        if( CursesIdx > ptable.getNewFileSize() ) CursesIdx = ptable.getNewFileSize();
        break;
    case 21: // Ctrl-u -> PageUp
        CursesIdx -= xTableSIZE * std::max((LINES - 2) / 2, 1);
        if( CursesIdx < 0 ) CursesIdx = 0;
        break;
    case 'a':
        mode = INSERTMODE;
        CursesIdx++;
        if( CursesIdx > ptable.getNewFileSize() ) CursesIdx--;
        break;
    case 'i':
        mode = INSERTMODE;
        break;
    case 'x':
    case KEY_DC: // del
        if( CursesIdx < ptable.getNewFileSize() ){
            ptable.erase(CursesIdx + 1);
            //clear();
            erase();
            this->print();
            refresh();
        }
        break;
    case 'u':
        // Undo
        ptable.undo();
        //clear();
        erase();
        this->print();
        refresh();
        break;
    case 18: // CTRL-R
        // Redo
        ptable.redo();
        //clear();
        erase();
        this->print();
        refresh();
        break;
    case ':': // コマンドモード
        //clear();
        erase();
        this->print();
        refresh();
        commandMode(key);
        break;
    default:
        // ターミナルのサイズが変わったなどの可能性がある
        //clear();
        erase();
        this->print();
        refresh();
        break;
    }
}


void HexEditor::insertMode(int key){

 head:
    switch(key){
    case KEY_UP:
        CursesIdx -= xTableSIZE;
        if( CursesIdx < 0 ) CursesIdx = 0;
        break;
    case KEY_DOWN:
        CursesIdx += xTableSIZE;
        if( CursesIdx > ptable.getNewFileSize() ) CursesIdx = ptable.getNewFileSize();
        break;
    case KEY_RIGHT:
        CursesIdx++;
        if( CursesIdx > ptable.getNewFileSize() ) CursesIdx--;
        break;
    case KEY_LEFT:
        CursesIdx--;
        if( CursesIdx < 0 ) CursesIdx = 0;
        break;
    case KEY_ESC:
        mode = NORMALMODE;
        break;
    case KEY_BACKSPACE:
        ptable.erase(CursesIdx);
        CursesIdx--;
        if( CursesIdx < 0 ) CursesIdx = 0;
        //clear();
        erase();
        this->print();
        refresh();
        break;
    case KEY_DC: // del
        if( CursesIdx < ptable.getNewFileSize() ){
            ptable.erase(CursesIdx + 1);
            //clear();
            erase();
            this->print();
            refresh();
        }
        break;
    default:
        // INSERT
        if( ('0' <= key && key <= '9') || ('a' <= key && key <= 'f') ) {
                
            if( '0' <= key && key <= '9' ){
                key -= '0';
            }
            else{
                key = key - 'a' + 10;
            }
            unsigned char data = (unsigned char)(key << 4); // 上位4bitとして扱う
            long long tz = CursesIdx - PageIdx;
            int tx = (int)(tz % (long long)xTableSIZE), ty = (int)(tz / (long long)xTableSIZE);

            ptable.insert(CursesIdx, data);
            this->print();
            move(ty + 1, xTable[tx]);
            refresh();
                
            key = getch();
            if( ('0' <= key && key <= '9') || ('a' <= key && key <= 'f') ){
                if( '0' <= key && key <= '9' ){
                    key -= '0';
                }
                else{
                    key = key - 'a' + 10;
                }
                data |= (unsigned char)key; // 下位4bitとして挿入
                ptable.buffer[ptable.buffer.size() - 1] = data; // 変更する
                this->print();
                refresh();
                CursesIdx++;
            }
            else{
                // 入力がこの時点で終了なので、keyは入力後として処理
                goto head;
            }
        }
        else{
            // TODO ターミナルのサイズを変更した可能性があるから、カーソル位置も調整する必要がある
            //clear();
            erase();
            this->print();
            refresh();
        }
        break;
    }
}

// normalModeから呼ばれる
void HexEditor::commandMode(int key){
    char buf[32] = {0};

    mvprintw(LINES - 1, 0, "%c", (char)key);

    keypad(stdscr, false);
    echo();
    mvgetnstr(LINES - 1, 1, buf, 31);
    noecho();
    keypad(stdscr, true);

    if( !strncmp(buf, "q!", 31) ){
        mode = QUIT;
    }
    else if( !strncmp(buf, "w!", 31) ){
        this->overWrite();
    }
    else if( !strncmp(buf, "wq!", 31) ){
        this->overWrite();
        mode = QUIT;
    }
    else{
        // アドレスジャンプの可能性がある
        char *endptr;
        int len = strlen(buf);
        long long address = strtoll(buf, &endptr, 16);
        if( len > 1 && buf[len-1] == 'G' && endptr == (buf + len - 1) ){
            CursesIdx = address;
            if( CursesIdx < 0 ) CursesIdx = 0;
            if( CursesIdx > ptable.getNewFileSize() ) CursesIdx = ptable.getNewFileSize();
        }
    }
}


void HexEditor::run(){

    this->print();

    for(;;){
        if( mode == QUIT ) break;

        // 表示範囲の更新
        
        if( CursesIdx < PageIdx ){
            /*
              飛んだケースの処理を考えると、
              xTableSIZE = 3のとき
              1/3 = 1
              2/3 = 1
              3/3 = 1
              4/3 = 2
              5/3 = 2
              6/3 = 2
              7/3 = 3

              PageIdx - xTableSIZE * X <= CursesIdx
              -X <= (CursesIdx - PageIdx) / xTableSIZE
              X >= (PageIdx - CursesIdx) / xTableSIZE
              割り切れるならX、割り切れないなら X + 1が解になる
            */
            long long X = (PageIdx - CursesIdx + xTableSIZE - 1) / xTableSIZE;
            PageIdx -= xTableSIZE * X;
            if( PageIdx < 0 ) PageIdx = 0;
            //clear();
            erase();
            this->print();
            refresh();
        }
        if( PageIdx + xTableSIZE * (LINES - 2) <= CursesIdx ){
            /*
              さてどうするか
              満たしたいのは、
              PageIdx + xTableSIZE * (LINES - 2) + xTableSIZE * X > CursesIdx
              PageIdx + xTableSIZE * ((LINES - 2) + X) > CursesIdx
              (LINES - 2) + X > (CursesIdx - PageIdx) / xTableSIZE
              X > (CursesIdx - PageIdx) / xTableSIZE - (LINES - 2)
            */
            long long X = (CursesIdx - PageIdx) / xTableSIZE - (LINES - 2) + 1;
            PageIdx += xTableSIZE * X;
            //clear();
            erase();
            this->print();
            refresh();
        }

        // modeの表示
        if( mode == INSERTMODE ) mvprintw(LINES - 1, 0, " --INSERT-- ");
        else mvprintw(LINES - 1, 0, "                ");

        long long z = CursesIdx - PageIdx;
        long long x = z % xTableSIZE, y = z / xTableSIZE;
        move((int)(y + 1), xTable[(int)x]);


        int key = getch();
        switch( mode ){
        case NORMALMODE:
            normalMode(key);
            break;
        case INSERTMODE:
            insertMode(key);
            break;
        default:
            break;
        }
    }
}


void HexEditor::print(){
    char buf[1<<11];   // たぶん H * xTableSizeでこの容量は越えないだろｗ
    int H = LINES - 2; // 最初の行と最後の行の処理を除くから-2

    // 8*2 + 2 + 16*2 + 18 = 68
    // ACSII表示の部分
    mvvline(1, 8*2 + 2 + 16*2+16+2, '|', 1);
    mvvline(1, 8*2 + 2 + 16*2+16+2 + 17, '|', 1);

    // アドレス表示
    mvprintw(1, 0, "%016llx", PageIdx);

    // 桁の表示
    int cnt = 0;
    for(int i = 18; ;){
        mvprintw(0, i, "%02x", cnt);
        mvprintw(0, 8*2 + 2 + 16*2+16+2 + 1 + cnt, "%x", cnt);
        i += 3;
        cnt++;
        if( cnt % 8 == 0 ) i++;
        if( cnt % 16 == 0 ) break;
    }

    if( H < 1 ) return;

    int res = ptable.read(buf, H * xTableSIZE, PageIdx);

    int y = 1, x = 16 + 2;
    for(int i = 0; i < res;){
        mvprintw(y, x, "%02X", (unsigned char)buf[i]);
        if( 0x20 <= buf[i] && buf[i] <= 0x7e ){
            mvprintw(y, 8*2 + 2 + 16*2 + 18 + 1 + i%16, "%c", buf[i]);
        }
        else{
            mvprintw(y, 8*2 + 2 + 16*2 + 18 + 1 + i%16, ".");
        }
        i++;
        if( i >= res ) break;
        x += 3;
        if( i % 8 == 0 ){
            x++;
        }
        if( i % 16 == 0 ){
            x = 16 + 2;
            y++;
            mvprintw(y, 0, "%016llx", PageIdx + (y - 1) * 16);
            mvvline(y, 8*2 + 2 + 16*2+16+2, '|', 1);
            mvvline(y, 8*2 + 2 + 16*2+16+2 + 17, '|', 1);
        }
    }
}

bool HexEditor::_genRandomString(char name[], int len, int rem){
    char c;

    if( rem == 0 ){
        // pathどうしよう
        struct stat64 st;
        if( stat64(name, &st) == 0 ) return false; // 成功したのでファイルが存在する
        return true;
    }

    for(c = 'a'; c <= 'z'; c++){
        name[len + rem - 1] = c;
        if( _genRandomString(name, len, rem - 1) ) return true;
    }

    for(c = 'A'; c <= 'Z'; c++){
        name[len + rem - 1] = c;
        if( _genRandomString(name, len, rem - 1) ) return true;
    }
    return false;
}


std::string HexEditor::getTmpFileName(){
    char name[512];
    int rem, len;

    if( originPath.length() > 400 ) assert(0); // とりあえず、まぁないとは思うけど
    strcpy(name, originPath.c_str());
    strcat(name, "_tmp_");
    len = strlen(name);

    // 1文字から順に一時ファイル作成の試み
    for(rem = 1; rem <= 100; rem++){ // 256文字までにはヒットするだろ
        name[len + rem] = '\0';
        if( _genRandomString(name, len, rem) ){
            return std::string(name);
        }
    }

    return "";
}


void HexEditor::overWrite(){
    std::ofstream targetFile;
    size_t len;
    long long i;
    char buf[(1<<12)+10];
    int bufSize = 1<<12;


    // 新規に書きこむ別名ファイルを用意する
    if( newFilePath == "" ) newFilePath = getTmpFileName();
    if( newFilePath == "" ) assert(0);

    targetFile.open(newFilePath.c_str(), std::ios::binary);
    if( targetFile.fail() ){
        puts("targetFile error");
        exit(0);
    }

    // 書き込み
    for(i = 0; i < ptable.getNewFileSize(); i += bufSize){
        len = ptable.read(buf, bufSize, i);
        targetFile.write(buf, len);
    }
}



#endif

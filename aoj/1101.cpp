#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <sstream>
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)

/*
  AOJ :: 1101
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1101&lang=jp
 */

list<char> buffer;
list<char>::iterator it;

void build_buffer(const string& in){
    int i, n = in.length();
    buffer.clear();
    rep(i,n) buffer.push_back(in[i]);
    it = buffer.begin();
}

void forward_char(){
    if( it != buffer.end() ) it++;
}
void forward_word(){
    // 空白の場合
    if( it != buffer.end() && *it == ' ' ){
        while( it != buffer.end() && *it == ' ' ) it++;
    }
    while( it != buffer.end() && *it != ' ' ) it++;
}

void backward_char(){
    if( it != buffer.begin() ) it--;
}
void backward_word(){
    if( it == buffer.end() ) it--;

    list<char>::iterator tmp = it;
    tmp--;
    if( tmp != buffer.begin() && *tmp == ' ' ){ // 単語の先頭だった場合
        it = tmp;
    }
    while( it != buffer.begin() && *it == ' ' ) it--;
    while( it != buffer.begin() && *it != ' ' ){
        it--;
        if( *it == ' ' ){
            it++; break;
        }
    }
}

void delete_char(){
    if( it != buffer.end() ) it = buffer.erase(it);
}
void delete_word(){
    // spaceを削除
    list<char>::iterator tmp = it;
    while( tmp != buffer.end() && *tmp == ' ' ) tmp++;
    if( tmp != buffer.end() ){
        while( it != buffer.end() && *it == ' ' ){
            it = buffer.erase(it);
        }
        while( it != buffer.end() && *it != ' ' ){
            it = buffer.erase(it);
        }
    }
}

void insertion(const string& in){
    int i, n = in.length();

    rep(i,n){
        buffer.insert(it, in[i]);
    }
}

int main(){
    int T,i,n;
    string in;

    cin >> T; cin.ignore();
    while( T-- ){
        getline(cin, in);
        cin >> n; cin.ignore();

        build_buffer(in);

        rep(i,n){
            getline(cin, in);
            if( in == "forward char" ){
                forward_char();
            }
            else if( in == "forward word" ){
                forward_word();
            }
            else if( in == "backward char" ){
                backward_char();
            }
            else if( in == "backward word" ){
                backward_word();
            }
            else if( in.substr(0,6)  == "insert" ){
                string tmp = in.substr(8,in.length() - 9);
                //cout << tmp << endl;
                insertion(tmp);
            }
            else if( in == "delete char" ){
                delete_char();
            }
            else if( in == "delete word" ){
                delete_word();
            }

            // debug
            /*
            printf("%d : ", i);
            foreach(s,buffer){
                if( s == it ) putchar('^');
                cout << *s;
            }
            if( it == buffer.end() ) putchar('^');
            cout << endl;
            */
        }

        // output
        foreach(s,buffer){
            if( s == it ) putchar('^');
            cout << *s;
        }
        if( it == buffer.end() ) putchar('^');
        cout << endl;
    }
    return 0;
}



/*
Hallow, Word.
7
forward char
delete word
insert "ello, "
forward word
backward char
backward char
insert "l"


^Hallow,
Word.

1. forward char
H^allow,
 Word.

2. delete word
H^
 Word.

3. insert "ello, "
Hello,
 ^ Word.

4. forward word
Hello,
  Word.^

5. backward char
Hello,
  Word^.

6. backward char
Hello,
  Wor^d.

7. insert "l"
Hello,
  Worl^d.

*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)

class MonochromaticBoard{
public:
    int theMin(vector<string> board){
        int h = board.size();
        int w = board[0].length();
        int i,j;
        int res = 0;
        bool allblack = true;

        // yoko
        rep(i,h){
            int wc = 0;
            rep(j,w){
                if( board[i][j] == 'W' ) wc++;
            }
            if( 0 < wc ) allblack = false;
            if( 0 < wc && wc != w ){
                res += w - wc;
                break;
            }
        }

        // tate
        rep(j,w){
            int wc = 0;
            rep(i,h){
                if( board[i][j] == 'W' ) wc++;
            }
            if( 0 < wc ) allblack = false;
            if( 0 < wc && wc != h ){
                res += h - wc;
                break;
            }
        }

        return allblack ? min(w,h) : res;
    }
};


int main(){
    const char *s[] = {"BBBBBBBB",
 "BBBBBBBB",
 "BBBBBBBB",
 "WBWBBBWB",
                       "BBBBBBBB"};


    vector<string> v;
    int i;
    rep(i,sizeof(s)/sizeof(s[0])) v.push_back(string(s[i]));

    MonochromaticBoard M;
    cout << M.theMin(v) << endl;

    return 0;
}


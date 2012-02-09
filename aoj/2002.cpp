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

int H,W;
char field[55][55];
bool kind[256], used[256];


// 長方形かどうか。自分より下の物体があればfalse
bool is_check(int x1, int y1, int x2, int y2, char mark){
    int i,j;
    for(i=y1; i<=y2; i++){
        for(j=x1; j<=x2; j++){
            if( field[i][j] == '.' ||
                (field[i][j] != mark && used[field[i][j]]) ) return false;
        }
    }
    return true;
}


bool solve(char mark){
    int i,j,x1,x2,y1,y2;

    x1 = y1 = 55;
    x2 = y2 = 0;
    rep(i,H){
        rep(j,W){
            if( field[i][j] == mark ){
                x1 = min(x1, j), y1 = min(y1, i);
                x2 = max(x2, j), y2 = max(y2, i);
            }
        }
    }

    if( !is_check(x1,y1,x2,y2,mark) ) return false;

    bool tmp[256];
    rep(i,256) tmp[i] = used[i];

    // まだ調べてない自分より高い物体から再帰
    for(i=y1; i<=y2; i++){
        for(j=x1; j<=x2; j++){
            if( !tmp[field[i][j]] ){
                tmp[field[i][j]] = true;
                used[field[i][j]] = true;
                bool res = solve(field[i][j]);
                used[field[i][j]] = false;
                if( !res ) return false;
            }
        }
    }
    return true;
}

int main(){
    int T,i,j;
    cin >> T;

    while( T-- ){
        cin >> H >> W;
        memset(kind, false, sizeof(kind));

        rep(i,H) cin >> field[i];

        bool ok = true;
        rep(i,H){
            rep(j,W){
                if( field[i][j] != '.' && !kind[field[i][j]] ){
                    used[field[i][j]] = true;
                    ok &= solve(field[i][j]);
                    used[field[i][j]] = false;
                    kind[field[i][j]] = true;
                }
            }
        }

        puts(ok ? "SAFE" : "SUSPICIOUS");
    }

    return 0;
}

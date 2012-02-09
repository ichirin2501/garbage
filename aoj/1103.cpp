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

int x[4],y[4];
bool board[4][4];

int solve(int cnt){
    int i, j, k, res = 0;

    if( cnt == 8 ){
        return 1;
    }

    bool f = false;
    rep(i,4){
        rep(j,4){
            if( !board[i][j] ){
                f = true; break;
            }
        }
        if( f ) break;
    }

    rep(k,4){
        int tx = j + x[k];
        int ty = i + y[k];
        if( tx < 0 || tx >= 4 || ty >= 4 || ty < 0 || board[ty][tx] ) continue;
        board[i][j] = board[ty][tx] = true;
        res += solve(cnt+1);
        board[i][j] = board[ty][tx] = false;
    }
    return res;
}

int main(){

    while( scanf("%d %d %d %d %d %d %d %d",x,y,x+1,y+1,x+2,y+2,x+3,y+3) != 1 ){
        memset(board, false, sizeof(board));
        cout << solve(0) << endl;
    }
    return 0;
}

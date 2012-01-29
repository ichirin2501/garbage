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
#include <sstream>
#include <list>
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)

const int dx[] = {-1,0,1,1,1,0,-1,-1};
const int dy[] = {-1,-1,-1,0,1,1,1,0};
int field[5][4];
int ans;


void remove_pair(int x, int y, int tx, int ty){
    int i, sa = 1;
    if( 4*y + x < 4*ty + tx ){
        for(i=4*y+x; i<20-sa; i++){
            if( i+1 == 4*ty + tx ) sa++;
            field[i/4][i%4] = field[(i+sa)/4][(i+sa)%4];
        }
    }
    else{
        for(i=4*ty+tx; i<20-sa; i++){
            if( i+1 == 4*y + x ) sa++;
            field[i/4][i%4] = field[(i+sa)/4][(i+sa)%4];
        }
    }
}

void undo(int x, int y, int tx, int ty, int num){
    int i, sa = 2;
    if( 4*y + x > 4*ty + tx ){
        for(i=19; i-sa>=4*ty+tx; i--){
            if( i < 4*y + x ) sa = 1;
            field[i/4][i%4] = field[(i-sa)/4][(i-sa)%4];
        }
    }
    else{
        for(i=19; i-sa>=4*y+x; i--){
            if( i < 4*ty + tx ) sa = 1;
            field[i/4][i%4] = field[(i-sa)/4][(i-sa)%4];
        }
    }
    field[y][x] = field[ty][tx] = num;
}

void backtrack(int cnt){
    int i,j,k;

    ans = min(ans, 20-cnt);
    if( cnt == 20 ) return;

    for(i=0; i<5; i++){
        for(j=0; j<4; j++){
            if( 4*i + j >= 20-cnt ) continue;
            for(k=0; k<8; k++){
                int tx = j + dx[k];
                int ty = i + dy[k];
                int num = field[i][j];
                if( tx < 0 || tx >= 4 || ty >= 5 || ty < 0 ) continue;
                if( 4*ty + tx >= 20-cnt || field[ty][tx] != field[i][j] ) continue;

                remove_pair(j,i,tx,ty);
                backtrack(cnt+2);
                undo(j,i,tx,ty,num);
                if( ans == 0 ) return;
            }
        }
    }
}

int main(){
    int T,i,j;

    cin >> T;
    while( T-- ){
        ans = 20;

        // input
        rep(i,5) rep(j,4) {
            cin >> field[i][j];
        }

        backtrack(0);
        cout << ans << endl;
    }

    return 0;
}

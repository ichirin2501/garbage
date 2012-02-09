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

char grid[110][110];
bool visited[110][110];
int H,W;

void dfs(int x, int y, char mark){
    if( x < 0 || y >= H || x >= W || y < 0 ) return;
    if( grid[y][x] != mark || visited[y][x] ) return;
    visited[y][x] = true;
    dfs(x-1,y,mark); dfs(x+1,y,mark); dfs(x,y-1,mark); dfs(x,y+1,mark);
}

int main(){
    int i,j,k,res;

    while( cin >> H >> W, H|W ){
        memset(visited, false, sizeof(visited));
        res = 0;

        rep(i,H) cin >> grid[i];

        rep(i,H){
            rep(j,W){
                if( !visited[i][j] ){
                    res++;
                    dfs(j,i,grid[i][j]);
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}

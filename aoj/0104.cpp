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
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)

bool visited[120][120];
char field[120][120];

int main(){
    int h,w,i;

    while( cin >> h >> w, h|w ){
        // init
        memset(visited, false, sizeof(visited));

        // input
        rep(i,h) cin >> field[i];

        int x = 0, y = 0;
        visited[y][x] = true;
        while( true ){
            switch( field[y][x] ){
            case '>': x++; break;
            case '<': x--; break;
            case '^': y--; break;
            case 'v': y++; break;
            default: break;
            }
            if( field[y][x] == '.' ){
                printf("%d %d\n",x,y);
                break;
            }
            if( visited[y][x] ){
                puts("LOOP");
                break;
            }
            visited[y][x] = true;
        }
    }

    return 0;
}

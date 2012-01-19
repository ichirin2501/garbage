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

const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
double memo[1<<7][55][55];

struct state{
    int S,x,y;
    state(int _s, int _x, int _y){
        S=_s, x=_x, y=_y;
    }
};

class ColorfulMazeTwo{
public:
    bool iscolor(char c){
        return ('A' <= c && c <= 'G');
    }
    double getProbability(vector<string> maze, vector<int> trap){
        int i,j,k;
        int h = maze.size();
        int w = maze[0].size();
        int ts = trap.size();
        int sx,sy,gx,gy;

        rep(i,h) rep(j,w){
            if( maze[i][j] == '$' ){
                sx = j; sy = i;
            }
            if( maze[i][j] == '!' ){
                gx = j; gy = i;
            }
        }

        queue<state> q;
        q.push(state(0,sx,sy));
        memo[0][sy][sx] = 1.0;

        while( !q.empty() ){
            int x = q.front().x;
            int y = q.front().y;
            int s = q.front().S;
            double life = memo[s][y][x];
            q.pop();

            rep(k,4){
                int tx = x + dx[k];
                int ty = y + dy[k];
                if( tx < 0 || ty >= h || tx >= w || ty < 0 || maze[ty][tx] == '#' ) continue;

                char c = maze[ty][tx];
                if( iscolor(c) && !(s & (1<<(c-'A'))) ){
                    double nc = life * (1.0 - (double)trap[c-'A'] / 100.0);
                    int ns = s | (1<<(c-'A'));
                    if( memo[ns][ty][tx] < nc ){
                        memo[ns][ty][tx] = nc;
                        q.push(state(ns, tx, ty));
                    }
                }
                else{
                    // 既に通過した色、または空
                    if( memo[s][ty][tx] < life ){
                        memo[s][ty][tx] = life;
                        q.push(state(s, tx, ty));
                    }
                }
            }
        }

        double res = 0.0;
        for(i=0; i<(1<<ts); i++) res = max(res, memo[i][gy][gx]);
        return res;
    }
};

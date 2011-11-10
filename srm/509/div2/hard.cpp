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

const int dx[] = {0, 0, 1,-1};
const int dy[] = {1,-1, 0, 0};

int memo[64][64][64];

struct state{
    int x,y,k,cost;
    state(int _x, int _y, int _k, int c){
        x = _x;
        y = _y;
        k = _k;
        cost = c;
    }
};

bool inside(int w, int h, int x, int y){
    return !(x<0 || x>=w || y>=h || y<0 );
}

class NumberLabyrinthDiv2{
public:
    int getMinimumNumberOfMoves(vector <string> board, int r1, int c1, int r2, int c2, int K){
        int i,j,k;
        int h = board.size();
        int w = board[0].size();
        int res = -1;
        
        rep(i,64)rep(j,64)rep(k,64) memo[i][j][k] = INT_MAX;

        queue<state> q;
        q.push(state(c1, r1, K, 0));
        memo[r1][c1][K] = 0;
        bool goal = false;
        
        while( !q.empty() ){
            state s = q.front();
            q.pop();
            if( board[s.y][s.x] == '.' ){
                if( s.k == 0 ) continue;
                REP(i,1,10){
                    rep(j,4){
                        int tx = s.x + dx[j] * i;
                        int ty = s.y + dy[j] * i;
                        if( !inside(w,h,tx,ty) || memo[ty][tx][s.k-1] <= s.cost+1 ) continue;
                        memo[ty][tx][s.k-1] = s.cost + 1;
                        q.push(state(tx, ty, s.k-1, s.cost+1));

                        if( tx==c2 && ty==r2 ){ // goal
                            goal = true;
                            res = s.cost + 1;
                            break;
                        }
                    }
                }
            }
            else{
                rep(i,4){
                    int d = board[s.y][s.x]-'0';
                    int tx = s.x + dx[i]*d;
                    int ty = s.y + dy[i]*d;
                    if( !inside(w,h,tx,ty) || memo[ty][tx][s.k] <= s.cost+1 ) continue;
                    memo[ty][tx][s.k] = s.cost + 1;
                    q.push(state(tx, ty, s.k, s.cost+1));

                    if( tx==c2 && ty==r2 ){ // goal
                        goal = true;
                        res = s.cost + 1;
                        break;
                    }
                }
            }
            if( goal ) break;
        }

        return res;
    }
};



















/*
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int memo[64][64][64];

class state{
public:
  int x,y,k,c;
  state(int _x, int _y, int _k, int _c){
    x=_x; y=_y; k=_k;
    c=_c;
  }
};

class NumberLabyrinthDiv2{
public:
  int getMinimumNumberOfMoves(vector <string> board, int r1, int c1, int r2, int c2, int K){
    queue<state> q;
    int w = board[0].size();
    int h = board.size();

    rep(i,64)rep(j,64)rep(k,64)memo[i][j][k]=INT_MAX;
    
    q.push(state(c1,r1,K,0));
    
    while( !q.empty() ){
      int x = q.front().x;
      int y = q.front().y;
      int k = q.front().k;
      int c = q.front().c;
      q.pop();
      if( board[y][x]=='.' ){
	if( k==0 )continue;

	REP(d,1,10){
	  rep(l,4){
	    int tx = x + dx[l] * d;
	    int ty = y + dy[l] * d;
	    if( tx<0 || tx>=w || ty>=h || ty<0 ) continue;
	    if( memo[k-1][ty][tx] <= c+1 ) continue;
	    memo[k-1][ty][tx] = c+1;
	    q.push(state(tx,ty,k-1,c+1));
#if DEB
	    printf("... (%d,%d) d:%d , k:%d  c:%d\n",tx,ty,d,k-1,c+1);
#endif
	  }
	}
      }else{
	rep(l,4){
	  int d = board[y][x]-'0';
	  int tx = x + dx[l] * d;	
	  int ty = y + dy[l] * d;
	  if( tx<0 || tx>=w || ty>=h || ty<0 ) continue;
	  if( memo[k][ty][tx] <= c+1 ) continue;
	  memo[k][ty][tx] = c+1;
	  q.push(state(tx,ty,k,c+1));
#if DEB
	  printf("    (%d,%d) , d:%d , k:%d  c:%d\n",tx,ty,d,k,c+1);
#endif
	}
      }
    }

    int ret = INT_MAX;
    rep(i,K+1)ret = min(ret, memo[i][r2][c2]);
    return ret==INT_MAX ? -1 : ret;
  }
};
 */

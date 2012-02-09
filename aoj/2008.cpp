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

int n,hx,hy,dx,dy,cx[25], cy[25];
int ans;
const double inf = 999999999.9;
double dist[25][25], start[25], dead[25];
bool used[25];
double memo[1<<20];

double sqr(int x){ return (double)x*x; }


void solve(int node, int cnt, double cost, int S){
    int i,j;

    //printf("cost = %lf, dead[%d] = %lf\n",cost ,node, dead[node]);
    if( cost >= dead[node] || memo[S] <= cost ) return;

    ans = max(ans, cnt);
    memo[S] = cost;
    if( cnt == n ) return;

    /*
      現在地からまだ拾っていないクリスタルのうち、一つでも取れないのがあるならOUT
     */
    rep(i,n){
        if( !used[i] ){
            if( cost + dist[node][i] >= dead[i] ) return;
        }
    }

    //printf("cnt = %d, node = %d, cost = %lf\n",cnt, node, cost);

    rep(i,n){
        if( !used[i] ){
            used[i] = true;
            solve(i, cnt + 1, cost + dist[node][i], S|(1<<i));
            used[i] = false;
            if( ans == n ) return;
        }
    }
}


int main(){
    int i,j;

    while( cin >> n >> hx >> hy >> dx >> dy, n|hx|hy|dx|dy ){
        // init
        ans = 0;
        rep(i,25) rep(j,25) dist[i][j] = inf;
        rep(i,1<<n) memo[i] = inf;
        memset(used, false, sizeof(used));

        // input
        set<pair<int,int> > sc;
        rep(i,n){
            int x,y; cin >> x >> y;
            sc.insert(make_pair(x,y));
        }

        j = 0;
        foreach(it,sc){
            cx[j] = it->first, cy[j] = it->second;
            j++;
        }
        n = j;

        // start -> other crystal
        rep(i,n) start[i] = sqrt( sqr(hx - cx[i]) + sqr(hy - cy[i]) );

        // dead line
        rep(i,n) dead[i] = sqrt( sqr(dx - cx[i]) + sqr(dy - cy[i]) );

        // crystal -> crystal
        rep(i,n){
            REP(j,i+1,n){
                double d = sqrt( sqr(cx[i] - cx[j]) + sqr(cy[i] - cy[j]) );
                dist[i][j] = dist[j][i] = d;
            }
        }

        rep(i,n){
            used[i] = true;
            solve(i, 1, start[i], 1<<i);
            used[i] = false;
        }

        puts( ans == n ? "YES" : "NO" );
    }

    return 0;
}

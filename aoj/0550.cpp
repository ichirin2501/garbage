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

const int inf = 1<<29;
int n;
int dp[2][2][5010];
int cut[10010];

/*
  dp[next][0][k+1] = min(dp[cur][0][k])
  dp[next][1][k+1] = min(dp[cur][0][k] + cut[i]);

  dp[next][1][k]   = min(dp[cur][1][k])
  dp[next][0][k]   = min(dp[cur][1][k] + cut[i])
 */
int main(){
    int i,j,k;

    scanf("%d",&n);
    // init
    rep(i,2)rep(j,2)rep(k,5010) dp[i][j][k] = inf;

    // input
    rep(i,n-1) scanf("%d",&cut[i]);

    dp[0][0][0] = 0;
    rep(i,n){
        int cur = i%2, next = (i+1)%2;
        rep(k,n/2+1){
            dp[next][0][k+1] = min(dp[next][0][k+1], dp[cur][0][k]);
            if( i < n-1 ) dp[next][1][k+1] = min(dp[next][1][k+1], dp[cur][0][k] + cut[i]);

            dp[next][1][k] = min(dp[next][1][k], dp[cur][1][k]);
            if( i < n-1 ) dp[next][0][k] = min(dp[next][0][k], dp[cur][1][k] + cut[i]);
        }
        rep(j,2)rep(k,n/2+1) dp[cur][j][k] = inf;
    }

    printf("%d\n",min(dp[n%2][0][n/2],dp[n%2][1][n/2]));

    return 0;
}

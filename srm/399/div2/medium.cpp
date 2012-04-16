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


typedef long long ll;
ll dp[22][110][110];

class MaximalProduct{
public:
    long long maximalProduct(int s, int k){
        int i,j,u,v;

        dp[0][0][0] = 1;
        for(i=0; i<k; i++){
            for(j=0; j<=s; j++){
                for(u=0; u+j<=s; u++){ // 現在の和
                    for(v=j; u+v<=s; v++){ // 次に使う項の値
                        dp[i+1][v][u+v] = max(dp[i+1][v][u+v], dp[i][j][u] * v);
                    }
                }
            }
        }
        ll res = 0;
        for(i=0; i<=s; i++) res = max(res, dp[k][i][s]);
        return res;
    }
};

/*
  k個の正数の和がsに等しい組み合わせで、productの最大値を求める問題
  1 <= k <= 20
  k <= s <= 100

  一つの項の値は最大でも100

  項の個数、最後に使った項の値、和　= productの最大値
  dp[i+1][next][k+next] = max(dp[i+1][next][k+next], dp[i][j][k] * next)
 */

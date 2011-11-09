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
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)

const long long mod = 1000000007;
long long dp[50][1010];

class TheCowDivTwo{
public:
    int find(int N, int K){
        int i,j,k;

        dp[0][0] = 1;
        for(i=0; i<N; i++){
            for(k=K; k>0; k--){
                for(j=0; j<N; j++){
                    dp[k][(j+i)%N] += dp[k-1][j];
                    dp[k][(j+i)%N] %= mod;
                }
            }
        }

        return (int)dp[K][0];
    }
};

int main(){
    TheCowDivTwo T;
    cout << T.find(1000,47) << endl;

    return 0;
}



/*
const long long mod = 1000000007LL;
long long dp[1010][50];

class TheCowDivTwo{
public:
  int find(int N, int K);
};

int TheCowDivTwo::find(int N, int K){
  dp[0][0] = 1;
  REP(i,1,N+1){
    for(int k=K; k>=0; k--){
      for(int j=0; j<N; j++){
	dp[(j+i)%N][k+1] += dp[j][k];
	dp[(j+i)%N][k+1] %= mod;
      }
    }
#if DEB
    rep(i,N+1){
      rep(j,K+1){
	printf("dp[%d][%d] = %lld\n",i,j,dp[i][j]);
      }
    }
    puts("");
#endif
  }
  return (int)dp[0][K];
}
 */

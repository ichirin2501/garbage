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
const ll mod = 1000000007LL;
ll dp[33][33][1<<8];
ll memo[33][33][1<<8];

// YET_SYSTEM_TEST

class DengklekBuildingRoads{
public:
    int bitcount(int bit){
        int res = 0;
        for(;bit;bit>>=1) if( bit&1 ) res++;
        return res;
    }
    
    ll solve(int N, int remain, int K, int id, int S){
        int i,j;
        ll res = 0;

        if( id == N-1 ) return (remain == 0 && S == 0);
        if( memo[id][remain][S] != -1 ) return memo[id][remain][S];

        /*
          S&1 は　現在のnodeの偶奇がわかる 0 = 偶, 1 = 奇
         */

        for(i=S&1; i<=remain; i+=2){
            rep(j,1<<K) if( dp[id][i][j] ) {
                res += (solve(N, remain-i, K, id+1, (S>>1)^j) * dp[id][i][j]) % mod;
                res %= mod;
            }
        }

        return memo[id][remain][S] = res;
    }
    

    int numWays(int N, int M, int K){
        int i,j,k;

        memset(memo, -1, sizeof(memo));

        rep(i,N){
            int bit = K + (i+K >= N ? N-(i+K)-1 : 0);

            //
            int ii, D[33][8], SUM[33];
            memset(D,0,sizeof(D)); memset(SUM,0,sizeof(SUM));
            D[0][0] = 1;
            rep(ii,bit) D[2][ii] = 1;
            
            for(ii=2; ii+2<=M; ii+=2){
                rep(j,bit){
                    for(k=j; k<bit; k++){
                        D[ii+2][k] += D[ii][j];
                    }
                }
            }

            rep(ii,31){
                int sum = 0;
                rep(j,bit) SUM[ii] += D[ii][j];
                //printf("SUM[%d] = %d\n",ii,SUM[ii]);
            }
            //return 0;

            rep(k,1<<bit){
                int one = bitcount(k);
                dp[i][one][k] = 1;
                for(j=one; j+2<=M; j+=2){
                    // ここの計算がおかしい
                    dp[i][j+2][k] = SUM[j+2+(one%2?-1:0)];
                    //dp[i][j+2][k] += dp[i][j][k] * bit;
                    dp[i][j+2][k] %= mod;
                }
            }
        }

        // debug
        
        rep(i,N){
            rep(j,M+1){
                rep(k,1<<min(K,N)){
                    printf("dp[%d][%d][%d] = %lld\n",i,j,k,dp[i][j][k]);
                }
            }
        }
        // 1 - 2 - 3
        
        

        int res = (int)solve(N, M, K, 0, 0);

        /*
        rep(i,N){
            rep(j,M+1){
                rep(k,1<<K){
                    printf("memo[%d][%d][%d] = %lld\n",i,j,k,memo[i][j][k]);
                }
            }
        }
        */

        return res;
    }
};

int main(){
    DengklekBuildingRoads D;
    cout << D.numWays(3, 19, 6) << endl; // answer is 45
    //cout << D.numWays(10,20,5) << endl;
    //cout << D.numWays(10, 20, 5) << endl;

    /*
    int bit = 8;
    int D[33][8];

    memset(D,0,sizeof(D));

    int i,j,k;

    D[0][0] = 1;
    rep(i,bit) D[2][i] = 1;

    for(i=2; i<=30; i+=2){
        rep(j,bit){
            for(k=j; k<bit; k++){
                D[i+2][k] += D[i][j];
            }
        }
    }

    rep(i,31){
        int sum = 0;
        rep(j,bit) sum += D[i][j];
        printf("D[%d] = %d\n",i,sum);
    }
    */

    return 0;
}


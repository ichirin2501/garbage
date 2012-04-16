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


int dp[11][1<<13];

class CollectingMarbles{
public:
    int bitcount(int n){
        int res = 0;
        while( n > 0 ){
            if( n&1 ) res++;
            n >>= 1;
        }
        return res;
    }

    int mostMarbles(vector <int> marblesWeights, int bagCapacity, int numberOfBags){
        int i,j,k,s, n = marblesWeights.size();
        int res = 0;

        rep(i,11) rep(j,1<<13) dp[i][j] = INT_MAX;

        dp[0][0] = 0;
        for(s=0; s<1<<n; s++){ // 入れたmarbleの種類
            for(i=0; i<numberOfBags; i++){ // 使用したバッグの個数
                if( dp[i][s] == INT_MAX ) continue;
                for(j=0; j<n; j++){ // 新しく使うmarble
                    if( !(s & (1<<j)) ){
                        if( dp[i][s] + marblesWeights[j] <= bagCapacity ){
                            dp[i][s|(1<<j)] = min(dp[i][s|(1<<j)], dp[i][s] + marblesWeights[j]);
                        }
                        else if( marblesWeights[j] <= bagCapacity ) {
                            dp[i + 1][s|(1<<j)] = min(dp[i + 1][s|(1<<j)] , marblesWeights[j]);
                        }
                    }
                }
            }
        }

        rep(i,numberOfBags) rep(j,1<<n) if( dp[i][j] != INT_MAX ){
            res = max(res, bitcount(j));
            //printf("dp[%d][%d] = %d, res = %d\n",i,j,dp[i][j],res);
        }
        return res;
    }
};

/*
  marbleは最大で13個
  1つのバッグのキャパシティは最大で20
  バッグの最大は10個

  dp[10][20][1<<13] = [使用したバッグの個数][現在のバッグの使用量][入れたmarbleの種類] = 個数
  仮に同じmarbleで、バッグの使用数も同じだった場合、空き容量が少ないほうがいい
 */

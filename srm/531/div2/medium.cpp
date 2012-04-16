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


const long long mod = 1000000007;
long long dp[110][110]; // [n曲目][使用した曲数]

class NoRepeatPlaylist{
public:
    int numPlaylists(int N, int M, int P){
        int i,j,k;

        dp[0][0] = 1;
        rep(i,P){
            rep(j,N+1) if( dp[i][j] ) {
                // 新しい曲を使う
                if( N-j > 0 ){
                    dp[i+1][j+1] += (dp[i][j] * (N - j)) % mod;
                    dp[i+1][j+1] %= mod;
                }

                // 使用済みの曲を使う
                if( j - M > 0 ){
                    dp[i+1][j] += (dp[i][j] * (j - M)) % mod;
                    dp[i+1][j] %= mod;
                }
            }
        }
        return (int)dp[P][N];
    }
};

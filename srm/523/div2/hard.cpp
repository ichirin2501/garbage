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

typedef long long ll;
const ll MOD = 1000000007;
ll dp[11][1<<10];
int W,H;

class SmallBricks31{
public:
    ll dfs(int w, int h, int bit, int next){
        if( w == W ){
            if( h == 1 ) return 1;
            if( dp[h-1][next] ) return dp[h-1][next];
            return dp[h-1][next] = dfs(0, h-1, next, 0);
        }
        

        ll res = dfs(w+1, h, bit, next);

        if( bit & (1<<w) ){
            res += dfs(w+1, h, bit, next|(1<<w));
            res %= MOD;
        }
        if( w+2 <= W && ((bit & (1<<w)) && (bit & (2<<w))) ){
            res += dfs(w+2, h, bit, next|(3<<w));
            res %= MOD;
        }
        if( w+3 <= W && ((bit & (1<<w)) && (bit & (4<<w))) ){
            res += dfs(w+3, h, bit, next|(7<<w));
            res %= MOD;
        }
        return res;
    }

    int countWays(int w, int h){
        W = w;
        return (int)dfs(0, h, (1<<w)-1, 0);
    }
};


int main(){
    SmallBricks31 S;
    cout << S.countWays(3, 2) << endl;
    return 0;
}


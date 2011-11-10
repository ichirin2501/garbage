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
const ll mod = 1000000009;
ll dp[11][1<<18];

class YetAnotherORProblem2{
public:
    int countSequences(int N, int R){
        int i,j,k;
        int r = 1<<18;

        rep(i,20){
            if( (1<<i) > R ){
                r = 1<<i;
                break;
            }
        }

        dp[0][0] = 1;
        
        REP(i,1,N+1){
            rep(j,r){
                int mask = ~j & (r-1);
                int sub = mask;
                do{
                    if( sub <= R ){
                        dp[i][j|sub] += dp[i-1][j];
                        dp[i][j|sub] %= mod;
                    }
                    sub = (sub-1) & mask;
                }while( sub != mask );
            }
        }

        ll res = 0;
        rep(i,r){
            res += dp[N][i];
            res %= mod;
        }
        return (int)res;
    }
};

int main(){
    YetAnotherORProblem2 Y;
    cout << Y.countSequences(10,15000) << endl; // 604862946


    int j = 6;
    int mask = ~j & 15;
    int sub = mask;
    do{
        printf("sub = %d\n",sub);
        sub = (sub-1) & mask;
    }while( sub != mask );

    return 0;
}

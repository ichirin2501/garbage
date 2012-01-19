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
#include <sstream>
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)

// YET_SYSTEM_TEST

typedef long long ll;

int dp[11][11][11];

class SumOfLuckiness{
public:
    long long theSum(int A, int B){
        int i,j,k;

        dp[1][1][0] = dp[1][0][1] = 1;
        for(i=2; i<=10; i++){
            for(j=0; j<=i; j++){
                for(k=0; k+j<=i; k++){
                    if( j > 0 ){
                        dp[i][j][k] += dp[i-1][j-1][k];
                    }
                    if( k > 0 ){
                        dp[i][j][k] += dp[i-1][j][k-1];
                    }
                }
            }
        }

        rep(i,11){
            rep(j,i+1){
                for(k=0; k+j<=i; k++){
                    printf("dp[%d][%d][%d] = %d\n",i,j,k,dp[i][j][k]);
                }
            }
        }

        return 0;
    }
};


/*

 */

int main(){
    SumOfLuckiness S;
    cout << S.theSum(1,10) << endl;

    return 0;
}


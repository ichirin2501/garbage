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


long double dp[20][20][2], pb[3][3][2];

class Volleyball{
public:
    double win(int sScore, int rScore, double probWinServe){
        int i,j,k;
        long double ret = 0.0;

        memset(dp, 0, sizeof(dp));
        memset(pb, 0, sizeof(pb));

        if( sScore<=14 ){
            dp[sScore][rScore][0] = 1.0;
            
            REP(k,0,28){
                rep(i,min(k+1,15)){
                    j = k - i;
                    if( j>=15 ) continue;
                    
                    //printf("k=%d, [%d][%d][0] = %.20llf   , [1]=%.20llf\n",k,i,j,dp[i][j][0], dp[i][j][1]);
                    
                    dp[i+1][j][0] += dp[i][j][0] * probWinServe + dp[i][j][1] * (1-probWinServe);
                    dp[i][j+1][1] += dp[i][j][1] * probWinServe + dp[i][j][0] * (1-probWinServe);
                }
            }
        }
        //printf("[14][15][0]=%.20llf  , [14][15][1]=%.20llf\n",dp[14][15][0],dp[14][15][1]);

        // sum
        rep(i,14) ret += dp[15][i][0];

        int start;
        if( sScore<=14 ){
            pb[0][0][0] = dp[14][14][0];
            pb[0][0][1] = dp[14][14][1];
            start = 0;
        }
        else{
            int tmp = min(sScore, rScore);
            pb[sScore-tmp][rScore-tmp][0] = 1.0;
            start = (sScore+rScore)%2;
        }

        for(k=start; k<100000; k++){
            if( k%2==0 ){
                pb[1][0][0] = pb[0][0][0] * probWinServe + pb[0][0][1] * (1-probWinServe);
                pb[0][1][1] = pb[0][0][1] * probWinServe + pb[0][0][0] * (1-probWinServe);
            }
            else{
                pb[2][0][0] = pb[1][0][0] * probWinServe;
                pb[0][0][0] = pb[0][1][1] * (1-probWinServe);
                pb[0][0][1] = pb[1][0][0] * (1-probWinServe);

                ret += pb[2][0][0];
            }
        }

        /*
        REP(k,28,6000){
            i = (k+1)/2;
            j = k - i;

            dp[i+1][j][0] += dp[i][j][0] * probWinServe + dp[i][j][1] * (1-probWinServe);
            dp[i][j+1][1] += dp[i][j][1] * probWinServe + dp[i][j][0] * (1-probWinServe);

            if( k==28 ){
                printf("dp[%d][%d][0]=%.20llf,  dp[%d][%d][1]=%.20llf\n",i,j,dp[i][j][0], i,j,dp[i][j][1]);
                printf("%.20llf,    %.20llf\n",dp[i+1][j][0], dp[i][j+1][1]);
            }

            if( k%2==1 ){
                dp[j+1][i][0] += dp[j][i][0] * probWinServe + dp[j][i][1] * (1-probWinServe);
                dp[j][i+1][0] += dp[j][i][1] * probWinServe + dp[j][i][0] * (1-probWinServe);
            }
        }
        */

        
        //REP(i,16,3000) ret += dp[i][i-2][0];

        /*
        REP(i,14,17){
            REP(j,14,17){
                printf("[%d][%d][0] = %.20llf,  [%d][%d][1] = %.20llf\n",i,j,dp[i][j][0], i,j,dp[i][j][1]);
            }
        }
        */

        return (double)ret;
    }
};

int main(){
    Volleyball V;

    printf("%.50lf\n", V.win(0, 0, 0.561111));
    return 0;
}


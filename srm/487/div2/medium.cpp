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


// ver2
int dp[55];

class BunnyComputer{
public:
    int getMaximum(vector <int> preference, int k){
        int i,j;
        int n = preference.size();
        int res = 0;

        for(i=0; i<=k; i++){
            if( i+k+1 >= n ) break;
            for(j=i+k+1; j<n; j+=k+1){
                dp[j] = max((j-2*(k+1) < 0 ? 0 : dp[j-2*(k+1)]) + preference[j] + preference[j-(k+1)],
                            (j-2*(k+1) < 0 ? 0 : -preference[j-2*(k+1)]) + dp[j-(k+1)] + preference[j]);
                dp[j] = max(dp[j], dp[j-(k+1)]);
            }
            res += dp[j-(k+1)];
        }

        return res;
    }
};


/*
// ver1
int dp[64][64];

class BunnyComputer{
public:
    int getMaximum(vector <int> preference, int k){
        int n = preference.size();
        int i,j;
        int res = 0;
        
        for(i=0; i<k+1; i++){
            for(j=i; j<n; j+=k+1){
                if( j - (k+1) < 0 ) continue;

                if( j - 2*(k+1) >= 0 ){
                    dp[i][j] = max(dp[i][j-(k+1)],
                                   max(dp[i][j-(k+1)] + preference[j] - preference[j-2*(k+1)],
                                       dp[i][j-2*(k+1)] + preference[j] + preference[j-(k+1)]));
                }
                else{
                    dp[i][j] = preference[j] + preference[j-(k+1)];
                }
            }
            res += dp[i][j - (k+1)];
        }
        
        return res;
    }
};
*/

int main(){
    int d[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
    vector<int> v;
    int i;
    
    rep(i,sizeof(d)/sizeof(d[0])) v.push_back(d[i]);

    BunnyComputer B;

    cout << B.getMaximum(v, 1) << endl;

    return 0;
}

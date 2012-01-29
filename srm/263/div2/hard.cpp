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


bool memo[55][55][55]; //[個数][][] [j,k)
int dp[55]; // [k)
int id[55]; // [ソート前のidx] -> ソート後のidx

class DequeSort{
public:
    int minDeques(vector<int> data){
        int i,j,k,u;
        int n = data.size();
        vector<int> tdata = data;

        // init
        memset(memo, false, sizeof(memo));
        rep(i,55) dp[i] = INT_MAX;

        sort(all(tdata));
        rep(i,n) rep(j,n) if( tdata[i] == data[j] ) id[j] = i;

        for(i=0; i<n; i++){
            memo[1][id[i]][id[i]+1] = true;
            for(u=1; u<=n; u++){
                for(j=0; j<n; j++){
                    for(k=1; k<=n; k++){
                        if( memo[u][j][k] ){
                            if( k < id[i]+1 ){ // push back
                                memo[u+1][j][id[i]+1] = true;
                            }
                            if( id[i] < j ){ // push front
                                memo[u+1][id[i]][k] = true;
                            }
                        }
                    }
                }
            }
        }

        // 連結
        for(i=1; i<=n; i++){
            if( memo[i][0][i] ) dp[i] = 1;
            for(j=1; j<i; j++){
                if( dp[j] != INT_MAX && memo[i-j][j][i] ){
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};


int main(){
    int d[] = {0, 2, 1, 4, 3, 6, 5, 8, 7, 9};
    vector<int> v;
    int i;
    rep(i,sizeof(d)/sizeof(d[0])) v.push_back(d[i]);

    DequeSort D;
    cout << D.minDeques(v) << endl;

    return 0;
}

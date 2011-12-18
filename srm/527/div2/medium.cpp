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

int dp[55][55][55];

class P8XGraphBuilder{
public:
    int solve(vector <int> scores){
        int i,j,k,u;
        int n = scores.size();

        memset(dp, -1, sizeof(dp));
        dp[1][0][1] = scores[0] * 2;

        for(k=1; k<n; k++){ // エッジを張った個数
            for(i=0; i<k; i++){ // 最後に張ったノード番号
                for(j=1; j<=k; j++){ // ノードiのdegree
                    if( dp[k][i][j] == -1 ) continue;
                    
                    // 同じノードに張る場合
                    dp[k+1][i][j+1] = max(dp[k+1][i][j+1],
                                          dp[k][i][j] - scores[j-1] + scores[j] + scores[0]);
                    
                    for(u=i+1; u<=k; u++){ // 次に張るノード番号
                        // 必ず次に選ぶノードはdegree1
                        dp[k+1][u][2] = max(dp[k+1][u][2], dp[k][i][j] + scores[2-1]);
                    }
                }
            }
        }

        int res = 0;
        rep(i,n) rep(j,n+1) res = max(res, dp[n][i][j]);

        return res;
    }
};

/*

 */


int main(){
    int d[] = {1, 3, 2, 5, 3, 7, 5};
    vector<int> sc;
    int i;
    
    rep(i,sizeof(d)/sizeof(d[0])) sc.push_back(d[i]);

    P8XGraphBuilder P;

    cout << P.solve(sc) << endl;

    return 0;
}

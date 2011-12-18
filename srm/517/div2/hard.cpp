#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <climits>
#include <map>
using namespace std;

vector<pair<int,int> > vp;
int dp[55][55];

// ll931110 
class CuttingGrass{
public:

    int theMin(vector <int> init, vector <int> grow, int H){
        int i;
        int n = init.size();
        
        for(i=0; i<n; i++) vp.push_back( make_pair(grow[i], init[i]) );
        sort(vp.begin(), vp.end());

        for(i=0; i<=n; i++){
            if( solve(i, H) ) return i;
        }

        return -1;
    }

    bool solve(int k, int H){
        int i,j;
        int n = vp.size();
        // init
        for(i=0; i<55; i++) for(j=0; j<55; j++) dp[i][j] = INT_MAX;
        dp[0][0] = 0;
        
        /*
          dp[i][j] := [最後に刈った草][刈った個数]
         */
        for(i=1; i<=n; i++){
            for(j=0; j<=k; j++){
                // 刈るとき
                if( j ){
                    if( dp[i-1][j-1]!=INT_MAX ){
                        dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (k-j)*vp[i-1].first);
                    }
                }

                // 刈らないとき
                if( dp[i-1][j]!=INT_MAX ){
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + vp[i-1].second + k*vp[i-1].first);
                }
            }
        }

        return dp[n][k]<=H;
    }
};


int main(){
    CuttingGrass C;
    return 0;
}

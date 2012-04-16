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

int dp[55][55];

class CasketOfStar{
public:
    int solve(const vector<int>& weight, int s, int e){
        int i, res = 0;

        if( e - s < 2 ) return 0;
        if( e - s == 2 ) return weight[s] * weight[e];
        if( dp[s][e] != -1 ) return dp[s][e];

        for(i=s+1; i<=e-1; i++){
            res = max(res, solve(weight,s,i) + solve(weight,i,e) + weight[s] * weight[e]);
        }

        return dp[s][e] = res;
    }

    int maxEnergy(vector <int> weight){
        memset(dp, -1, sizeof(dp));
        return solve(weight, 0, (int)weight.size()-1);
    }
};

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

const double inf = -999999999.9;
double dp[55]; // dp[i] i以降の要素を使った最大値

class MergersDivTwo{
public:
    double solve(const vector<int>& revenues, int k, int now){
        int i, j, n = revenues.size();
        double res = inf;

        if( now+k > n ) return inf;
        if( dp[now] != inf ) return dp[now];

        int sum = 0;
        for(i=now; i<n; i++){
            if( i >= now+k-1 ){
                double tmp = solve(revenues, k, i);
                if( tmp != inf ){
                    res = max(res, (tmp + (double)sum) / (double)(i-now+1));
                }
            }
            sum += revenues[i];
        }
        
        return dp[now] = max(res, (double)sum/(double)(n-now));
    }

    double findMaximum(vector <int> revenues, int k){
        int i;
        rep(i,55) dp[i] = inf;

        sort(rall(revenues));
        return solve(revenues, k, 0);
    }
};


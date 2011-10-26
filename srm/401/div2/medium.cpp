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

typedef long long ll;
ll dp[40][40];

class FIELDDiagrams{
public:
    ll solve(int n, int m, int k){
        if( n<k ) return 1LL;
        if( dp[m][k] ) return dp[m][k];
        ll ret = 0;
        int i;
        for(i=m; i<=k; i++){
            ret += solve(n,i,k+1);
        }
        
        return dp[m][k] = ret;
    }
    long long countDiagrams(int fieldOrder){
        return solve(fieldOrder, 0, 1) - 1;
    }
};


/*
//rev2
class FIELDDiagrams{
public:
	long long dp[64][64];
	long long dfs(int n, int m){
		long long ret = 1;
		if( dp[n][m] ) return dp[n][m];
		for(int i=1; i<=min(n,m); i++){
			ret += dfs(i,m-1);
		}
		return dp[n][m] = ret;
	}
	long long countDiagrams(int fieldOrder){
		return dfs(fieldOrder,fieldOrder)-1;
	}
};
 */

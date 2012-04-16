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
#include <climits>
#include <cmath>
#include <sstream>
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)


// 復習2

/*
  10^6 までで最大でも126個しかラッキー数は存在しない
  個数を求めた後、貪欲に選択すればいい
 */
vector<int> lucky;
const int inf = 1<<20;
int dp[1000010];

class TheSumOfLuckyNumbers{
public:

    void make_lucky(int n, int N){
        if( n <= N ){
            if( n > 0 ) lucky.push_back(n);
            make_lucky(10 * n + 4, N);
            make_lucky(10 * n + 7, N);
        }
    }

    int dfs(int n){
        int i, res = inf;

        if( n == 0 ) return 0;
        if( dp[n] ) return dp[n];

        for(i=lucky.size()-1; i>=0; i--){
            if( n >= lucky[i] ){
                res = min(res, dfs(n - lucky[i]) + 1);
            }
        }
        return dp[n] = res;
    }

    vector<int> sum(int n){
        int i,j,k;

        if( n < 4 ) return vector<int>();

        make_lucky(0,n);
        sort(all(lucky));

        int cnt = dfs(n);
        if( cnt == inf ) return vector<int>();

        // 貪欲に数字の小さいほうから取っていく
        vector<int> res;
        while( n > 0 ){
            rep(i,lucky.size()){
                if( dp[n - lucky[i]] == cnt - 1 ){
                    res.push_back(lucky[i]);
                    cnt--;
                    n -= lucky[i];
                    break;
                }
            }
        }
        
        sort(all(res));
        return res;
    }
};

























/*
vector<int> lucknum;
int dp[1000010];

class TheSumOfLuckyNumbers{
public:
    void make_lucknum(int n){
        if( n>=1000000 ) return;
        if( n>0 ) lucknum.push_back(n);
        make_lucknum(10*n + 4);
        make_lucknum(10*n + 7);
    }

    vector <int> sum(int n){
        make_lucknum(0);

        sort(all(lucknum));
        int i,j;
        int m = lucknum.size();

        fill(dp, dp+1000010, INT_MAX);
        dp[0] = 0;
        rep(i,m){
            for(j=lucknum[i]; j<=n; j++){
                if( dp[j-lucknum[i]]!=INT_MAX ){
                    dp[j] = min(dp[j], dp[j-lucknum[i]]+1);
                }
            }
        }

        if( dp[n]==INT_MAX ) return vector<int>();

        vector<int> ret;
        while( n ){
            rep(i,m){
                if( dp[n-lucknum[i]] == dp[n]-1 ){
                    ret.push_back( lucknum[i] );
                    n -= lucknum[i];
                    break;
                }
            }
        }
        return ret;
    }
};


int main(){
    TheSumOfLuckyNumbers T;
    vector<int> t;
    t = T.sum(913356);

    int i;
    rep(i,t.size()){
        printf("%d ",t[i]);
    }
    puts("");

    return 0;
}
*/























/*
/rev2
vector<int> v;
int dp[1000010];
class TheSumOfLuckyNumbers{
public:
	void dfs(int n, int k){
		if( k<=n && k>0 )v.pb(k);
		if( k>n ) return;
		dfs(n,10*k+7); dfs(n,10*k+4);
	}
	vector <int> sum(int n){
		vector<int> ret;
		dfs(n,0);
		sort(all(v));
		rep(i,n+1)dp[i]=INT_MAX;
		dp[0] = 0;
		rep(i,n+1)if( dp[i]!=INT_MAX ){
			for(int j=0; j<v.size() && i+v[j]<=n; j++){
				dp[i+v[j]] = min(dp[i+v[j]], dp[i]+1);
			}
		}
		if( dp[n]==INT_MAX ) return vector<int>();
		
		int k = n;
		for(;;){
			if( dp[k]==0 )break;
			rep(i,v.size()){
				if( dp[k]-1 == dp[k-v[i]] ){
					k = k-v[i];
					ret.pb(v[i]);
					break;
				}
			}
		}
		sort(all(ret));
		
		return ret;
	}
};
 */

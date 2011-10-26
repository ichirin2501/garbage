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

const ll mod = 1000000009;
map<vector<int>, int> S;

class FoxStones{
public:
    int getCount(int N, int M, vector <int> sx, vector <int> sy){
        int i,j,k;
        vector<int> tmp;

        for(i=1; i<=M; i++){
            for(j=1; j<=N; j++){
                tmp.clear();
                rep(k,sx.size()){
                    int dist = max( abs(sx[k]-j), abs(sy[k]-i) );
                    tmp.push_back(dist);
                }
                S[tmp]++;
            }
        }

        ll ret = 1LL;
        foreach(it,S){
            for(i=it->second; i>=1; i--){
                ret *= i;
                ret %= mod;
            }
        }

        return (int)ret;
    }
};







































/*

const int mod = 1000000009;
map<vector<int>,int> memo;
int fact[50000];

typedef long long ll;

class FoxStones{
public:
  int getCount(int N, int M, vector <int> sx, vector <int> sy){
    int n = sx.size();
    ll ret = 1;
    fact[0] = 1;
    REP(i,1,50000)fact[i] = (int)(((ll)fact[i-1]*(ll)i)%(ll)mod);

    rep(h,M){
      rep(w,N){
	vector<int> tmp;
	rep(i,n){
	  tmp.pb( max(abs(sx[i]-1-w),abs(sy[i]-1-h)) );
	}
	memo[tmp]++;
      }
    }
    foreach(memo,itr){
      ret *= (ll)fact[itr->second];
      ret %= (ll)mod;
    }

    return (int)ret;
  }
};
 */

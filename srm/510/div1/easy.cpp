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


typedef long long ll;

class TheAlmostLuckyNumbersDivOne{
public:
    ll solve(const ll a, const ll b, ll num, int k, int n){
        int i;
        ll res = (a <= num ? 1 : 0);
        if( b < num ) return 0;

        res += solve(a, b, 10*num + 4, k, n+1);
        res += solve(a, b, 10*num + 7, k, n+1);
        
        if( k == 0 ){
            rep(i,10) if( !(i == 4 || i == 7) ) {
                res += solve(a, b, 10*num + i, k+1, n+1);
            }
        }
        return res;
    }

    long long find(long long a, long long b){
        int i;
        ll res = 0;

        REP(i,1,10){
            res += solve(a, b, i, !(i==4 || i==7), 1);
        }
        return res;
    }
};

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

typedef long long ll;

class MagicDiamonds{
public:
    bool isprime(ll n){
        ll i;
        if( n == 1 ) return false;
        for(i=2; i*i<=n; i++){
            if( n%i == 0 ) return false;
        }
        return true;
    }
    long long minimalTransfer(long long n){
        if( isprime(n) ){
            return n == 3 ? 3 : 2;
        }else{
            return 1;
        }
    }
};

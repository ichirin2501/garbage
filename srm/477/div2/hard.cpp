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


// YET_SYSTEM_TEST
typedef long long ll;
const ll mod = 1000000007;
ll F[13];

ll dp[1<<12];

class CarelessSecretary{
public:
    ll func(int n){
        if( n == 0 ) return 1;
        if( n == 1 ) return 0;
        return (ll)(n - 1) * (func(n-1) + func(n-2));
    }

    int howMany(int N, int K){
        int i;
        rep(i,13) F[i] = func(i);

        rep(i,13){
            cout << F[i] << endl;
        }
        return 0;
    }
};

int main(){
    CarelessSecretary C;

    cout << C.howMany(10,10) << endl;

    return 0;
}


/*
ビット集合を使う。

M人、(N-K)_P_(K-M), (N-M)_P_(N-K)

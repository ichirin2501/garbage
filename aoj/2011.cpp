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
#include <complex>
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)

typedef long long ll;

int days[55];
ll dp[55];

int main(){
    int n,i,j,f;

    while( cin >> n, n ){
        memset(days, 0, sizeof(days));
        rep(i,n) dp[i] = 1LL << i;

        rep(i,n){
            cin >> f;
            rep(j,f){
                int d; cin >> d;
                days[i] |= 1<<(d-1);
            }
        }

        rep(i,33){
            ll S = 0;
            rep(j,n){
                if( days[j] & (1<<i) ){ // j人目の人がi日目の予定があいてるか
                    S |= dp[j];
                }
            }
            if( S == (1LL<<n) - 1 ) break;
            rep(j,n) if( days[j] & (1<<i) ) dp[j] = S;

        }

        printf("%d\n",i == 33 ? -1 : i+1);
    }

    return 0;
}

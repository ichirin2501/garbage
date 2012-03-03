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


bool primes[1000010]; // false is prime.
bool ok[1000010];

void build_prime(){
    int i,j;

    primes[0] = primes[1] = true;
    for(i=2; i*i<=1000000; i++){
        if( !primes[i] ){
            for(j=i*2; j<=1000000; j+=i) primes[j] = true;
        }
    }
}

int main(){
    int n,x,i,j,k;
    int dish[33];

    build_prime();

    while( scanf("%d%d",&n,&x), n|x ){

        rep(i,n) scanf("%d",dish+i);
        sort(dish, dish+n);

        int res = 0;
        memset(ok, false, sizeof(ok));
        ok[0] = true;
        for(i=0; i<n; i++){
            for(j=dish[i]; j<=x; j++){
                ok[j] |= ok[j-dish[i]];
                if( !primes[j] && ok[j] ) res = max(res, j);
            }
        }

        if( res == 0 ){ puts("NA"); }
        else{ printf("%d\n",res); }
    }

    return 0;
}

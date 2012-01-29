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

typedef long long ll;
ll gcd(ll x, ll y){ return y ? gcd(y,x%y) : x; }
ll lcd(ll x, ll y){
    return x/gcd(x,y) * y;
}

int main(){
    ll a1,a2,a3,m1,m2,m3;
    ll i,j,k;

    while( cin >> a1 >> m1 >> a2 >> m2 >> a3 >> m3 ){
        if( !(a1|a2|a3|m1|m2|m3) ) break;

        ll a = a1;
        for(i=1; a!=1 ;i++) a = a * a1 % m1;

        ll b = a2;
        for(j=1; b!=1; j++) b = b * a2 % m2;

        ll c = a3;
        for(k=1; c!=1; k++) c = c * a3 % m3;

        cout << lcd(lcd(i,j),k) << endl;
    }

    return 0;
}

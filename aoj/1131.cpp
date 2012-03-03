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


int gcd(int x, int y){ return y ? gcd(y,x%y) : x; }

int solve(int p, int q, int a, int c, int n, int prod){
    int i,j,res = 0;

    //printf("p = %d, q = %d, a = %d, c = %d, n = %d, prod = %d\n",p,q,a,c,n,prod);
    if( p == 0 ) return 1;
    if( n == 0 ) return 0;
    
    // c >= q / p
    //printf("%d/%d = %d, c = %d, prod = %d\n",q,p,q/p,c,prod);
    for(i=max(min(q/p,a),c); i*prod <= a; i++){
        if( p*i < q ) continue;

        int a1 = p*i - q;
        int b1 = i*q;
        res += solve(a1, b1, a, i, n-1, prod*i);
    }

    return res;
}

/*
  N個以下（項
  

  p/q - 1/b1 >= 0
  p*b1 / (b1*q) - { q / (q*b1) }
  p*b1 >= q　が必須
  (p*b1 - q) / (b1 * q)
 */

int main(){
    int p,q,a,n;

    while( cin >> p >> q >> a >> n, p|q|a|n ){
        cout << solve(p,q,a,1,n,1) << endl;
    }

    return 0;
}

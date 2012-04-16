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

ll gcd(ll x, ll y){ return y ? gcd(y,x%y) : x; }

class FoxAndGCDLCM{
public:
    long long get(long long G, long long L){
        ll res = LLONG_MAX;

        if( L%G != 0 ) return -1;

        for(ll a=G; ; a+=G){
            if( a > L/(a/G) ) break;
            if( L % (a/G) == 0 && gcd(a,L/(a/G)) == G ){
                res = min(res, a+(L/(a/G)));
            }
        }

        return (res == LLONG_MAX ? -1 : res);
    }
};

int main(){
    ll a = 2810920, b = 3382750;
    cout << a*b << endl;

    FoxAndGCDLCM F;
    cout << F.get(10,950863963000) << endl;
}

/*
  問題文の意味がよくわからない
  gcd(a,b) = G
  lcm(a,b) = L
  lcm(a,b) = a*b/gcd(a,b)
  問題の意味はわかった。9分経過
  a*b % G == 0
  a*b / G == L  
  a*b == G*L
  a or b は 必ず G で割り切れる
  aをGの倍数だと仮定すると、
  for(a=G; ;a+=G)
  a/G * b <= 10^12 <= L
  L % (a/G) == 0 のとき
  b = L/(a/G)

  最後のサンプルだけ合わない。本当にGCDとかも正しいのか？
  違うじゃんｗｗｗ、修正。よさそうなのでsubmit
  System test passed.
 */

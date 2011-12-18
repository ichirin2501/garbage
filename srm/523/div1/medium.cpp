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
const ll mod = 1000000007LL;
ll pat[64];
ll dp[64][64];

class BricksN{
public:
    ll solve(int w, int h){
        int i;

        if( dp[w][h] ) return dp[w][h];
        if( w == 0 || h == 0 ) return 1LL;

        ll res = solve(w-1, h) + ((pat[w] * solve(w, h-1)) % mod);
        res %= mod;

        for(i=1; i<w; i++){
            res += ((pat[i] * solve(i, h-1)) % mod) * solve(w-i-1, h);
            res %= mod;
        }

        return dp[w][h] = res;
    }

    int countStructures(int w, int h, int k){
        int i,j;

        pat[0] = 1;
        for(i=1; i<=w; i++){
            for(j=1; j<=k; j++){
                if( i < j ) break;
                pat[i] += pat[i-j];
                pat[i] %= mod;
            }
        }

        return (int)solve(w,h);
    }
};


int main(){
    BricksN B;
    //cout << B.countStructures(3,1,3) << endl;
    //cout << B.countStructures(3,2,3) << endl;
    //cout << B.countStructures(1,5,1) << endl;
    cout << B.countStructures(10,10,3) << endl;
    
    return 0;
}


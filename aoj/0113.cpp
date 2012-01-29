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


int main(){
    int p,q,i;

    while( cin >> p >> q ){
        map<int,int> cycle;
        string res;
        int idx = 1;

        cycle.insert(make_pair(p,0));
        while( p > 0 ){
            res += (char)(10 * p / q + '0');
            p = 10 * p % q;
            if( cycle.count(p) ) break;
            cycle.insert(make_pair(p,idx));
            idx++;
        }
        cout << res << endl;
        if( p > 0 ){
            idx = cycle[p];
            rep(i,idx) putchar(' ');
            for(i=idx; i<res.length(); i++) putchar('^');
            puts("");
        }
    }
    return 0;
}

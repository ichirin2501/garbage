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

class MagicCandy{
public:
    int whichOne(int n){
        ll i;
        for(i=1LL; i*i<(ll)n; i++);
        if( (i-1)*(i-1)+(i-1) >= (ll)n ) return (int)((i-1)*(i-1)+1);
        return (int)(i*i - (i-1));
    }
};

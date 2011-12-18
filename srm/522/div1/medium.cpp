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
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)


typedef long long ll;

class CorrectMultiplication{
public:
    long long getMinimum(int a, int b, int c){
        ll ret = (ll)1e16;
        
        for(ll A=1; A<=100000; A++){
            ll tmp = c / A;
            for(ll B=tmp; B<=tmp+1; B++){
                if( B == 0 ) continue;
                ret = min(ret, abs(A-a) + abs(B-b) + abs(A*B-c));
                ret = min(ret, abs(B-a) + abs(A-b) + abs(B*A-c));
            }
        }
        return ret;
    }
};

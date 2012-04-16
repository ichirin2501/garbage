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

int X,Y,res;

class CountExpressions{
public:

    void solve(int cx, int cy, int val, int num){
        
        if( cx == 0 && cy == 0 ){
            res += (int)(num == val);
            return;
        }

        if( cx > 0 ){
            solve(cx - 1, cy, val, num + X);
            solve(cx - 1, cy, val, num - X);
            solve(cx - 1, cy, val, num * X);
        }
        if( cy > 0 ){
            solve(cx, cy - 1, val, num + Y);
            solve(cx, cy - 1, val, num - Y);
            solve(cx, cy - 1, val, num * Y);
        }
    }

    int calcExpressions(int x, int y, int val){
        X = x, Y = y;
        res = 0;
        solve(1, 2, val, X);
        solve(2, 1, val, Y);
        return res;
    }
};

/*
  "a op1 b op2 c op3 d",
 */

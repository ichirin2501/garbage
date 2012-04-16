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


/*
  Xp + Yq = A
  Xa + Yb = B
  X(p+a) + Y(q+b) = A + B
  p+a,q+b >= 0
 */
class KingXNewCurrency{
public:
    bool ok(int z, int X, int Y){
        int p,q;
        for(p=0; X*p<=z; p++){
            for(q=0; X*p + Y*q <= z; q++){
                if( z == X*p + Y*q ) return true;
            }
        }
        return false;
    }
    int howMany(int A, int B, int X){
        int Y,res = 0;

        if( A%X == 0 && B%X == 0 ) return -1;
        for(Y=0; Y<=max(A,B); Y++){
            if( ok(A,X,Y) && ok(B,X,Y) ) res++;
        }
        return res;
    }
};

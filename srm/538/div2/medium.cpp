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


class EvenRoute{
public:
    string isItPossible(vector <int> x, vector <int> y, int wantedParity){
        int i,j, n = x.size();
        int res = 0;

        rep(i,n){
            res |= 1 << ((abs(x[i]) + abs(y[i])) % 2);
        }

        if( res == 3 || (res+1) % 2 == wantedParity ) return "CAN";
        return "CANNOT";
    }
};

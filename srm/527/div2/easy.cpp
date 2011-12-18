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


class P8XMatrixTransformation{
public:
    string solve(vector <string> original, vector <string> target){
        int i,j;
        int h = original.size();
        int w = original[0].length();
        int sum1 = 0, sum2 = 0;
        
        rep(i,h) rep(j,w) if( original[i][j] == '1' ) sum1++;
        rep(i,h) rep(j,w) if( target[i][j] == '1' ) sum2++;

        return sum1 == sum2 ? "YES" : "NO";
    }
};

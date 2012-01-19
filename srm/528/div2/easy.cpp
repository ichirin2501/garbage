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


class MinCostPalindrome{
public:
    int getMinimum(string s, int oCost, int xCost){
        int n = s.length();
        int res = 0;
        int i;

        for(i=0; i<n/2; i++){
            if( s[i] == '?' && s[n-i-1] == '?' ){
                res += 2 * min(oCost, xCost);
            }
            else if( (s[i] == 'o' && s[n-i-1] == '?') ||
                     (s[i] == '?' && s[n-i-1] == 'o') ){
                res += oCost;
            }
            else if( (s[i] == 'x' && s[n-i-1] == '?') ||
                     (s[i] == '?' && s[n-i-1] == 'x') ){
                res += xCost;
            }
            else if( s[i] != s[n-i-1] ){
                return -1;
            }
        }
        if( n%2 && s[i] == '?' ) res += min(oCost, xCost);

        return res;
    }
};

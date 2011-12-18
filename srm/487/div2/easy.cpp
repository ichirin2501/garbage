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


class BunnyExamAfter{
public:
    int getMaximum(string black, string gray, string white){
        int n = black.length();
        int i;
        int res = 0;

        rep(i,n){
            if( gray[i] != white[i] ) res++;
            else if( black[i] != gray[i] ) res += 2;
        }
        
        return res;
    }
};

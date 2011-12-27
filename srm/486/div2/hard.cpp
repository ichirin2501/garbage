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


class CrazyLine{
public:
    int calc(const vector<int>& heights){
        int i = 0, j = heights.size()-1;
        int l = heights[0];
        int r = heights[0];
        int res = 0;

        if( heights.size() == 1 ) return 0;

        i++;
        for(;;){
            res += abs(heights[j] - l); l = heights[j--]; if( i > j ) break;
            res += abs(heights[j] - r); r = heights[j--]; if( i > j ) break;

            res += abs(heights[i] - l); l = heights[i++]; if( i > j ) break;
            res += abs(heights[i] - r); r = heights[i++]; if( i > j ) break;
        }

        return res;
    }

    int maxCrazyness(vector<int> heights){
        vector<int> a = heights;
        vector<int> b = heights;
        sort(all(a));
        sort(rall(b));
        return max(calc(a), calc(b));
    }
};

/*
  a,b,cのとき、計算は
  abs(a-b) + abs(b-c)
  
 */

int main(){
    int d[] = {1000};
    vector<int> v;
    int i;
    rep(i,sizeof(d)/sizeof(d[0])) v.push_back(d[i]);

    CrazyLine C;
    cout << C.maxCrazyness(v) << endl;


    return 0;
}

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


class MountainRoad{
public:
    int sqr(int x){ return x*x; }
    double findDistance(vector <int> start, vector <int> finish){
        int n = start.size();
        int i,j;
        vector<pair<int,int> > v;

        rep(i,n) v.push_back(make_pair(start[i], finish[i]));
        sort(all(v));
        
        double res = 0.0;
        int p = 0;
        REP(i,1,n){
            if( v[i].first < v[p].second && v[p].second < v[i].second ){
                res += 2.0 * sqrt( (double)sqr(v[p].second - v[p].first) / 2.0 );
                res -= 2.0 * sqrt( (double)sqr(v[p].second - v[i].first) / 2.0 );
                p = i;
            }
        }
        res += 2.0 * sqrt( (double)sqr(v[p].second - v[p].first) / 2.0 );

        return res;
    }
};

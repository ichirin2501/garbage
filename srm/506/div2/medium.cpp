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


class SlimeXSlimesCity{
public:
    int merge(vector <int> population){
        int i,j;
        int n = population.size();
        vector<pair<int,int> > vp;
        int res = 0;
        
        rep(i,n) vp.push_back( make_pair(population[i], i) );
        sort(all(vp));

        rep(i,n){
            long long sum = vp[i].first;
            rep(j,i) sum += vp[j].first;
            REP(j,i+1,n){
                if( sum < vp[j].first ) break;
                sum += vp[j].first;
            }
            if( j == n ) res++;
        }

        return res;
    }
};

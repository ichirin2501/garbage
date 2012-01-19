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


typedef long long ll;

class TurretPlacement{
public:
    ll sqr(int x){ return (ll)x*x; }
    long long count(vector<int> x, vector<int> y){
        ll res = 0;
        int i,j;
        int n = x.size();

        rep(i,n){
            REP(j,i+1,n){
                double dist = sqrt((double)sqr(x[i] - x[j]) + (double)sqr(y[i] - y[j]));
                ll m = (ll)floor(2.0*dist) - 1;
                res += m * (m+1) / 2;
            }
        }

        return res;
    }
};


int main(){
    int _x[] = {0,0};
    int _y[] = {0,1};
    int i;
    vector<int> x,y;
    rep(i,sizeof(_x)/sizeof(_x[0])){
        x.push_back(_x[i]);
        y.push_back(_y[i]);
    }
    TurretPlacement T;
    cout << T.count(x,y) << endl;
    return 0;
}



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


int main(){
    int n,m,a,h,p,q,i;
    vector<pair<int, pair<int,int> > > vp;

    while( cin >> n >> m >> a, n|m|a ){
        vp.clear();
        rep(i,m){
            cin >> h >> p >> q;
            vp.push_back(make_pair(h,make_pair(p,q)));
        }
        sort(rall(vp));
        rep(i,m){
            int e = vp[i].second.second;
            int d = vp[i].second.first;
            if( e == a || d == a ){
                a = (e + d) - a;
            }
        }
        cout << a << endl;
    }
    return 0;
}

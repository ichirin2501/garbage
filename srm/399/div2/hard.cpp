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

bool no[1010];

class AvoidingProduct{
public:
    vector <int> getTriple(vector <int> a, int n){
        int i,x,y,m = a.size();
        int sum = INT_MAX;
        vector<int> ac, res;

        rep(i,m) no[a[i]] = true;
        REP(i,1,1002) if( !no[i] ) ac.push_back(i);

        for(x=1; x<=1000; x++){
            if( no[x] ) continue;
            for(y=x; y<=1000; y++){
                if( no[y] ) continue;
                int tz = max(n/(x*y), 1);

                for(i=tz; i<=tz+1; i++){
                    // 以上で最小
                    int t = *lower_bound(all(ac), i);

                    // 未満で最大
                    int l = 0, r = ac.size() - 1;
                    while( l < r ){
                        int mid = (l + r) / 2 + 1;
                        if( ac[mid] < i ){
                            l = mid;
                        }
                        else{
                            r = mid - 1;
                        }
                    }
                    
                    int z, tmp;
                    if( abs(n - x*y*t) < abs(n - x*y*ac[l]) ){
                        tmp = abs(n - x*y*t);
                        z = t;
                    }
                    else{
                        tmp = abs(n - x*y*ac[l]);
                        z = ac[l];
                    }

                    vector<int> g;
                    g.push_back(x); g.push_back(y); g.push_back(z);
                    sort(all(g));
                    if( sum > tmp || (sum == tmp && res > g) ){
                        res = g;
                        sum = tmp;
                    }
                }
            }
        }

        return res;
    }
};


/*
  |n - x*y*z|
  
  (x,y)を決定すると、最小値になるようなzの決め方は2通りになる

  x <= y <= z
  n - k*z = 0
  k*z = n
  z = max(n/k,1)


  n/k 以上になる要素を集合aから lower_boundで見つける
  
 */

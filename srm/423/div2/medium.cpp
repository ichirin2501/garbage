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


class TheTower{
public:
    vector<int> count(vector<int> x, vector<int> y){
        int i,j,u,k;
        int n = x.size();
        vector<int> ret;

        for(k=0; k<n; k++){
            int sum = INT_MAX;
            for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                    int tx = x[i];
                    int ty = y[j];
                    int cnt = 0;

                    vector<int> v;
                    for(u=0; u<n; u++){
                        v.push_back(abs(tx - x[u]) + abs(ty - y[u]));
                    }

                    sort(all(v));
                    for(u=0; u<=k; u++){
                        cnt += v[u];
                    }
                    sum = min(sum, cnt);
                }
            }
            ret.push_back(sum);
        }
        return ret;
    }
};

/*
  i個の駒を同じ座標に集めるときの最小移動回数
  上下左右の移動だから、あの方法が使える…という経験則＞＜
  あとは、任意のi個の駒が選択できるという点。
  
 */
















/*
class TheTower{
public:
    vector <int> count(vector <int> x, vector <int> y){
        int n = x.size();
        vector<int> ret(n,INT_MAX);
        int tmp[64];

        rep(i,n){
            rep(j,n){
                int tx = x[i];
                int ty = y[j];
                REP(k,1,n+1){
                    rep(l,n){
                        tmp[l] = abs(tx-x[l])+abs(ty-y[l]);
                    }
                    sort(tmp, tmp+n);
                    int cnt = 0;
                    rep(l,k){
                        cnt += tmp[l];
                    }
                    ret[k-1] = min(ret[k-1], cnt);
                }
            }
        }
        return ret;
    }
};
*/

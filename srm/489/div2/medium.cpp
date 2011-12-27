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

class BuyingFlowers{
public:
    int buy(vector<int> roses, vector<int> lilies){
        int i,j,k;
        int n = roses.size();
        int res = INT_MAX;

        for(i=0; i<(1<<n); i++){
            int sr = 0, sl = 0;

            for(j=0; (1<<j)<=i; j++){
                if( i & (1<<j) ){
                    sr += roses[j];
                    sl += lilies[j];
                }
            }

            if( abs(sr - sl) <= 1 ){
                for(k=1; k*k <= (sr + sl); k++){
                    if( (sr + sl) % k != 0 ) continue;
                    res = min(res, abs( k - (sr + sl)/k ));
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};

/*
  花のセットは高々16セットしかない。
  各セットの各花の数は10000まで
  隣同士の花は同じ種類にしてはいけないから、
  その条件を満たしつつ、長方形の形にするためには、
  花の個数は同じ、または差が1個でなければならない。
  その個数で構成できる長方形を探索すればいい。
 */

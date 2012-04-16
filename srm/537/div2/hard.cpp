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

// cheat
class PrinceXToastbook{
public:
    double eat(vector <int> prerequisite){
        int i,j, n = prerequisite.size();
        double res = 0.0;
        bool used[55];
        
        rep(i,n){
            double p = 1.0;
            int k = 1;
            memset(used, false, sizeof(used));

            for(j = i; j != -1; j = prerequisite[j]){
                if( used[j] ){
                    p = 0.0; break;
                }

                p /= (double)k;
                k++;
                used[j] = true;
            }
            res += p;
        }

        return res;
    }
};

/*
  食べられるパンの個数　の　期待値を求める問題。
  食べられるパンの個数 = X とすると、
  X = X1 + X2 + .. + Xn
  Xaはa番目のパンを食べたかどうか 0 or 1
  E[X] = E[X1 + X2 + .. + Xn] = E[X1] + E[X2] + .. + E[Xn]
  インディケータ変数だから、確率の和になる
  
 */

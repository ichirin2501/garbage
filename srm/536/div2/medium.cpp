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


class RollingDiceDivTwo{
public:
    int minimumFaces(vector <string> rolls){
        int i,j, n = rolls.size(), m = rolls[0].length();
        int res = 0;

        rep(i,n) sort(all(rolls[i]));

        rep(i,m){
            int tmp = 0;
            rep(j,n) tmp = max(tmp, rolls[j][i]-'0');
            res += tmp;
        }
        return res;
    }
};

/*
  問題の意味がわからない。
  あ、やっとわかった（20分後
 */

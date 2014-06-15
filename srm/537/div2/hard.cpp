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

class PrinceXToastbook{
public:
    double calcProbability(int cnt, int idx, const vector<int>& prerequisite) {
        if (cnt > prerequisite.size()) return 0.0;
        if (prerequisite[idx] == -1)   return 1.0 / cnt;
        return calcProbability(cnt + 1, prerequisite[idx], prerequisite) * 1.0 / cnt;
    }
    double eat(vector <int> prerequisite){
        double res = 0;
        for (int i=0; i<prerequisite.size(); ++i) {
            res += 1.0 * calcProbability(1, i, prerequisite);
        }
        return res;
    }
};

/*
  期待値の線形性を使う
  ある知識Xを得るためには知識Yが必要、知識Yを得るためには知識Zが必要〜
  という確率は、
  YよりZが先になる確率=1/2 (ZY)
  この状態だと
  ・Zより先
  ・ZとYの間
  ・Yより後
  の3カ所の状態がありえる。よって、Yより後になる確率は1/3なので、
  ZYXの確率は 1/2 * 1/3 = 1/6
  無関係な知識iに関しては無視することが出来るので、
  関係のある状態に対して知識aがどの位置になるかだけを考えれば良い
 */

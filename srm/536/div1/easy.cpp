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


class MergersDivOne{
public:
    double findMaximum(vector <int> revenues){
        int i, n = revenues.size();
        double res = 0.0;

        sort(all(revenues));
        res = (revenues[0] + revenues[1]) / 2.0;
        REP(i,2,n) res = (res + revenues[i]) / 2.0;
        return res;
    }
};


/*
  てきとー貪欲したら落ちたｗ
  どこに落ちる要素があるんだよって感じなんだけど、
  ソートしてから、要素がマイナスの限り、(res + revenues[i])/2.0
  を繰り返して、新しい要素がプラスになったらまとめて足せばいいかなって考えた。
  それだとだめで、x <= y <= z　のとき、
  (x + y + z)/3 = x/3 + y/3 + z/3
  (((x + y)/2) + z)/2 = x/4 + y/4 + z/2
  z/3 < z/2
  前者を大きくするためには、z/2 - z/3 < (x/3 - x/4) + (y/3 - x/4)
  が成り立つ必要がある
  2z/12 < x/12 + y/12
  2z < x + y
  前提として x <= y <= z なので、zの2倍よりもx+yが大きくなることはない
  よって、成立せず、最大値を求めるためには、毎回2で割る後者の方法を取る。
  ちゃんと証明してからsubmitしろって話ですよね、がおー。
 */

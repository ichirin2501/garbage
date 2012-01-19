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
#define EPS 1e-9

class Mosquitoes{
public:
    int getMaximum(vector <int> xInit, vector <int> v, int R){
        int i,j,k;
        int n = xInit.size();
        int res = 1;

        // t = (2R - x2 + x1) / (v2 - v1)
        // x1 < x2

        rep(i,n){ // x1
            rep(j,n){ // x2
                if( i == j ) continue;

                double t = (double)(2*R - xInit[j] + xInit[i]) / (double)(v[j] - v[i]);
                if( t < 0.0 ) continue;

                double x1 = xInit[i] + v[i] * t;
                double x2 = xInit[j] + v[j] * t;
                int cnt = 2;
                rep(k,n){
                    if( k == i || k == j ) continue;
                    double x3 = xInit[k] + v[k] * t;
                    if( x1 <= x3 && x3 <= x2 ){
                        cnt++;
                    }
                }
                res = max(res, cnt);
            }
        }

        return res;
    }
};

/*
  同じ速度の蚊は存在しない。
  爆弾の起爆時間と位置は整数じゃなくてもいい、というのが厄介すぎる
  うーん、適当な蚊を2匹選んで、その中点に爆弾を設置すればいい？
  最も時間がかかるケースを考えると、
  半径Rが最大でも100だから、蚊i(x=-100,v=0)と、蚊j(x=100,v=-1)を選択したとき、
  t=400で、蚊i(x=-100,v=0), 蚊j(x=-300,v=-1)だから、
  中点x=-200に爆弾設置で、R=100ぎりぎり。これ以上は無理。
  半径の範囲から、爆弾の設置可能箇所の限界は大きくない(整数)
  速度はどの蚊も重複しないという条件が生きた。
  ん、最悪のケースは本当に上であってる？
  半径R=100, 蚊i(x=-100,v=2), 蚊j(x=100,v=1)を選択したとき、
  t=400で、蚊i(x=700,v=2), 蚊j(x=500,v=1), R=100でぎりぎり。
  起爆時間が整数なら、あとは探索するだけなんだが…。
  整数の時間で処理したときに、実数時間で起爆していれば殺せる蚊がいた場合、
  最初に選択した2匹の蚊と少なくとも1匹は接触していることになる。
  接触が1匹の場合、最初の時間tには範囲内にいたことになるから、
  その1匹と接触する時間t'とすると、t~t'の範囲に起爆すれば殺すことができる。
  接触が2匹の場合、最初の蚊の接触時間t'、次の蚊の接触時間t''とすると、
  t' ~ t''の範囲に起爆すれば殺すことができる。
  接触時間を求める式が必要DESU
  x1 + v1 * t = x2 + v2 * t
  t(v1 - v2) = x2 - x1
  t = (x2 - x1) / (v1 - v2)
  (v1 - v2)が0になることはない。各々の蚊の速度は重複しないという条件から。
  (x2 - x1)が0になることはありえる。
  うーん、やはりわからんｗ。複数の蚊に接触する時間を求めても、次がわからない。
  ここで、ぐぐった。
  任意の2匹の蚊がちょうど2Rになるような時間に対して、各蚊が範囲にいるかどうか
  でいいのか、言われてみればその通り。
  x2 > x1として、
  x2 + v2 * t - (x1 + v1 * t) = 2R
  t(v2 - v1) = 2R - x2 + x1
  t = (2R - x2 + x1) / (v2 - v1)
  うーん、惜しいところまできてたけど、ちょうど2Rの位置になる時刻だけ考慮すればいい
  という発想に至れなかった。
 */

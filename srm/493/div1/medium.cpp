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

// YET_SYSTEM_TEST

class AmoebaCode{
public:
    int find(string code, int K){
        
    }
};


/*
問題概要
文字'0'~'7'で構成される文字列が与えられる。
同じ文字同士で最小の距離を文字列全体の距離として定義する。
その距離をできるだけ大きくしたい。
'0'には1〜Kまでの任意の値で置換することができる。
そのときに、考えられる最大の距離を求める問題。


K<=7までしかないから、
123456712...　で、最大でも距離は7まで。
計算量も多くないはずだから、
使用できる文字から貪欲に使って試していけばいい。
 */

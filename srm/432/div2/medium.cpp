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
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)


class LampsGrid{
public:

    void lighton(int c, vector<string>& initial){
        int n = initial.size();
        int i;

        rep(i,n){
            initial[i][c] = 
        }
    }

    int solve(int k, vector<string>& initial, int K){
        int i,cnt=0;
        int m = initial[0].length();

        rep(i,m){
            if( initial[k][i] == '0' ){
                lighton(i, initial);
                cnt++;
            }
        }
    }

    int mostLit(vector<string> initial, int K){
        int n = initial.size();
        int m = initial[0].length();
        int i,j,k;
        int ret = 64;

        rep(i,n){
            ret = max(ret, solve(i, initial, K));
        }
        return ret;
    }
};


/*
スイッチを押す順序を関係ない
スイッチを2度押すと元に戻る
ちょうどK回スイッチを押す必要があるから、
消化するために押すことが考えられる
スイッチが最大で50個

任意の2つを同時にONにすることができるのは、XORで
  0101
^ 0101
= 0
0になることが条件

順番に押すか押さないかを決めていく
あるスイッチkを押すときに、
少なくともk-1までのon状態のrowが必要
もしかして、そんなに状態数増えない？
解法がわからない　→　探索問題

あ
一つのrowを完成させると仮定する
そのとき、スイッチを押す箇所が一意に決まる
最低で何か所、残りの回数の遇奇
遇なら可能
奇なら不可能

 */

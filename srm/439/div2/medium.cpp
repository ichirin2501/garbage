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


class PouringWater{
public:
    int getMinBottles(int N, int K){
        int i;
        vector<int> b;

        while(N > 0){
            for(i=0; 1<<i <= N; i++);
            i--;
            N -= (1<<i);
            b.push_back(1<<i);
        }

        if( b.size() <= K ) return 0;

        int sum = 0;
        for(i=K; i<b.size(); i++) sum += b[i];
        return b[K-1] - sum;
    }
};


int main(){
    PouringWater P;
    cout << P.getMinBottles(13,2) << endl;
    return 0;
}


/*
問題概要
N本のボトルがあり、各ボトルには1Lの水が入っている。
各ボトルは無制限に水を蓄えることができる。
任意の2つのボトルを選び、片方に水を全て注ぐ。
ただし、選ぶ任意の2つのボトルは同じ水量でなければならない。
この操作を繰り返して、K本以下に全ての水が入った状態を作りたい。
条件によっては作成できない場合がある。そのときは、
新しくボトルを購入することができる。初期の水量は1Lである。
K本以下に全ての水が入った状態を作るために、
購入しなければならないボトルの数は最小でいくつか。

作れる水量は順に2,4,8,16...になる
例えば、N=5,K=1のときは、
1,1,1,1,1
2,1,1,1
2,2,1
4,1
4,1,1,1,1  3本購入
4,2,2
4,4,
8

N=13, K=2
1,1,1,1,1,1,1,1,1,1,1,1,1
2,2,2,2,2,2,1
4,4,4,1
8,4,1

シミュレーションでも間に合いそう。
2倍、2倍だから、貪欲で確定できる
 */

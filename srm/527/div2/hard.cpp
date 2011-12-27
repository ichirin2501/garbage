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
typedef long long ll;

class P8XCoinChangeAnother{
public:
    vector<long long> solve(int N, long long coins_sum, long long coins_count){
        
    }
};

/*
  値が2の乗数だということに注目。
  例えば、2^kだけを使って合計値を表現できないとき、
  2^(k+1)以降の値を使用しても表現できない。
  2^k * 2 == 2^(k+1)
  2^kのみで表現可能なときの使用枚数と、限度枚数の差を取って、
  <del>その差分だけ、なるべく大きいものに変換していく。</del>
  2^k が2枚 -> 2^(k+1) が1枚
  2^k が4枚 -> 2^(k+2) が1枚
  2^k が8枚 -> 2^(k+3) が1枚
  しかし、2^(N-1)までのコインしか使えない。
  大量のコインの差分があり、変換可能な最大のコインが2^(N-1)を
  上回る場合は、調整する必要がある。
  2^(k+a) > 2^(N-1)　のとき、
  2^(N-1) のコインを 2^(k+a - (N-1))枚使うことになる。
  あ、差分を元になるべく大きいものに変換してもだめでした。
  中間ぐらいの値で使い切った場合と、小さい値と大きい値で使った場合は、
  後者のほうが辞書順的には遅い順になる。しかも、枚数を丁度に合わせるのも…。
  ぜんぜんだめ。ギブアップして、Editorials読みたい、が英語わからんｗ
  kusanoさんの記事を読む。眼から鱗でした。
  最適解は、coins[i] >= 2 のとき、k>=i+2,coins[k] = 0 が成立する。
  もし、coins[i+2] >= 1なら、
  1. coins[i] -= 2, coins[i+1] += 1,
  2. coins[i+2] -= 1, coins[i+1] += 2,
  つまり、例えば[2,0,1]のとき
  1. [2,0,1] -> [0,1,1]
  2. [0,1,2] -> [0,3,0]
  枚数を維持したまま、辞書順で小さいものが得られてしまう。
  よって、2枚以上のコインが2種類あるときは、連続しており、
  そのような箇所は1箇所しかない。
  適当にコインを1枚ずつ、割り振って、
  コインの枚数が足りない場合は、
  
 */

int main(){
    P8XCoinChangeAnother P;

    vector<ll> res = P.solve(20, 1024, 5);
    int i;

    rep(i,res.size()){
        printf("%lld, ", res[i]);
    }
    puts("");

    return 0;
}

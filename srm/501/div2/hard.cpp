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

typedef long long ll;

const int mod = 1000000007;
int dp[41][41][1610][3];

class FoxAverageSequence{
public:
    int solve(const vector<int>& seq, int idx, int prev, int sum, int K){
        int i,j,k;
        ll res = 0;

        if( K >= 2 ) return 0;
        if( idx == seq.size() ) return 1;
        if( dp[idx][prev][sum][K] != -1 ) return dp[idx][prev][sum][K];

        if( seq[idx] == -1 ){
            for(i=0; i<=sum/idx; i++){
                int K2 = (prev > i ? K+1 : 0);
                res += solve(seq, idx+1, i, sum+i, K2);
                res %= mod;
            }
        }
        else{
            int K2 = ( prev > seq[idx] ? K+1 : 0 );
            if( seq[idx] <= sum/idx ){
                res += solve(seq, idx+1, seq[idx], sum+seq[idx], K2);
                res %= mod;
            }
        }
        return dp[idx][prev][sum][K] = res;
    }

    int theCount(vector<int> seq){
        int i;
        int res = 0;
        memset(dp, -1, sizeof(dp));

        if( seq[0] == -1 ){
            for(i=0; i<=40; i++){
                res += solve(seq, 1, i, i, 0);
                res %= mod;
            }
        }
        else{
            res += solve(seq, 1, seq[0], seq[0], 0);
            res %= mod;
        }

        return res;
    }
};

/*
  以下の条件を満たす数列を、素晴らしい数列と定める。
  1. 各項は範囲[0,40]の整数
  2. 1<=i<N, A[i] <= (A[0] + A[1] + ... A[i-1]) / i
  3. 0<=i<N-2, A[i] > A[i+1] > A[i+2] を満たす箇所がない
  与えられる数列の項には-1が含まれており、その-1の項には任意の値を
  設定することができる。そのときの上記の条件を満たす数列のパターン数を求める。

  復習。
  見るからにDP。
  考慮すべき状態は、何回連続で減少したか、
  一つ前の項の値、何個目かの3つ。
  dp[何個目][一つ前の項の値][減少回数] = パターン数
  ひと通り書いた後で気付いた。条件2をすっかり忘れてるｗ
  dp[何個目][一つ前の項の値][合計値][減少回数] = パターン数
  項の個数は40個、値は最大40、1600だから計算が間に合わない。
  iで割っているから、A[0]=40, A[1]=40でも、A[2] = (40+40)/2 = 40
  値は最大でも40になる。
  <del>dp[何個目][一つ前の項の値][最大値][減少回数] = パターン数</del>
  条件2は、毎回割る値が異なるので、割った値からは逆算できない。
  ループ形式のDPだとできない。最大値は加算した状態で持つ必要がある。
  計算量的にメモ化再帰で無駄な処理を避ける必要がある。
  ごりごり書いて、system test passed.
  sum/iの最大値としての状態を配列に格納してたけど、これだとだめだった。
  最大値は同じでも、和が異なるなら、次の状態の最大値が変わってくるから。
  過去に書いたコードを見ると、ループで書いてるｗ，俺すごいｗ
  一見間に合わない感じがする危ないコード、だめですねこれ。
  最大値だけの状態だと区別すべき状態が混ざってしまうから、割った余りも
  状態に含めてるのか、なるほど。よく思いついたなー。
  状態数的に、和で持つのと、最大値と余りで、メモリ量同じ。
 */

int main(){
    int d[] = {-1, 40, -1, -1, -1, 10, -1, -1, -1, 21, -1};
    int i;
    vector<int> v;
    rep(i,sizeof(d)/sizeof(d[0])) v.push_back(d[i]);

    FoxAverageSequence F;

    cout << F.theCount(v) << endl;

    return 0;
}

















/*
const int mod = 1000000007;
int dp[3][40][42][42][42];

class FoxAverageSequence{
public:
    int theCount(vector <int> seq);
};

int FoxAverageSequence:: theCount(vector <int> seq){
    int n = seq.size();

    if( seq[0]==-1 ){
        rep(i,41){
            dp[0][0][i][i][0] = 1;
        }
    }else{
        dp[0][0][seq[0]][seq[0]][0] = 1;
    }

    REP(i,1,n){
        rep(k,2){
            rep(s,41){
                rep(j,41){
                    rep(r,40)if( dp[k][r][s][j][i-1] ){
                        if( seq[i]!=-1 ){
                            if( seq[i]<=s ){
                                int d = (s*i+r+seq[i])/(i+1);
                                int R = (s*i+r+seq[i])%(i+1);
                                if( j>seq[i]  ){
                                    dp[k+1][R][d][seq[i]][i] += dp[k][r][s][j][i-1];
                                    dp[k+1][R][d][seq[i]][i] %= mod;
                                }else{
                                    dp[0][R][d][seq[i]][i] += dp[k][r][s][j][i-1];
                                    dp[0][R][d][seq[i]][i] %= mod;
                                }
                            }
                        }else{
                            rep(l,s+1){
                                int d = (s*i+r+l)/(i+1);
                                int R = (s*i+r+l)%(i+1);
                                if( j>l ){
                                    dp[k+1][R][d][l][i] += dp[k][r][s][j][i-1];
                                    dp[k+1][R][d][l][i] %= mod;
                                }else{
                                    dp[0][R][d][l][i] += dp[k][r][s][j][i-1];
                                    dp[0][R][d][l][i] %= mod;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int ret = 0;
    rep(k,2){
        rep(r,40){
            rep(s,41){
                rep(j,41){
                    ret += dp[k][r][s][j][n-1];
                    ret %= mod;
                }
            }
        }
    }
    return ret;
}

*/

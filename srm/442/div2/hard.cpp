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

const int inf = 99999999;
int dp[55][250010];

class EqualTowers{
public:
    int solve(const vector<int>& bricks, int k, int d){
        int res = -inf;

        if( d > 250000 ) return -inf;
        if( k == bricks.size() ){
            return d == 0 ? 0 : -inf;
        }
        if( dp[k][d] ) return dp[k][d];
        
        // k番目のブロックを使わない
        res = max(res, solve(bricks, k+1, d));

        // 高い塔に乗せる
        res = max(res, bricks[k] + solve(bricks, k+1, d + bricks[k]));

        // 低い塔に乗せる
        res = max(res, (bricks[k] > d ? bricks[k] - d : 0) + solve(bricks, k+1, abs(d - bricks[k])));

        return dp[k][d] = res;
    }

    int height(vector <int> bricks){
        int res = solve(bricks, 0, 0);
        return res == 0 ? -1 : res;
    }
};



/*
// TLE
int dp[55][250010];

class EqualTowers{
public:
    int height(vector<int> bricks){
        memset(dp, -1, sizeof(dp));
        int i,j,k;
        int n = bricks.size();

        dp[0][0] = 0;
        for(i=0; i<n; i++){
            for(j=0; j<250001; j++){
                if( dp[i][j] == -1 ) continue;

                for(k=i+1; k<=n; k++){
                    if( j + bricks[k-1] < 250001 ){
                        dp[k][j+bricks[k-1]] = max(dp[k][j+bricks[k-1]],
                                                   dp[i][j] + bricks[k-1]);
                    }
                    if( abs(j - bricks[k-1]) < 250001 ){
                        dp[k][abs(j-bricks[k-1])] = max(dp[k][abs(j-bricks[k-1])],
                                                        dp[i][j] + (bricks[k-1] > j ? bricks[k-1]-j:0));
                    }
                }
            }
        }

        int res = 0;
        rep(i,n+1) res = max(res, dp[i][0]);
        
        return res == 0 ? -1 : res;
    }
};
*/


/*
  そういえば解けてなかったなぁと思いだしたので。
  2つの塔の高さの差を利用する。
  塔の差がdのとき、高さhのブロックを乗せる場合、
  高い塔に乗せるとき、d+kの差
  低い塔に乗せるとき、abs(d-k)の差になる
  塔の高さの差が0のとき、等しい。
  dp[使ったブロックの位置][高さの差] = 最大の高さ
  forループで書いたらやはりTLEした。
  使っていない状態が多すぎるので、メモ化DPで無駄なく処理する。
  再帰で書くと、トップダウン的になるから
  dp[位置k以降のブロックを使った場合][高さの差] = 最大の高さ
  先にブロックを使わない状態でトップダウンして行って、
  部分的最適解を求めていく。のだが、
  バグがなかなか取れなかった。
  最初は再帰の引数に加算した高さを持たせていて、
  dp[k][d]が新しい状態のときに、位置k未満のブロックの高さも含んだ高さを
  代入してしまっていた。
  メモ化DPへの苦手意識はまだ取れない。
  順序を意識するループのほうが簡単に感じるのは何故だー
 */


int main(){
    int d[] = {400, 421, 58236, 39488, 3772, 44124, 846, 61, 12041, 485, 114, 5622, 174381, 4682, 48880, 23787, 22, 8443, 1196, 25658, 41739, 7, 8, 5530, 10};
    vector<int> v;
    int i;
    rep(i,sizeof(d)/sizeof(d[0])) v.push_back(d[i]);

    EqualTowers E;

    cout << E.height(v) << endl;
    return 0;
}

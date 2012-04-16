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
char buf[55];
ll dp[55][55];

// ooooo xxxxx ooooo xxxxx ooooo xxxxx ooooo xxxxx
// ooooooooooooooooooooxxxxxxxxxxxxxxxxxxxx
class SPartition{
public:
    string str;

    ll solve(int idx, int xid, int yid){
        ll res = 0;

        if( dp[xid][yid] != -1 ) return dp[xid][yid];
        if( idx == str.length() ) return 1LL;
        
        if( xid < str.length()/2 && str[idx] == buf[xid] ){
            res += solve(idx + 1, xid + 1, yid);
        }
        if( yid < str.length()/2 && str[idx] == buf[yid] ){
            res += solve(idx + 1, xid, yid + 1);
        }

        return dp[xid][yid] = res;
    }

    ll backtrack(int idx, int cnt, int no, int nx){
        int i,j;
        ll res = 0;

        if( no == 0 && nx == 0 ){
            buf[cnt] = 0;
            memset(dp, -1, sizeof(dp));
            return solve(0, 0, 0);
        }

        // oを取る
        for(i=idx; i<str.length(); i++){
            if( str[i] == 'o' ){
                buf[cnt] = 'o';
                res += backtrack(i + 1, cnt + 1, no - 1, nx);
                break;
            }
        }

        for(i=idx; i<str.length(); i++){
            if( str[i] == 'x' ){
                buf[cnt] = 'x';
                res += backtrack(i + 1, cnt + 1, no, nx - 1);
                break;
            }
        }
        cout << "res = " << res << endl;

        return res;
    }

    long long getCount(string s){
        int i,j, n = s.length();
        int no = 0, nx = 0;
        str = s;

        rep(i,n) if( s[i] == 'o' ) no++; else nx++;
        if( no % 2 || nx % 2 ) return 0LL;
        
        return backtrack(0, 0, no/2, nx/2);
    }
};

int main(){
    SPartition S;

    cout << S.getCount("oxox") << endl;
    cout << S.getCount("oooxxx") << endl;
    cout << S.getCount("xoxxox") << endl;
    cout << S.getCount("xo") << endl;
    cout << S.getCount("ooooxoox") << endl;
    cout << S.getCount("ooxxoxox") << endl;
    return 0;
}


/*
  最初に、同じ部分文字列が生成できる文字列を求める。
  生成する文字列において、同じ文字列は生成しない
  え、つまりどういうことｗ
  str[idx] = 必ずXかYに属する
  str[0] が X
  str[1] が Y
  のとき、X[0] == Y[0] でなければならない

  あれ、順序を意識して書いたら、同じ文字列も生成されてるじゃん。なにやってんの
 */

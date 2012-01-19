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

bool used[44];
char word[22];
map<pair<long long, pair<int,int> >, long long> dp;

class SPartition{
public:
    ll calc(const string& s, int idx, ll S, int a, int b){
        int i,j;
        int n = s.length();
        ll res = 0;
        pair<long long, pair<int,int> > plii = make_pair(S,make_pair(a,b));

        if( idx == n/2 ){
            //printf("a=%d, b=%d\n",a,b);
            return 1LL;
        }

        if( dp.count(plii) == 1 ) return dp[plii];

        REP(i,a,n){
            if( used[i] || word[idx] != s[i] ) continue;
            REP(j,b,n){
                if( used[j] || word[idx] != s[j] || i == j ) continue;
                used[i] = used[j] = true;
                res += calc(s, idx+1, S|(1LL<<i)|(1LL<<j), i+1, j+1);
                used[i] = used[j] = false;
            }
        }

        return dp[plii] = res;
    }

    ll solve(const string& s, int idx, int to, int tx){
        ll res = 0;
        int i,j,k;
        int n = s.length();

        if( to == 0 && tx == 0 ){
            dp.clear();
            memset(used, false, sizeof(used));
            //puts(word);
            res = calc(s,0,0LL,0,0);
            //cout << res << endl;
        }

        if( to > 0 ){
            word[idx] = 'o';
            res += solve(s, idx+1, to-1, tx);
        }

        if( tx > 0 ){
            word[idx] = 'x';
            res += solve(s, idx+1, to, tx-1);
        }

        return res;
    }

    long long getCount(string s){
        int i;
        int n = s.length();
        int tx = 0, to = 0;

        rep(i,n) if( s[i] == 'o' ) to++;
        tx = n - to;
        if( to%2 || tx%2 ) return 0;

        return solve(s, 0, to/2, tx/2);
    }
};


/*
偶数の長さnの文字列が与えられる。
文字は'o', 'x'の2種類で構成されている。
n/2の部分文字列X,Yを作ったとき、
同じ文字列になるパターン数を求める。
（2つは区別する）


DPだけど解けなかった。
文字列の並び自体は多くないだろうとは考えてたけど、
ある文字列を決定しちゃうのかー、なるほど。
決定してしまえば、パターン数は高速に求められる。
 */


int main(){
    int i,j;
    string s = "xoxxox";

    SPartition S;

    //cout << S.getCount("xoxxox") << endl;
    cout << S.getCount("oooooooooooooooooo") << endl;
    return 0;
 }

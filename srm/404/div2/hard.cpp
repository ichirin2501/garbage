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
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define DEB 0
#define EPS 1e-9


int dp[55][55]; //[高さ][現在のsweetsのインデックス] = 最大値
int K,Ssweets[55];
vector<int> height, x, y, sweets, starirLength;
map<int,int> height_index; // <height, index>

class GetToTheTop{
public:
    int sqr(int x){ return x*x; }

    bool isjump(int i, int j){
        if( (x[i] <= x[j] && x[j] <= x[i]+starirLength[i]) ||
            (x[i] <= x[j]+starirLength[j] && x[j]+starirLength[j] <= x[i]+starirLength[i]) ||
            (x[j] <= x[i] && x[i] <= x[j]+starirLength[j]) ||
            (x[j] <= x[i]+starirLength[i] && x[i]+starirLength[i] <= x[j]+starirLength[j]) ){

            // 真上の場合
            return abs(y[j]-y[i]) <= K;
        }
        else{
            // 左か右の場合
            return (sqr(x[i]-(x[j]+starirLength[j]))+sqr(y[i]-y[j]) <= K*K ||
                    sqr(x[i]+starirLength[i]-x[j])+sqr(y[i]-y[j]) <= K*K );
        }
    }

    void bublle_sort(){
        int i,j;
        int n = x.size();
        rep(i,n-1){
            for(j=n-1; j>i; j--){
                if( y[j] < y[j-1] ||
                    y[j]==y[j-1] && x[j] < x[j-1] ){
                    swap(x[j], x[j-1]);
                    swap(y[j], y[j-1]);
                    swap(starirLength[j], starirLength[j-1]);
                    swap(sweets[j], sweets[j-1]);
                }
            }
        }
    }

    int collectSweets(int _K, vector<int> _sweets, vector<int> _x, vector<int> _y, vector<int> _stairLength){
        int i,j,k;

        // copy
        x = _x;
        y = _y;
        K = _K;
        sweets = _sweets;
        starirLength = _stairLength;


        height.push_back(0);
        rep(i,y.size()){
            height.push_back(y[i]);
        }
        sort(all(height));

        height.erase(unique(all(height)), height.end());

        int m = height.size();
        // make_height_index
        rep(i,m) height_index[height[i]] = i;

        x.push_back(0);
        y.push_back(0);
        sweets.push_back(0);
        starirLength.push_back(200000);
        // sort
        bublle_sort();

        int n = x.size();

        // 最初に同じ高さで移動できる集合の価値を求めておく
        rep(i,sweets.size()) Ssweets[i] = sweets[i];
        rep(i,m){
            // 同じ高さだけに対して処理
            rep(j,n){
                if( y[j] == height[i] ){
                    REP(k,j+1,n){
                        if( y[k] == height[i] && isjump(j,k) ){
                            Ssweets[k] = max(Ssweets[k], Ssweets[j] + sweets[k]);
                        }
                    }
                }
            }
            // 同じ高さで移動できる集合を全て最大値に更新
            for(j=n-1; j>=0; j--){
                if( y[j] == height[i] ){
                    for(k=j-1; k>=0; k--){
                        if( y[k] == height[i] && isjump(j,k) ){
                            Ssweets[k] = max(Ssweets[k], Ssweets[j]);
                        }
                    }
                }
            }
        }

        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        
        rep(i,m){
            // 同じ高さを移動して最大値更新
            for(j=n-1; j>=0; j--){
                if( dp[i][j] != -1 && y[j] == height[i] ){
                    for(k=j-1; k>=0; k--){
                        if( y[k] == height[i] && isjump(j,k) ){
                            dp[i][k] = max(dp[i][k], dp[i][j]);
                        }
                    }
                }
            }

            rep(j,n){
                if( dp[i][j] != -1 && y[j] == height[i] ){
                    REP(k,j+1,n){ // j -> k
                        if( y[k] <= height[i] ) continue;
                        if( isjump(j,k) ){
                            int next = height_index[y[k]];
                            if( dp[next][k] < dp[i][j] + Ssweets[k] ){
                                dp[next][k] = dp[i][j] + Ssweets[k];
                            }
                        }
                    }
                }
            }
        }

        int ret = 0;
        rep(i,m) rep(j,n) ret = max(ret, dp[i][j]);

        return ret;
    }
};


int main(){
    GetToTheTop G;

    int kk = 3;

    // sweets
    int a[] = {1,1,1};

    // x
    int b[] = {1,4,6};

    // y
    int c[] = {1,4,1};

    // len
    int d[] = {2,1,2};

    vector<int> _x, _y, sw, slen;

    int i,j;
    rep(i,sizeof(a)/sizeof(a[0])){
        sw.push_back( a[i] );
        _x.push_back( b[i] );
        _y.push_back( c[i] );
        slen.push_back( d[i] );
    }

    cout << G.collectSweets(kk, sw, _x, _y, slen) << endl;

    return 0;
}


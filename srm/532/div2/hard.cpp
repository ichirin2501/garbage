#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <list>
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


const int mod = 1000000007;
bool ok[1<<8][1<<8][1<<8];
int dp[110][1<<8][1<<8];
vector<int> vi[1<<8][1<<8];

class DengklekPaintingSquares{
public:
    bool ischeck(int a, int b, int c){
        int i;

        for(i=0; i<8; i++){
            if( b & (1<<i) ){
                int cnt = 0;
                if( i > 0 ){
                    if( b & (1<<(i-1)) ) cnt++; // 右
                }
                if( b & (1<<(i+1)) ) cnt++; // 左
                if( a & (1<<i) ) cnt++;
                if( c & (1<<i) ) cnt++;
                if( cnt % 2 != 0 ) return false;
            }
        }

        return true;
    }

    int solve(int N, int M, int h, int a, int b){
        int i;
        int res = 0;

        if( h == N ) return (int)ok[a][b][0];
        if( dp[h][a][b] != -1 ) return dp[h][a][b];

        /*
        rep(i,1<<M){
            if( ok[a][b][i] ){
                res += solve(N, M, h+1, b, i);
                res %= mod;
            }
        }
        */
        rep(i,vi[a][b].size()){
            res += solve(N, M, h+1, b, vi[a][b][i]);
            res %= mod;
        }

        return dp[h][a][b] = res;
    }


    int numSolutions(int N, int M){
        int i,j,k;

        memset(dp, -1, sizeof(dp));
        memset(ok, false, sizeof(ok));
        rep(i,1<<M){
            rep(j,1<<M){
                rep(k,1<<M){
                    if( ischeck(i,j,k) ){
                        ok[i][j][k] = true;
                        //
                        vi[i][j].push_back(k);
                    }
                }
            }
        }

        return solve(N, M, 0, 0, 0);
    }
};


int main(){
    DengklekPaintingSquares D;

    /*
    cout << D.numSolutions(1,1) << endl;
    cout << D.numSolutions(2,2) << endl;
    cout << D.numSolutions(1,3) << endl;
    cout << D.numSolutions(47,7) << endl;
    */
    cout << D.numSolutions(100,8) << endl;

    return 0;
}

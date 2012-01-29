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


int dp[110];

class NewAlbum{
public:
    int leastAmountOfCDs(int nSongs, int length, int cdCapacity){
        int i,j;

        for(i=0; i<=nSongs; i++) dp[i] = INT_MAX;

        dp[0] = 0;
        for(i=0; i<nSongs; i++){
            if( dp[i] == INT_MAX ) continue;
            for(j=1; j <= (cdCapacity + 1)/(length + 1) && i+j<=nSongs; j++){
                if( j % 13 == 0 ) continue;
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
        return dp[nSongs];
    }
};


int main(){
    NewAlbum N;
    cout << N.leastAmountOfCDs(7,2,6) << endl;
    cout << N.leastAmountOfCDs(20,1,100) << endl;
    cout << N.leastAmountOfCDs(26,1,100) << endl;
    cout << N.leastAmountOfCDs(26,3,51) << endl;
    cout << N.leastAmountOfCDs(67,271,1000) << endl;
    cout << N.leastAmountOfCDs(27,1,27) << endl;
    return 0;
}


/*
1つのCDに入る曲数の限界を求める
n <= (capa - n + 1) / len
n <= (capa+1)/len - n/len
n + n/len <= (capa+1)/len
n*len + n <= capa+1
n(len + 1) <= capa+1
n <= (capa+1) / (len+1)

i : 既に使った曲数
j : 1つのCDで使う曲数
dp[i + j] = dp[i] + 1
 */

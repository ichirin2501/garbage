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
ll dp[55][100010];
vector<int> maxPoints, pointsPerMinute, requiredTime;

bool cmp(const int a, const int b){
    return (ll)pointsPerMinute[b] * requiredTime[a] < (ll)pointsPerMinute[a] * requiredTime[b];
}

class TheProgrammingContestDivOne{
public:
    int find(int T, vector<int> _maxPoints, vector<int> _pointsPerMinute, vector<int> _requiredTime){
        int i,j,k;
        int n = _maxPoints.size();
        vector<int> id;
        maxPoints = _maxPoints;
        pointsPerMinute = _pointsPerMinute;
        requiredTime = _requiredTime;

        rep(i,n) id.push_back(i);
        sort(all(id), cmp);

        for(i=1; i<=n; i++){
            int idx = id[i-1];
            for(j=1; j<=T; j++){
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

                k = j - requiredTime[idx];
                if( k >= 0 ){
                    dp[i][j] = max(dp[i][j],
                                   dp[i-1][k] + (ll)maxPoints[idx] - j * (ll)pointsPerMinute[idx]);
                }
            }
        }

        return (int)dp[n][T];
    }
};


/*
問題概要
プログラミングコンテストの時間と、与えられた問題の得点、
解く時間、1分辺りの減少ポイントが与えられる。
与えられた問題を全て解かなくてもよい。
最大得点を得るときの得点を求める問題。


解くのにかかる時間は一定だから、
問題を解く順番で、解ける問題数が変わることはない。
得点は変化する。
2問解くときは、
maxPoints[i] - (requiredTime[i] + t) * pointsPerMinute[i]
maxPoints[j] - (requiredTime[j] + requiredTime[i] + t) * pointsPerMinute[j]
req[i],req[j]は1回ずつ必ずかかる。
解く順序で変化するのは、point[i] * req[j]か、point[j] * req[i]のどちらか。
値が小さいほうが減少が抑えられるから、それで解く順序が決まる。
あとは、コンテスト時間は最大で100000だから、解くか解かないかのナップザックDPでおｋ
 */








/*
typedef long long ll;

ll dp[2][100010];

class TheProgrammingContestDivOne{
public:
    int find(int T, vector <int> maxPoints, vector <int> pointsPerMinute, vector <int> requiredTime);
};

int TheProgrammingContestDivOne::find(int T, vector <int> m, vector <int> p, vector <int> r){
    int n = m.size();

    rep(i,n)REP(j,i+1,n){
        if((ll)r[i]*p[j]>(ll)r[j]*p[i]){
            swap(m[i],m[j]), swap(p[i],p[j]), swap(r[i],r[j]);
        }
    }
    rep(i,n){
        int cur = i%2;
        int next = (i+1)%2;
        for(int j=T; j>=r[i]; j--){
            dp[next][j] = max(dp[cur][j], dp[cur][j-r[i]]+(ll)m[i]-(ll)j*p[i]);
        }
        rep(i,T+1)dp[cur][i]=0;
    }
    int ret = 0;
    rep(i,T+1)ret=max(ret,(int)dp[n%2][i]);
    return ret;
}
*/

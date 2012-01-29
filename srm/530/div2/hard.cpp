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

ll memo[55];

// YET_SYSTEM_TEST

class GogoXReimuHakurai{
public:
    ll dfs(const vector<string>& choices, int node){
        ll res = 0;
        int n = choices.size();
        int i;

        printf("befor node = %d\n",node);
        if( node == n - 1 ) return 1;
        if( memo[node] != -1 ) return memo[node];

        printf("node = %d\n",node);

        rep(i,n) if( choices[node][i] == 'Y' ) {
            res += dfs(choices,i);
            printf("node=%d, i=%d, res=%lld\n",node,i,res);
        }

        return memo[node] = res;
    }

    int solve(vector<string> choices){
        int i,j;
        int n = choices.size();

        memset(memo, -1, sizeof(memo));
        rep(i,n)rep(j,i+1) choices[i][j] = 'N';

        rep(i,n){
            cout << choices[i] << endl;
        }

        ll res = 0;
        rep(i,n) if( choices[0][i] == 'Y' ) res += dfs(choices, i);
        return res;
    }
};


int main(){
    vector<string> vs;
    int i;
    rep(i,50) vs.push_back("YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY");

    GogoXReimuHakurai G;

    cout << G.solve(vs) << endl;
    return 0;
}

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

const int inf = 1<<29;
int edge[22][22];

int main(){
    int i,j,k,n,m,a,b,c,d,start,end,money,hasira;

    rep(i,22) rep(j,22) edge[i][j] = inf;
    rep(i,22) edge[i][i] = 0;

    cin >> n;
    cin >> m;
    rep(i,m){
        scanf("%d,%d,%d,%d",&a,&b,&c,&d);
        a--, b--;
        edge[a][b] = c;
        edge[b][a] = d;
    }
    scanf("%d,%d,%d,%d",&start,&end,&money,&hasira);

    // worshall
    rep(k,n){
        rep(i,n){
            rep(j,n){
                edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
            }
        }
    }

    printf("%d\n",money - hasira - (edge[start-1][end-1] + edge[end-1][start-1]));

    return 0;
}

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

int sum[100010];

int main(){
    int n,m,i,j,k;

    while( scanf("%d %d",&n,&m) != EOF ){
        rep(i,n-1){
            int t; scanf("%d",&t);
            sum[i+1] = sum[i] + t;
        }
        int now = 0;
        int res = 0;
        rep(i,m){
            scanf("%d",&k);
            res += abs(sum[now] - sum[now+k]);
            res %= 100000;
            now += k;
        }
        printf("%d\n",res);
    }
    return 0;
}

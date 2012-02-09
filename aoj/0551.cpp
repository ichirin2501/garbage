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
int broke[100010];

int main(){
    int n,l,i,j;
    vector<pair<int,int> > vp;

    scanf("%d %d",&n,&l);
    rep(i,n){
        int a; scanf("%d",&a);
        vp.push_back(make_pair(a,i));
    }

    sort(rall(vp));

    int tsum = 0;
    rep(i,vp.size()){
        int t, id = vp[i].second;
        if( id == 0 ){
            t = broke[1];
        }
        else if( id == n-1 ){
            t = broke[n-2];
        }
        else{
            t = max(broke[id-1], broke[id+1]);
        }
        int tt = tsum - t + vp[i].first;
        //printf("id=%d, tt = %d, tsum=%d, t = %d\n",id,tt,tsum,t);
        if( l > tt ){
            tsum += l - tt;
            broke[id] = tsum;
        }
        else{
            broke[id] = l + t - vp[i].first;
        }
    }

    printf("%d\n",tsum);

    return 0;
}

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

/*
  AOJ :: 0100
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0100&lang=jp
 */

typedef long long ll;

int main(){
    int n,num,tanka,count,i;
    vector<int> jun;
    set<int> S;
    map<int,ll> mll;

    while( cin >> n, n ){
        // init
        jun.clear(); S.clear(); mll.clear();

        rep(i,n){
            cin >> num >> tanka >> count;

            if( S.count(num) == 0 ){
                jun.push_back(num);
                S.insert(num);
            }
            mll[num] += (ll)tanka * (ll)count;
        }

        bool ok = false;
        rep(i,jun.size()){
            if( mll[jun[i]] >= 1000000 ){
                ok = true;
                printf("%d\n",jun[i]);
            }
        }
        if( !ok ){
            puts("NA");
        }
    }

    return 0;
}


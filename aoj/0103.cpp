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


int main(){
    int run=0, out=0, point=0;
    int t; cin >> t;
    string in;

    while ( cin >> in ){
        if( in == "HIT" ){
            run++;
            if( run >= 4 ){
                run--; point++;
            }
        }
        else if( in == "OUT" ){
            out++;
        }
        else if( in == "HOMERUN" ){
            point += run + 1;
            run = 0;
        }

        if( out == 3 ){
            printf("%d\n",point);
            run = out = point = 0;
        }
    }

    return 0;
}

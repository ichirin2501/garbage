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

bool isinside(int x, int y, int r){
    return ( x*x + y*y < 4*r*r );
}

int main(){
    int tate,yoko,high,n,r,i;

    while( cin >> tate >> yoko >> high, tate|yoko|high ){
        cin >> n;
        rep(i,n){
            cin >> r;
            if( isinside(tate,yoko,r) || isinside(tate,high,r) || isinside(yoko,high,r) ){
                puts("OK");
            }
            else{
                puts("NA");
            }
        }
    }

    return 0;
}

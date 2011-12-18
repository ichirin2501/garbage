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
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)

class PointErasingTwo{
public:
    bool inside(int x1, int y1, int x2, int y2, int px, int py){
        return ( x1 < px && px < x2 &&
                 min(y1,y2) < py && py < max(y1,y2) );
    }
    
    int getMaximum(vector<int> y){
        int n = y.size();
        int i,j,k;
        int res = 0;
        
        rep(i,n){
            REP(j,i+1,n){
                if( y[i] == y[j] ) continue;

                int cnt = 0;
                REP(k,i+1,j){
                    if( inside(i, y[i], j, y[j], k, y[k]) ) cnt++;
                }
                res = max(res, cnt);
            }
        }

        return res;
    }
};


int main(){
    int d[] = { 0, 1, 2, 3, 4 };
    vector<int> p;
    int i,j;
    
    rep(i,sizeof(d)/sizeof(d[0])) p.push_back(d[i]);

    PointErasingTwo P;
    cout << P.getMaximum(p) << endl;

    return 0;
}

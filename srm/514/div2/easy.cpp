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

class MagicalGirlLevelOneDivTwo{
public:
    double sqr(int x){ return x*x; }
    double theMinDistance(int d, int x, int y){
        // inside
        if( -d <= x && x <= d && -d <= y && y <= d ) return 0.0;

        if( -d <= x && x <= d ) return (double)min(abs(y - (-d)), abs(y - d));

        if( -d <= y && y <= d ) return (double)min(abs(x - (-d)), abs(x - d));

        int i,j;
        double res = 999999999999.0;
        for(i=-1; i<=1; i+=2){
            for(j=-1; j<=1; j+=2){
                int p = d * i;
                int q = d * j;
                res = min(res, sqrt(sqr(p-x) + sqr(q-y)));
            }
        }

        return res;
    }
};


int main(){
    MagicalGirlLevelOneDivTwo M;

    printf("%lf\n", M.theMinDistance(5,10,10));
    printf("%lf\n", M.theMinDistance(5,10,3));
    printf("%lf\n", M.theMinDistance(5,-8,-6));
    printf("%lf\n", M.theMinDistance(5,3,2));
    printf("%lf\n", M.theMinDistance(345,-471,333));
    return 0;
}

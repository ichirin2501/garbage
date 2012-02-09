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
#include <complex>
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)

typedef complex<double> point;

//#define PI 3.141592653589793238462643383279
// 許容する誤差ε
#define EPS (1e-10)
// 2つのスカラーが等しいかどうか
#define EQ(a,b) (abs((a)-(b)) < EPS)

bool used[440];

int main(){
    int n,i,j;

    while( cin >> n, n ){
        memset(used, false, sizeof(used));
        double run = 0.0;

        vector<point> p;
        rep(i,n){
            int x,y; cin >> x >> y;
            p.push_back(point(x,y));
        }

        point now(0,0), dir(0,1);

        for(;;){
            int id = -1;
            double ag = 1000;
            rep(i,n){
                if( !used[i] ){
                    double a = std::arg(dir/(p[i] - now));
                    if( ag > a || (EQ(ag,a) && abs(p[id] - now) > abs(p[i] - now)) ){
                        ag = a;
                        id = i;
                    }
                }
            }
            if( id == -1 ) break;
            run += abs(p[id] - now);
            dir = (p[id] - now) / abs(p[id] - now);
            now = p[id];
            used[id] = true;
        }

        printf("%.1lf\n",run);
    }

    return 0;
}

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

// 500 <= n <= 5000, n+=100
int main(){
    int n,a,b;

    while( cin >> n, n ){
        int ret = 999999999;
        for(a=0; 200*a <= n; a++){
            for(b=0; 200*a + 300*b <= n; b++){
                if( (n - (200*a + 300*b)) % 500 != 0 ) continue;
                int c = (n - (200*a + 300*b)) / 500;
                int ac = 1520*(a/5) + 380*(a%5);
                int bc = 1870*(b/4) + 550*(b%4);
                int cc = 2244*(c/3) + 850*(c%3);
                //printf("a=%d, b=%d, c=%d, sum=%d,  n=%d, ac=%10.4lf, bc=%10.4lf, cc=%10.4lf, sum=%lf\n",a,b,c,200*a+300*b+500*c,n,ac,bc,cc,ac+bc+cc);
                ret = min(ret, ac + bc + cc);
            }
        }
        printf("%d\n",(int)(ret));
    }
    return 0;
}

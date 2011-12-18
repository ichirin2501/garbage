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

typedef long long ll;

class CountingSeries{
public:
    long long countThem(long long a, long long b, long long c, long long d, long long upperBound){
        ll res = (a <= upperBound ? (upperBound - a) / b + 1 : 0);
        int m;

        if( d > 1 ){
            ll tmp = 1;
            for(m=0; m<60; m++){
                ll k = c * tmp;
                if( k > upperBound ) break;
                if( k < a || (k - a)%b != 0 ){
                    res++;
                }
                tmp *= d;
            }
        }
        else{
            if( c <= upperBound && (c < a || (c - a)%b != 0) ) res++;
        }

        return res;
    }
};

int main(){
    CountingSeries C;
    cout << C.countThem(1, 1, 1, 2, 1000) << endl;
    cout << C.countThem(3, 3, 1, 2, 1000) << endl;
    cout << C.countThem(40, 77, 40, 100000, 40) << endl;
    cout << C.countThem(452, 24, 4, 5, 600) << endl;
    cout << C.countThem(234, 24, 377, 1, 10000) << endl;
    cout << C.countThem(	3, 1, 3, 4, 948926270240LL) << endl;
    return 0;
}

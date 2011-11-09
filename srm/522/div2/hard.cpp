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
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)


typedef long long ll;

class CorrectMultiplicationTwo{
public:
    int getMinimum(int a, int b, int c){
        ll ret = 100000000000000LL;

        for(ll A=1; A<=c; A++){
            ll tmp = abs(A-a);
            ll B = c / A;
            ll B1 = B + 1;
            ll C = A*B;
            ll C1 = A*B1;

            tmp += min(abs(B-b) + abs(C-c), abs(B1-b) + abs(C1-c));
            ret = min(ret, tmp);
        }
        return (int)ret;
    }
};


int main(){
    CorrectMultiplicationTwo C;

    cout << C.getMinimum(19, 28, 522) << endl;
    cout << C.getMinimum(399, 522, 199999) << endl;
    cout << C.getMinimum(1, 1, 1000000) << endl;
    cout << C.getMinimum(1000, 100, 10) << endl;

    return 0;
}


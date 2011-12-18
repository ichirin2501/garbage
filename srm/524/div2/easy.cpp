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

// a*b*c = N
// c = N / (a*b)
class ShippingCubes{
public:
    int minimalCost(int N){
        int a,b,c;
        int res = INT_MAX;

        for(a=1; a<=N; a++){
            for(b=a; a*b<=N; b++){
                if( N % (a*b) != 0 ) continue;
                c = N / (a*b);
                res = min(res, a + b + c);
            }
        }
        return res;
    }
};

int main(){
    ShippingCubes S;
    cout << S.minimalCost(1) << endl;
    cout << S.minimalCost(6) << endl;
    cout << S.minimalCost(7) << endl;
    cout << S.minimalCost(200) << endl;
    
    return 0;
}

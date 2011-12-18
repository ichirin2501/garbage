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

class BitwiseEquations{
public:
    long long kthPlusOrSolution(int x, int k){
        int i,j = 0;
        ll res = 0;

        for(i=0; 1LL<<j <= (ll)k; i++){
            if( !((1LL<<i) & (ll)x) ){
                res |= ( ((1LL<<j) & (ll)k) ? 1LL : 0LL ) << i;
                j++;
            }
        }

        return res;
    }
};


int main(){
    BitwiseEquations B;

    cout << B.kthPlusOrSolution(5,1) << endl;
    cout << B.kthPlusOrSolution(5,2) << endl;
    cout << B.kthPlusOrSolution(5,3) << endl;
    cout << B.kthPlusOrSolution(5,5) << endl;

    return 0;
}


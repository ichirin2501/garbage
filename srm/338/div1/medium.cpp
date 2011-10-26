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


long double p[2];

class RandomSwaps{
public:
    double getProbability(int arrayLength, int swapCount, int a, int b){
        int i,j;

        if( a==b ){
            p[1] = 1.0;
        }
        else{
            p[0] = 1.0;
        }

        double e = (double)(arrayLength-1) / (double)arrayLength;
        double f = (double)(arrayLength-2) / (double)(arrayLength-1);
        long double g = (long double)e*f;

        rep(i,swapCount){
            long double tmp1 = p[0] * 2.0 * 1.0/(long double)arrayLength * 1.0/(long double)(arrayLength-1) + p[1] * g;
            p[0] = 1.0 - tmp1;
            p[1] = tmp1;
        }

        return (double)p[1];
    }
};

int main(){
    RandomSwaps R;

    printf("%.10lf\n",R.getProbability(100,500,3,3));
    return 0;
}

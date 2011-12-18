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

class MinimalDifference{
public:

    int digitsum(int n){
        int res = 0;

        do{
            res += n%10;
            n /= 10;
        }while( n>0 );
        
        return res;
    }

    int findNumber(int A, int B, int C){
        int i;
        int res = INT_MAX, sa = INT_MAX;
        int csum = digitsum(C);

        for(i=A; i<=B; i++){
            int sum = digitsum(i);
            if( abs(sum - csum) < sa ){
                sa = abs(sum - csum);
                res = i;
            }
        }

        return res;
    }
};


int main(){
    MinimalDifference M;

    cout << M.findNumber(1,9,10) << endl;
    cout << M.findNumber(11,20,20) << endl;
    cout << M.findNumber(1,1,999) << endl;
    cout << M.findNumber(100,1000,99) << endl;
    cout << M.findNumber(1987,9123,1) << endl;

    return 0;
}


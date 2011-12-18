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

class FallingPoints{
public:
    vector<double> getHeights(vector<int> X, int R){
        int n = X.size();
        int i;
        vector<double> res;
        
        rep(i,n){
            if( i == 0 || abs(X[i] - X[i-1]) > R ){
                res.push_back( 0 );
            }
            else{
                double b = (double)abs(X[i] - X[i-1]);
                res.push_back( res[i-1] + sqrt( (double)R*R - b*b ) );
            }
        }

        return res;
    }
};

int main(){
    int x[] = {0, 9, 19};
    vector<int> X;
    FallingPoints F;
    int i;
    
    rep(i,sizeof(x)/sizeof(x[0])) X.push_back(x[i]);

    vector<double> res = F.getHeights(X, 10);
    return 0;
}

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

class CirclesCountry{
public:
    int sqr(int x){ return x*x; }

    bool isinside(int x, int y, int r, int px, int py){
        return r*r > sqr(px-x)+sqr(py-y);
    }

    int leastBorders(vector<int> X, vector<int> Y, vector<int> R, int x1, int y1, int x2, int y2){
        int n = X.size();
        int i;
        int res = 0;

        rep(i,n){
            if( isinside(X[i],Y[i],R[i],x1,y1) ^ isinside(X[i],Y[i],R[i],x2,y2) ){
                res++;
            }
        }
        
        return res;
    }
};


int main(){
    int X[] = {-107,-38,140,148,-198,172,-179,148,176,153,-56,-187};
    int Y[] = {175,-115,23,-2,-49,-151,-52,42,0,68,109,-174};
    int R[] = {135,42,70,39,89,39,43,150,10,120,16,8};

    vector<int> x,y,r;
    int i;
    rep(i,sizeof(X)/sizeof(X[0])){
        x.push_back(X[i]);
        y.push_back(Y[i]);
        r.push_back(R[i]);
    }

    CirclesCountry C;
    cout << C.leastBorders(x,y,r,102,16,19,-108) << endl;

    return 0;
}

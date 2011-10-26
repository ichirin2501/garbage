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


#define DEB 1
#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)

class SquaredSubsets{
public:
    bool isinside(int n, int x, int y, int px, int py){
        return (x<=px && px<=x+n) && (y<=py && py<=y+n);
    }

    long long countSubsets(int n, vector <int> x, vector <int> y){
        vector<int> tx, ty;
        set<long long> S;
        int i,j,k;

        rep(i,x.size()){
            tx.push_back(x[i]); tx.push_back(x[i]-n);
            ty.push_back(y[i]); ty.push_back(y[i]-n);
        }

        int m = tx.size();

        rep(i,m) rep(j,m){
            long long b = 0;
            rep(k,x.size()){
                if( isinside(n, tx[i], ty[j], x[k], y[k]) ){
                    b |= 1LL << k;
                }
            }
            S.insert(b);
        }
        
#if DEB
        foreach(it, S){
            cout << *it << endl;
        }
#endif

        return (long long)S.size();
    }
};

int main(){
    int _x[] = {-5,0,5};
    int _y[] = {0,0,0};
    vector<int> x, y;

    int i,j;
    rep(i,sizeof(_x)/sizeof(_x[0])){
        x.push_back(_x[i]);
        y.push_back(_y[i]);
    }

    SquaredSubsets S;

    cout << S.countSubsets(5, x, y) << endl;


    return 0;
}


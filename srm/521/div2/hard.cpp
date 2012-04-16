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
#define EPS 1e-9


typedef long long ll;

class SquaredSubsets{
public:
    bool isinside(int n, double x, double y, int p, int q){
        return (x-EPS <= p && p <= x+n+EPS && y-EPS <= q && q <= y+n+EPS);
    }

    long long countSubsets(int n, vector <int> x, vector <int> y){
        int i,j,a,b,k,u,m = x.size();
        vector<double> d;
        set<ll> sl;

        d.push_back(0); d.push_back(0.5); d.push_back(-n); d.push_back(-n-0.5);

        rep(i,m){
            rep(j,m){
                rep(a,d.size()){
                    rep(b,d.size()){
                        double tx = x[i] + d[a];
                        double ty = y[j] + d[b];
                        ll S = 0;
                        rep(u,m) if( isinside(n,tx,ty,x[u],y[u]) ) S |= 1LL<<u;
                        if( S != 0 ) sl.insert(S);
                    }
                }
            }
        }
        
        return (ll)sl.size();
    }
};




























/*
class SquaredSubsets{
public:
    bool isinside(int n, double x, double y, int px, int py){
        return ( x <= px && px <= x+n &&
                 y <= py && py <= y+n );
    }

    long long countSubsets(int n, vector <int> x, vector <int> y){
        int i,j,k,l,u;
        int N = x.size();
        set<long long> st;
        double dx[] = {0, 0.5, -n, -n-0.5};
        double dy[] = {0, 0.5, -n, -n-0.5};

        rep(i,N){
            rep(j,N){
                rep(k,4){
                    rep(l,4){
                        double tx = x[i] + dx[k];
                        double ty = y[j] + dy[l];
                        long long b = 0;
                        rep(u,N){
                            if( isinside(n, tx, ty, x[u], y[u]) ){
                                b |= (1LL<<u);
                            }
                        }
                        if( b ) st.insert(b);
                    }
                }
                
            }
        }

        return (long long)st.size();
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
*/


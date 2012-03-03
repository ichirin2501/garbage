#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <sstream>
#include <complex>
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define EPS 1e-8

typedef complex<double> P;

int n, h[55];
double dist[55];
const double inf = 9999999999.9;


/*
  sin = d/b
  |b|sin = d
  a X b = |a||b|sin
  |d| = aXb / |a|
 */

double dot(const P& a, const P& b){
    return (a.real()*b.real() + a.imag()*b.imag());
}
double cross(const P& a, const P& b){
    return (a.real()*b.imag() - a.imag()*b.real());
}

// 線分abと点cとの最短距離
double lpdist(const P& a, const P& b, const P& c){
    if( dot(b-a, c-a) < 0.0 ) return abs(c-a);
    if( dot(a-b, c-b) < 0.0 ) return abs(c-b);
    return abs(cross(b-a, c-a)) / abs(b-a);
}

// 線分seと線分abとの最短距離
double lldist(const P& s, const P& e, const P& a, const P& b){
    double d = inf;
    // 線分seと点a,bとの距離を求める
    d = min(d, lpdist(s,e,a));
    d = min(d, lpdist(s,e,b));

    // 線分abと点s,eとの距離を求める
    d = min(d, lpdist(a,b,s));
    d = min(d, lpdist(a,b,e));
    return d;
}

// 線分の端点がブロック内部に存在するか
bool inside(const P& s, const P& e, int ix, int iy, int ax, int ay){
    return ((ix <= s.real() && s.real() <= ax && iy <= s.imag() && s.imag() <= ay) ||
            (ix <= e.real() && e.real() <= ax && iy <= e.imag() && e.imag() <= ay));
}

// 線分seと線分abが交差しているか
bool llcr(const P& s, const P& e, const P& a, const P& b){
    return ( (cross(s-e, a-e) * cross(s-e,b-e) < 0.0) &&
             (cross(a-b, s-b) * cross(a-b,e-b) < 0.0) );
}

// 半径rでゴールできるか
double sqr(double x){ return x*x; }

bool f(double r){
    int i;
    rep(i,n){
        if( r > (double)h[i] ){
            if( r*r >= sqr(dist[i]) + sqr(r - (double)h[i]) ) return false;
        }
        else{
            if( dist[i] <= r ) return false;
        }
    }
    return true;
}


int main(){
    int i,j,k;
    int ix, iy, ax, ay;
    P s,e;

    while( cin >> n, n ){
        bool no = false;

        cin >> s.real() >> s.imag() >> e.real() >> e.imag();
        rep(i,n){
            cin >> ix >> iy >> ax >> ay >> h[i];
            P a(ix,iy), b(ax,ay), c(ix,ay), d(ax,iy);
            dist[i] = min(min(lldist(s,e,a,c), lldist(s,e,a,d)),
                          min(lldist(s,e,b,c), lldist(s,e,b,d)));

            if( inside(s,e,ix,iy,ax,ay) ||
                (llcr(s,e,a,c) || llcr(s,e,a,d) || llcr(s,e,b,c) || llcr(s,e,b,d)) ) no = true;
        } 

        if( no ){
            printf("%lf\n",0.0);
            continue;
        }

        double l = 0.0, r = 1000.0;
        rep(i,60){
            double mid = (l + r) / 2.0;
            //printf("l = %lf,  r = %lf,  mid = %lf\n",l,r,mid);
            if( f(mid) ){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        printf("%lf\n",l);
    }
    return 0;
}

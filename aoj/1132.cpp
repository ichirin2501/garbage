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

typedef complex<double> Point;
Point p[300];

double sqr(double x){ return x*x; }

bool isok(Point& e, Point& q){
    return (sqr(e.real() - q.real()) + sqr(e.imag() - q.imag()) < 1.0);
}

/*
 Point(0,1)　左に90度回転
 Point(0,-1)　右に90度回転
 */
int main(){
    int n,i,j,k, res;

    while( scanf("%d",&n), n ){
        res = 1;
        rep(i,n) cin >> p[i].real() >> p[i].imag();

        rep(i,n){
            REP(j,i+1,n){
                double dist = sqr(p[i].real() - p[j].real()) + sqr(p[i].imag() - p[j].imag());
                if( dist < 4.0 ){
                    dist /= 4.0; // (d/2)^2
                    double x = sqrt(1.0 - dist); // x
                    Point M((p[i].real() + p[j].real())/2.0, (p[i].imag() + p[j].imag())/2.0);

                    Point d = (p[i] - p[j])/abs(p[i] - p[j]);
                    Point e1 = M + d*Point(0,-1)*x;
                    Point e2 = M + d*Point(0,1)*x;

                    int cnt1 = 2, cnt2 = 2;

                    rep(k,n) if( i != k && j != k ){ // e1
                        if( isok(e1, p[k]) ) cnt1++;
                        if( isok(e2, p[k]) ) cnt2++;
                    }
                    res = max(res, max(cnt1,cnt2));
                }
            }
        }

        printf("%d\n",res);
    }
    return 0;
}

/*
(sqrt(2)/2)^2 + x^2 = 1
1 - (sqrt(2)/2)^2
*/

/*
  2点の距離dとすると、
  1^2 = (d/2)^2 + x^2
  1^2 - (d/2)^2 = x^2
  求めるべき距離xが出る
  2点の中点から、垂直に距離xのベクトル先が円の中心になる。
 */

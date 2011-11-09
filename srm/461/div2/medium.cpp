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

#define EPS 1e-5
#define DEB 1
#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)


class ColoringRectangle{
public:
    int chooseDisks(int width, int height, vector <int> red, vector <int> blue){
        int i,ret = 1000;
        sort(rall(red));
        sort(rall(blue));

        double h = height / 2.0;

        vector<int> rb, br;
        int rn = red.size();
        int bn = blue.size();
        rep(i,min(rn,bn)){
            rb.push_back( red[i] ); rb.push_back( blue[i] );
            br.push_back( blue[i] ); br.push_back( red[i] );
        }
        if( i<rn ) rb.push_back( red[i] );
        if( i<bn ) br.push_back( blue[i] );
        
        // 先頭を赤
        double sum = 0;
        rep(i,rb.size()){
            double r = rb[i] / 2.0;
            double x = sqrt(r*r - h*h);
            sum += 2*x;
            if( sum >= (double)width + EPS ){
                ret = i + 1;
                break;
            }
        }

        // 先頭を青
        sum = 0;
        rep(i,br.size()){
            double r = br[i] / 2.0;
            double x = sqrt(r*r - h*h);
            sum += 2*x;
            if( sum >= (double)width + EPS ){
                ret = min(ret, i+1);
                break;
            }
        }
        return ret==1000 ? -1 : ret;
    }
};












/*
#define EPS 1e-5
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define DEB 0
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)

double sqr(double x){
    return x*x;
}

class ColoringRectangle{
public:
    int chooseDisks(int w, int h, vector <int> red, vector <int> blue);
};

int ColoringRectangle::chooseDisks(int w, int h, vector <int> red, vector <int> blue){
    int ret = INT_MAX;
    double H = (double)h/2.0;
    sort(red.rbegin(), red.rend());
    sort(blue.rbegin(), blue.rend());
  
    // first red
    int n=0, m=0, cnt=0;
    double x,sum=0.0;
    for(;;){
        if( n>=red.size() ) break;
        x = sqr((double)red[n++]/2.0) - sqr(H);
        sum += 2.0*sqrt(x);
        cnt++;
#if DEB
        printf("red: x:%lf  sum:%lf  cnt:%d\n",2.0*sqrt(x),sum,cnt);
#endif
        if( sum-EPS >= (double)w ){
            ret = min(ret, cnt);
            break;
        }

        if( m>=blue.size() ) break;
        x = sqr((double)blue[m++]/2.0) - sqr(H);
        sum += 2.0*sqrt(x);
        cnt++;
        if( sum-EPS >= (double)w ){
            ret = min(ret, cnt);
            break;
        }
    }

    // first blue
    n=m=cnt=0;
    sum = 0.0;
    for(;;){
        if( m>=blue.size() ) break;
        x = sqr((double)blue[m++]/2.0) - sqr(H);
        sum += 2.0*sqrt(x);
        cnt++;
        if( sum-EPS >= (double)w ){
            ret = min(ret, cnt);
            break;
        }

        if( n>=red.size() ) break;
        x = sqr((double)red[n++]/2.0) - sqr(H);
        sum += 2.0*sqrt(x);
        cnt++;
        if( sum-EPS >= (double)w ){
            ret = min(ret, cnt);
            break;
        }
    }

    return ret==INT_MAX ? -1 : ret;
}
*/

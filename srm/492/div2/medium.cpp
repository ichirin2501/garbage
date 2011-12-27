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
#include <sstream>
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define EPS 1e-9

class TimeTravellingGardener{
public:
    int determineUsage(vector<int> distance, vector<int> height){
        int i,j,u;
        int n = distance.size();
        int m = height.size();
        vector<int> x;
        int res = m-1;

        int xx = 0;
        x.push_back(xx);
        for(i=0; i<n; i++){
            xx += distance[i];
            x.push_back(xx);
        }

        for(i=0; i<m-1; i++){
            for(j=i+1; j<m; j++){
                double k = (double)(height[i] - height[j]) / (double)(x[i] - x[j]);

                int cnt = 0;
                for(u=0; u<m; u++){
                    if( i == u || j == u ) continue;
                    double y = k * (x[u] - x[j]) + height[j];
                    if( abs((double)height[u] - y) < EPS ){
                        ;
                    }
                    else if( y >= -EPS && height[u] > y ){
                        cnt++;
                    }
                    else{
                        break;
                    }
                }
                if( u == m ){
                    res = min(res, cnt);
                }
            }
        }
        return res;
    }
};

/*
  復習。
  2本なら1本も切らなくていい。
  切らない任意の2本の木を選択して、直線を引く
  そのときの切る必要がある木の本数を数える。
  選択した2本の木の横、縦の差で傾きがわかる。
  y - y1 = (y2 - y1) / (x2 - x1) * (x - x1)
  任意の2本の木を選択して、いずれのパターンも
  直線を引くのが不可能だった場合は、最小の木以外を全て切っても同じ。
  もし、最小の木以外全てを切らなくても直線が引けるなら
  切らない木とのペアで直線が引けるはずだが、引けないから成り立たない。
 */

int main(){
    int d[] = {2,2};
    int h[] = {1,3,10};
    vector<int> a,b;
    int i;
    rep(i,sizeof(d)/sizeof(d[0])) a.push_back(d[i]);
    rep(i,sizeof(h)/sizeof(h[0])) b.push_back(h[i]);

    TimeTravellingGardener T;

    cout << T.determineUsage(a,b) << endl;

    return 0;
}




















/*
#define EPS 1e-8
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define DEB 0
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)


class TimeTravellingGardener{
public:
  int determineUsage(vector <int> distance, vector <int> height);
};

int TimeTravellingGardener::determineUsage(vector <int> distance, vector <int> height){
  int n = height.size();
  int ret = INT_MAX;
  
  // x
  vector<int> x;
  x.pb(0);
  rep(i,distance.size()){
    int t = x[i] + distance[i];
    x.pb(t);
  }
#if DEB
  rep(i,x.size()){
    printf("%d : %d \n",x[i], height[i]);
  }
#endif

  rep(i,n){
    rep(j,n){
      if( i==j )continue;
      int a,b,p,q,cnt=0,f=0;
      a = x[i];  b = height[i];
      p = x[j];  q = height[j];
      rep(k,n){
	if( k==i || k==j )continue;
	double y = (double)(q-b) * (double)(x[k] - a) /(double)(p-a) + (double)b;
	if( y >= (double)height[k]+EPS ){
	  cnt = 999999;
	  break;
	}
	if( !(y+EPS > (double)height[k] && (double)height[k] > y-EPS) ){
	  cnt++;
	}
	if( y<0.0 ) f = 1;
#if DEB
	printf("(%d,%d)  , y:%lf, height[%d]:%d,  cnt:%d  f:%d\n",i,j,y,k,height[k],cnt,f);
#endif
      }
      ret = min(ret, cnt+f);
    }
  }

  return ret;
}
 */

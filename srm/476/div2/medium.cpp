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


class Badgers{
public:
    bool f(const vector<int>& hunger, const vector<int>& greed, int totalFood, int k){
        int i;
        int n = hunger.size();
        vector<int> vp;

        for(i=0; i<n; i++) vp.push_back((k-1) * greed[i] + hunger[i]);
        sort(all(vp));
        for(i=0; i<k; i++){
            if( totalFood - vp[i] < 0 ) break;
            totalFood -= vp[i];
        }
        return i == k;
    }

    int feedMost(vector<int> hunger, vector<int> greed, int totalFood){
        int i;
        int n = hunger.size();

        for(i=n; i>0; i--){
            if( f(hunger, greed, totalFood, i) ) break;
        }
        return i;
    }
};























/*
class Badgers{
public:
  int feedMost(vector <int> hunger, vector <int> greed, int totalFood);
};

int Badgers::feedMost(vector <int> hunger, vector <int> greed, int totalFood){
  int n = hunger.size();
  for(int k=n; k>0; k--){
    // sort
    rep(i,n-1){
      for(int j=n-1; j>i; j--){
	if( hunger[i]+greed[i]*(k-1) > hunger[j]+greed[j]*(k-1) ){
	  swap(hunger[i], hunger[j]); swap(greed[i], greed[j]);
	}
      }
    }
#if DEB
    printf("k:%d\n",k);
    rep(i,n){
      printf("(%d,%d)\n",hunger[i], greed[i]);
    }
    puts("");
#endif
    int sum = 0;
    int cnt = 0;
    rep(i,k){
      if( sum + hunger[i]+greed[i]*(k-1) > totalFood )break;
      sum += hunger[i]+greed[i]*(k-1);
      cnt++;
#if DEB
      printf("cnt:%d   sum:%d\n",cnt, sum);
#endif
    }
    if( cnt == k ) return k;
  }

  return 0;
}
 */

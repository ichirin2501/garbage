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


class OlympicCandles{
public:
    int numberOfNights(vector<int> candles){
        int n = candles.size();
        int i,j;

        for(i=1; i<=n;i++){
            sort(rall(candles));
            for(j=0; j<i; j++){
                if( candles[j] == 0 ) return i-1;
                candles[j]--;
            }
        }
        return n;
    }
};

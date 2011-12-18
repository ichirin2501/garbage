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


class TheAirTripDivTwo{
public:
    int find(vector <int> flights, int fuel){
        int i;
        int n = flights.size();
        int sum = 0;

        rep(i,n){
            if( fuel < sum + flights[i] ) return i;
            sum += flights[i];
        }
        return n;
    }
};

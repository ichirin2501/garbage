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


class CreateGroups{
public:
    int minChanges(vector <int> groups, int minSize, int maxSize){
        int n = groups.size();
        int i;
        int sum = 0;

        rep(i,n) sum += groups[i];
        if( sum > maxSize * n || sum < minSize * n ) return -1;
        sum = 0;

        int b = 0;
        rep(i,n) if( groups[i] < minSize ) sum += minSize - groups[i];
        b = sum;
        rep(i,n) if( maxSize < groups[i] ) b -= groups[i] - maxSize;

        return sum + (b < 0 ? -b : 0);
    }
};

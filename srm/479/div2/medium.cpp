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

bool use[1010];

class TheCoffeeTimeDivTwo{
public:
    int find(int n, vector <int> tea){
        int i,j;
        vector<int> coffee;
        int res = 0;

        sort(rall(tea));

        rep(i,tea.size()) use[tea[i]] = true;
        for(i=n; i>0; i--) if( !use[i] ) coffee.push_back(i);

        // tea
        for(i=0; i<tea.size(); i+=7){
            res += 2 * tea[i] + 4 * min(7, (int)tea.size()-i) + 47;
        }

        // coffee
        for(i=0; i<coffee.size(); i+=7){
            res += 2 * coffee[i] + 4 * min(7, (int)coffee.size()-i) + 47;
        }

        return res;
    }
};

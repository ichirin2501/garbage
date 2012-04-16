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
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)


class ImportantTasks{
public:
    int maximalCost(vector <int> complexity, vector <int> computers){
        int i;
        int n = complexity.size(), m = computers.size();

        sort(all(complexity)); sort(all(computers));

        int k = 0;
        int res = 0;

        for(i=0; i<n; i++){
            for(; k<m; ){
                if( complexity[i] <= computers[k++] ){ res++; break; }
            }
            if( k >= m ) break;
        }
        return res;
    }
};

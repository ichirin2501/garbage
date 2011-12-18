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


class StrangeComputer{
public:
    int setMemory(string mem){
        int n = mem.length();
        int i;
        int cnt = 0;

        rep(i,n){
            if( (mem[i] == '1' && cnt%2 == 0) ||
                (mem[i] == '0' && cnt%2 == 1) ){
                cnt++;
            }
        }

        return cnt;
    }
};

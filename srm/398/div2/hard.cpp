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


class MatchString{
public:

    int placeWords(string matchString, vector <string> matchWords){
        int res = INT_MAX;
        int i, j, n = matchWords.size();

        rep(i,50){
            int cnt = 0;
            rep(j,n){
                int r = matchWords[j].find_last_of(matchString[j], i);

                if( r == string::npos ) break;

                cnt += i - r;
            }
            if( j == n ) res = min(res, cnt);
        }

        return res == INT_MAX ? -1 : res;
    }
};



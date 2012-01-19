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


class Cut{
public:
    int getMaximum(vector <int> eelLengths, int maxCuts){
        int res = 0;
        int i;
        int n = eelLengths.size();
        bool used[55];

        memset(used, false, sizeof(used));

        vector<int> tmp;
        for(i=0; i<n; i++){
            if( eelLengths[i] % 10 == 0 ){
                used[i] = true;
                tmp.push_back(eelLengths[i]);
            }
        }
        sort(all(tmp));

        for(i=0; i<n; i++){
            if( !used[i] && eelLengths[i] >= 10 ){
                tmp.push_back(eelLengths[i]);
            }
        }

        int m = tmp.size();

        for(i=0; i<m; i++){
            if( tmp[i] == 10 ){
                res++;
                continue;
            }
            if( tmp[i]%10 == 0 ){
                res += min(maxCuts, tmp[i]/10 - 1) + (maxCuts >= tmp[i]/10 - 1);
                maxCuts -= (tmp[i]/10 - 1);
            }
            else{
                res += min(maxCuts, tmp[i]/10);
                maxCuts -= tmp[i]/10;
            }
            if( maxCuts <= 0 ) break;
        }

        return res;
    }
};

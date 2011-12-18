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


bool num[110];

class SimpleGuess{
public:
    int getMaximum(vector<int> hints){
        int n = hints.size();
        int i,x,y;

        rep(i,n) num[hints[i]] = true;

        int mx = *max_element(all(hints));
        int res = 0;

        for(x=1; x<mx; x++){
            for(y=x; x+y<=mx; y++){
                if( num[x+y] && num[y-x] ) res = max(res, x*y);
            }
        }
        return res;
    }
};



int main(){
    int d[] = { 50, 58, 47, 57, 40 };
    vector<int> v;
    int i;
    rep(i,sizeof(d)/sizeof(d[0])) v.push_back(d[i]);

    SimpleGuess S;

    cout << S.getMaximum(v) << endl;
}

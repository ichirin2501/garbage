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


class ColorfulRabbits{
public:
    int getMinimum(vector<int> replies){
        int n = replies.size();
        int i;
        map<int,int> m;
        int res = 0;

        rep(i,n) m[replies[i]]++;

        foreach(it,m){
            res += ((it->second-1) / (it->first+1) + 1) * (it->first+1);
        }

        return res;
    }
};


int main(){
    int d[] = {2,2,2,2};
    vector<int> v;
    int i;

    rep(i,sizeof(d)/sizeof(d[0])) v.push_back(d[i]);

    ColorfulRabbits C;

    cout << C.getMinimum(v) << endl;


    return 0;
}


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
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)


class ToastXToast{
public:
    int bake(vector <int> undertoasted, vector <int> overtoasted){
        int n = undertoasted.size();
        int m = overtoasted.size();

        sort(all(undertoasted));
        sort(all(overtoasted));

        if( undertoasted[0] > overtoasted[0] ||
            undertoasted[n-1] > overtoasted[m-1] ){
            return -1;
        }

        if( undertoasted[n-1] < overtoasted[0] ) return 1;
        return 2;
    }
};

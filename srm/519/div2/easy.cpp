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


const char *week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

class WhichDay{
public:
    string getDay(vector<string> notOnThisDay){
        vector<string> w;
        int i;

        rep(i,7) w.push_back(string(week[i]));
        sort(all(w));
        sort(all(notOnThisDay));
        rep(i,6) if( w[i] != notOnThisDay[i] ) return w[i];
        return w[6];
    }
};


int main(){
    const char *ww[] = {"Sunday", "Friday", "Tuesday", "Wednesday", "Monday", "Saturday"};
    vector<string> v;
    int i;
    rep(i,6) v.push_back(string(ww[i]));

    WhichDay W;
    cout << W.getDay(v) << endl;

    return 0;
}

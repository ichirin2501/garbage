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

class InterestingParty{
public:
    int bestInvitation(vector<string> first, vector<string> second){
        int n = first.size();
        map<string, int> ms;
        int i;
        int res = 0;

        rep(i,n){
            ms[first[i]]++;
            ms[second[i]]++;
        }

        foreach(it,ms){
            res = max(res, it->second);
        }

        return res;
    }
};


int main(){
    const char *s1[] = {"t", "o", "p", "c", "o", "d", "e", "r", "s", "i", "n", "g", "l", "e", "r",
                        "o", "u", "n", "d", "m", "a", "t", "c", "h", "f", "o", "u", "r", "n", "i"};
    const char *s2[] = {"n", "e", "f", "o", "u", "r", "j", "a", "n", "u", "a", "r", "y", "t", "w", 
                        "e", "n", "t", "y", "t", "w", "o", "s", "a", "t", "u", "r", "d", "a", "y"};
    vector<string> vs1, vs2;
    int i;
    int n = sizeof(s1)/sizeof(s1[0]);

    rep(i,n){
        vs1.push_back(string(s1[i]));
        vs2.push_back(string(s2[i]));
    }

    InterestingParty I;

    cout << I.bestInvitation(vs1, vs2) << endl;

}

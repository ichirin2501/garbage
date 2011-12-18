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


class AnagramFree{
public:
    int getMaximumSubset(vector<string> S){
        int n = S.size();
        int i;
        set<string> ss;

        rep(i,n){
            sort(all(S[i]));
            ss.insert(S[i]);
        }

        return (int)ss.size();
    }
};


int main(){
    const char *s[] = {"creation","sentence","reaction","sneak","star","rats","snake"};
    vector<string> vs;
    int i;
    rep(i,sizeof(s)/sizeof(s[0])) vs.push_back(string(s[i]));

    AnagramFree A;
    cout << A.getMaximumSubset(vs) << endl;

}

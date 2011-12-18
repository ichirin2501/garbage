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


class AmoebaDivTwo{
public:
    int count(vector<string> table, int K){
        int h = table.size();
        int w = table[0].length();
        int i,j,k;
        int res = 0;

        // 1xK
        rep(i,h){
            for(j=0; j+K<=w; j++){
                bool ok = true;
                rep(k,K){
                    if( table[i][j+k] == 'M' ) ok = false;
                }
                if( ok ) res++;
            }
        }

        if( K == 1 ) return res;

        // Kx1
        rep(j,w){
            for(i=0; i+K<=h; i++){
                bool ok = true;
                rep(k,K){
                    if( table[i+k][j] == 'M' ) ok = false;
                }
                if( ok ) res++;
            }
        }

        return res;
    }
};


int main(){
    const char *s[] = {"AAA",
 "AAM",
 "AAA"};
    vector<string> vs;
    int i;
    rep(i,sizeof(s)/sizeof(s[0])) vs.push_back(string(s[i]));

    AmoebaDivTwo A;

    cout << A.count(vs, 2) << endl;

    return 0;
}



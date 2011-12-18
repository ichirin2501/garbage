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

class SoccerLeagues{
public:
    vector<int> points(vector<string> matches){
        int n = matches.size();
        int i,j;
        vector<int> res;

        rep(i,n){
            int sum = 0;
            rep(j,n){
                // home's
                if( matches[i][j] == 'W' ) sum += 3;
                if( matches[i][j] == 'D' ) sum += 1;
            }
            rep(j,n){
                // oppo
                if( matches[j][i] == 'L' ) sum += 3;
                if( matches[j][i] == 'D' ) sum += 1;
            }

            res.push_back(sum);
        }

        return res;
    }
};

int main(){
    const char *s[] = {"-LWWLWDLDWWWWWWDDWDW",
 "D-WWLDDWDWDLWDDWLWDD",
 "LL-DLDWDLDLDWWWLWDDW",
 "LDD-LLLDLWLWWWWDWDWL",
 "LWWW-DWDLWDWDWWWDWDW",
 "DLLWD-WWLLDDDLWWDWWW",
 "WWLWDL-LLDWWWWWDWWLW",
 "LLLLLDW-LDLWDDLLLDWL",
 "DWWWWDDD-DWWWWDWWWDW",
 "WWWWLLLWL-LWWWWWLWWW",
 "DWWWWWWWLW-WDWWWWWWW",
 "DDDLLLDWWWL-DDWDWLDD",
 "LWLWLDLLLDLW-DDDWWDD",
 "LLWWLWDDLWLWL-WWWDLL",
 "WWWWLLDDDWLWDD-WWWLW",
 "DLDLLLWWLLLWWLW-DWLL",
 "DLWWWLDLWWDWWDWL-WWD",
 "LLDDLLWLLWLWLDLWW-WW",
 "LLWLLLWWLWLWWDWWLD-W",
 "LLWDLWDWDWLLWWDDWWL-"};

    vector<string> vs;
    int i;
    rep(i,sizeof(s)/sizeof(s[0])) vs.push_back(string(s[i]));

    SoccerLeagues S;

    vector<int> res = S.points(vs);

    return 0;
}


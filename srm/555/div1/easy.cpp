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

bool valid[55][55]; // [a,b)
const int inf = 999999999;
int dp[55][55];

class CuttingBitString {
public:
    bool is_valid(string s) {
        long long r = 0;
        if (s[0] == '0') return 0; // no readling zero
        for (int i=0; i<s.length(); ++i) {
            long long bit = (s[i] == '1');
            r |= (bit << ((long long)s.length() - i - 1));
        }
        while (r > 0 && r % 5 == 0) r /= 5;
        return r == 1;
    }

    int recr(int s, int t) {

        if (dp[s][t] != -1) return dp[s][t];
        if (valid[s][t])    return 1;
        
        int res = inf;
        for (int i=s+1; i<t; ++i) {
            res = min(res, recr(s, i) + recr(i, t));
        }
        return dp[s][t] = res;
    }

    int getmin(string S) {
        memset(valid, false, sizeof(valid));
        memset(dp, -1, sizeof(dp));
        for (int i=0; i<(int)S.length(); ++i) {
            for (int j=1; i + j<=S.length(); ++j) {
                if (is_valid(S.substr(i, j))) {
                    valid[i][i + j] = true;
                }
                //cout << S.substr(i, j) << " : " << valid[i][i + j] << endl;
            }
        }
        int res = recr(0, (int)S.length());
        return res == inf ? -1 : res;
    }
    
};


int main() {
    CuttingBitString C;
    cout << C.getmin("101101101") << endl;
    cout << C.getmin("1111101") << endl;
    cout << C.getmin("00000") << endl;
    cout << C.getmin("110011011") << endl;
    cout << C.getmin("1000101011") << endl;
    cout << C.getmin("111011100110101100101110111") << endl;
}

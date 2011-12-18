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

class RedAndGreen{
public:
    int minPaints(string row){
        int n = row.length();
        int i,j;
        int res = INT_MAX;

        rep(i,n+1){
            int cnt = 0;
            for(j=0; j<i; j++) if( row[j] == 'G' ) cnt++;
            for(; j<n; j++) if( row[j] == 'R' ) cnt++;
            res = min(res, cnt);
        }
        
        return res;
    }
};


int main(){
    RedAndGreen R;
    
    cout << R.minPaints("RGRGR") << endl;
    cout << R.minPaints("RRRGGGGG") << endl;
    cout << R.minPaints("GGGGRRR") << endl;
    cout << R.minPaints("RGRGRGRGRGRGRGRGR") << endl;
    cout << R.minPaints("RRRGGGRGGGRGGRRRGGRRRGR") << endl;
    cout << R.minPaints("RRRRR") << endl;
    cout << R.minPaints("GGGGG") << endl;

    return 0;
}


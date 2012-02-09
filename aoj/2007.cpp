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
#include <complex>
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)


const int m[] = {10, 50, 100, 500};

int main(){
    int N, coin[4],i;

    bool x = false;
    while( cin >> N, N ){
        scanf("%d %d %d %d", &coin[0], &coin[1], &coin[2], &coin[3]);

        if( x ) puts("");
        x = true;

        int sum = 0;
        rep(i,4) sum += m[i] * coin[i];

        sum -= N;
        if( sum < 0 ) { puts("error"); exit(1); }

        int tmp[4];
        for(i=3; i>=0; i--){
            tmp[i] = sum / m[i];
            sum -= (sum / m[i]) * m[i];
        }

        rep(i,4){
            if( tmp[i] < coin[i] ){
                printf("%d %d\n", m[i], coin[i] - tmp[i]);
            }
        }
    }

    return 0;
}

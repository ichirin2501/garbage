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


int cb[20][20];

void make_comb(){
    // cb[n][m] = cb[n-1][m] + cb[n-1][m-1]
    int i,j;
    const int sz = 20;

    for(i=0; i<sz; i++) cb[i][i] = 1;
    for(i=1; i<sz; i++){
        cb[i][0] = 1;
        cb[i][1] = i;
    }

    for(i=2; i<sz; i++){
        for(j=1; j<=i; j++){
            cb[i][j] = (cb[i-1][j] + cb[i-1][j-1]);
        }
    }
}


class PrimeSoccer{
public:
    double getProbability(int skillOfTeamA, int skillOfTeamB){
        int i;
        const int prime[] = {2,3,5,7,11,13,17};
        double sumA = 0.0, sumB = 0.0;
        // comb
        make_comb();
        
        rep(i,7){
            double pa = (double)skillOfTeamA/100.0;
            double pb = (double)skillOfTeamB/100.0;
            double qa = 1.0 - pa;
            double qb = 1.0 - pb;
            sumA += (double)cb[18][prime[i]] * pow(pa,(double)prime[i]) * pow(qa,18.0 - (double)prime[i]);
            sumB += (double)cb[18][prime[i]] * pow(pb,(double)prime[i]) * pow(qb,18.0 - (double)prime[i]);
        }

        return 1.0 - (1.0-sumA) * (1.0-sumB);
    }
};


int main(){
    PrimeSoccer P;

    printf("%.10lf\n", P.getProbability(50,50));
    printf("%.10lf\n", P.getProbability(100,100));
    printf("%.10lf\n", P.getProbability(12,89));
}


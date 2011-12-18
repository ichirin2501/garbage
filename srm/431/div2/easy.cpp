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


class MegaCoolNumbersEasy{
public:
    bool isMegaCool(int n){
        int i;
        string str;

        do{
            str += string(1, n%10 + '0');
            n /= 10;
        }while( n>0 );

        reverse(all(str));

        int diff = str[0] - str[1];
        REP(i,1,str.length()-1){
            if( str[i] - str[i+1] != diff ) return false;
        }
        return true;
    }
    
    int count(int N){
        int i;
        int res = 0;

        for(i=1; i<=N; i++){
            if( isMegaCool(i) ) res++;
        }

        return res;
    }
};

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
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)

class MissingParentheses{
public:
    int countCorrections(string par){
        int n = par.length();
        int i,x=0, ans=0;
        
        rep(i,n){
            if( par[i]=='(' ){
                x++;
            }else{
                x--;
            }
            if( x<0 ){
                ans++;
                x=0;
            }
        }

        return x + ans;
    }
};

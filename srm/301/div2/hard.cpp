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
#include <sstream>
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)


const int inf = 999999999;
int memo[55][55];

class CorrectingParenthesization{
public:
    bool ismatch(char a, char b){
        return ( (a == '(' && b == ')') ||
                 (a == '[' && b == ']') ||
                 (a == '{' && b == '}') );
    }

    int parse(const string& str, int s, int e){
        int i;
        int res = inf;
        int cnt;

        if( s == e ) return 0;
        if( memo[s][e] != -1 ) return memo[s][e];

        if( ismatch(str[s], str[e-1]) ){
            cnt = 0;
        }
        else if( str[s] == '(' || str[s] == '[' || str[s] == '{' ||
                 str[e-1] == ')' || str[e-1] == ']' || str[e-1] == '}' ){
            cnt = 1;
        }
        else{
            cnt = 2;
        }

        // 両端を対応させたとき
        res = min(res, parse(str, s+1, e-1) + cnt);

        // iは区切る位置
        // [s,i), [i,e)
        for(i=s+2; i<e; i+=2){
            res = min(res, parse(str,s,i) + parse(str,i,e));
        }

        return memo[s][e] = res;
    }

    int getMinErrors(string s){
        int n = s.length();

        memset(memo, -1, sizeof(memo));

        return parse(s, 0, n);
    }
};

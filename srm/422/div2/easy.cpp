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


string itos(int n){
    char buf[50];
    sprintf(buf,"%d",n);
    return string(buf);
}

class MultiNumber{
public:
    string check(int number){
        int i,j;
        string s = itos(number);
        int n = s.length();
        
        REP(i,1,n){
            int a=1, b=1;
            for(j=0; j<i; j++) a *= s[j]-'0';
            for(j=i; j<n; j++) b *= s[j]-'0';
            if( a == b ) return "YES";
        }
        return "NO";
    }
};


int main(){
    MultiNumber M;

    cout << M.check(1) << endl;
    cout << M.check(1221) << endl;
    cout << M.check(1236) << endl;
    cout << M.check(4729382) << endl;
    cout << M.check(42393338) << endl;
    cout << M.check(1999999999) << endl;

    return 0;
}

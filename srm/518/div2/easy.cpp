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

class TwiceString{
public:
    string getShortest(string s){
        int n = s.length();
        int i,j;

        for(i=1; i<n; i++){
            for(j=0; i+j<n; j++) if( s[i+j] != s[j] ) break;
            if( i+j == n ) return s + s.substr(j);
        }
        
        return s + s;
    }
};


int main(){
    TwiceString T;

    cout << T.getShortest("aa") << endl;
    cout << T.getShortest("xxxxx") << endl;
    cout << T.getShortest("topcoder") << endl;
    cout << T.getShortest("abracadabra") << endl;

    return 0;
}


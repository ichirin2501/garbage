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

int parse(string s){
    int i,j,x;
    int n = s.length();

    //cout << s << endl;

    x = 0;
    for(i=n-1; i>=0; i--){
        if( s[i] == '(' ) x++;
        if( s[i] == ')' ) x--;
        if( x == 0 && (s[i] == '+' || s[i] == '-') ) break;
    }

    if( i == -1 ){
        x = 0;
        for(i=n-1; i>=0; i--){
            if( s[i] == '(' ) x++;
            if( s[i] == ')' ) x--;
            if( x == 0 && (s[i] == '*' || s[i] == '/') ) break;
        }
    }

    if( i == -1 ){
        for(j=0; j<n; j++) if( !('0' <= s[j] && s[j] <= '9') ) break;
        if( j == n ){ // number
            return atoi(s.c_str());
        }
        // ()
        return parse(s.substr(1,s.length()-2));
    }
    else{
        int a = parse(s.substr(0,i)), b = parse(s.substr(i+1));
        switch(s[i]){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        }
    }
}

int main(){
    int T;
    string in;

    cin >> T;
    while( T-- ){
        cin >> in;
        cout << parse(in.substr(0,in.length()-1)) << endl;
    }

    return 0;
}

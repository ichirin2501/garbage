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

/*
  AOJ :: 0101
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0101&lang=jp
 */


int main(){
    int n,i;
    string in;

    cin >> n; cin.ignore();
    rep(i,n){
        getline(cin, in);
        while( true ){
            int p = in.find("Hoshino");
            if( p == string::npos ) break;
            in[p+6] = 'a';
        }
        cout << in << endl;
    }

    return 0;
}

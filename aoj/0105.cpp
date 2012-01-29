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


int main(){
    map<string,set<int> > msv;
    string in;
    int page,i;

    while( cin >> in >> page ){
        if( msv.count(in) ){
            msv[in].insert(page);
        }
        else{
            set<int> tmp; tmp.insert(page);
            msv[in] = tmp;
        }
    }

    foreach(it,msv){
        cout << it->first << endl;
        i = 0;
        foreach(js,it->second){
            if( i > 0 ) putchar(' ');
            printf("%d",*js);
            i++;
        }
        puts("");
    }

    return 0;
}

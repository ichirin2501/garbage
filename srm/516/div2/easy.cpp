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

class NetworkXZeroOne{
public:
    string reconstruct(string message){
        int n = message.length();
        int i,j;
        
        rep(i,n){
            if( message[i] != '?' ) break;
        }
        for(j=i-1; j>=0; j--){
            message[j] = ('o' + 'x') - message[j+1]; 
        }
        for(i++; i<n; i++){
            message[i] = ('o' + 'x') - message[i-1]; 
        }
        return message;
    }
};

int main(){
    NetworkXZeroOne N;

    cout << N.reconstruct("x?x?") << endl;
    cout << N.reconstruct("?xo?") << endl;
    cout << N.reconstruct("xo") << endl;
    cout << N.reconstruct("o??x??o") << endl;
    cout << N.reconstruct("???????x") << endl;

    return 0;
}

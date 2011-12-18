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

class FortunateNumbers{
public:
    bool isfortunatenum(int n){
        do{
            if( !(n%10 == 8 || n%10 == 5) ) return false;
            n /= 10;
        }while( n > 0 );
        return true;
    }

    int getFortunate(vector<int> a, vector<int> b, vector<int> c){
        int i,j,k;
        set<int> si;

        rep(i,a.size()){
            rep(j,b.size()){
                rep(k,c.size()){
                    if( isfortunatenum(a[i] + b[j] + c[k]) ){
                        si.insert( a[i] + b[j] + c[k] );
                    }
                }
            }
        }

        return si.size();
    }
};

int main(){
    
    return 0;
}



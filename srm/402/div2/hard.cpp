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

map<vector<int>, double> memo;

class RandomSort{
public:
    bool isok(const vector<int> permutation){
        int i;
        rep(i,permutation.size()-1){
            if( permutation[i] > permutation[i+1] ) return false;
        }
        return true;
    }
    double solve(vector<int> permutation){
        int n = permutation.size();
        int i,j,cnt=0;
        double ret = 0.0;

        if( memo.count(permutation) ) return memo[permutation];
        if( isok(permutation) ) return 0.0;

        rep(i,n){
            REP(j,i+1,n){
                if( permutation[i] > permutation[j] ){
                    swap(permutation[i], permutation[j]);
                    ret += solve(permutation);
                    swap(permutation[i], permutation[j]);
                    cnt++;
                }
            }
        }

        return memo[permutation] = ret/(double)cnt + 1.0;
    }

    double getExpected(vector <int> permutation){
        return solve(permutation);
    }
};

int main(){
    return 0;
}

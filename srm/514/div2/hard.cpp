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


typedef long long ll;

ll len[110];
vector<string> A;

class MagicalGirlLevelThreeDivTwo{
public:
    bool isone(ll index, int n, int K){
        if( n < A.size() ){
            return '1' == A[n][index];
        }
        int i;
        for(i=0; ;i++){
            if( len[n-1-K*i] > index ){
                return isone(index, n-1-K*i, K);
            }
            index -= len[n-1-K*i];
        }
    }
    
    int theCount(vector <string> first, int n, long long lo, long long hi){
        int i,j;
        int K = first.size();
        int ret = 0;

        A = first;

        rep(i,K) len[i] = first[i].length();
        for(i=K; i<=n; i++){
            for(j=0; i-1-K*j>=0 ;j++){
                len[i] += len[i-1-K*j];
            }
            if( len[i] > hi ){
                n = i;
                break;
            }
        }
        for(ll id=lo; id<=hi; id++){
            if( isone(id,n,K) ){
                ret++;
            }
        }

        return ret;
    }
};


int main(){
    MagicalGirlLevelThreeDivTwo M;
    const char *s[] = {"101", "01"};
    vector<string> first;
    int i;
    for(i=0; i<sizeof(s)/sizeof(s[0]); i++) first.push_back(string(s[i]));
    cout << M.theCount(first, 4, 2, 5) << endl;

    return 0;
}






















/*

typedef long long ll;
ll len[110];

class MagicalGirlLevelThreeDivTwo{
public:
    char dfs(vector<string>&first, ll id, int n){
        int K = first.size();

        //printf("id:%lld, n:%d\n",id,n);
        if( n < K ) return first[n][id];

        ll tmp = 0;
        for(int j=0; n-j*K-1>=0; j++){
            if( id < len[n-j*K-1] ){
                return dfs(first, id, n-j*K-1);
            }
            id -= len[n-j*K-1];
            //printf("j:%d , id:%lld\n",j,id);
        }
    }
    int theCount(vector <string> first, int n, long long lo, long long hi){
        int K = first.size();

        rep(i,K) len[i] = first[i].size();
        for(int i=K; i<=n; i++){
            if( hi < len[i-1] ){ n = i-1; break; }
            for(int j=0; i-j*K-1>=0; j++){
                len[i] += len[i-j*K-1];
            }
        }
    
        int ret = 0;
        for(ll i=lo; i<=hi; i++){
            if( dfs(first, i, n)=='1' ) ret++;
            //printf("i:%lld ,ret:%d\n",i,ret);
        }

        return ret;
    }
};

*/

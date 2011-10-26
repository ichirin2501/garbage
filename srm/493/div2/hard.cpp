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


#define DEB 0
#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)



class CrouchingAmoebas{
public:
    long long dist(long long tx, long long ty, long long x, long long y, long long A){
        long long ret = 0;
        if( x < tx || tx+A < x ){
            ret += min(abs(tx-x), abs(tx+A-x));
        }
        if( y < ty || ty+A < y ){
            ret += min(abs(ty-y), abs(ty+A-y));
        }
        return ret;
    }
    int count(vector <int> x, vector <int> y, int A, int T){
        vector<int> tx, ty;
        int ret = 0;
        int i,j,k;

        rep(i,x.size()){
            tx.push_back(x[i]); tx.push_back(x[i]-A);
            ty.push_back(y[i]); ty.push_back(y[i]-A);
        }

        int n = tx.size();

        rep(i,n) rep(j,n){
            vector<long long> tmp;

            rep(k,x.size()) tmp.push_back( dist(tx[i], ty[j], x[k], y[k], A) );

#if DEB
            printf("(%d,%d)\n",tx[i], ty[j]);
            rep(k,tmp.size()){
                printf("%d : (%d,%d)  = dist=%lld\n",k,x[k],y[k],tmp[k]);
            }
#endif
            
            sort(all(tmp));
            long long sum = 0;
            int cnt = 0;
            rep(k,tmp.size()){
                sum += tmp[k];
                if( sum > T ) break;
                cnt++;
            }
            ret = max(ret, cnt);
        }

        return ret;
    }
};

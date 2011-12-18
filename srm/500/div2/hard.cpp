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

// YET_SYSTEM_TEST

class GeometricProgressions{
public:
    // n > 0
    map<int,int> sosu(int n){
        map<int,int> res;
        int i;

        if( n == 1 ){
            res.insert( make_pair(1,1) );
            return res;
        }

        for(i=2; i*i <= n; i++){
            int cnt = 0;
            while( n%i == 0 ){
                n /= i;
                cnt++;
            }
            if( cnt ) res.insert( make_pair(i, cnt) );
        }
        if( n > 1 ) res.insert( make_pair(n, 1) );

        return res;
    }

    int count(int b1, int q1, int n1, int b2, int q2, int n2){
        set< map<int,int> > S;
        map<int,int> t1, t2, tmp;
        int i;

        
        if( b1 == 0 ){
            t1.insert( make_pair(0,0) );
            S.insert( t1 );
        }
        else{
            if( q1 <= 1 ){
                S.insert(sosu(b1));
                if( q1 == 0 && n1 >= 2 ){
                    t1.insert( make_pair(0,0) );
                    S.insert( t1 );
                }
            }
            else{
                t1 = sosu(b1);
                tmp = sosu(q1);
                // debug
                /*
                foreach(it, tmp){
                    printf("db: %d : %d\n", it->first, it->second);
                }
                puts("");
                */

                t1.insert(make_pair(1,1));
                S.insert(t1);

                rep(i,n1-1){
                    foreach(it,tmp){
                        t1[it->first] += it->second;
                    }
                    S.insert( t1 );
                }
            }
        }

        // S2
        if( b2 == 0 ){
            t2.insert( make_pair(0,0) );
            S.insert( t2 );
        }
        else{
            if( q2 <= 1 ){
                S.insert(sosu(b2));
                if( q2 == 0 && n2 >= 2 ){
                    t2.insert( make_pair(0,0) );
                    S.insert( t2 );
                }
            }
            else{
                t2 = sosu(b2);
                tmp = sosu(q2);
                // debug
                /*
                foreach(it, tmp){
                    printf("db: %d : %d\n", it->first, it->second);
                }
                puts("");
                */

                t2.insert(make_pair(1,1));
                S.insert(t2);

                rep(i,n2-1){
                    foreach(it,tmp){
                        t2[it->first] += it->second;
                    }
                    S.insert( t2 );
                }
            }
        }

        //debug
        /*
        foreach(it,S){
            map<int,int> tt = *it;
            foreach(ii, tt){
                cout << ii->first << " : " << ii->second << endl;
            }
            puts("");
        }
        */

        return S.size();
    }
};

int main(){
    GeometricProgressions G;

    //cout << G.count(3,2,5,6,2,5) << endl;
    //cout << G.count(3,4,100500,48,1024,1000) << endl;
    cout << G.count(1,1,1,0,0,1) << endl;
    return 0;
}

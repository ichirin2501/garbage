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


class StonesGame{
public:
    bool isok(int N, int M, int K, int L){

        if( !(abs(M-L+1)%2 == K%2 && K > abs(M-L)) ) return false;

        if( K%2 ){
            return ( ((M <= K/2 && M < L) || K/2 < M) &&
                     ((N-K+1+K/2 < M && L < M) || N-K+1+K/2 >= M) );
        }
        else{
            return ( ((M <= K/2 && M < L) || K/2 < M) && 
                     ((N-K+1+K/2 <= M && L < M) || N-K+1+K/2 > M) );
        }
    }

    string winner(int N, int M, int K, int L){
        int i;
        if( M == L || isok(N,M,K,L) ) return "Romeo";
        if( K == 1 ) return "Draw";
        
        for(i=1; i+K-1<=N; i++){
            if( i+K-1 < M ) continue;
            if( i > M ) break;

            // i ~ i+K-1

            if( M <= i+K/2 ){
                //奥
                //printf("(oku), i=%d, %d\n",i,M+K-1-2*(M-i));
                if( !isok(N, M+K-1-2*(M-i), K, L) ) return "Draw";
            }
            else{
                //手前
                //printf("(tema), i=%d, %d\n",i,M-((K-1)-2*((K-1)-(M-i))));
                if( !isok(N, M-((K-1)-2*((K-1)-(M-i))), K, L) ) return "Draw";
            }
        }
        
        
        return "Strangelet";
    }
};


int main(){
    StonesGame S;

    /*
    cout << S.winner(3,3,3,2) << endl; //D
    cout << S.winner(10, 1, 8, 5) << endl; //S
    cout << S.winner(	9, 3, 3, 9) << endl; //D
    cout << S.winner(6,6,4,2) << endl; //S
    cout << S.winner(	6, 1, 3, 4) << endl; //D
    cout << S.winner(8, 2, 5, 7) << endl; //D
    cout << S.winner(9, 6, 8, 7) << endl; //D
    cout << S.winner(	7, 6, 2, 2) << endl;//D
    cout << S.winner(	10, 3, 9, 10) << endl;//D
    cout << S.winner(10, 5, 10, 6) << endl;//R
    cout << S.winner(10, 4, 2, 3) << endl;//R
    cout << S.winner(8, 8, 1, 6) << endl;//D
    cout << S.winner(10, 5, 9, 8) << endl;//D
    cout << S.winner(9, 8, 7, 4) << endl;//R
    cout << S.winner(10, 9, 2, 10) << endl;//R
    cout << S.winner(9, 7, 3, 6) << endl;//D
    */

    
    cout << S.winner(3,1,1,2) << endl;
    cout << S.winner(5,1,2,2) << endl;
    cout << S.winner(5,5,2,3) << endl;
    cout << S.winner(10,5,5,10) << endl;
    cout << S.winner(1000000, 804588, 705444, 292263) << endl;
    //cout << S.winner(100, 10, 50, 60) << endl;
    cout << S.winner(1000000, 100000, 500000, 600000) << endl;
    

    return 0;
}

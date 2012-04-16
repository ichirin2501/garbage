#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <list>
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


int dp[1<<20];

class EllysCheckers{
public:
    bool solve(int bit, int n){
        int i;
        bool res = false;

        bit &= (1<<(n-1))-1;
        if( bit == 0 ) return true;
        if( dp[bit] != -1 ) return (bool)!dp[bit];

        // move
        rep(i,n-1) if( (bit&(1<<i)) && !(bit&(1<<(i+1))) ){
            int next = bit;
            next |= 1<<(i+1);
            next &= ~(bit&(1<<i));
            res |= solve(next, n);
        }

        // jump
        rep(i,n-3) if( ((bit&(7<<i)) == (7<<i)) && !(bit&(1<<(i+3))) ) {
            int next = bit;
            next |= 1<<(i+3);
            next &= ~(bit&(1<<i));
            res |= solve(next, n);
        }
        dp[bit] = res;
        return !res;
    }

    string getWinner(string board){
        memset(dp, -1, sizeof(dp));

        int i, bit = 0, n = board.length();
        rep(i,n) if( board[i] == 'o' ) bit |= 1<<i;

        return !solve(bit, n) ? "YES" : "NO";
    }
};

int main(){
    EllysCheckers E;

    /*
    cout << E.getWinner("o...") << endl; // yes
    cout << E.getWinner("...") << endl; // no
    cout << E.getWinner("o..") << endl; // no
    cout << E.getWinner(".o...") << endl; // yes
    cout << E.getWinner("..o..o") << endl; // yes
    cout << E.getWinner(".o...ooo..oo..") << endl;
    cout << E.getWinner("......o.ooo.o......") << endl;
    cout << E.getWinner(".o..o...o....o.....o") << endl;
    */

    string s = ".....oooo";
    sort(all(s));
    do{
        cout << s << " : " << E.getWinner(s) << endl;
    }while( next_permutation(all(s)) );

    return 0;
}

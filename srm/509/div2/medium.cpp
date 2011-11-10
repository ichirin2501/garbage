#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const int mod = 9;
int cb[64][64];

class LuckyRemainder{
 public:
    void make_comb(){
        // cb[n][m] = cb[n-1][m] + cb[n-1][m-1]
        int i,j;
        const int sz = 64;

        for(i=0; i<sz; i++) cb[i][i] = 1;
        for(i=1; i<sz; i++){
            cb[i][0] = 1;
            cb[i][1] = i % mod;
        }

        for(i=2; i<sz; i++){
            for(j=1; j<=i; j++){
                cb[i][j] = (cb[i-1][j] + cb[i-1][j-1]) % mod;
            }
        }
    }

    int getLuckyRemainder(string X){
        int ret = 0;
        int n = X.length();
        int i,j;

        make_comb();

        for(i=0; i<n; i++){
            int num = X[i]-'0';
            for(j=0; j<n; j++){
                ret = (ret + num*cb[n-1][j]) % mod;
            }
        }
        return ret;
    }
};

int main(){
    LuckyRemainder L;
    L.make_comb();

    /*
    int i,j;
    for(i=0; i<10; i++){
        for(j=0; j<=i; j++){
            printf("%d_C_%d = %d\n",i,j,cb[i][j]);
        }
    }

    1234だと、
    1 * 10^0 = 1
    1 * 10^1 = 3C1
    1 * 10^2 = 3C2
    1 * 10^3 = 3C3 * (10%9) * (10%9) * (10%9)
    */

    cout << L.getLuckyRemainder("123") << endl;
    cout << L.getLuckyRemainder("8") << endl;
    
    return 0;
}

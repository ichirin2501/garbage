#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

const long long mod = 1000000007;
long long dp[55][4][4];

int comb(int n, int r){
    if( r==0 ) return 1;
    if( n==0 ) return 0;
    return comb(n-1, r) + comb(n-1, r-1);
}

class SRMSystemTestPhase{
public:
    int getY(const string& str){
        int i,ret=0;

        for(i=0; i<str.length(); i++){
            if( str[i]=='Y' ) ret++;
        }

        return ret;
    }

    int TEI(int m, int passed, int challenged){
        return comb(m, passed) * comb(m-passed, challenged);
    }

    int countWays(vector<string> description){
        int n = description.size();
        int i,j,k,a,b;

        dp[0][3][0] = 1;

        for(i=1; i<=n; i++){
            
            int m = getY(description[i-1]);

            for(j=0; j<=m; j++){
                for(k=0; k<=m-j; k++){

                    int A = TEI(m,j,k);

                    for(a=j; a<4; a++){
                        for(b=0; b<4; b++){
                            if( a==j && b>k ) continue;
                            dp[i][j][k] += dp[i-1][a][b] * A;
                            dp[i][j][k] %= mod;
                        }
                    }
                }
            }
        }

        // sum
        long long ret = 0;
        for(i=0; i<4; i++){
            for(j=0; j<4; j++){
                ret += dp[n][i][j];
                ret %= mod;
            }
        }

        return (int)ret;
    }
};


int main(){
    const char *s[] = {"YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY", "YYY"};
    vector<string> vs;
    for(int i=0; i<sizeof(s)/sizeof(s[0]); i++) vs.push_back(string(s[i]));

    SRMSystemTestPhase S;
    cout << S.countWays(vs) << endl;

    return 0;
}

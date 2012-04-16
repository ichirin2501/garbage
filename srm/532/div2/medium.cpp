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

bool used[55];

// 1,1,1,1,1
class DengklekMakingChains{
public:
    bool isfront(const string& a){
        return (a[2] != '.');
    }
    bool isback(const string& a){
        return (a[0] != '.');
    }

    int maxBeauty(vector <string> chains){
        int i,j;
        int n = chains.size();
        string str;

        memset(used, false, sizeof(used));

        rep(i,n){
            if( chains[i][0] != '.' && chains[i][1] != '.' && chains[i][2] != '.' ){
                str += chains[i];
                used[i] = true;
            }
        }

        int sum = 0;
        int idf = -1, idb = -1;
        rep(i,n) if( !used[i] && isfront(chains[i]) ) {
            rep(j,n) if( !used[j] && i != j && isback(chains[j]) ) {
                int tmp = 0;
                tmp += chains[i][2] - '0'; // front
                if( chains[i][1] != '.' ) tmp += chains[i][1] - '0';
                tmp += chains[j][0] - '0'; // back
                if( chains[j][1] != '.' ) tmp += chains[j][1] - '0';
                if( sum < tmp ){
                    sum = tmp;
                    idf = i;
                    idb = j;
                }
            }
        }

        if( idf != -1 && idb != -1 ){
            str = chains[idf] + str, used[idf] = true;
            str = str + chains[idb], used[idb] = true;
        }
        else{
            int one = -1;
            sum = 0;
            rep(i,n){
                if( !used[i] && isfront(chains[i]) ){
                    int tmp = 0;
                    tmp += chains[i][2] - '0';
                    if( chains[i][1] != '.' ) tmp += chains[i][1] - '0';
                    if( sum < tmp ){
                        one = i;
                        sum = tmp;
                    }
                }
            }
            bool f = false;
            rep(i,n){
                if( !used[i] && isback(chains[i]) ){
                    int tmp = 0;
                    tmp += chains[i][0] - '0';
                    if( chains[i][1] != '.' ) tmp += chains[i][1] - '0';
                    if( sum < tmp ){
                        one = i;
                        sum = tmp;
                        f = true;
                    }
                }
            }
            if( one != -1 ){
                if( f ){
                    str = str + chains[one];
                }
                else{
                    str = chains[one] + str;
                }
                used[one] = true;
            }
        }

        rep(i,n) if( !used[i] ){
            str += chains[i];
        }

        int res = 0;
        i = 0;
        while( i < str.length() ){
            int tmp = 0;
            while( i < str.length() && str[i] != '.' ){
                tmp += str[i] - '0';
                i++;
            }
            i++;
            res = max(res, tmp);
        }

        return res;
    }
};

int main(){
    
}


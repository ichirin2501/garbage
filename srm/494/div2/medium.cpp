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

int w,h;

class Painting{
public:
    bool isok(int n, vector<string>& picture){
        int i,j,ii,jj;
        bool used[64][64];

        memset(used, false, sizeof(used));

        for(i=0; i+n<=h; i++){
            for(j=0; j+n<=w; j++){
                if( picture[i][j] == 'W' ) continue;
                bool ok = true;
                for(ii=i; ii<i+n; ii++){
                    for(jj=j; jj<j+n; jj++){
                        if( picture[ii][jj] == 'W' ){
                            ok = false;
                            goto F;
                        }
                    }
                }
            F:
                if( ok ){
                    for(ii=i; ii<i+n; ii++){
                        for(jj=j; jj<j+n; jj++){
                            used[ii][jj] = true;
                        }
                    }
                }
            }
        }

        // check
        rep(i,h){
            rep(j,w){
                if( picture[i][j] == 'B' && used[i][j] == false ) return false;
            }
        }

        return true;
    }

    int largestBrush(vector<string> picture){
        h = picture.size();
        w = picture[0].length();

        int l = 1, r = min(w,h);

        while( l < r ){
            int mid = (l + r) / 2 + 1;

            if( isok(mid, picture) ){
                l = mid;
            }
            else{
                r = mid - 1;
            }
        }

        return l;
    }
};


int main(){
    const char *s[] = {"WBBB",
 "BBBB",
 "BBBB",
 "BBBB"};

    vector<string> vs;
    int i;
    rep(i,sizeof(s)/sizeof(s[0])) vs.push_back(string(s[i]));

    Painting P;

    cout << P.largestBrush(vs) << endl;

}



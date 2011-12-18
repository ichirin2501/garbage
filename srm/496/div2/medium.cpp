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


class ColoredStrokes{
public:
    int getLeast(vector<string> picture){
        int h = picture.size();
        int w = picture[0].length();
        int i,j;
        int res = 0;
        
        // r
        rep(i,h){
            bool f = false;
            rep(j,w){
                if( picture[i][j] == 'R' || picture[i][j] == 'G' ){
                    if( !f ){
                        f = true;
                        res++;
                    }
                }
                else{
                    f = false;
                }
            }
        }

        // b is vertical
        rep(j,w){
            bool f = false;
            rep(i,h){
                if( picture[i][j] == 'B' || picture[i][j] == 'G' ){
                    if( !f ){
                        f = true;
                        res++;
                    }
                }
                else{
                    f = false;
                }
            }
        }

        return res;
    }
};



int main(){
    const char *s[] = {"GR",
                       "BG"};
    vector<string> vs;
    int i;
    rep(i,sizeof(s)/sizeof(s[0])) vs.push_back(string(s[i]));

    ColoredStrokes C;

    cout << C.getLeast(vs) << endl;

    return 0;
}

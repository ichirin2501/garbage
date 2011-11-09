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

bool used[64];

class TheLotteryBothDivs{
public:
    double find(vector <string> goodSuffixes){
        int n = goodSuffixes.size();
        int i,j;

        rep(i,n)if( !used[i] ){
            rep(j,n)if( i!=j && !used[j] ){
                int p = goodSuffixes[j].rfind(goodSuffixes[i]);
                if( p != -1 && goodSuffixes[j].length() - p == goodSuffixes[i].length() ){
                    used[j] = true;
                }
            }
        }

        double ret = 0.0;
        rep(i,n)if( !used[i] ){
            double tmp = 1.0;
            rep(j,goodSuffixes[i].length()) tmp *= 0.1;
            ret += tmp;
        }

        return ret;
    }
};

int main(){
    const char *s[] = {"47", "58", "4747", "502"};
    vector<string> good;
    int i;
    TheLotteryBothDivs T;

    for(i=0; i<sizeof(s)/sizeof(s[0]); i++) good.push_back(string(s[i]));

    printf("%lf\n",T.find(good));
    return 0;
}





















/*
//"000000000" to "999999999"
bool check[64];

bool cmp(const string& a, const string& b){
    return a.size() < b.size();
}
class TheLotteryBothDivs{
public:
    double find(vector <string> good){
        double ret = 0.0;
        sort(good.begin(), good.end(),cmp);
        rep(i,good.size()){
            if( check[i] )continue;
            REP(j,i+1,good.size()){
                if( check[j] )continue;
                int k;
                for(k=0; k<good[i].size(); k++){
                    if( good[j][good[j].size()-good[i].size()+k]!=good[i][k] )break;
                }
                if( k==good[i].size() ){
                    check[j] = true;
                }
            }
        }
        vector<string> vs;
        rep(i,good.size()){
            if( check[i] )continue;
            vs.pb(good[i]);
        }
        rep(i,vs.size()){
            double tmp = 1.0;
            rep(j,vs[i].size()){
                tmp *= 10.0;
            }
            ret += 1.0/tmp;
        }
        return ret;
    }
};

*/

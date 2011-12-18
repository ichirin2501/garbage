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

bool isd[10];
string memo[10000]; //文字列
int lenmemo[10000];

class MultiplesWithLimit{
public:
    string itos(int n){
        string res;
        do{
            res += n%10 + '0';
            n /= 10;
        }while( n>0 );
        reverse(all(res));
        return res;
    }
    string minMultiples(int N, vector <int> forbiddenDigits){
        int i;
        int n = forbiddenDigits.size();
        vector<int> ac;

        rep(i,n) isd[forbiddenDigits[i]] = true;
        rep(i,10) if( !isd[i] ) ac.push_back(i);

        queue<pair<int,string> > q;
        q.push(make_pair(0,""));
        int m = ac.size();

        while( !q.empty() ){
            int r = q.front().first;
            string s = q.front().second;

            q.pop();

            rep(i,m){
                int next = (10*r + ac[i]) % N;
                string tmp = s + string(1,ac[i] + '0');
                if( tmp == "0" ) continue;

                if( memo[next] == "" ){
                    if( tmp.length() >= 10 ){
                        tmp.erase(tmp.begin()+3, tmp.begin()+4);
                    }
                    q.push(make_pair(next, tmp));
                    memo[next] = tmp;
                    lenmemo[next] = lenmemo[r] + 1;
                    if( next == 0 ) goto end;
                }
            }
        }
    end:
        string res = memo[0];

        if( res == "" ) return "IMPOSSIBLE";
        if( res.length() < 9 ){
            return res;
        }else{
            int u = res.length();
            return res.substr(0,3) + "..." + res.substr(u-3) + "(" + itos(lenmemo[0]) + " digits)";
        }
    }
};



/*
bool isd[10];
map<int,string> memo; //<余り,最小の倍数>

bool cmp(string& a, string& b){
    if( a.length() == b.length() ){
        return a > b;
    }else{
        return a.length() > b.length();
    }
}

class MultiplesWithLimit{
public:
    string itos(int n){
        string res;
        do{
            res += n%10 + '0';
            n /= 10;
            //cout << "rr=" << res << endl;
        }while( n>0 );
        reverse(all(res));
        return res;
    }
    string minMultiples(int N, vector <int> forbiddenDigits){
        int i;
        int n = forbiddenDigits.size();
        vector<int> ac;

        rep(i,n) isd[forbiddenDigits[i]] = true;
        rep(i,10) if( !isd[i] ) ac.push_back(i);

        queue<pair<int,string> > q;
        q.push(make_pair(0,""));
        int m = ac.size();

        while( !q.empty() ){
            int r = q.front().first;
            string s = q.front().second;

            q.pop();

            rep(i,m){
                int next = (10*r + ac[i]) % N;
                string tmp = s + string(1,ac[i] + '0');
                if( tmp == "0" ) continue;

                if( memo[next] == "" || cmp(memo[next], tmp) ){ // > 
                    q.push(make_pair(next, tmp));
                    memo[next] = tmp;
                }
            }
        }

        string res = memo[0];

        if( res == "" ) return "IMPOSSIBLE";
        if( res.length() < 9 ){
            return res;
        }else{
            int u = res.length();
            return res.substr(0,3) + "..." + res.substr(u-3) + "(" + itos(u) + " digits)";
        }
    }
};
*/

int main(){
    int d[] = {0,2,3,4,5,6,7,8,9};
    vector<int> f;
    MultiplesWithLimit M;
    int i;
    rep(i,sizeof(d)/sizeof(d[0])) f.push_back(d[i]);

    cout << M.minMultiples(9973, f) << endl;

    return 0;
}


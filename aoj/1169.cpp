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

bool used[40];
string dp[40];
vector<pair<int,string> > edge[40];

int main(){
    int n,a,s,g,i,j,k;

    while( cin >> n >> a >> s >> g, n|a|s|g ){

        rep(i,40) dp[i] = "";
        rep(i,40) edge[i].clear();
        memset(used, false, sizeof(used));

        rep(i,a){
            int x,y; string lab; cin >> x >> y >> lab;
            edge[y].push_back(make_pair(x,lab)); // 反対にする
        }

        used[g] = true;
        bool loop = false;

        rep(i,260){
            bool flag = false;

            rep(j,n) if( used[j] ) { // j -> u
                string str = dp[j];

                rep(k,edge[j].size()){
                    int u = edge[j][k].first;
                    string& lab = edge[j][k].second;
                    if( dp[u] == "" || dp[u] > lab + str ){
                        used[u] = true;
                        dp[u] = lab + str;
                        flag = true;
                        if( u == s && i >= n-1 ){
                            loop = true;
                            break;
                        }
                    }
                }
                if( loop ) break;
            }

            if( !flag || loop ) break;
        }

        if( loop || dp[s] == "" ){
            puts("NO");
        }
        else{
            cout << dp[s] << endl;
        }
    }

    return 0;
}


/*
  goal -> start で調べる。
  最悪でもn-1回で解は出る
  n回目以上の処理時にdp[start]の最小が更新された場合はループに入ってると判断できる
  答えの文字は最長でも260文字だから、260回調べれば確実。
 */

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
#include <sstream>
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)


vector<int> edge[66];
bool used[66];
int match[66];

void add_edge(int u, int v){
    edge[u].push_back(v);
    edge[v].push_back(u);
}

bool dfs(int u){
    int i;
    used[u] = true;
    for(i=0; i<edge[u].size(); i++){
        int v = edge[u][i];
        int w = match[v];
        if( w == -1 || (!used[w] && dfs(w)) ){
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}

bool b_match(const vector<string>& rows, const vector<string>& columns){
    int i,j,k;
    int res = 0;
    int h = rows.size();
    int w = columns.size();

    // make edge
    for(i=0; i<2*w; i++) edge[i].clear();
    for(i=0; i<w; i++){
        for(j=0; j<w; j++){
            for(k=0; k<h; k++){
                if( !(rows[k][i] == columns[j][k] || rows[k][i] == '?' ||
                      columns[j][k] == '?') ){
                    break;
                }
            }
            if( k == h ){
                add_edge(i,w+j);
            }
        }
    }

    memset(match, -1, sizeof(match));
    for(i=0; i<w; i++){
        memset(used, false, sizeof(used));
        if( dfs(i) ) res++;
    }

    return res == w;
}

class P8XMatrixRecovery{
public:
    vector <string> solve(vector <string> rows, vector <string> columns){
        int i,j,k;
        int h = rows.size();
        int w = rows[0].length();

        for(i=0; i<h; i++){
            for(j=0; j<w; j++){
                if( rows[i][j] == '?' ){
                    rows[i][j] = '0';
                    if( !b_match(rows, columns) ) rows[i][j] = '1';
                }
            }
        }

        return rows;
    }
};


int main(){
    P8XMatrixRecovery P;
    vector<string> r,c;
    int i,j,k;
    const char *s1[] = {"??0"
,"11?"
,"?01"
,"1?1"};
    const char *s2[] = {"1???"
,"?111"
,"0?1?"};

    rep(i,sizeof(s1)/sizeof(s1[0])){
        r.push_back(string(s1[i]));
    }
    rep(i,sizeof(s2)/sizeof(s2[0])){
        c.push_back(string(s2[i]));
    }

    vector<string> res = P.solve(r, c);


    puts("answer");
    rep(i,res.size()){
        cout << res[i] << endl;
    }
    return 0;
}

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

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

class AlphabetPath{
public:
    string doesItExist(vector<string> letterMaze){
        int i,j,sx,sy,k;
        int h = letterMaze.size();
        int w = letterMaze[0].length();

        rep(i,h) rep(j,w) if( letterMaze[i][j] == 'A' ){
            sx = j;
            sy = i;
        }

        REP(i,1,26){
            bool ok = false;
            rep(k,4){
                int tx = sx + dx[k];
                int ty = sy + dy[k];
                if( tx < 0 || ty >= h || tx >= w || ty < 0 || letterMaze[ty][tx] == '.' ) continue;
                if( 'A'+i == letterMaze[ty][tx] ){
                    sx = tx, sy = ty;
                    ok = true;
                    break;
                }
            }
            if( !ok ) break;
        }
        
        return i == 26 ? "YES" : "NO";
    }
};

int main(){
    const char *s[] = {"..............",
 "..............",
 "..............",
 "...DEFGHIJK...",
 "...C......L...",
 "...B......M...",
 "...A......N...",
 "..........O...",
 "..ZY..TSRQP...",
 "...XWVU.......",
                       ".............."};


    vector<string> ss;
    int i,j;

    rep(i,sizeof(s)/sizeof(s[0])) ss.push_back(string(s[i]));

    AlphabetPath A;
    cout << A.doesItExist(ss) << endl;

    return 0;
}

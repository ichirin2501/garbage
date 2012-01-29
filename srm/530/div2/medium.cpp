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

class GogoXCake{
public:
    bool isok(int x, int y, vector<string>& cake, const vector<string>& cutter){
        int cw = cake[0].length(), ch = cake.size();
        int tw = cutter[0].length(), th = cutter.size();
        int i,j,sx;

        for(i=0; i<tw; i++) if( cutter[0][i] == '.' ) break;
        sx = i;

        rep(i,th){
            rep(j,tw){
                if( y + i >= ch || x + j - sx >= cw || x + j - sx < 0 ) return false;
                if( cutter[i][j] == '.' ){
                    if( cake[y + i][x + j - sx] == '.' ){
                        cake[y + i][x + j - sx] = 'X';
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        return true;
    }

    string solve(vector <string> cake, vector <string> cutter){
        int cw = cake[0].length(), ch = cake.size();
        int i,j;

        rep(i,ch){
            rep(j,cw){
                if( cake[i][j] == '.' ){
                    if( !isok(j,i,cake,cutter) ) return "NO";
                }
            }
        }

        return "YES";
    }

};

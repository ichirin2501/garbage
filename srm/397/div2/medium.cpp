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



class SortingGame{
public:
    int fewestMoves(vector <int> board, int k){
        int i, n = board.size();
        map<vector<int>, int> memo;
        queue<vector<int> > q;
        
        q.push(board);
        memo[board] = 0;

        while( !q.empty() ){
            vector<int> now = q.front();
            int step = memo[now];
            q.pop();

            // check
            for(i=0; i<n; i++) if( now[i] != i + 1 ) break;
            if( i == n ) return step;

            for(i=0; i+k<=n; i++){
                vector<int> tmp = now;
                reverse(tmp.begin() + i, tmp.begin() + i + k);
                if( memo.count(tmp) == 0 ){
                    memo[tmp] = step + 1;
                    q.push(tmp);
                }
            }
        }
        return -1;
    }
};


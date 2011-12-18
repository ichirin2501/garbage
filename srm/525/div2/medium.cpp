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

// 最大で 3ms
class DropCoins{
public:
    int getMinimum(vector <string> board, int K){
        int i,j,k;
        int h = board.size();
        int w = board[0].length();
        int res = INT_MAX;
        int p[50];
        
        rep(k,h){
            // init
            rep(i,w) p[i] = 0;
            
            REP(i,k,h){
                int sum = 0, prev = 0;
                rep(j,w){

                    p[j] += (board[i][j] == 'o');
                    sum += p[j];

                    while( sum > K ){
                        sum -= p[prev];
                        prev++;
                    }
                    if( sum == K ){
                        int cost = max(k, h-i-1) + 2*min(k, h-i-1) +
                            max(prev, w-j-1) + 2*min(prev, w-j-1);
                        res = min(res, cost);
                    }
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};


// O(n^4) だと 最大7ms
/*
int sum[50][50];

class DropCoins{
public:
    int getMinimum(vector <string> board, int K){
        int i,j,ii,jj;
        int h = board.size();
        int w = board[0].length();
        int res = INT_MAX;

        rep(i,h){
            rep(j,w){
                sum[i+1][j+1] += sum[i+1][j] + sum[i][j+1] - sum[i][j] + (board[i][j] == 'o');
            }
        }

        REP(i,1,h+1){
            REP(j,1,w+1){
                REP(ii,i,h+1){
                    REP(jj,j,w+1){
                        int tmp = sum[ii][jj] + sum[i-1][j-1] - sum[i-1][jj] - sum[ii][j-1];
                        if( tmp == K ){
                            int cost = max(i-1, h-ii) + 2*min(i-1, h-ii) +
                                max(j-1, w-jj) + 2*min(j-1, w-jj);
                            res = min(res, cost);
                        }
                    }
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};
*/

/*
// O(n^6)
class DropCoins{
public:
    int getMinimum(vector <string> board, int K){
        int i,j,ii,jj,u,v,x,y;
        int h = board.size();
        int w = board[0].length();
        int res = INT_MAX;
        vector<pair<int,int> > I,J;

        rep(i,h){
            rep(j,w){
                REP(ii,i,h){
                    REP(jj,j,w){
                        I.clear(), J.clear();
                        I.push_back(make_pair(0,i));
                        I.push_back(make_pair(i,ii));
                        I.push_back(make_pair(ii,h));
                        J.push_back(make_pair(0,j));
                        J.push_back(make_pair(j,jj));
                        J.push_back(make_pair(jj,w));

                        rep(u,3){
                            rep(v,3){
                                int cnt = 0;
                                for(y=I[u].first; y<I[u].second; y++){
                                    for(x=J[v].first; x<J[v].second; x++){
                                        if( board[y][x] == 'o' ) cnt++;
                                    }
                                }

                                if( cnt == K ){
                                    int tmp = max(I[u].first,h-I[u].second) +
                                        2*min(I[u].first, h-I[u].second) +
                                        max(J[v].first,w-J[v].second) +
                                        2*min(J[v].first, w-J[v].second);
                                    //printf("tmp = %d\n",tmp);
                                    res = min(res,tmp);
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return res == INT_MAX ? -1 : res;
    }
};
*/

int main(){
    const char *s[] = {"o"};

    vector<string> v;
    int i;
    rep(i,sizeof(s)/sizeof(s[0])) v.push_back(string(s[i]));

    // 26
    DropCoins D;
   
    cout << D.getMinimum(v, 1) << endl;

    return 0;
}

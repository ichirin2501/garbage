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

bool cmp(const pair<int,int>& a, const pair<int,int>& b){
    if( a.second == b.second ) return a.first < b.first;
    return a.second < b.second;
}

class DucksAlignment{
public:
    int minimumTime(vector <string> grid){
        int i,j,k,u;
        int h = grid.size();
        int w = grid[0].length();
        vector<pair<int,int> > ducks;
        int res = INT_MAX;
        
        rep(i,h){
            rep(j,w){
                if( grid[i][j] == 'o' ){
                    ducks.push_back(make_pair(j,i));
                }
            }
        }
        int ds = ducks.size();

        // tate
        sort(all(ducks));
        rep(i,h){
            rep(j,w-ds+1){
                int sum = 0;
                rep(u,ds){
                    int x = j + u;
                    int y = i;
                    sum += abs(ducks[u].first - x) + abs(ducks[u].second - y);
                }
                res = min(res, sum);
            }
        }

        sort(all(ducks),cmp);
        rep(i,h-ds+1){ // tate
            rep(j,w){
                int sum = 0;
                rep(u,ds){
                    int x = j;
                    int y = i + u;
                    sum += abs(ducks[u].first - x) + abs(ducks[u].second - y);
                }
                res = min(res, sum);
            }
        }
        
        return res;
    }
};

/*
  移動先のマスにアヒルが居ても移動できることに注意。
  適当な座標を決めて、縦と横のラインを調べてやればいい。
  アヒルを基準に考えると、ラインに詰めるが面倒そう。
  ラインの各マスには順にそのマスから一番近い場所にいるアヒルに
  対応させればいいかな？
  だめでした。
  x..o...
  x.....o
  xo.....
  例えば、xのラインにアヒルを揃えたいとき、
  マスを基準に一番近いアヒルを決めていくと、
  (0,0)には、(0,3)のアヒル、コスト3
  (0,1)には、(2,1)のアヒル、コスト2
  (0,2)には、(1,6)のアヒル、コスト7
  という計算になってしまう。
  最小重み2部マッチングでも解けそう。でも、mediumでそれはないｗ
  縦のラインで調べるときは、アヒルをy軸でソートさせたもの、
  横のラインで調べるときは、アヒルをx軸でソートさせたもの、
  を各マスに順に割り当てれば良さそう？
  サンプル通ったので提出、system test passed.
  どうしてソートで対応させて良いのか、という証明ができなかった。
  ので、Editorialsを見た。
  各軸で分けて考えるのか、なるほど。
  ソート云々は結果的にうまくいった感じ…だめだめだ。
 */

int main(){
    const char *s[] = {"...o..........................",
                       "............................o.",
                       ".o............................",
                       "............o.................",
                       ".................o............",
                       "......................o.......",
                       "......o.......................",
                       "....o.........................",
                       "...............o..............",
                       ".......................o......",
                       "...........................o..",
                       ".......o......................"};
    vector<string> vs;
    int i;
    rep(i,sizeof(s)/sizeof(s[0])) vs.push_back(string(s[i]));

    DucksAlignment D;

    cout << D.minimumTime(vs) << endl;


    return 0;
}

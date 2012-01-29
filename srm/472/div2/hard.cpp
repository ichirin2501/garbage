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


// YET_SYSTEM_TEST

double xp[5010][1010], yp[5010][1010];
double sxp[5010], syp[5010];

class RectangularIsland{
public:
    double theProbablity(int width, int height, int x, int y, int steps){
        int i,j;

        xp[0][x] = yp[0][y] = 1.0;
        REP(i,1,steps+1){
            rep(j,width){
                if( j > 0 ) xp[i][j-1] += xp[i-1][j] * 0.25;
                if( j < width - 1 ) xp[i][j+1] += xp[i-1][j] * 0.25;
            }
            rep(j,height){
                if( j > 0 ) yp[i][j-1] += yp[i-1][j] * 0.25;
                if( j < height - 1 ) yp[i][j+1] += yp[i-1][j] * 0.25;
            }
        }

        rep(i,height){
            printf("%d : %lf\n",i,yp[1][i]);
        }

        // 移動回数毎に生きてる確率を求める
        rep(i,steps+1){
            rep(j,width) sxp[i] += xp[i][j];
            rep(j,height) syp[i] += yp[i][j];
        }
        puts("");
        rep(i,steps+1){
            printf("%d : %lf\n",i,syp[i]);
        }

        double ret = 0.0;
        rep(i,steps+1){
            ret += sxp[i] * syp[steps-i];
            if( i == steps - i ) ret += sxp[i] * syp[steps-i];
            printf("[%d] = %lf  * [%d] = %lf\n",i,sxp[i],steps-i,syp[steps-i]);
        }

        return ret;
    }
};

int main(){
    RectangularIsland R;

    //printf("%.20lf\n", R.theProbablity(5,8,4,3,1));
    printf("%.20lf\n", R.theProbablity(2,2,0,1,5));
    /*
      s.
      ..
     */
    return 0;
}


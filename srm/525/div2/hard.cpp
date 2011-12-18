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

/*
  
  row[a].substr(c,z) == col[b].substr(d,z)
  ok[z][a][c][b][d]

  row[0]の文字列を2ヶ所で区切ると、3列になる
  abc|def|gh
  1箇所目をi, 2箇所目をjとすると
  col[0].substr(0,i)   == row[0].substr(0,i)
  col[1].substr(0,j-i) == row[0].substr(i,j-i)
  col[2].substr(0,r0-j)== row[0].substr(j)
  
  ok[i][0][0][0][0] && ok[j-i][0][i][1][0] && ok[r0-j][0][j][2][0]
  と対応することがわかる
  
  同様にrow[1]の文字列を2ヶ所で区切ると、3列になる
  ABC|DEF|GH
  1箇所目をi2, 2箇所目をj2とすると
  col[0].substr(i,i2)       == row[1].substr(0,i2)
  col[1].substr(j-i, j2-i2) == row[1].substr(i2, j2-i2)
  col[2].substr(r0-j, r1-j2)== row[1].substr(j2)

  ok[i2][1][0][0][i] && ok[j2-i2][1][i2][1][j-i] && ok[r1-j2][1][j2][2][r0-j]
  と対応することがわかる

  最後に、
  col[0].substr(i+i2)        == row[2].substr(0,c0-(i+i2))
  col[1].substr(j-i+j2-i2)   == row[2].substr(c0-(i+i2), c1-(j-i+j2-i2))
  col[2].substr(r0-j+r1-j2)  == row[2].substr(c1-(j-i+j2-i2) + c0-(i+i2), c2-(r0-j+r1-j2))

  ok[c0-(i+i2)][2][0][0][i+i2] && ok[c1-(j-i+j2-i2)][2][c0-(i+i2)][1][j-i+j2-i2]
  && ok[c2-(r0-j+r1-j2)][2][c1-(j-i+j2-i2) + c0-(i+i2)][2][r0-j+r1-j2]

 */

bool ok[55][3][55][3][55];

class MagicalSquare{
public:

    long long getCount(vector <string> rowStrings, vector <string> columnStrings){
        int a,b,c,d,z, i,j,i2,j2;
        long long ret = 0;

        for(a=0; a<3; a++){
            for(b=0; b<3; b++){
                for(z=0; z<=50; z++){
                    for(c=0; c<=(int)rowStrings[a].length()-z; c++){
                        for(d=0; d<=(int)columnStrings[b].length()-z; d++){
                            ok[z][a][c][b][d] = 
                                (rowStrings[a].substr(c,z) == columnStrings[b].substr(d,z));
                        }
                    }
                }
            }
        }

        int r0 = rowStrings[0].length();
        int r1 = rowStrings[1].length();
        int r2 = rowStrings[2].length();
        int c0 = columnStrings[0].length();
        int c1 = columnStrings[1].length();
        int c2 = columnStrings[2].length();

        for(i=0; i<=r0; i++){
            for(j=i; j<=r0; j++){
                for(i2=0; i2<=r1; i2++){
                    for(j2=i2; j2<=r1; j2++){

                        if( !(ok[i][0][0][0][0] && ok[j-i][0][i][1][0] && ok[r0-j][0][j][2][0]) )
                            continue;

                        if( !(ok[i2][1][0][0][i] && ok[j2-i2][1][i2][1][j-i] && ok[r1-j2][1][j2][2][r0-j]) )
                            continue;

                        if( r2 - (c1-(j-i+j2-i2)+c0-(i+i2)) != c2 - (r0-j+r1-j2) )
                            continue;
                        
                        if( !(ok[c0-(i+i2)][2][0][0][i+i2] && ok[c1-(j-i+j2-i2)][2][c0-(i+i2)][1][j-i+j2-i2] &&
                              ok[c2-(r0-j+r1-j2)][2][c1-(j-i+j2-i2)+c0-(i+i2)][2][r0-j+r1-j2]) )
                            continue;

                        ret++;
                    }
                }
            }
        }
            


        return ret;

    }
};


int main(){
    const char *s1[] = {"xx", "xx", "xx"};
    const char *s2[] = {"xxx", "xx", "xx"};
    vector<string> r,c;
    int i;
    rep(i,sizeof(s1)/sizeof(s1[0])){
        r.push_back(string(s1[i]));
        c.push_back(string(s2[i]));
    }

    MagicalSquare M;

    cout << M.getCount(r,c) << endl;
    
    return 0;
}

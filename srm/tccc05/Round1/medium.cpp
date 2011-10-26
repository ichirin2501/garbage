#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

long double board[8][8];
long double tmp[8][8];

class ChessKnight{
public:
    void move(int x, int y){
        static const int dx[] = {1,2,2,1,-1,-2,-2,-1};
        static const int dy[] = {-2,-1,1,2,2,1,-1,-2};

        int k;
        for(k=0; k<8; k++){
            int tx = x + dx[k];
            int ty = y + dy[k];
            if( tx<0 || tx>=8 || ty>=8 || ty<0 ) continue;
            tmp[ty][tx] += board[y][x] / 8.0;
        }
    }

    double probability(int x, int y, int n){
        int i,j,k;
        
        memset(board,0,sizeof(board));

        board[y-1][x-1] = 1.0;

        for(k=0; k<n; k++){

            memset(tmp, 0, sizeof(tmp));

            for(i=0; i<8; i++){
                for(j=0; j<8; j++){
                    move(j, i);
                }
            }

            // copy
            for(i=0; i<8; i++){
                for(j=0; j<8; j++){
                    board[i][j] = tmp[i][j];
                }
            }
        }

        // sum
        long double ret = 0.0;
        for(i=0; i<8; i++){
            for(j=0; j<8; j++){
                ret += board[i][j];
            }
        }

        return (double)ret;
    }
};


int main(){
    ChessKnight C;
    printf("%.20lf\n",C.probability(4,3,50));

    return 0;
}

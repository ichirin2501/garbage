#include <iostream>
#include <string>
#include <cstdio>
using namespace std;


class RotatedClock{
public:
    string getEarliest(int hourHand, int minuteHand){
        int i,j,k;
        
        for(i=0; i<12; i++){ // hour
            for(j=0; j<60; j+=2){ // minute

                int h = 30*i + j/2;
                int m = 6*j;
                for(k=0; k<360; k+=30){

                    //printf("%d , %d\n",(h+k)%360, (m+k)%360);

                    if( (h+k)%360 == hourHand && (m+k)%360 == minuteHand ){

                        printf("%d = %d,  %d = %d   k=%d\n",i,h,j,m,k);

                        char buf[8];
                        sprintf(buf, "%02d:%02d", i, j);
                        return string(buf);
                    }
                }
            }
        }
        
        return "";
    }
};


/*
  1時間 = 360/12 = 30度 = 5メモリ
  1メモリ辺り、6度
  12分進むと短針が1メモリ
  長針が何分動いたら短針が1度進むのか？
  12:6 = x:1
  x = 2
  つまり、2分経過すると短針は1度進む
  あとは全探索
  
  解答なしのサンプルが合わない。
  む、ここで問題を勘違いしてることに気付く
  19,19で解なし、ってどういうことだ
  同じ角度なんだから、回転すれば00:00が答えだと思うのだけど
  
  240, 36のとき、角度の差は204度
  9時12分のとき、短針は270+6度
  長針は72度で、差は204度
  あれ、答えが存在してる気がするのだが？…
  んんー、問題解釈間違えてる？
  30度ずつ回転して確かめるように書いたら通った。
  The clock has a scale marked in 30 degree increments , 
  and both hands point to the same mark at 00:00 .
  この英文に30度ずつ回転するって意味があるのか？
  英語ワカラン
 */


int main(){
    RotatedClock R;

    //cout << R.getEarliest(19, 19) << endl;
    //cout << R.getEarliest(1, 12) << endl;
    cout << R.getEarliest(240, 36) << endl;
    return 0;
}

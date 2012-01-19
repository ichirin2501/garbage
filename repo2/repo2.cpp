#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <set>
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define DEB 0

void input();
void output();

/*
  問題概要
  0,1から成るグリッドが与えられる。
  ある'1'のマスに注目したとき、そのマスを含む最大面積の長方形を出力する。
  同じ位置の長方形は2度出力しない。
  '1'のマスは1回以上、出力されるいずれかの長方形に含まれていなければならない。

  入力形式について
  最初の行にはテストケースの個数が与えられる。
  次から、高さと幅、続いてフィールド情報がテストケースの数だけ与えられる。
  TestCase
  H W
  x_{0,0} x_{0,1} x_{0,2} ... x_{0,W-1}
  x_{1,0} x_{1,1} x_{1,2} ... x_{1,W-1}
  ...
  x_{H-1,0} ...


  アルゴリズム
  左上から'1'のマスを長方形の左上のマスと定めて、
  そのマスを含む長方形を調べる。

  起点を含むブロックの高さを h とする
  次のブロックh'がhより大きい場合は、高さhのまま面積を計算
  次のブロックh'がhより小さい場合は、高さをh'に更新して面積を計算
  次のブロックの高さが0になったら終了

  必要な情報は、最大面積と、起点と、縦横

  出力処理について
  各マスに保存した 情報{(幅,高さ), 起点(x,y)} について、重複なしの集合を求める
  C言語だとちょっと面倒だなー
  テスト段階だし、set使うかｗ

  残念ながら計算量は N^5
  定数倍の高速化ならまだ十分余地がある
  定数倍高速化を頑張るとする。
  1. 擬似ヒストグラムのメモ化
  2. ヒストグラムの高さが低くなる時だけ処理すればいい
 */

#define N 100

typedef struct _Info{
    int x,y,w,h,S;
} Info;

char field[N][N+1];
Info cells[N][N];
int H,W;
int hist[N][N+1];

int main(){
    int i,j,k,t,u,v,z,i2,j2;
    int TestCase;

    scanf("%d", &TestCase);

    rep(t,TestCase){
        printf("Case %d#\n", t+1);

        memset(cells, -1, sizeof(cells));
        memset(hist, 0, sizeof(hist));
        input();

        // 擬似ヒストグラム
        rep(i,H){
            rep(j,W){
                if( field[i][j] == '0' ) continue;

                rep(k,H) if( field[(i+k)%H][j] == '0' ) break;
                hist[i][j] = k;
            }
        }

        rep(i,H){
            rep(j,W){
                if( field[i][j] == '1' ){

                    int height = 0;
                    rep(u,W+1){
                        v = (u == W ? 0 : hist[i][(j+u)%W]);

                        if( u == 0 ){
                            height = v; continue;
                        }

                        if( height > v ){
                            // 長方形に含まれる各セルの情報を更新
                            rep(i2, height){
                                rep(j2, u){ // u+1
                                    int x = (j + j2) % W;
                                    int y = (i + i2) % H;
                                    if( cells[y][x].S < height * u ){
                                        cells[y][x].x = j; cells[y][x].y = i;
                                        cells[y][x].w = u;
                                        cells[y][x].h = height;
                                        cells[y][x].S = height * u;
                                    }
                                }
                            }
                            height = v;
                        }
                        if( height == 0 ) break;
                    }
                }
            }
        }
        output();
    }

    return 0;
}


void output(){
    int i,j;
    char out[N][N];

    set<pair<pair<int,int>, pair<int,int> > > sp;
    rep(i,H){
        rep(j,W){
            pair<int,int> pa(cells[i][j].x, cells[i][j].y);
            pair<int,int> pb(cells[i][j].w, cells[i][j].h);

            sp.insert(make_pair(pa,pb));
        }
    }

    foreach(it,sp){
        int x,y,w,h;
        x = it->first.first; y = it->first.second;
        w = it->second.first; h = it->second.second;

        if( x == -1 || y == -1 ) continue;

        memset(out, '0', sizeof(out));
        rep(i,h){
            rep(j,w){
                out[(y + i)%H][(x + j)%W] = '1';
            }
        }

        rep(i,H){
            rep(j,W){
                printf("%c", out[i][j]);
            }
            puts("");
        }
        puts("");
    }
}

void input(){
    int i,j;
    scanf("%d %d",&H,&W);

    if( H > N || W > N ){
        printf("error : H <= %d , W <= %d\n", N, N);
        exit(0);
    }

    rep(i,H) scanf("%s", field[i]);

    // 0,1 only check
    rep(i,H){
        if( strlen(field[i]) != W ){
            printf("error : グリッドの幅が正しい入力ではありません\n");
            exit(0);
        }
        rep(j,W){
            if( !(field[i][j] == '0' || field[i][j] == '1') ){
                printf("error : 0,1以外の文字が含まれています\n");
                exit(0);
            }
        }
    }
}

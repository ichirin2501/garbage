#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

/*
  AOJ :: 0110
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0110
 */

char in[3][130];

bool iseq(){
    int tmp[130];
    int na = strlen(in[0]), nb = strlen(in[1]), nc = strlen(in[2]);
    int i;

    memset(tmp, 0, sizeof(tmp));
    for(i=0; i<na; i++) tmp[i] += in[0][na-i-1] - '0';
    for(i=0; i<nb; i++) tmp[i] += in[1][nb-i-1] - '0';
    for(i=1; i<130; i++){
        tmp[i] += tmp[i-1] / 10;
        tmp[i-1] %= 10;
    }

    for(i=0; i<nc; i++){
        if( tmp[i] != in[2][nc-i-1] - '0' ) return false;
    }
    for(; i<130; i++) if( tmp[i] != 0 ) return false;
    return true;
}

bool ischeck(int n, int p, int num){
    int i;
    bool res = false;

    if( n == 3 ){ // end
        return iseq();
    }

    if( in[n][p] == '\0' ){ // next str
        return ischeck(n+1, 0, num);
    }

    if( in[n][p] == 'X' ){
        if( p == 0 && num == 0 && strlen(in[n]) > 1 ) return false;
        in[n][p] = num + '0';
        res = ischeck(n, p+1, num);
        in[n][p] = 'X';
    }
    else{
        res = ischeck(n, p+1, num);
    }
    return res;
}

int main(){
    int num;

    while( ~scanf(" %[^+]+%[^=]=%s ", in[0], in[1], in[2]) ){
        for(num=0; num<=9; num++){
            if( ischeck(0, 0, num) ) break;
        }
        if( num > 9 ){
            puts("NA");
        }
        else{
            printf("%d\n",num);
        }
    }

    return 0;
}

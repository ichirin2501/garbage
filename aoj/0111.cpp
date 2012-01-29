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

map<string,char> btos;

void init(){
    btos["101"] = ' ';
    btos["000000"] = '\'';
    btos["000011"] = ',';
    btos["10010001"] = '-';
    btos["010001"] = '.';
    btos["000001"] = '?';
    btos["100101"] = 'A';
    btos["10011010"] = 'B';
    btos["0101"] = 'C';
    btos["0001"] = 'D';
    btos["110"] = 'E';
    btos["01001"] = 'F';
    btos["10011011"] = 'G';
    btos["010000"] = 'H';
    btos["0111"] = 'I';
    btos["10011000"] = 'J';
    btos["0110"] = 'K';
    btos["00100"] = 'L';
    btos["10011001"] = 'M';
    btos["10011110"] = 'N';
    btos["00101"] = 'O';
    btos["111"] = 'P';
    btos["10011111"] = 'Q';
    btos["1000"] = 'R';
    btos["00110"] = 'S';
    btos["00111"] = 'T';
    btos["10011100"] = 'U';
    btos["10011101"] = 'V';
    btos["000010"] = 'W';
    btos["10010010"] = 'X';
    btos["10010011"] = 'Y';
    btos["10010000"] = 'Z';
}

string ctob(char c){
    int n = ('A'<=c && c<='Z' ? c - 'A' : c==' ' ? 26 : c=='.' ? 27 : c==',' ? 28 :
             c=='-' ? 29 : c=='\'' ? 30 : 31);
    string res = "00000";
    int i = 0;
    //printf("c=%c, n=%d\n",c,n);
    while( n > 0 ){
        res[i++] = n % 2 + '0';
        n /= 2;
    }
    reverse(all(res));
    return res;
}

int main(){
    int i,j;
    string in;

    init();

    while( getline(cin,in) ){
        string bin,res;

        rep(i,in.size()){
            bin += ctob(in[i]);
        }

        int base = 0;
        for(i=0; i+base<bin.length()+1; ){
            string tmp = bin.substr(base, i);
            if( btos.count(tmp) ){
                res += btos[tmp];
                base += tmp.length();
                i = 1;
            }
            else{
                i++;
            }
            //printf("base=%d, i=%d, tmp=%s\n",base,i,tmp.c_str());
        }

        cout << res << endl;
    }

    return 0;
}

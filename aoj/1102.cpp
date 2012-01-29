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
#include <complex>
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)

typedef complex<int> term;

bool overflow;

bool isnumber(const string& str){
    int i;
    for(i=0; i<str.length(); i++) if( !('0' <= str[i] && str[i] <= '9') ) return false;
    return true;
}

term parse(string str){
    int i,j, n = str.length();
    int x = 0;

    //cout << str << endl;
    if( str.length() == 0 ) return term(0,0);

    for(i=n-1; i>=0; i--){
        if( str[i] == '(' ) x++;
        if( str[i] == ')' ) x--;
        if( x == 0 && (str[i] == '+' || str[i] == '-') ){
            break;
        }
    }

    if( i == -1 ){
        x = 0;
        for(i=n-1; i>=0; i--){
            if( str[i] == '(' ) x++;
            if( str[i] == ')' ) x--;
            if( x == 0 && str[i] == '*' ){
                break;
            }
        }

        if( i == -1 ){
            if( isnumber(str) ){
                int res = 0;
                for(j=0; j<n; j++){
                    res = 10*res + (str[j] - '0');
                    if( res > 10000 ){
                        overflow = true;
                        break;
                    }
                }
                //printf("res = %d\n",res);
                return term(res,0);
            }
            if( str.length() == 1 && str[0] == 'i' ){
                return term(0,1);
            }
            return parse(str.substr(1,str.length()-2));
        }
    }

    term c;
    term a = parse(str.substr(0,i)), b = parse(str.substr(i+1));
    if( str[i] == '-' ) c = a - b;
    if( str[i] == '+' ) c = a + b;
    if( str[i] == '*' ) c = a * b;

    if( abs(c.real()) > 10000 || abs(c.imag()) > 10000 ) overflow = true;
    return c;
}


int main(){
    string in;

    while( cin >> in ){
        overflow = false;
        term res = parse(in);

        if( overflow ){
            puts("overflow");
        }
        else{
            if( res.imag() == 0 ){
                printf("%d\n",res.real());
            }
            else if( res.real() == 0 ){
                printf("%di\n",res.imag());
            }
            else{
                printf("%d%+di\n",res.real(),res.imag());
            }
        }
    }

    return 0;
}

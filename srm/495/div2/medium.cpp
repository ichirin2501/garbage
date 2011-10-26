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
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)

int mi[64], ma[64];

class ColorfulCards{
public:
    bool isprime(int n){
        int i;
        for(i=2; i*i<=n; i++) if( n%i==0 ) return false;
        return n>1;
    }

    vector <int> theCards(int N, string colors){
        int n = colors.length();
        int i,j;

        j = 0;
        for(i=1; i<=N; i++){ //mi
            if( isprime(i) ){
                if( colors[j]=='R' ) mi[j++] = i;
            }
            else{
                if( colors[j]=='B' ) mi[j++] = i;
            }
            if( n==j ) break;
        }


        j = n-1;
        for(i=N; i>=0; i--){
            if( isprime(i) ){
                if( colors[j]=='R' ) ma[j--] = i;
            }
            else{
                if( colors[j]=='B' ) ma[j--] = i;
            }
            if( j<0 ) break;
        }

        // check
        vector<int> ret;
        
        rep(i,n){
            if( ma[i] == mi[i] ){
                ret.push_back(ma[i]);
            }
            else{
                ret.push_back(-1);
            }
        }

        return ret;
    }
};

int main(){
    ColorfulCards C;
    vector<int> ret;
    ret = C.theCards(5,"RRR");

    int i;
    rep(i,ret.size()){
        cout << ret[i] << endl;
    }
    return 0;
}




























/*
vector<int> primes;
bool check[1024];

void make_prime(int n){
  check[0]=check[1]=true;
  for(int i=2; i*i<=n; i++){
    for(int j=i*2; j<=n; j+=i){
      check[j] = true;
    }
  }
  for(int i=1; i<=n; i++){
    if( !check[i] ){
      primes.push_back(i);
    }
  }
}
bool isprime(int n){
  if( n<2 ) return false;
  for(int i=2; i*i<=n; i++){
    if( n%i==0 ) return false;
  }
  return true;
}


class ColorfulCards{
public:
  
  vector <int> theCards(int N, string colors){
    vector<int> tmp1,tmp2;

    make_prime(N);

    int p = 0;
    int s = 1;
    int prev = 0;
    rep(i,colors.size()){
      if( colors[i]=='R' ){
	for(; p<primes.size() && primes[p]<prev; p++);
	tmp1.push_back(primes[p]);
	prev = primes[p];
	p++;
      }else{
	for(; s<prev || isprime(s); s++);
	tmp1.push_back(s);
	prev = s;
	s++;
      }
    }
#if DEB
    puts("tmp1");
    rep(i,tmp1.size()){
      printf("%d,",tmp1[i]);
    }
    puts("");
#endif

    p = primes.size()-1;
    s = N;
    prev = N+1;
    for(int i=colors.size()-1; i>=0; i--){
      if( colors[i]=='R' ){
	for(; p>=0 && primes[p]>prev; p--);
	tmp2.push_back(primes[p]);
	prev = primes[p];
	p--;
      }else{
	for(; s>prev || isprime(s); s--);
	tmp2.push_back(s);
	prev = s;
	s--;
      }
    }
    reverse(tmp2.begin(), tmp2.end());

#if DEB
    puts("tmp2");
    rep(i,tmp2.size()){
      printf("%d,",tmp2[i]);
    }
    puts("");
#endif


    rep(i,tmp1.size()){
      if( tmp1[i]!=tmp2[i] ){
	tmp1[i] = -1;
      }
    }
    return tmp1;
  }
};
 */

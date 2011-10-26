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

typedef long long ll;

class FactoVisors{
public:
    ll gcd(ll x, ll y){
        return y ? gcd(y,x%y) : x;
    }
    ll lcd(ll x, ll y){
        return x*y/gcd(x,y);
    }
    int getNum(vector <int> divisors, vector <int> multiples){
        ll g = multiples[0];
        int i,j;

        for(i=1; i<multiples.size(); i++) g = gcd(g, multiples[i]);

        ll d = divisors[0];
        
        for(i=1; i<divisors.size(); i++){
            d = lcd(d, divisors[i]);
            if( d > 1000000000 ) return 0;
        }

        return (int)(g/d);
    }
};






























/*
lass FactoVisors{
public:
	int gcd(int x, int y){
		return y ? gcd(y,x%y) : x;
	}
	long long lcm(int x, int y){
		return (long long)x/gcd(x,y)*y;
	}
	int getNum(vector <int> divisors, vector <int> multiples){
		int n = divisors.size();
		int m = multiples.size();
		long long k = divisors[0];
		rep(i,n)k = lcm(k,divisors[i]);
		long long d = multiples[0];
		rep(i,m)d = (long long)gcd(d,multiples[i]);
		
		if( d%k!=0 ) return 0;
		d /= k;
		int ret = 1;
		for(long long i=2; i*i<=d; i++){
			int cnt = 0;
			while( d%i==0 ){
				cnt++;
				d/=i;
			}
			ret *= (cnt+1);
		}
		if( d>1 )ret*=2;
		return ret;
	}
};
 */

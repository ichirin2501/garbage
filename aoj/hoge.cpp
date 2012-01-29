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

bool of=0;
string expr;
typedef pair<int,int> pi;
#define mp make_pair

void ck(pi a)
{
	if(abs(a.first)>10000||abs(a.second)>10000)
	of=1;
}

pi add(pi a,pi b,char op)
{
	ck(a),ck(b);
	pi ret;
	ret.first=a.first+(op=='+'?b.first:-b.first);
	ret.second=a.second+(op=='+'?b.second:-b.second);
	
	ck(ret);
	return ret;
}
pi mul(pi x,pi y)
{
	ck(x),ck(y);
	int a=x.first,b=x.second,c=y.first,d=y.second;
	pi ret=mp(a*c-b*d,a*d+b*c);
	
	ck(ret);
	return ret;
}
pi eval(int s,int t)
{
	int p=t-1,d=0;//左結合なので右から演算子を探していく
	for(;p>s;p--)
	{
		char c=expr[p];
		if(c=='(')d++;
		if(c==')')d--;
		if(d==0&&(c=='+'||c=='-'))break;
	}
	//単項
	if(p==s)
	{
		if(expr[s]=='-')
		{
			pi ret=eval(s+1,t);
			ret.first*=-1,ret.second*=-1;
			return ret;
		}
		if(expr[s]=='+')return eval(s+1,t);
		
		for(p=t-1,d=0;p>s;p--)
		{
			char c=expr[p];
			if(c=='(')d++;
			if(c==')')d--;
			if(d==0&&c=='*')break;
		}
		//単因数
		if(p==s)
		{
			if(expr[s]=='(')return eval(s+1,t-1);
			
			if(expr[s]=='i')return mp(0,1);
			int n=0;
			for(int i=s;i<t;i++)
			{
				n*=10,n+=expr[i]-'0';
				if(n>10000)of=1;
			}
			return mp(n,0);
		}
		//複数因数
		return mul(eval(s,p),eval(p+1,t));
	}
	//複数項
	return add(eval(s,p),eval(p+1,t),expr[p]);
}

int main()
{
	while(getline(cin,expr))
	{
		of=0;
		pi ans=eval(0,expr.size());
		
		if(of)cout<<"overflow"<<endl;
		else
		{
			int a=ans.first,b=ans.second;
			
			if(a==0&&b==0)cout<<0<<endl;
			else if(a==0) cout<<b<<"i"<<endl;
			else if(b==0)cout<<a<<endl;
			else if(b>0)cout<<a<<"+"<<b<<"i"<<endl;
			else cout<<a<<b<<"i"<<endl;
		}
	}
	return 0;
}

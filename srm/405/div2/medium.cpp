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

class RelativePath{
public:
    string makeRelative(string path, string currentDir){
        int i,j;
        
        if( currentDir[currentDir.size()-1] != '/' ){
            currentDir += "/";
        }

        int n = path.size();
        int m = currentDir.size();
        string cd;

        rep(i,n){
            if( path[i] != currentDir[i] ){
                break;
            }
        }
        int idx = path.rfind("/",i-1) + 1;
        REP(j,i,m) if( currentDir[j] == '/' ) cd += "../";

        return cd + path.substr(idx);
    }
};






















/*

class RelativePath{
public:
	string makeRelative(string path, string cur){
		string ret;
		int n = path.size();
		int m = cur.size();
		int k;
		if( cur[m-1]!='/' ) cur+="/";
		m++;
		for(k=0; k<min(n,m) && path[k]==cur[k]; k++);
		int idx = path.find_last_of('/',k-1);
		int cnt = 0;
		for(;k<m; k++)if( cur[k]=='/' )cnt++;
		string tmp;
		while(cnt--)tmp+="../";
		
		return tmp + path.substr(idx+1);
		
	}
};
 */

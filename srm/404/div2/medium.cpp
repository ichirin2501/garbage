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

//vector<string> triangle;

class RevealTriangle{
public:
    vector<string> triangle;

    bool isok(int i, int j){
        int s = (triangle[i][j]=='?') + (triangle[i][j+1]=='?') + (triangle[i+1][j]=='?');
        return (s==1);
    }

    void isset(int i, int j){
        char &a = triangle[i][j];
        char &b = triangle[i][j+1];
        char &c = triangle[i+1][j];
        if( c=='?' ){
            c = (((a - '0')+(b - '0')) % 10) + '0';
        }
        else{
            if( b=='?' ){
                b = (c - a) + '0' + (a<=c ? 0 : 10);
            }
            else{
                a = (c - b) + '0' + (b<=c ? 0 : 10);
            }
        }
    }

    void solve(){
        int n = triangle.size();
        int i,j;

        bool loop = true;
        while( loop ){
            loop = false;
            rep(i,n-1){
                rep(j,triangle[i].length()-1){
                    if( isok(i,j) ){
                        loop = true;
                        isset(i,j);
                    }
                }
            }
        }
    }

    vector<string> calcTriangle(vector<string> questionMarkTriangle){
        triangle = questionMarkTriangle;
        
        solve();
        return triangle;
    }
};


int main(){
    int i;
    const char *s[] = {"???2", "??2", "?2", "2"};
    vector<string> vs;
    rep(i,sizeof(s)/sizeof(s[0])) vs.push_back(string(s[i]));

    RevealTriangle R;
    vector<string> ret = R.calcTriangle(vs);

    rep(i,ret.size()){
        cout << ret[i] << endl;
    }
    return 0;
}




/*
//rev
class RevealTriangle{
public:
	void ok(string& s1, string& s2){
		int x;
		rep(i,s1.size())if( s1[i]!='?' ) x=i;
		//printf("x:%d\n",x);
		for(int i=x-1; i>=0; i--){
			if( s1[i]=='?' && s2[i]!='?' ){
				int k = s2[i]-s1[i+1];
				if( k<0 )k+=10;
				//printf("one:k:%d\n",k);
				s1[i] = k+'0';
			}else if( s1[i]!='?' && s2[i]=='?' ){
				s2[i] = ((s1[i+1]-'0')+(s1[i]-'0'))%10 + '0';
			}
		}
		for(int i=x+1; i<s1.size(); i++){
			if( s1[i]=='?' && s2[i-1]!='?' ){
				int k = s2[i-1]-s1[i-1];
				if( k<0 )k+=10;
				s1[i] = k+'0';
			}else if( s1[i]!='?' && s2[i-1]=='?' ){
				s2[i-1] = ((s1[i]-'0')+(s1[i-1]-'0'))%10 + '0';
			}
		}
	}
	vector <string> calcTriangle(vector <string> ques){
		int n = ques.size();
		for(int i=n-1; i>0; i--){
			ok(ques[i-1],ques[i]);
		}
		
		return ques;
	}
};
 */

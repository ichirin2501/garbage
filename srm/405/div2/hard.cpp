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

char used[120];

class IdealString{
public:
    bool plug(char alpha, int idx, int remain, int len){
        if( len==0 ) return true;
        if( len<0 ) return false;

        int i,j;
        for(i=remain; i>=0; i--){
            int cnt = idx+i;
            used[cnt] = alpha;
            if( plug(alpha+1, idx+i+1, remain-i+cnt-1, len-cnt) ) return true;
            used[cnt] = -1;
        }
        
        return false;
    }
    string construct(int length){

        memset(used, -1, sizeof(used));
        if( !plug('A', 1, 0, length) ) return "";

        char str[128];
        vector<pair<char,int> > remainchar;

        memset(str, 0, sizeof(str));

        int i,j;
        REP(i,1,120){
            if( used[i] != -1 ){
                str[i-1] = used[i];
                remainchar.push_back(make_pair(used[i], i-1));
            }
        }

        sort(all(remainchar));

        rep(i,remainchar.size()){
            int cnt = remainchar[i].second;
            rep(j,120){
                if( cnt == 0 ) break;
                if( str[j] == 0 ){
                    str[j] = remainchar[i].first;
                    cnt--;
                }
            }
        }

        return string(str);
    }
};


int main(){
    IdealString I;
    cout << I.construct(1) << endl;
    cout << I.construct(2) << endl;
    cout << I.construct(3) << endl;
    cout << I.construct(4) << endl;
    cout << I.construct(5) << endl;
    cout << I.construct(6) << endl;
    cout << I.construct(7) << endl;
    cout << I.construct(8) << endl;
    cout << I.construct(9) << endl;
    cout << I.construct(10) << endl;
    cout << I.construct(11) << endl;
    cout << I.construct(12) << endl;
    cout << I.construct(13) << endl;
    cout << I.construct(14) << endl;
    return 0;
}




























/*
class state{
public:
	char c;
	int id;
	state(char _c, int _id){
		c = _c;  id = _id;
	}
};


stack<state> st;
bool flag = false;

class IdealString{
public:
	void dfs(char moji, int idx, int sum, int length){
		if( 0>length ) return;
		if( 0==length ){
			flag = true;
		}
		for(int i=idx+sum; i>=idx; i--){
			if( i>=length )continue;
			st.push(state(moji,i+1));
			dfs(moji+1, i+1, sum-(i-idx)+i, length-(i+1));
			if( flag ) return;
			st.pop();
		}
	}
	string construct(int length){
		string ret;
		char hash[256];
		char str[1024];
		memset(hash,0,sizeof(hash));
		memset(str,0,sizeof(str));
		dfs('A',0,0,length);
		
		if( flag==true ){
			while( !st.empty() ){
				//printf("%c : %d\n",st.top().c, st.top().id);
				hash[st.top().c] = st.top().id;
				st.pop();
			}
			rep(i,256)if( hash[i]!=0 ){
				str[hash[i]-1] = i;
				hash[i]--;
			}
			int k = 0;
			rep(i,256)if( hash[i]!=0 ){
				while(hash[i]>0){
					if( str[k]==0 ){
						str[k] = i;
						hash[i]--;
					}
					k++;
				}
			}
			ret = string(str);
		}
		
		return ret;
	}
};
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

bool edge[210][210];
bool used[210];

class CactusCount{
public:
    vector<string> split(const vector<string>& _e){
        int i,j,base;
        vector<string> ret;

        string ss;
        for(i=0; i<_e.size(); i++) ss += _e[i];

        base = 0;
        for(j=0; j<ss.length(); j++){
            if( ss[j]==',' ){
                ret.push_back( ss.substr(base, j-base) );
                base = j + 1;
            }
        }
        ret.push_back( ss.substr(base, j-base) );
        return ret;
    }

    bool dfs(int node, bool start_flag, int start, int n){
        int i;

        printf("node=%d\n",node);

        for(i=1; i<=n; i++){
            if( edge[node][i] && !used[i] ){
                used[i] = true;
                printf("next=%d  now=%d\n",i,node);
                if( dfs(i, false, start, n) ) return true;
                //used[i] = false;
            }
        }

        return true;
    }

    int countCacti(int n, vector <string> _e){
        int i;

        vector<string> sub = split(_e);

        for(i=0; i<sub.size(); i++){
            int a,b;
            sscanf(sub[i].c_str(), "%d %d",  &a, &b);
            printf("(%d,%d)\n",a,b);
            
            edge[a][b] = edge[b][a] = true;
        }

        int ret = 0;
        for(i=1; i<=n; i++){
            if( !used[i] ){
                cout << "i=" << i << endl;
                used[i] = true;
                dfs(i, true, i, n);
                ret++;
            }
        }

        return ret;
    }
};


int main(){
    CactusCount C;
    
    const char *s[] = {"1 2,2 3,3 4,4 5,5 3,1 3,6 7,7 8,6 8,8 9,9 1",
                       "0,10 11,11 9,12 13,14 15,15 16,16 17,14 17,14 16"};
    vector<string> ed;
    for(int i=0; i<sizeof(s)/sizeof(s[0]); i++) ed.push_back(string(s[i]));
    
    cout << C.countCacti(17, ed) << endl;

    return 0;
}

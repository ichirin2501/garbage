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
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)

class SRMRoomAssignmentPhase{
public:
    int countCompetitors(vector<int> ratings, int K){
        int key = ratings[0];
        int i;
        int n = ratings.size();

        sort(rall(ratings));
        
        rep(i,n){
            if( ratings[i] == key ){
                return i / K;
            }
        }
        return -1;
    }
};


int main(){
    int d[] = {1197, 1198, 1196, 1195, 1199};
    vector<int> v;
    int i;
    
    rep(i,sizeof(d)/sizeof(d[0])) v.push_back(d[i]);

    SRMRoomAssignmentPhase S;
    cout << S.countCompetitors(v, 1) << endl;

    return 0;
}

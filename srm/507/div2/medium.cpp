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


class CubeStickers{
public:
    string isPossible(vector<string> sticker){
        int i;
        int n = sticker.size();
        map<string,int> msi;

        for(i=0; i<n; i++){
            msi[sticker[i]]++;
        }

        int sum = 0;
        foreach(it,msi){
            sum += (it->second >= 2 ? 2 : 1);
        }

        return sum >= 6 ? "YES" : "NO";
    }
};

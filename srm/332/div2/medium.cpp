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


class CreatePairs{
public:
    int maximalSum(vector<int> data){
        int i;
        int n = data.size();
        vector<int> minus, plus;
        int res = 0;

        for(i=0; i<n; i++){
            if( data[i] > 0 ) plus.push_back(data[i]);
            if( data[i] <= 0 ) minus.push_back(data[i]);
        }

        sort(rall(plus));
        sort(all(minus));

        for(i=0; i<(int)plus.size()-1; i+=2){
            res += max(plus[i] * plus[i+1], plus[i] + plus[i+1]);
        }
        if( plus.size() % 2 ) res += plus[i];

        for(i=0; i<(int)minus.size()-1; i+=2){
            res += max(minus[i] * minus[i+1], minus[i] + minus[i+1]);
        }
        if( minus.size() % 2 ) res += minus[i];

        return res;
    }
};














/*
class CreatePairs{
public:
    int maximalSum(vector <int> data){
        int ret = 0;

        if( data.size()<=2 ){
            if( data.size()==1 ){
                return data[0];
            }else{
                return max(data[0]*data[1], data[0]+data[1]);
            }
        }else{
            sort(all(data));
            int i;
            for(i=1; i<data.size() && data[i]<=0; i+=2){
                ret += data[i-1]*data[i];
            }
            i--;
            int j;
            for(j=data.size()-2; j>=i; j-=2){
                ret += max(data[j+1]*data[j], data[j+1]+data[j]);
            }
            j+=2;
            if( i<j ){
                for(;i<j;i++)ret+=data[i];
            }
        }
        return ret;
    }
};
*/

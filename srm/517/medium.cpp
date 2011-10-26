#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class CompositeSmash{
public:
    bool dfs(int N, int target){
        int i;

        if( N == target ) return true;
        if( N < target ) return false;

        bool go = false;
        bool ret = true;
        for(i=2; i*i<=N; i++){
            if( N%i==0 ){
                go = true;
                ret &= dfs(i, target) | dfs(N/i, target);
            }
        }
        return go && ret;
    }
    string thePossible(int N, int target){
        return dfs(N,target) ? "Yes" : "No";
    }
};

int main(){
    CompositeSmash C;
    
    cout << C.thePossible(517,47) << endl;
    cout << C.thePossible(8,4) << endl;
    cout << C.thePossible(12,6) << endl;
    cout << C.thePossible(5,8) << endl;
    cout << C.thePossible(100000,100000) << endl;
    
    cout << C.thePossible(5858,2) << endl;
    
    cout << C.thePossible(81461,2809) << endl;
    cout << C.thePossible(65536,256) << endl;
    cout << C.thePossible(3,2) << endl;
    
    return 0;
}


/*
  {5, 1, 6, 5, 8, 4, 7} = 36  time 0
  {7, 2, 0, 6, 12, 7, 9} = ?  time 1
  {0, 3, 1, 7, 16, 10, 11}
  {2, 4, 2, 8, 20, 13, 0}
  {4, 5, 3, 9, 24, 0, 2}
  {6, 6, 4, 10, 0, 3, 4}

  時間t辺りに増える高さは　sum{grow}
  伸びたら必ずどれかを切る必要があるということ
  なので、次の高さは sum{grow} + nowsum - (Di+grow[i])
 */

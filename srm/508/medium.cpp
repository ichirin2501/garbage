#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> prime;

class DivideAndShift{
public:
    void make_primes(int N){
        int i;

        for(i=2; i*i<=N; i++){
            if( N%i==0 ){
                prime.push_back(i);
                while( N%i==0 ) N /= i;
            }
        }
        if( N > 1 ) prime.push_back(N);
    }

    int solve(int N, int M, int cnt){
        int ret = min(M-1, N-M+1) + cnt;
        int i;

        if( M==1 ) return cnt;

        for(i=0; i<prime.size(); i++){
            if( N%prime[i]==0 ){
                int n = N/prime[i];
                int m = (M-1) % n + 1;
                ret = min(ret, solve(n, m, cnt+1));
            }
        }

        return ret;
    }
    int getLeast(int N, int M){
        prime.clear();
        make_primes(N);

        return solve(N, M, 0);
    }
};


int main(){
    DivideAndShift D;

    
    cout << D.getLeast(56, 14) << endl;
    cout << D.getLeast(49, 5) << endl;
    cout << D.getLeast(256, 7) << endl;
    cout << D.getLeast(6, 1) << endl;
    cout << D.getLeast(77777, 11111) << endl;
    
    cout << D.getLeast(7,3) << endl;

    return 0;
}

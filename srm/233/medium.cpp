#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class PipeCuts{
public:
    double probability(vector <int> weld, int L){
        int i,j;
        int n = weld.size();

        sort(weld.begin(), weld.end());

        int cnt=0, sum=0;
    
        for(i=0; i<n; i++){
            for(j=i+1; j<n; j++){
                //printf("%d , %d, %d\n",weld[i], weld[j]-weld[i], 100-weld[j]);
                if( weld[i] > L || weld[j]-weld[i] > L || 100-weld[j] > L ){
                    //printf("i=%d, j=%d\n",i,j);
                    cnt++;
                }
                sum++;
            }
        }

        return (double)cnt / (double)sum;
    }
};

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

class TheNumbersWithLuckyLastDigit{
public:
    int find(int n){
        static const int num[] = {20,11,12,23,4,15,16,7,8,19};
        static const int cnt[] = { 5, 2, 3, 5,1, 3, 4,1,2, 4};
        
        int sum = num[n%10];
        int ret = cnt[n%10];

        if( sum > n ) return -1;

        return ret;
    }
};

int main(){
    int d[10], c[10];
    for(int i=0; i<10; i++) c[i] = d[i] = 999;

    int nm[] = {0,4,7};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                for(int l=0; l<3; l++){
                    for(int y=0; y<3; y++){
                        int sum = nm[i]+nm[j]+nm[k]+nm[l]+nm[y];
                        int cnt = (i>0)+(j>0)+(k>0)+(l>0)+(y>0);
                        if( sum==0 ) continue;
                        d[sum%10] = min(d[sum%10], sum);
                        c[sum%10] = min(c[sum%10], cnt); 
                    }
                }
            }
        }
    }

    for(int i=0; i<10; i++){
        printf("%d,",d[i]);
    }

    return 0;
}

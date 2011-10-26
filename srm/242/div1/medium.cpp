#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

long double pa[20200], pb[20200];
long double sumpb[20010];

class DiceThrows{
public:
    double winProbability(int numDiceA, vector <int> sidesA, int numDiceB, vector <int> sidesB){
        int i,j,k;
        pa[0] = pb[0] = 1.0;
        
        // A
        for(i=0; i<numDiceA; i++){
            for(j=20000; j>=0; j--){
                for(k=0; k<6; k++){
                    pa[j + sidesA[k]] += pa[j] / 6.0;
                }
                pa[j] = 0.0;
            }
        }

        // B
        for(i=0; i<numDiceB; i++){
            for(j=20000; j>=0; j--){
                for(k=0; k<6; k++){
                    pb[j + sidesB[k]] += pb[j] / 6.0;
                }
                pb[j] = 0.0;
            }
        }

        long double tmp = 0.0;
        for(i=0; i<=20000; i++){
            sumpb[i] = tmp;
            tmp += pb[i];
        }
        
        long double ret = 0.0;
        for(i=0; i<=20000; i++){
            ret += pa[i] * sumpb[i];
        }

        return (double)ret;
    }
};


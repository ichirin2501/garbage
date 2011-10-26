#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

class SRMCodingPhase{
public:
    int countScore(vector <int> points, vector <int> skills, int luck){
        int i,j,k;
        int ret = 0;
        int lt[3];
        
        vector<int> v;
        v.push_back(0);
        v.push_back(1);
        v.push_back(2);

        for(i=0; i<=luck; i++){
            for(j=0; j<=luck-i; j++){
                lt[0] = i;
                lt[1] = j;
                lt[2] = luck - i - j;
                sort(v.begin(), v.end());
                do{
                    int timesum = 0, sum = 0;
                    for(k=0; k<3; k++){
                        int id = v[k];
                        int tm = max(1, skills[id] - lt[k]);
                        timesum += tm;
                        if( timesum > 75 ) break;
                        sum += points[id] - (id==0? 2 : id==1 ? 4 : 8) * tm;
                    }
                    ret = max(ret, sum);
                }while( next_permutation(v.begin(), v.end()) );
            }
        }

        return ret;
    }
};


int main(){
    SRMCodingPhase S;
    int p[] = {256, 512, 5024};
    int s[] = {3, 3, 75};

    vector<int> po, ski;
    for(int i=0; i<3; i++){
        po.push_back(p[i]);
        ski.push_back(s[i]);
    }

    cout << S.countScore(po, ski, 2) << endl;

    return 0;
}

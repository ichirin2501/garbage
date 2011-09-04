#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

class TheFansAndMeetingsDivTwo{
public:
    double find(vector <int> minJ, vector <int> maxJ, vector <int> minB, vector <int> maxB){
        double ret = 0.0;
        int n = minJ.size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int sa = min(maxJ[i], maxB[j]) - max(minJ[i], minB[j]) + 1;
                if( sa<=0 ) continue;
                ret += (double)sa * (1.0/(double)(maxJ[i]-minJ[i]+1) * 1.0/(double)(maxB[j]-minB[j]+1));
            }
        }
        return ret/n/n;
    }
};

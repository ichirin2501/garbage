#include <iostream>
#include <vector>
using namespace std;

class CoinReversing{
public:
    double expectedHeads(int N, vector <int> a){
        double h = (double)N;
        double t = 0.0;

        for(int i=0; i<a.size(); i++){
            double tmp = h;
            h = h - h*(double)a[i]/N + t*(double)a[i]/N;
            t = t - t*(double)a[i]/N + tmp*(double)a[i]/N;
        }

        return h;
    }
};

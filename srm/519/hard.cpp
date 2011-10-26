#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class BinaryCards{
 public:
    long long largestNumber(long long A, long long B){
        int i;
        long long sa = B-A;
        for(i=0; 1LL<<i < sa; i++){
            ;
        }
        long long wa = (1LL<<i) - 1LL;

        return A|B|wa;
    }
};

int main(){
    BinaryCards B;
    cout << B.largestNumber(1125899906842630,1125899906842632) << endl;
    return 0;
}

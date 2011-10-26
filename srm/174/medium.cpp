#include <iostream>
#include <cstdio>
using namespace std;

class BirthdayOdds{
public:
    int minPeople(int minOdds, int daysInYear){
        int i;
        double tmp = 1.0;
        for(i=daysInYear; i>=1; i--){
            tmp *= (double)i / daysInYear;
            if( 100.0*tmp < 100.0 - (double)minOdds ){
                break;
            }
            printf("%lf , %lf\n",100.0*tmp, 100.0-(double)minOdds);
        }
        return daysInYear - i + 1;
    }
};



/*
  問題概要
  
 */

int main(){
    BirthdayOdds B;
    cout << B.minPeople(99, 1) << endl;
    //cout << B.minPeople(50, 365) << endl;
    return 0;
}

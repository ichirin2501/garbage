#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class LargestSubsequence{
public:
    string getLargest(string s){
        string ret;

        int p = 0;
        for(;;){
            char tmp = -1;
            int idx = -1;

            for(int i=p; i<s.length(); i++){
                if( tmp < s[i] ){
                    tmp = s[i];
                    idx = i;
                }
            }

            if( idx==-1 ) break;

            ret += tmp;
            p = idx + 1;

            //cout << p << endl;
        }
        

        return ret;
    }
};

int main(){
    LargestSubsequence L;
    cout << L.getLargest("aquickbrownfoxjumpsoverthelazydog") << endl;

    return 0;
}

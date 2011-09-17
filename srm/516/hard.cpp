#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;

class NetworkXMessageRecovery{
public:
    string recover(vector <string> messages){
        string ret;

        // 最初にてきとーに連結させておく
        set<char> sc;
        for(int i=0; i<messages.size(); i++){
            for(int j=0; j<messages[i].size(); j++){
                sc.insert(messages[i][j]);
            }
        }
        set<char>::iterator it;
        for(it=sc.begin(); it!=sc.end(); it++){
            ret += *it;
        }

        for(;;){
            bool f = false;
            
            for(int i=0; i<messages.size(); i++){
                for(int j=1; j<messages[i].size(); j++){
                    int p = ret.find(messages[i][j-1]);
                    int q = ret.find(messages[i][j]);
                    if( q < p ){
                        for(p++; p<ret.size() && ret[p] < messages[i][j]; p++);
                        ret.insert(ret.begin()+p, messages[i][j]);
                        ret.erase(ret.begin()+q);
                        f = true;
                    }
                }
            }

            if( !f ) break;
        }
        return ret;
    }
};


int main(){
    const char *str[] = {"gp", "Mtb", "TC", "oMb", "vWQS", "xCb", "BGWQfL", "BvWfS", "MC", "iZrkRYwy", "q", "GQfSL", "OairckEN", "oMTxb", "DXezP", "DumIzj", "p", "oMtx", "oMT", "MtTx", "otTb", "V", "GWQS", "AqFU", "xCb", "gpl", "aZkRYEyN", "oMTxCb", "BvSL", "DJnue", "vGWfSL", "V", "p", "GL", "tTxb", "tTx", "V", "Mtx", "BGQfL", "oTCb", "g", "aHZRE", "BWf", "tTC", "Mx", "l", "pl", "BGWfL", "FU", "GfSL"};
    vector<string> msg;
    for(int i=0; i<sizeof(str)/sizeof(str[0]); i++){
        msg.push_back(string(str[i]));
    }
    NetworkXMessageRecovery N;
    cout << N.recover(msg) << endl;

    return 0;
}



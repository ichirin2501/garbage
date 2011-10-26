#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

class Undo{
public:
    string getText(vector <string> commands, vector <int> time){
        int n = commands.size();
        int i,j;
        vector<string> state;
        char comm[8], d[16];

        state.push_back("");

        for(i=0; i<n; i++){
            sscanf(commands[i].c_str(), "%s %s", comm, d);
            if( comm[0]=='t' ){
                // type
                state.push_back( state[i] + string(d) );
            }
            else{
                // undo
                int nt = time[i] - atoi(d);
                for(j=0; j<n; j++){
                    if( nt <= time[j] ) break;
                }
                state.push_back( state[j] );
            }
        }
        return state[state.size()-1];
    }
};


int main(){
    Undo U;
    const char *s[] = {"type a", "undo 1", "undo 1"};
    int t[] = {1,2,3};

    vector<int> vi;
    vector<string> vs;
    for(int i=0; i<sizeof(t)/sizeof(t[0]); i++) vi.push_back(t[i]);
    for(int i=0; i<sizeof(s)/sizeof(s[0]); i++) vs.push_back(string(s[i]));

    cout << U.getText(vs,vi) << endl;

    return 0;
}

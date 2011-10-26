#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct _tp{
    int x1,x2,y1,y2;
} tp[3];


class ThreeTeleports{
public:
    long long dfs(int nx, int ny, int gx, int gy, int cnt, long long sum){
        int i;
        long long ret = abs(nx-gx) + abs(ny-gy) + sum;
        if( cnt==3 ) return ret;
        
        for(i=0; i<3; i++){
            ret = min(ret, dfs(tp[i].x2, tp[i].y2, gx,gy, cnt+1, sum+10+abs(nx-tp[i].x1)+abs(ny-tp[i].y1)) ); // 1 -> 2
            ret = min(ret, dfs(tp[i].x1, tp[i].y1, gx,gy, cnt+1, sum+10+abs(nx-tp[i].x2)+abs(ny-tp[i].y2)) );
        }

        return ret;
    }
    int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports){
        int i;
        int n = teleports.size();
        
        // parse
        for(i=0; i<n; i++){
            sscanf(teleports[i].c_str(), "%d %d %d %d", &tp[i].x1, &tp[i].y1, &tp[i].x2, &tp[i].y2);
        }

        // brute
        return (int)dfs(xMe, yMe, xHome, yHome, 0,0);
    }
};

int main(){
    const char *s[] = {"0 1 0 999999999", "1 1000000000 999999999 0", "1000000000 1 1000000000 999999999"};
    vector<string> tel;
    for(int i=0; i<3; i++) tel.push_back(string(s[i]));

    ThreeTeleports T;
    cout << T.shortestDistance(0,0,1000000000,1000000000,tel) << endl;
    return 0;
}

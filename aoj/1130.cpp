#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cctype>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

char map[21][21];
int w, h;
int tile = 0;

void dfs(int x, int y){
    if (!(0 <= x && x < w && 0 <= y && y < h)) return;
    tile++;
    map[y][x] = '#';
    if (map[y-1][x] == '.') dfs(x, y-1);
    if (map[y+1][x] == '.') dfs(x, y+1);
    if (map[y][x-1] == '.') dfs(x-1, y);
    if (map[y][x+1] == '.') dfs(x+1, y);
}

int main(){
    int sx, sy;
    while (1){
        scanf("%d %d", &w, &h);
        if (w == 0 && h == 0) break;
        memset(map, '#', sizeof(map));
        tile = 0;
        for (int i = 0; i < h; i++){
            cin >> map[i];
            for (int p = 0; p < w; p++){
                if (map[i][p] == '@'){
                    sx = p;
                    sy = i;
                }
            }
        }
        dfs(sx, sy);
        printf("%d\n", tile);
    }
    
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <sstream>
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)


class FoxAndMountainEasy {
public:

string possible(int n, int h0, int hn, string history) {
    pair<int,int> pii = height_from_history(history);
    int m = n;
    int h = h0;

    // 最小値が出たので、その分移動する
    if (h + pii.second < 0) {
        m -= abs(h + pii.second);
        h += abs(h + pii.second);
    }
    m -= (int)history.length();
    h += pii.first;

    // あとは偶奇を見る
    // 高さ abs(h - hn) % 2 == m % 2 が必須条件
    // かつ、m回の移動 = mの高さ移動できる
    if (abs(h - hn) % 2 == m % 2 && abs(h - hn) <= m) {
        return "YES";
    } else {
        return "NO";
    }
}

pair<int,int> height_from_history(const string& history) {
    int res = 0;
    int h = 0;
    for(int i=0; i<history.length(); ++i) {
        h += (history[i] == 'U' ? 1 : -1);
        res = min(res, h);
    }
    return pair<int,int>(h,res);
}

};


int main() {
    FoxAndMountainEasy F;

    cout << F.possible(4,0,4,"UU") << endl;
    cout << F.possible(4,0,4,"D") << endl;
    cout << F.possible(4,100000,100000,"DDU") << endl;
    cout << F.possible(4,0,0,"DDU") << endl;
    cout << F.possible(20,20,20,"UDUDUDUDUD") << endl;
    cout << F.possible(20,0,0,"UUUUUUUUUU") << endl;
    cout << F.possible(20,0,0,"UUUUUUUUUUU") << endl;

    return 0;
}

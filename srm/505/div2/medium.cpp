#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)


class PerfectSequences{
public:
    string fixIt(vector<int> seq){
        long long kake, sum;
        int i,j;
        int n = seq.size();

        if( n == 1 ) return "Yes";

        sort(all(seq));

        rep(i,n){
            kake = 1;
            sum = 0;
            rep(j,n)if( i!=j ){
                sum += seq[j];
                kake *= seq[j];
                if( sum+1 < kake ) break;
            }
            if( j < n ) continue;
            // 0
            if( sum == kake && kake == 0 && seq[i] > 0 ) return "Yes";
                
            if( kake > 1 &&
                sum%(kake-1) == 0 &&
                sum/(kake-1) != seq[i] ) return "Yes";
        }

        return "No";
    }
};

int main(){
    PerfectSequences P;
    int d[] = {1,3,4};
    //int d[] = {1,2,3};
    //int d[] = {1,4,2,4,2,4};
    //int d[] = {1000000,1,1,1,1,2};
    //int d[] = {8};
    //int d[] = {2,0,2};
    //int d[] = {0,3};
    //int d[] = {0,2};
    vector<int> seq;
    int i;
    rep(i,sizeof(d)/sizeof(d[0])) seq.push_back(d[i]);

    cout << P.fixlt(seq) << endl;

    return 0;
}


/*
a*b <= a+b

a,bのどちらかが1のときは a+bのほうが大きい

1 2 2 4 4
+ : 13(9)
* : 64(16)

1 1 1 1 2 1000000
+ : 1000006(6)
* : 2000000(2)


a*b　に新しい要素を追加しても増加しない場合は　1　しかない

最大の要素を一つ減らしたとき、
a+b+1 < a*b　なら、
要素の値を変更しても、等しくならない。
条件から少なくとも2以上差がある。
和を2以上大きくしたいときは、
対応する値に変換する必要があるが、
2以上だとa*bの増加量のほうが大きい

a+b+1 == a*b
なら最大の要素を1に変換すればよい。

a+b+1 >= a*b

10+c = 7*c
10 = 7c - c
10 = 6c
c = 10/6
よって、割り切れない値


1 2 3　のとき
3+c = 2c
3 = c
割り切れてるので完全数列可能
ただし、元の数字と同じだからだめ

0が2つあったら和も0にする必要がある

というか、最大の要素を操作するだけじゃだめだ。

まず、交換する値を決める
if sum + 1 < kake　になった時点で、選択した値では等しくできない


 */

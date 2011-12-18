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
#include <sstream>
using namespace std;

#define REP(i,a,n) for(i=a; i<n; i++)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); it++)

typedef long long ll;

class BirthdayCake{
public:
    int bitcount(ll n){
        int res = 0;
        while( n > 0 ){
            if( n&1 ) res++;
            n >>= 1LL;
        }
        return res;
    }

    int howManyFriends(vector<string> availableFruits, vector<string> friendsDislikings, int K){
        int i,j,k;
        int n = availableFruits.size();
        int m = friendsDislikings.size();
        vector<ll> S;
        map<string,ll> ms;
        ll mask = (1LL << n) - 1;

        rep(i,n){
            ms[availableFruits[i]] = 1LL << i;
        }

        rep(i,m){
            stringstream ss(friendsDislikings[i]);
            string in;
            ll bit = mask;
            while( ss >> in ){
                if( ms.count(in) ){
                    bit ^= ms[in];
                }
            }
            S.push_back(bit); // S[友達] = 大丈夫な果物の集合
        }

        int res = 0;

        for(i=1; i<1<<m; i++){
            ll kuda = mask;

            rep(j,m){
                if( i & (1<<j) ){
                    kuda &= S[j];
                }
            }

            if( n - bitcount(kuda ^ mask) >= K ){
                res = max(res, bitcount((ll)i));
            }
        }

        return res;
    }
};

/*
  友達の人数は最大でも20人
  1<<20 = 1048576
  ビット集合を用いて、ビットが立ってる位置の友達を選択
  ん、選択した友達だけが共通の嫌いな食べ物を含んでいるわけではない
  DPかなぁ
  dp[果物の個数][最後に選んだ果物の位置] = 嫌う果物を含んだ友達の集合
  でいけそうかな？
  出来ない、嫌う果物を含んだ友達の集合同士を比較する際、
  単純に人数比較だと、同じ人数の場合、後の果物次第で最適選択が異なる。
  それらの状態も分ける必要があるから、
  [嫌う果物を含んだ友達の集合][果物の個数][最後に選んだ果物の位置]
  1<<20 * 50 * 50　間に合わない。
  
  友達の集合に対して、その集合に含まれている果物と、
  それらの果物の個数とKの一致、次にそれらの果物を嫌う友達の集合を調べて、
  最初の友達の集合との一致を調べる、とか。
  だめでした。友達が嫌う果物が果物の集合にない場合がある。
  
  最初に大丈夫な果物の集合を求めておく。
  ビット集合を用いた友達の集合から、
  選択した友達の大丈夫な果物を求める。
  全ての果物との差を取って、K個以上の果物を選択しても、
  その友達の集合が成り立つなら更新。
  1<<20 * 2 * 50　ぎりぎり…
  これで良さそう。
  最後はすごく単純な形に落ち着いた。
  
  どうしてもっと早くに「大丈夫な果物」を求めようとしなかったんだろう。
  「大丈夫な果物の集合」と「大丈夫じゃない果物の集合」も同じ、とか思ったのか。
  友達の集合をビット集合で扱う場合、
  嫌いな果物を調べても、実際はその集合以外にも嫌う友達がいる可能性がある。
  よって、最大でも選択した友達の人数しか得られず、その集合以外も加味した場合は減ってしまう。
  そのため、果物をK個選んだときに何人の友達がケーキを食べられるのかがわからない。
  大丈夫な果物のときは、大丈夫な果物の種類と、果物の選択が最悪の状態もすぐわかる。
  一人一人の大丈夫な果物の集合をANDして、ビットが立ってない果物の数とその種類が、
  その友達の集合全員が食べられるぎりぎりの条件になる。
  最悪ケースの果物の個数がK個以上なら、その友達の集合は全員ケーキを食べることができる。
 */


int main(){
    const char *s1[] = 	{"vqayzaldyi", "qlgsukdmfe", "baewytlvfh", "eeqrrjsie", "olfnklc", "itfxtfgykb", "ntlhit", "korzk", "rbamtmo", "docur", "hllpve", "jdplceqcc", "mankgl", "fwthcv", "jdodyv", "zfifjpc", "wydhboirp", "duracx", "lcdwaalr", "adiffpyvx", "ctfxai", "jablas", "lcqkulmvb", "wcabop", "ajsynuc", "cqmaqngsfs", "xkeoczhzd", "pxomu", "dyygo", "jkmagcj", "ijtfgc", "mjrdfcxhpu", "xdfkjd", "torelq", "wdibtt", "dsqvv", "lwlyzv", "lynygya", "auqviptooe", "ojfhhv", "uuukzppfb"};
    const char *s2[] = {"mankgl ntlhit auqviptooe itfxtfgykb jablas", "mankgl hllpve olfnklc vqayzaldyi docur fwthcv", "eeqrrjsie wdibtt auqviptooe jdplceqcc ctfxai", "wdibtt dsqvv dyygo wcabop adiffpyvx xdfkjd zfifjpc", "ntlhit dyygo baewytlvfh ojfhhv jkmagcj korzk", "jdplceqcc ajsynuc uuukzppfb jdodyv mankgl ntlhit", "pxomu baewytlvfh wdibtt vqayzaldyi wydhboirp", "mjrdfcxhpu cqmaqngsfs olfnklc docur ctfxai jablas", "xkeoczhzd ctfxai rbamtmo ojfhhv lcqkulmvb", "jablas lcqkulmvb auqviptooe lwlyzv zfifjpc dsqvv", "docur hllpve dsqvv itfxtfgykb vqayzaldyi", "uuukzppfb hllpve ojfhhv dyygo xdfkjd ctfxai", "torelq baewytlvfh eeqrrjsie jablas wydhboirp", "itfxtfgykb olfnklc jdplceqcc mjrdfcxhpu auqviptooe", "jablas duracx fwthcv olfnklc lcqkulmvb wdibtt", "dsqvv vqayzaldyi wydhboirp itfxtfgykb hllpve korzk", "lcqkulmvb eeqrrjsie ntlhit dsqvv itfxtfgykb hllpve", "xkeoczhzd docur adiffpyvx ijtfgc mjrdfcxhpu fwthcv", "uuukzppfb ctfxai mankgl rbamtmo jdplceqcc docur", "mjrdfcxhpu jablas korzk baewytlvfh ijtfgc torelq"};

    vector<string> v1, v2;
    int i,j;

    rep(i,sizeof(s1)/sizeof(s1[0])) v1.push_back(string(s1[i]));
    rep(i,sizeof(s2)/sizeof(s2[0])) v2.push_back(string(s2[i]));

    BirthdayCake B;

    cout << B.howManyFriends(v1, v2, 20) << endl;

    return 0;
}

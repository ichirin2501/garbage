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

// YET_SYSTEM_TEST

typedef long long ll;

ll lifed[100010];
int damage[100010], waterhole[100010];

struct state{
    int life, cnt, id;
    state(int c, int l, int i){
        cnt = c, life = l, id = i;
    }
    bool operator<(const state& a)const{
        if( cnt == a.cnt ) return id < a.id;
        return cnt > a.cnt;
    }
};

int main(){
    int N,H,i,j,k,res=0;
    priority_queue<state> q;
    map<int,int> mi;

    // input
    scanf("%d %d", &N, &H);
    rep(i,N) scanf("%d %d", &damage[i], &waterhole[i]);

    q.push(state(0,1,N-2));
    while( !q.empty() ){
        int idx = q.top().id;

        if( idx == -1 ){
            res = q.top().cnt;
            break;
        }

        int d = damage[idx], w = waterhole[idx];
        int life = q.top().life, cnt = q.top().cnt;
        q.pop();

        // debug
        printf("id=%3d, (%3d %3d), life = %3d, cnt = %3d\n",idx,d,w,life,cnt);

        // 泉を使わない
        if( life + d <= H ){
            q.push(state(cnt, life+d, idx-1));
            printf("   life = %3d, cnt = %3d, id = %3d\n",life+d,cnt,idx-1);
        }

        // 泉を使う
        // min(x+w,H) - d >= life
        // これが成り立つ最小のxがほしい
        // a + w <= H   >= life + d
        // もし　H < life + d　なら絶対無理
        if( H >= life + d ){
            q.push(state(cnt+1, max(life+d-w,1), idx-1));
            printf("   life = %3d, cnt = %3d, id = %3d\n",max(life+d-w,1),cnt+1,idx-1);
        }
    }

    printf("%d\n",res);

    return 0;
}
/*
  地下N階（逆から）見ていくと、
  例えば、入力例では、最後のN階に行くためには
  ・泉をN-1階で使わない場合 life >= 10
  ・泉をN-1階で使う場合 life >= 10-4 = 6
  が最低基準になる。
  次にN-2階からN-1階に移動するときを見ると
  ・泉をN-2階で使わない場合 life >= 5
  ・泉をN-2階で使う場合 life >= 5-1 = 4
  これらから、
  地下N-2階から地下N階まで泉を0回使う場合、なし
  地下N-2階から地下N階まで泉を1回使う場合、地下N-2の段階でlife7以上、地下N-1階で泉使用
  地下N-2階から地下N階まで泉を2回使う場合、

  map<泉の使用回数,life>

  ダメージを足して、（泉を使うなら）回復量を引く
  N階からN-1階に移動するときには、(9 4)
  q : (0,10),(1,6)
  N-1階からN-2階に移動するときには、(4 1)
  (0,10)<-(0,14)は無理
  (0,10)<-(1,13)も無理、よって(0,10)はありえない
  (1,6)<-(1,10)は可能かも
  (1,6)<-(2,9)は可能かも
  q : (1,10), (2,9)
  N-2階からN-3階に移動するときは、(0 8)
  (1,10)<-(1,10)は可能かも
  (1,10)<-(2,2)は可能かも
  (2,9)<-(2,9)は可能かも
  (2,9)<-(3,1)は可能かも
  q' : (1,10),(2,2),(2,9),(3,1)
  同数の泉使用回数がある場合は、最低限必要なライフが少ないほうを選択する
  q : (1,10),(2,2),(3,1)
  逆からダイクストラしか浮かばない…。

  げー、各階の泉は何回でも使用できるのかorz
  難易度あがったー、わからねえｗ
 */

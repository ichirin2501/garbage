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

class RemovingDigits {
public:
    bool isPossibleTopDigit(int idx, string& remNumber, map<char,int>& remDigits) {
        int numCount[10] = {};
        for (char i='0'; i<='9'; ++i) {
            numCount[i - '0'] = remDigits[i];
        }
        for (int i=0; i<idx; ++i) {
            if (numCount[remNumber[i] - '0'] <= 0) return false;
            numCount[remNumber[i] - '0']--;
        }
        int remCnt = 0;
        for (int i=idx; i<(int)remNumber.length(); ++i) {
            if (remNumber[idx] == remNumber[i]) {
                remCnt++;
            }
        }
        return remCnt > numCount[ remNumber[idx] - '0' ];
    }
    bool _isAllUsed(map<char,int>& s) {
        for (char c='0'; c<='9'; ++c) {
            if (s[c] > 0) return false;
        }
        return true;
    }
    int findIndexOfGoodTopDigit(string& remNumber, map<char,int>& remDigits) {
        for (char c='9'; c >= '0'; --c) {
            for (int i=0; i < (int)remNumber.length(); ++i) {
                if (remNumber[i] != c) continue;
                if (isPossibleTopDigit(i, remNumber, remDigits)) {
                    return i;
                }
            }
        }
        return -1; // まずない
    }
    void removeNumberFromDigit(int idx, string& remNumber, map<char,int>& remDigits) {
        for (int i=0; i<idx; ++i) {
            remDigits[remNumber[i]]--;
        }
        remNumber.erase(0, idx + 1);

        // 残った削除要素数と等しくなったら丸ごと消す
        int cnt = 0;
        for (int i='0'; i<='9'; ++i) cnt += remDigits[i];
        if (cnt == (int)remNumber.length()) {
            for (int i=0; i<(int)remNumber.length(); ++i) {
                remDigits[remNumber[i]]--;
            }
            remNumber = "";
        }
    }

    string maxNumber(string number, string digits){
        string answer = "";
        string remainNumber = number;
        map<char,int> remainDigits;
        // init
        for (char c='0'; c<='9'; ++c) remainDigits[c] = 0;
        for (int i=0; i<(int)digits.length(); ++i) remainDigits[ digits[i] ]++;

        while (! _isAllUsed(remainDigits)) {
            int target_idx = findIndexOfGoodTopDigit(remainNumber, remainDigits);
            answer += remainNumber[target_idx];
            removeNumberFromDigit(target_idx, remainNumber, remainDigits);
        }

        return answer + remainNumber;
    }
};


int main() {
    RemovingDigits R;

    cout << R.maxNumber("12345", "513") << endl;
    cout << R.maxNumber("112352", "1123") << endl;

    cout << R.maxNumber("123456654321", "612534") << endl;

    cout << R.maxNumber("654321123456", "612534") << endl;

    return 0;
}

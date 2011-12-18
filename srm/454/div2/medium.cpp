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

map<char,int> alpha;

class WordsGame{
public:
    int calc(const string& word, string str){
        int n = word.length();
        int i,j;
        int res = 0;

        rep(i,n){
            if( word[i] == str[i] ) continue;
            REP(j,i,n){
                if( word[i] == str[j] ){
                    swap(str[i], str[j]);
                    res++;
                    break;
                }
            }
        }
        return res;
    }

    int minimumSwaps(vector<string> grid, string word){
        int n = grid.size();
        int i,j;
        int res = INT_MAX;

        rep(i,word.length()) alpha[word[i]]++;

        // yoko
        rep(i,n){
            map<char,int> tmp;
            rep(j,n) tmp[grid[i][j]]++;
            if( alpha == tmp ){
                res = min(res, calc(word, grid[i]));
            }
        }

        // tate
        rep(j,n){
            map<char,int> tmp;
            rep(i,n) tmp[grid[i][j]]++;
            if( alpha == tmp ){
                string ts;
                rep(i,n) ts += grid[i][j];
                res = min(res, calc(word, ts));
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};


int main(){
    const char *s[] = {"TZNIUhIvjkCoAwYwMajKTZcRwVDklAccDwYTYRDnPlyRMzftz", "aUHYVaWwSKSEaubYDdazImUQELhBdNGTSpbMjTuxzcsnlEJuq", "tJbjwekWCAMJsfaHVUdZPMzcNifPyTHMdhCdSWbAWqnTcJIHj", "yOVMpbZHiDIfrxTucWFUupiMKJnbrnuulmmHeyXRtSveHIqoO", "minJtupHVBsDCGjLleBrwRmpnLGIxzlrZZhptITiUljxgrfjS", "SASbnBrymdBZJnldcKhnaVEwoAEIolexeEFkteASDnCWNMPNR", "WXodyFcegpDqeWFQpzDMDjPbsCcjjCyjWvDFQwSIrENRmeqFq", "FrGOvisNrWnZClXgdkxLfQslsuAlJrAHCaNRynnbTZESrgkvw", "iTasLPwBuVQdThiEWpMhsipnkTlxbYpqHTvELDiGbUaTuVFlI", "BKstAxijlnNLCuzPhZMwVmbTvagHprqfeIcdyGXUQOERSYJko", "wKrKKjbYlTMHvRcAWDDiFvbZtETIuEBbvzrOobFOoHdrCGgiI", "ffiQSwartIBVGpfdAVloGnlncIliHDWDhSYnigPtllbGGsXLU", "XRGGjkfqkGJOCVCbnqUSEXkwaKRaHVJZPnRsULlZeAkOOflxM", "CZpeeqtfvZLgsIpkLZmklHjuAsoiBBvvkBRDthVDSIMULwtix", "pEMXqRYaLmzwZzqqCGmGvSJfPAsfnjqfTASLYoWPYzWIMXsRP", "GteiugQxPEoHMYHZXoTNqcfFQVKaRtKpLrVqTifFxaZaGTROq", "kzNBZmVIJexgjiWxLMdlrKhjxGQdzOoKpxpMSjhUuSqkHZosK", "KIDpGxTGcMgFmSwNtBTvrBnzOxYcWhjmxkBiVJyYhsKlXvPwo", "YYcwITniBinSYZIjMruwYhKeIPnIUiNPNdqIFuYlXbipbRGNS", "dyBPPKFhnOvfjgJgjgZyFzOIywNWGFnSmeVuFmzMCzzqGDjsA", "DdiuMNjjRxfcDQkCrCXWKbIbtGXHYJTgIyvFzVZHBickmpoQU", "zYnSrZMwWvNIvXguEbfxRNLoouXTjZrXrMSssqUwyugGMOCaJ", "qIRWiLuqsorOpKBkeLqQhEtnYMGOkHtNYlnPgMBQOLTghAsFm", "oRlHTDRdKuPHCLKdTAzdqfQnHFcajeOJuVuvBEtLIrVbpKPro", "xZkEWJKlhfgZDaEfLNnFiIHOwIViHKhstYqlbdRCVshulaghy", "sZWmmfoYAyPAVJOjxEpTtYgYpZFTHwRiqJeedAcfwHODkclES", "AwbZDIOFQCGvWcNxBIOmjtDRKLetzxSLgWmRfzoWJgpYXxVhg", "lzUxcHNvpUplYymQrxeqKgdFUBLphQZyXOJxTrqzpPwtCUkLu", "OihoJnEKXYLxwDZUhvAYWJXzIIBqURPCoPIOGOGeqAuegkJEN", "BOtVCciNejEhZjRBcHccIPramuXIwLgwfUGxctsvdXDskmJNU", "rcsDXvCrMcXfHsVllFUfnxAKgTeUtdinOHjkjpmKQmBNfBICZ", "QqeUNCLoDReFETrPDfLCedMejdCoXqIBwfpJKcQykUUhUiQBJ", "MydrAWzaFXaeBPPtjPEgDyBRKFtKcaskUNZiSHOVLePMboSpZ", "civNBldYYSKruNvhSQOeRLeknHKxkpwVRbJShNaTgaoGbYgiz", "jqXRkUAMUwdWhdAyGSXITWVFuRsuSGVYzFceAlwgaGQxqFEfw", "PatalXlkTQQMkEDTInMbcCRrPvqgsbDGKLDQzxdkcaeobHxyE", "RymToAmwIsPgpkUgFhStaUCVdBKMgoazjsDpfBMBKNxjntyDH", "NYWtsEHIZlPBWAoWJsCPXraxsPtisUMIMjLnpsvuHFRtCqkQM", "uoXqRSPkNJrgVmeSxXvEaoYWpdRviMkAiXRMVFrjjhYTNlQqX", "IcncxGDkaqFHMeGjNjiArGoutQVzHubhBILgDPENZDIknuGfS", "UhSvzyxjoPLcfosyaywaMkTmlspCKcUWcCttNfLqnsSJCLJUY", "bFcChpJWqroITUQCITIOLqSVfVrqCsXRJgRNSYNsNJryBPruH", "hmSgQzevGgrYHvMxXwNupAxSwnYHAWmaVitQqSxXfDtERyPhd", "gWLygYgrfFFJUMulOYPXQOqmIEfVUmYtADihgGphvImRFhWfH", "HeehEtyvyHeIrBSpntsBUDvPBVvNoPCFFcgMmQCEAdHLlWojk", "nCtFfMUcxhGOZCnoQmCjWTwKXmHpzIdQaqiksCHJGAJimCtyV", "LfCnFrGMznUhsFyZjilRDeNMuGSHYfxEGoawDkepmkfjNQjWi", "ZnjkdohJbadWmOtstcsDjFuyKfOXXkFOnGuyaakoMHAeMSxnh", "eJszbOvLdLrXXthZmltVgaFVuMJVCXfobRxnZUJrsSFVIdISZ"};
;
    int i;
    vector<string> vs;
    rep(i,sizeof(s)/sizeof(s[0])) vs.push_back(string(s[i]));

    WordsGame W;

    cout << W.minimumSwaps(vs, "gaRQHGjsdUpyTVowklBYCxqLtMNOczJXPirIEnSZevmfAbKuh") << endl;

    
    return 0;
}

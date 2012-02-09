#include <iostream>
#include <cstdlib>
using namespace std;
typedef long long lli;
int main(){
	lli a,b,c;
	for(;;){
		cin>>a>>b>>c;
		if(a==0)break;
		bool ans=false;
		if(c==0){
			if(a!=1)cout << a <<" " << b << " " << 1 << " " << 0 << endl;
			else cout << 1 <<" " << max(b,(lli)0) << " " << 1 << " " << min(b,(lli)0) << endl;
			continue;
		}
		int s=-abs(c),e=abs(c);

		for(lli i=1;i<=a;i++){
			if(a%i!=0)continue;
			for(lli j=s;j<=e;j++){
				if(j==0||c%j!=0)continue;
				if(b==j*a/i+i*c/j){
					ans=true;
					if(a==i*i){
						cout<<i<<" "<<max(c/j,j)<<" "<<i<<" "<<min(c/j,j)<<endl;
					}else{
						cout<<a/i<<" "<<c/j<<" "<<i<<" "<<j<<endl;
					}
					break;
				}
			}
			if(ans)break;
		}
		if(!ans){
			cout<<"Impossible"<<endl;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define y1 y_1
const int N=1e3+1;
int n;
signed main(){
	freopen("wota.in","r",stdin);
	freopen("wota.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	long long ans=1,i=5;
	if(n<5){
		cout<<n*(n-1)/2<<endl;
		return 0;
	}
	while(i<=n) i*=10;
	i=i/10;
	if(n<i*3) ans+=(n-i*1+1)*1;
	else{
		ans+=i*2;
		if(n<i*5)ans+=(n-i*3+1)*2;
		else{
			ans+=i*4;
			if(n<i*7) ans+=(n-i*5+1)*3;
			else{
				ans+=i*6;
				if(n<i*9) ans+=(n-i*7+1)*4;
				else{
					ans+=i*8;
					ans+=(n-i*9+1)*5;
				}
			}
		}
	}
	for(long long j=2;j<=10;j+=2){
		if(n>=i*j-1) ans--;
		else break;
	}
	cout<<ans-1;
	return 0;
}

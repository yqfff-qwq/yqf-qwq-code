#include<bits/stdc++.h>
using namespace std;
void solve(long long n){
	long long ans=1,i=5;
	if(n<5){
		cout<<n*(n-1)/2<<'\n';
		return;
	}
	while(i<=n)i*=10;
	i=i/10;
	if(n<i*3)ans+=(n-i*1+1)*1;
	else{
		ans+=i*2;
		if(n<i*5)ans+=(n-i*3+1)*2;
		else{
			ans+=i*4;
			if(n<i*7)ans+=(n-i*5+1)*3;
			else{
				ans+=i*6;
				if(n<i*9)ans+=(n-i*7+1)*4;
				else{
					ans+=i*8;
					ans+=(n-i*9+1)*5;
				}
			}
		}
	}
	for(long long j=2;j<=10;j+=2){
		if(n>=i*j-1)ans--;
		else break;
	}
	cout<<ans-1<<'\n';
}
signed main(){
 	freopen("wota.in","r",stdin);
	freopen("wota.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	long long n;
	cin>>n;
	solve(n);
//	for(int i=1;i<=n;i++){
//		cout<<i<<' ';
//		solve(i);
//	}
	return 0;
}

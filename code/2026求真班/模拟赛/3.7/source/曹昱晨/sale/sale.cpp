#include<bits/stdc++.h>
using namespace std;
long long ans,a[505];
signed main(){
 	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>=3)
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			for(long long k=j+1;k<=n;k++){
				ans=max(ans,a[i]|a[j]|a[k]);
			}
		} 
	}
	else if(n==2)ans=a[1]|a[2];
	else ans=a[1];
	cout<<ans;
	return 0;
}
/*
无论如何只选3颗 
*/

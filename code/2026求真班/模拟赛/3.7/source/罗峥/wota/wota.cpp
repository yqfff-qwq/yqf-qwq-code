#include <bits/stdc++.h>
using namespace std;
long long n,ans,t=1,x,l,r;
signed main(){
	freopen("wota.in","r",stdin);
	freopen("wota.out","w",stdout);
	cin>>n;
	while(t*5<=n) t*=10;
	for(int i=1;i<=9;i++) {
		x=i*t-1,l=max(1ll,x-n),r=min(n,x-1);
		if(l<r) ans+=(r-l+1)>>1;
	}
	cout<<ans;
	return 0;
}

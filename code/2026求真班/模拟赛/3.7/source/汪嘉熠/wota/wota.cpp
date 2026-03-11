#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL getmax9(LL x){
	LL tmp=0;
	for(int i=0;;i++){
		LL nxt=tmp*10ll+9ll;
		if(nxt>x)return tmp;
		tmp=nxt;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("wota.in","r",stdin);
	freopen("wota.out","w",stdout);
	LL n; cin>>n;
	if(n==1){cout<<0;return 0;}
	if(n==2){cout<<1;return 0;}
	if(n==3){cout<<4;return 0;}
	if(n==4){cout<<6;return 0;}
	LL t=getmax9(2ll*n-1ll),ans=0ll;
	for(LL i=0ll;;i++){
		LL num=(t+1ll)*i+t;
		if(num>2ll*n-1ll)break;
		if(num-1ll<=n)ans+=num/2ll;
		else ans+=n-(num+1ll)/2ll+1ll;
	}
	cout<<ans;
	return 0;
}

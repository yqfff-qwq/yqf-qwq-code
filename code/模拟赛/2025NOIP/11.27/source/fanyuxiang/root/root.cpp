#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline int rd(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
int t,n,m;
int calc(int x,int n){
	if(x<=0)return 0;
	return (x-1)/n+1;
}
void sol(){
	n=rd();m=rd()+1;
	int sum=0,ans=0;
	for(int i=63;~i;i--){
		if(m>>i&1){
			int s=sum|((n-1)>>i&1)<<i,
				t=s%n;
			// cout<<t<<'\n';
			ans+=calc(t+(1ll<<i)-1,n)-calc(t-1,n);
		}
		sum|=((m>>i&1)^((n-1)>>i&1))<<i;
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("root.in","r",stdin);
	freopen("root.out","w",stdout);
	for(t=rd();t--;)sol();
	return 0;
}
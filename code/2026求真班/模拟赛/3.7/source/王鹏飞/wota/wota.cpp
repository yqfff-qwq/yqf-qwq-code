#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lowbit(x) x&-x
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}
ll n,ans,t=1,x,l,r;
signed main(){
	freopen("wota.in","r",stdin);
	freopen("wota.out","w",stdout);
	n=read();
	while(t*5<=n) t*=10;
	for(int i=1;i<=9;i++) {
		x=i*t-1,l=max(1ll,x-n),r=min(n,x-1);
		if(l<r) ans+=(r-l+1)>>1;
	}
	write(ans);
	putchar('\n');
}

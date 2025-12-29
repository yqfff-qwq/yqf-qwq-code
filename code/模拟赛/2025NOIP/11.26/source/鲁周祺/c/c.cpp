#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lowbit(x) x&-x
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
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
inline ll max(ll x,ll y){
	return x>y?x:y;
}
inline ll min(ll x,ll y){
	return x<y?x:y;
}
const int N=305;
ll T=1,n,k,h[N],c[N];
signed main(){
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
//	T=read();
	while(T--){
		n=read();
		k=read();
		for(int i=1;i<=n;i++){
			h[i]=read();
			c[i]=read();
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Mamba return
#define Out 0;
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
		x=-x;
		putchar('-');
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
const int N=1005;
ll T=1,n,a[N],ans=1e9,b[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
			b[i]=b[i-1]+a[i];
		}
		for(int i=1;i<n;i++){
			ll res=b[i];
			for(int j=1;j<=i;j++){
				ll num=b[n]-b[i];
				for(int k=n;k>i;k--){
					ans=min(ans,abs(res-num));
					num-=a[k];
				}
				res-=a[j];
			}
		}
		write(ans);
		putchar('\n');
	}
	Mamba Out
}

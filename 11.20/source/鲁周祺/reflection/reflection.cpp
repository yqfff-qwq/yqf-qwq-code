#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lowbit(x) x&-x
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
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
const int N=2e5+5;
ll T=1,n,q,c,a[N],b[105][N];
signed main(){
	freopen("reflection.in","r",stdin);
	freopen("reflection.out","w",stdout);
//	T=read();
	while(T--){
		n=read();
		q=read();
		c=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		for(int i=1;i<=100;i++){
			b[i][0]=i;
			for(int j=1;j<=n;j++){
				b[i][j]=abs(a[j]-b[i][j-1]);
			}
		}
		while(q--){
			ll l=read(),r=read(),x=read();
			if(l==1&&x<=100){
				write(b[x][r]);
				putchar('\n');
				continue;
			}
			for(int i=l;i<=r;i++){
				x=abs(a[i]-x);
			}
			write(x);
			putchar('\n');
		}
	}
	return 0;
}
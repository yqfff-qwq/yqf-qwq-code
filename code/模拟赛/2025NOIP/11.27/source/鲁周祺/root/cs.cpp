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
ll T=1,n;
inline ll sol(ll x){
	return (x*n+1)^(n-1);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen("cs.out","w",stdout);
//	T=read();
	while(T--){
		n=13771770778412;
		for(int i=65620;i<=65624;i++){
			write(sol(i));
			putchar('\n');
		}
//		for(int i=0;i<=873;i++){
//			write((i*n+1)^(n-1));
//			putchar('\n');
//		}
	}
	return 0;
}
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
inline ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
const int N=2e5+5,mod=998244353;
ll T=1,n,k,a[N];
signed main(){
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		k=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		if(n==2){
			ll x=gcd(a[1],a[2]);
			x=gcd(x,k);
			write((k/x+1)%mod);
			putchar('\n');
		}
	}
	return 0;
}
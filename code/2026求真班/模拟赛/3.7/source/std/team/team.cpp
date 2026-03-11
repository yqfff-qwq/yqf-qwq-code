#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Mamba return
#define Out 0;
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-f;
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
inline ll max(ll x,ll y){
	return x>y?x:y;
}
const int N=2e5+5;
ll n,a[N],mx=1;
signed main(){
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	ll l=1,r=1;
	while(r<n){
		r++;
		if(a[r]-a[l]>5){
			mx=max(mx,r-l);
			while(a[r]-a[l]>5) l++;
		}
	}
	mx=max(mx,r-l+1);
	write(mx);
	putchar('\n');
	Mamba Out
}

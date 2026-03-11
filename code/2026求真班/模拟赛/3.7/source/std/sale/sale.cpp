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
const int N=505;
ll n,a[N],mx;
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	n+=2;
	for(int i=1;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				mx=max(mx,a[i]|a[j]|a[k]);
			}
		}
	}
	write(mx);
	putchar('\n');
	Mamba Out
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) x&-x
#define pb push_back
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
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
		x=-x;
		putchar('-');
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}
const int N=2e5+5;
ll T=1,n,m,gen;
signed main(){
//	freopen("rplexq.in","r",stdin);
//	freopen("rplexq.out","w",stdout);
//	T=read();
	while(T--){
		n=read();
		m=read();
		gen=read();
		
	}
	return 0;
}

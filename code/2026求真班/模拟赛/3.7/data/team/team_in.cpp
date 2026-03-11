#include<bits/stdc++.h>
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
const ll P=1e9;
ll T=1,n;
mt19937 rnd(time(0));
signed main(){
//	freopen(".in","r",stdin);
	freopen("team3_5.in","w",stdout);
//	T=read();
	while(T--){
		n=2e5;
		write(n);
		putchar('\n');
		ll x;
		for(int i=1;i<=n;i++){
			x=rnd()%P+1ll;
//			x=1e9;
			write(x);
			if(i!=n) putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}

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
const int N=2e5+5;
ll T=1,n;
string s;
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
//	T=read();
	while(T--){
		cin>>s;
		n=s.size();
		s=" "+s;
		ll ans=1;
		for(int i=2;i<=n;i++){
			if(s[i]!=s[i-1]) break;
			ans++;
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}

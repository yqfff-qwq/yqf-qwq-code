#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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
ll T=1,n,m,ans;
inline ll sol(ll x){
	return (x*n+1)^(n-1);
}
signed main(){
	freopen("root.in","r",stdin);
	freopen("root.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		m=read();
		ans=0;
		if((n-1)^1<=m) ans++;
		if(sol(1)>m){
			if(sol(2)<=m) ans++;
			write(ans);
			putchar('\n');
			continue;
		}
		ll l=1,r=((1ll<<60)-1)/n+1,_,__;
		while(l<r){
			_=l;
			__=r;
			ll mid=l+r>>1;
//			write(mid);
//			putchar('\n');
			if(sol(mid)<=m){
				if(mid>1&&sol(mid-1)>m){
					l=mid-1;
//					puts("1");
					break;
				}else{
					if(sol(mid+1)<=m) l=mid+1;
					else if(sol(mid+2)<=m){
						l=mid+1;
//						puts("2");
						break;
					}else{
						l=mid;
//						puts("3");
						break;
					}
				}
			}else{
				if(sol(mid+1)<=m){
					l=mid;
//					puts("4");
					break;
				}else{
					if(mid>1&&sol(mid-1)>m){
						r=mid-1;
//						if(mid>2&&sol(mid-2)<=m){
//							l=mid-2;
//							puts("5");
//							break;
//						}else{
//							r=mid-2;
//						}
					}else{
						if(mid>2&&sol(mid-2)>m){
							l=mid-2;
//							puts("6");
							break;
						}else{
							l=mid-1;
//							puts("7");
							break;
						}
					}
				} 
			}
			if(l==_&&r==__) break;
		}
		write(l+ans);
//		write(sol(l));
//		putchar(' ');
		putchar('\n');
	}
	return 0;
}
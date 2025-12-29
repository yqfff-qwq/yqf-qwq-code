#include<bits/stdc++.h>
using namespace std;
#define ll int
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
inline ll max(ll x,ll y){
	return x>y?x:y;
}
const int N=1005;
ll T=1,n,p[N],a[N],l,r,c[N],m,mx,cnt;
vector<ll>v[N];
bitset<N>vis;
signed main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
//	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++){
			a[i]=p[i]=read();
			c[a[i]]=i;
		}
		vis[0]=true;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
			m++;
			if(i==a[i]) vis[i]=true;
			if(m==mx){
				if(i-l<=1){
					l=i;
					vis[i]=true;
					continue;
				}
				if(vis[l+1]) continue;
				v[++cnt].pb(l+1);
				vis[l+1]=true;
				for(int j=l+2;j<=i;j++){
					
//					write(j);
//					putchar(' ');
//					write(v[cnt].back());
//					putchar('\n');
					
					if(vis[a[v[cnt].back()]]){
						j++;
						for(int k=l;k<=i;k++){
							if(!vis[k]){
								cnt++;
								v[cnt].pb(k);
								vis[k]=true;
								break;
							}
						}
						continue;
					}
					vis[a[v[cnt].back()]]=true;
					v[cnt].pb(a[v[cnt].back()]);
				}
				l=i;
			}
		}
		
		
		write(cnt);
		putchar('\n');
		for(int i=1;i<=cnt;i++){
			write(v[i].size());
			putchar(' ');
			for(auto j:v[i]){
				write(j);
				putchar(' ');
			}
			putchar('\n');
		}
	}
	return 0;
}

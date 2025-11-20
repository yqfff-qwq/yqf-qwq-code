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
const int N=1e5+5;
ll T=1,n,q,base,mod,a[N],cnt=1,head[N],dict[N],par[N],in[N],b[N],m,ans[N],c[N];
unordered_map<ll,bool>mp;
struct edge{
	ll to,next;
}e[N<<1];
inline void add(ll u,ll v){
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt++;
}
inline void dfs1(ll x){
	for(int i=head[x];i;i=e[i].next){
		ll z=e[i].to;
		if(z!=par[x]){
			dict[z]=dict[x]+1;
			par[z]=x;
			dfs1(z);
		}
	}
}
inline void dfs(ll x,ll p){
	for(int i=head[x];i;i=e[i].next){
		ll z=e[i].to;
		if(z!=p){
			b[++m]=a[z];
			c[z]=m;
			dfs(z,x);
		}
	}
}
signed main(){
	freopen("temple.in","r",stdin);
	freopen("temple.out","w",stdout);
//	T=read();
	while(T--){
		n=read();
		base=read();
		mod=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		for(int i=1;i<n;i++){
			ll u=read(),v=read();
			add(u,v);
			add(v,u);
			in[u]++;
			in[v]++;
		}
		q=read();
		if(n<=5000&&q<=5000){
			dict[1]=1;
			dfs1(1);
			while(q--){
				ll u=read(),v=read();
				if(u==v){
					puts("No");
					continue;
				}
				if(a[u]==a[v]){
					puts("Yes");
					continue;
				}
				bool f=false;
				mp.clear();
				mp[a[u]]=true;
				mp[a[v]]=true;
				if(dict[u]<dict[v]) swap(u,v);
				while(dict[u]>dict[v]){
					u=par[u];
					if(u==v){
						puts("No");
						f=true;
						break;
					}else if(mp[a[u]]){
						puts("Yes");
						f=true;
						break;
					}else mp[a[u]]=true;
				}
				if(f) continue;
				while(par[u]!=par[v]){
					u=par[u];
					v=par[v];
					if(mp[a[u]]||mp[a[v]]){
						f=true;
						puts("Yes");
						break;
					}
					mp[a[u]]=true;
					mp[a[v]]=true;
				}
				if(f) continue;
				u=par[u];
				puts(mp[a[u]]?"Yes":"No");
			}
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(in[i]==1){
				b[1]=a[i];
				c[i]=1;
				m=1;
				dfs(i,0);
				break;
			}
		}
		ll l=1,r=1;
		mp[b[1]]=true;
		while(r<m){
			r++;
			while(mp[b[r]]){
				mp[b[l]]=false;
				ans[l++]=r-1;
			}
			mp[b[r]]=true;
		}
		for(int i=m;i>=1;i--){
			if(ans[i]==0) ans[i]=m;
		}
		while(q--){
			ll u=read(),v=read();
			if(c[u]>c[v]) swap(u,v);
			puts(ans[c[u]]<v?"Yes":"No");
		}
	}
	return 0;
}
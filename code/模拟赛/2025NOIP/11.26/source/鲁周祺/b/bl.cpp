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
ll T=1,n,m,t,U,V,cnt=1,head[N],dis[N],ans=1e18,d[N];
bitset<N>vis,is,flag;
struct edge{
	ll to,next,w;
}e[N<<1];
struct node{
	ll x,y;
	bool operator< (const node& g) const {
		return y>g.y;
	}
};
inline void add(ll u,ll v,ll w){
	e[cnt].next=head[u];
	e[cnt].to=v;
	e[cnt].w=w;
	head[u]=cnt++;
}
inline void dij(ll s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	for(int i=1;i<=n;i++) vis[i]=false;
	priority_queue<node>q;
	q.push({s,0});
	while(!q.empty()){
		node p=q.top();
		q.pop();
		ll x=p.x,y=p.y;
		if(vis[x]) continue;
		vis[x]=true;
		for(int i=head[x];i;i=e[i].next){
			ll z=e[i].to,w=e[i].w;
			if(dis[z]>dis[x]+w){
				dis[z]=dis[x]+w;
				if(!vis[z]) q.push({z,dis[z]});
			}
		}
	}
}
inline void dfs(ll x,ll y){
	for(int i=head[x];i;i=e[i].next){
		ll z=e[i].to,w=e[i].w;
		if(z==t){
			is[x]=true;
			continue;
		}
		if(!vis[z]&&w+y<=dis[z]){
			vis[z]=true;
			dfs(z,w+y);
			if(is[z]) is[x]=true;
		}else if(w+y<=dis[z]&&is[z]) is[x]=true;
	}
}
inline void dfs1(ll x){
	for(int i=head[x];i;i=e[i].next){
		ll z=e[i].to;
		if(!vis[z]&&is[z]){
			e[i].w=0;
			vis[z]=true;
			dfs1(z);
		}
	}
}
inline void dfs2(ll x,ll y){
	if(x==t){
		dij(U);
		ans=min(ans,dis[V]);
		return;
	}
	for(int i=head[x];i;i=e[i].next){
		ll z=e[i].to,w=e[i].w;
		if(!flag[z]&&w+y<=d[z]){
			flag[z]=true;
			e[i].w=0;
			dfs2(z,w+y);
			flag[z]=false;
			e[i].w=w;
		}
	}
}
signed main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
//	T=read();
	while(T--){
		n=read();
		m=read();
		ll s=read();
		t=read();
		U=read();
		V=read();
		for(int i=1;i<=m;i++){
			ll u=read(),v=read(),w=read();
			add(u,v,w);
			add(v,u,w);
		}
		dij(s);
		for(int i=1;i<=n;i++){
			write(dis[i]);
			putchar('\n');
		}
	}
	return 0;
}

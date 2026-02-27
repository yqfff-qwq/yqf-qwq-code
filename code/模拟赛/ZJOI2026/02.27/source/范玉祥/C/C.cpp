#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define uint unsigned int
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>
const int inf=0x3f3f3f3f;
inline int rd(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const int N=2e5+5;
int n,t[N],q,k,sz[N],dfn[N],idx[N],cnt,son[N],top[N],f[N];
vi e[N];
int lb(int x){
	if(x==0)return 0;
	int mul=1;
	while(x%k==0){
		x/=k;
		mul*=k;
	}
	return x%k*mul;
}
void upd(int p,int v){
	for(;p<=n+1;p+=p&-p)t[p]^=v;
}
void add(int l,int r,int v){
	upd(l,v);upd(r+1,v);
}
int qry(int p){
	int s=0;
	for(;p;p-=p&-p)s^=t[p];
	return s;
}
void dfs1(int u,int fa){
	sz[u]=1;f[u]=fa;
	for(auto v:e[u]){
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v])son[u]=v;
	}
}
void dfs2(int u,int fa){
	idx[dfn[u]=++cnt]=u;top[u]=fa;
	if(son[u])dfs2(son[u],fa);
	for(auto v:e[u])if(v^son[u])dfs2(v,v);
}
void mdf(int u,int w){
	while(u){
		int v=top[u];
		add(dfn[v],dfn[u],w);
		u=f[v];
	}
}
int getans(int p){
	int s=0;
	for(;p;p-=lb(p))s^=qry(dfn[p]);
	return s;
}
signed main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	n=rd();q=rd(),k=rd();
	for(int i=1;i<=n;i++){
		int x=lb(i);
		e[min(n+1,i+x)].pb(i);
	}
	dfs1(n+1,0);
	dfs2(n+1,n+1);
	for(int op,p,v;q--;){
		op=rd(),p=rd();
		if(op==1)v=rd(),mdf(p,v);
		else cout<<getans(p)<<'\n';
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

namespace quick_io{
	template<typename T>
	void input(T &x){
		x=0;
		bool f=0;
		char ch=' ';
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
		if(f) x=-x;
	}

	template<typename T>
	void print(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) print(x/10);
		putchar(x%10+'0');
	}
}
using namespace quick_io;

const int N=1e5+10;

bitset<N> a[N];

int l[N<<1],ne[N<<1],head[N],tail[N],idx;

void con(int u,int v){
	idx++;
	l[idx]=v;
	if(head[u]) ne[tail[u]]=idx;
	else head[u]=idx;
	tail[u]=idx;
}

int dep[N],fa[N],sz[N],son[N];
void dfs1(int u){
	sz[u]=1;
	for(int i=head[u];i;i=ne[i]){
		int v=l[i];
		if(fa[u]==v) continue;
		fa[v]=u;
		dep[v]=dep[u]+1;
		a[v]^=a[u];
		dfs1(v);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}

int top[N];
void dfs2(int u){
	if(!son[u]) return;
	top[son[u]]=top[u];
	dfs2(son[u]);
	for(int i=head[u];i;i=ne[i]){
		int v=l[i];
		if(fa[u]==v) continue;
		if(son[u]==v) continue;
		top[v]=v;
		dfs2(v);
	}
}

int LCA(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) u^=v^=u^=v;
		u=fa[top[u]];
	}
	if(dep[u]<dep[v]) return u;
	else return v;
}

int n,base,mod,q;
signed main(){
	freopen("temple.in","r",stdin);
	freopen("temple.out","w",stdout);
	input(n);
	input(base);
	input(mod);
	for(int i=1;i<=n;i++){
		int t;
		input(t);
		a[i][t]=1;
	}
	for(int i=1;i<n;i++){
		int u,v;
		input(u);
		input(v);
		con(u,v);
		con(v,u);
	}
	fa[1]=0;
	dep[1]=1;
	dfs1(1);
	top[1]=1;
	dfs2(1);
	input(q);
	while(q--){
		int u,v;
		input(u);
		input(v);
		int lca=LCA(u,v);
		int d=dep[u]+dep[v]-2*dep[lca]+1;
		auto t=a[u]^a[v]^a[lca]^a[fa[lca]];
		if(t.count()==d) puts("No");
		else puts("Yes");
	}
}


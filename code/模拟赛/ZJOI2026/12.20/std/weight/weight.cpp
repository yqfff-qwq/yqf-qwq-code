//A tree without skin will surely die.
//A man without face will be alive.
#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define per(i,j,k) for(int i=j;i>=k;--i)
int const N=3e5+10,mod=998244353;
unsigned int t,w[N],Q[N];
int n,L[N],R[N],rev[N],cnt,ans[N],Fa[N],top[N],heavy[N],siz[N];
vector<int>a[N],qry1[N],qry2[N];
inline void dfs(int x,int fa){
	Q[x]=Q[fa]^w[x],Fa[x]=fa,siz[x]=1;
	for (auto v:a[x]) if (v^fa){
		dfs(v,x),siz[x]+=siz[v];
		if (siz[v]>siz[heavy[x]]) heavy[x]=v;
	}
}
inline void Dfs(int x,int fa,int tp){
	top[x]=tp,L[x]=++cnt,rev[cnt]=x;
	if (heavy[x]) Dfs(heavy[x],x,tp);
	for (auto v:a[x]){
		if (v==fa || v==heavy[x]) continue;
		Dfs(v,x,v);
	}
	R[x]=cnt;
}
struct Trie{
	int ch[N*32][2],siz[N*32],cnt=1;
	inline void insert(unsigned int x,int v){
		int nw=1;
		per(i,31,0){
			if (!ch[nw][x>>i&1]) ch[nw][x>>i&1]=++cnt,ch[cnt][0]=ch[cnt][1]=siz[cnt]=0;
			nw=ch[nw][x>>i&1],siz[nw]+=v;
		}
	}
	inline int query(unsigned int val){
		int nw=1,res=0;
		per(i,31,0){
			bool it=val>>i&1;
			if (t>>i&1) res+=siz[ch[nw][it]];
			nw=ch[nw][it^(t>>i&1)];
		}
		return res;
	}
}T;
inline void dfs1(int x,int fa){
	for (auto v:a[x]){
		if (v==fa) continue;
		if (v==heavy[x]) continue;
		dfs1(v,x);
		for (auto id:qry1[v]) ans[id]-=T.query(Q[id]^w[x]);
		rep(i,L[v],R[v]) T.insert(Q[rev[i]],-1);
	}
	if (heavy[x]) dfs1(heavy[x],x);
	T.insert(Q[x],1);
	for (auto v:a[x]){
		if (v==fa) continue;
		if (v==heavy[x]) continue;
		rep(i,L[v],R[v]) T.insert(Q[rev[i]],1);
	}
	for (auto v:a[x]){
		if (v==fa) continue;
		if (v==heavy[x]) continue;
		for (auto id:qry1[v]) ans[id]+=T.query(Q[id]^w[x]);
	}
	ans[x]+=T.query(Q[x]^w[x]);
}
inline void dfs2(int x,int fa,bool tg){
	if (tg){
		int t=x;
		while (t){
			for (auto v:a[t]){
				if (v==Fa[t]) continue;
				if (v==heavy[t]) continue;
				rep(g,L[v],R[v]) T.insert((Q[rev[g]]^w[t]),1);
			}
			T.insert((Q[t]^w[t]),1);
			for (auto id:qry2[t]) ans[id]+=T.query(Q[id]);
			t=heavy[t];
		}
		T.ch[1][0]=T.ch[1][1]=0,T.cnt=1;
	}
	for (auto v:a[x]){
		if (v==fa) continue;
		dfs2(v,x,(v!=heavy[x]));
	}
}
inline void solve(){
	cin>>n;
	rep(i,1,n-1){
		int u,v;cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	rep(i,1,n) cin>>w[i];
	cin>>t,dfs(1,0),Dfs(1,0,1);
	int times=1,gg=1;
	rep(i,1,n) gg=1ll*gg*n%mod;
	rep(i,1,n){
		int x=i,las=0;
		while (x){
			if (las) qry1[las].push_back(i);
			if (top[x]!=x) qry2[Fa[x]].push_back(i);
			las=top[x],x=Fa[top[x]];
		}
	}
	dfs1(1,0),T.cnt=1,T.ch[1][0]=T.ch[1][1]=0,dfs2(1,0,1);
	rep(i,1,n) times=1ll*times*ans[i]%mod,times%=mod;
	gg+=mod-times,gg%=mod,cout<<gg<<'\n';
}
signed main(){
	freopen("weight.in","r",stdin);
	freopen("weight.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	// cin>>t;
	while (t--) solve();
	return 0;
}
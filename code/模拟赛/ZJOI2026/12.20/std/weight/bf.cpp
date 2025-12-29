//A tree without skin will surely die.
//A man without face will be alive.
#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define per(i,j,k) for(int i=j;i>=k;--i)
int const N=3e5+10,mod=998244353;
unsigned int t,w[N],Q[N];
int n,dep[N],Fa[N];vector<int>a[N];
inline void dfs(int x,int fa){
	Q[x]=Q[fa]^w[x],dep[x]=dep[fa]+1,Fa[x]=fa;
	for (auto v:a[x]) if (v^fa) dfs(v,x);
}
inline int LCA(int x,int y){
	while (x^y)
		if (dep[x]>dep[y]) x=Fa[x];
		else y=Fa[y];
	return x;
}
inline void solve(){
	cin>>n;
	rep(i,1,n-1){
		int u,v;cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	rep(i,1,n) cin>>w[i];
	cin>>t,dfs(1,0);
	int times=1,gg=1;
	rep(i,1,n) gg=1ll*gg*n%mod;
	rep(i,1,n){
		int res=0;
		rep(j,1,n)
			if ((Q[i]^Q[j]^w[LCA(i,j)])<t) ++res,cout<<i<<','<<j<<" pair!\n";
		cout<<res<<" ???\n";
		times=1ll*times*res%mod,times%=mod;
	}
	gg+=mod-times,gg%=mod,cout<<gg<<'\n';
}
signed main(){
	freopen("3.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	// cin>>t;
	while (t--) solve();
	return 0;
}
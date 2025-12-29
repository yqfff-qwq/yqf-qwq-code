#include<bits/stdc++.h>
using namespace std;
int const N=4e3+5;
struct Query{
	int id,l,r;
}; vector<Query>Q[N];
vector<int>G[N];
int ans[N];
int f[N][N];
int n;
void dfs(int u,int fa){
	for(int i=u;i<=n;i++)
		f[u][i]=1;
	int now=1;
	for(int v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		for(int i=1;i<=n;i++)
			f[u][i]+=f[v][i];
	}
	for(auto q:Q[u]){
		int total=f[u][q.r]-f[u][q.l-1];
		int res=total*(total-1)/2;
		for(int v:G[u]){
			if(v==fa)continue;
			int part=f[v][q.r]-f[v][q.l-1];
			res-=part*(part-1)/2;
		}
		ans[q.id]=res;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("rplexq.in","r",stdin);
	freopen("rplexq.out","w",stdout);
	int m,r;
	cin>>n>>m>>r;
	for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	for(int i=1;i<=m;i++){
		int l,r,x; cin>>l>>r>>x;
		Q[x].emplace_back(Query{i,l,r});
	}
	dfs(r,0);
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<'\n';
	return 0;
}
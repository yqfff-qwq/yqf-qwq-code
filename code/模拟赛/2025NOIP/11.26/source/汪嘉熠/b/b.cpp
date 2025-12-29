#include<bits/stdc++.h>
using namespace std;
int const N=1e5+5;
using LL=long long;
int n,m,p1,p2,st,ed;
namespace space{
	struct Edge{
		int v;
		LL w;
	}; vector<Edge>G[N];
	struct Node{
		int u;
		LL w;
		bool operator<(const Node&nd)const{
			return w>nd.w;
		}
	};
	void Dijkstra(int st_p,LL*dist){
		for(int i=1;i<=n;i++)dist[i]=1e18;
		dist[st_p]=0ll;
		priority_queue<Node>pq;
		pq.emplace(Node{st_p,0ll});
		bitset<N>mark;
		while(!pq.empty()){
			int u=pq.top().u;
			LL w=pq.top().w;
			pq.pop();
			if(mark[u])continue;
			mark[u]=1;
			for(auto it:G[u])
				if(w+it.w<dist[it.v]){
					dist[it.v]=w+it.w;
					pq.emplace(Node{it.v,w+it.w});
				}
		}
	}
	LL dist1[N],dist2[N],dist3[N];
	bitset<N>mark;
	#define min(x,y) ((x)<(y)?(x):(y))
	LL f[N],g[N];
	void dfs(int u){
		if(mark[u])return;
		mark[u]=1;
		LL ff=dist2[u],gg=dist3[u];
		for(auto it:G[u])
			if(dist1[it.v]+it.w==dist1[u]){
				dfs(it.v);
				LL nf=min(f[it.v],dist2[u]);
				LL ng=min(g[it.v],dist3[u]);
				if(ff+gg>nf+ng)
					ff=nf,gg=ng;
			}
		f[u]=ff,g[u]=gg;
	}
	void solve(){
		while(m--){
			int u,v; LL w;
			cin>>u>>v>>w;
			G[u].emplace_back(Edge{v,w});
			G[v].emplace_back(Edge{u,w});
		}
		Dijkstra(p1,dist1);
		Dijkstra(st,dist2);
		Dijkstra(ed,dist3);
		dfs(p2);
		LL ans=min(dist2[ed],f[p2]+g[p2]);
		cout<<ans;
		return;
	}
	#undef min(x,y)
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n>>m;
	cin>>p1>>p2;
	cin>>st>>ed;
	space::solve();
	return 0;
}

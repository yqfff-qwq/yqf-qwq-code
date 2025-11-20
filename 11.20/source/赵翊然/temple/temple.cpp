#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
constexpr int N=100011;
constexpr int P=21;
int n,q,tot,base,mod;
int a[N],val[N],dfn[N],st[P][N],dep[N];
vector<int> e[N];
bitset<N> vis[N];
int get(int x,int y){
	return dfn[x] < dfn[y] ? x : y;
}
void dfs(int step,int la){
	dfn[step]=++tot;
	st[0][tot]=la;
	dep[step]=dep[la] + 1;
	for(auto i : e[step]){
		if(i == la) continue;
		vis[i]=vis[step];
		vis[i].flip(a[i]);
		dfs(i,step);
	}
}

int Lca(int x,int y){
	if(x == y) return x;
	x=dfn[x];
	y=dfn[y];
	if(x > y) swap(x,y);
	int p=__lg(y-x);
	x++;
	return get(st[p][x],st[p][y -(1 << p) + 1]);
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("temple.in","r",stdin);
    freopen("temple.out","w",stdout);
	cin>>n>>base>>mod;
	for(int i=1;i<= n;i++)
	cin>>a[i];
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	vis[1][a[1]]=1;
	dfs(1,0);
	for(int j=1;j<=20;j++)
	for(int i=1;i+(1<<(j-1))<=n;i++)
	st[j][i]=get(st[j-1][i],st[j-1][i+(1<<(j-1))]);
	cin>>q;
	while(q--){
		int x,y,lca;
		bitset<N> v;
		cin>>x>>y;
		lca=Lca(x,y);
		v[a[lca]]=1;
		if((vis[x]^vis[y]^v).count()==(dep[x]+dep[y]-dep[lca]*2+1))
		cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
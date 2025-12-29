#include<bits/stdc++.h>
using namespace std;
int const N=1e5+5;
int to[N];
int cnt=0;
vector<int>G[N];
bitset<N>mark;
bool dfs(int u,int st){
	if(mark[u])return false;
	if(u==st){
		cnt++;
		G[cnt].emplace_back(u);
		return true;
	}
	mark[u]=1;
	if(dfs(to[u],st)){
		G[cnt].emplace_back(u);
		return true;
	}
	return false;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	int n; cin>>n;
	for(int i=1;i<=n;i++){
		int fa; cin>>fa;
		to[fa]=i;
	}
	for(int u=1;u<=n;u++){
		if(to[u]==u){
			mark[u]=1;
			continue;
		}
		dfs(to[u],u);
	}
	cout<<cnt<<'\n';
	for(int i=1;i<=cnt;i++){
		cout<<G[i].size()<<' ';
		for(int it:G[i])
			cout<<it<<' ';
		cout<<'\n';
	}
	return 0;
}
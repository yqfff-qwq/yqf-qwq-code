#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int p[N];
bool vis[N];
int x;
vector<int> ans[N];
void dfs(int u,int f){
	vis[u]=1;
	ans[x].push_back(p[u]);
	if(p[u]==f)return;
	dfs(p[u],f);
}
signed main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		if(i!=p[i]&&!vis[i]){
			x++;
			dfs(i,i);
		}
	}
	cout<<x<<'\n';
	for(int i=1;i<=x;i++){
		cout<<ans[i].size()<<' ';
		for(int j=0;j<ans[i].size();j++)cout<<ans[i][j]<<' ';
		cout<<'\n';
	}
	return 0;
}

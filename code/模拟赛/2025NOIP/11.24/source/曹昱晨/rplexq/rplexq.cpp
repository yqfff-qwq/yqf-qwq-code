#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int Cnt,Head[N],Next[N<<1],Go[N<<1];
void Add(int u,int v){
	Next[++Cnt]=Head[u];
	Head[u]=Cnt;
	Go[Cnt]=v;
	return;
}
int fa[N];
vector<int> son[N];
void dfs(int u,int f){
	for(int i=Head[u];i;i=Next[i]){
		int v=Go[i];
		if(v!=f){
			fa[v]=u;
			son[u].push_back(v);
			dfs(v,u);
		}
	}
	return;
}
int solve(int l,int r,int u){
	int re=0;
	if(l<=u&&u<=r)re++;
	for(int i=0;i<son[u].size();i++){
		re+=solve(l,r,son[u][i]);
	}
	return re;
}
int calc(int l,int r,int x){
	vector<int> v;
	int sum=0;
	if(l<=x&&x<=r){
		v.push_back(1);
		sum++;
	}
	for(int i=0;i<son[x].size();i++){
		int s=solve(l,r,son[x][i]);
		if(s>0){
			v.push_back(s);
			sum+=s;
		}
	}
	int ans=0;
	for(int i=0;i<v.size();i++){
		ans+=v[i]*(sum-v[i]);
	}
	return ans>>1;
}
signed main(){
	freopen("rplexq.in","r",stdin);
	freopen("rplexq.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m,r;
	cin>>n>>m>>r;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		Add(u,v),Add(v,u);
	}
	dfs(r,0);
	for(int i=1;i<=m;i++){
		int l,r,x;
		cin>>l>>r>>x;
		cout<<calc(l,r,x)<<'\n';
	}
	return 0;
}

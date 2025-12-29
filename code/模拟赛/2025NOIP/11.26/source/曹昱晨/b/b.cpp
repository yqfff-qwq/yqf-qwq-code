#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+5,M=4e5+5;
struct cyc{
	long long go,p;
	bool operator <(const cyc c)const{
		return p>c.p;
	}
}e[M];
long long Cnt=1,Head[N],Next[M];
void Add(long long u,long long v,long long w){
	Next[++Cnt]=Head[u];
	Head[u]=Cnt;
	e[Cnt].go=v,e[Cnt].p=w;
}
long long n,m,s,t,u,v,cnt;
long long ans[N];
bool vis[N];
vector<cyc> fa[N];
vector<vector<long long> > E;
void dfs(long long u,long long st,vector<long long> &v){
	if(u==st){
		E.push_back(v);
		return;
	}
	int len=v.size();
	for(long long i=0;i<fa[u].size();i++){
		if(i==0)v.push_back(fa[u][i].p);
		else v[len]=fa[u][i].p;
		dfs(fa[u][i].go,st,v);
		v[len]=0;
	}
}
void Dijstra(long long st,long long ed,bool bb){
	memset(ans,0x3f,sizeof ans);
	memset(vis,0,sizeof vis);
	priority_queue<cyc> q;
	ans[st]=0,vis[st]=1;
	for(long long i=Head[st];i;i=Next[i]){
		ans[e[i].go]=e[i].p;
		if(bb)fa[e[i].go].push_back({st,i});
		q.push(e[i]);
	}
	while(!q.empty()){
		cyc t=q.top();
		while(!q.empty()&&vis[t.go]){
			q.pop();
			t=q.top();
		}
		vis[t.go]=1;
		for(long long i=Head[t.go];i;i=Next[i]){
			if(!vis[e[i].go]){
				if(ans[e[i].go]==ans[t.go]+e[i].p){
					if(bb)fa[e[i].go].push_back((cyc){t.go,i});
				}
				else if(ans[e[i].go]>ans[t.go]+e[i].p){
					ans[e[i].go]=ans[t.go]+e[i].p;
					q.push((cyc){e[i].go,ans[e[i].go]});
					if(bb){
						fa[e[i].go].clear();
						fa[e[i].go].push_back((cyc){t.go,i});
					}
				}
			}
		}
	}
}
long long Ans=0x3f3f3f3f3f3f3f3f;
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>s>>t>>u>>v;
	for(long long i=1;i<=m;i++){
		long long a,b,c;
		cin>>a>>b>>c;
		Add(a,b,c),Add(b,a,c);
	}
	Dijstra(s,t,1);
	vector<long long> newvector;
	dfs(t,s,newvector);
	for(long long i=0;i<E.size();i++){
		vector<long long> del;
		for(long long j=0;j<E[i].size();j++){
			del.push_back(e[E[i][j]].p);
			e[E[i][j]].p=e[E[i][j]^1].p=0;
		}
		Dijstra(u,v,0);
		Ans=min(Ans,ans[v]);
		for(long long j=0;j<E[i].size();j++){
			e[E[i][j]].p=e[E[i][j]^1].p=del[j];
		}
	}
	cout<<Ans;
	return 0;
}
/*
8 8
5 7
6 8
1 2 2
2 3 3
3 4 4
1 4 1
1 5 5
2 6 6
3 7 7
4 8 8
*/

#include <bits/stdc++.h>
//#define int long long
using namespace std;
int n,m,S,T,s,t,u,v,w,d[100005];bool f[100005];
int H[100005],N[400005],V[400005],W[400005],l=1;
priority_queue<pair<int,int> > q;vector<int> ve;
void add(int u,int v,int w){N[++l]=H[u];H[u]=l;V[l]=v;W[l]=w;}
void dij(int S)
{
	memset(d,0x3f,sizeof(d));
	memset(f,false,sizeof(f));
	d[S]=0;q.push({0,S});
	while(!q.empty())
	{
		u=q.top().second;q.pop();
		if(f[u])continue;f[u]=true;
		for(int i=H[u];i;i=N[i])
		{
			if(d[V[i]]<=d[u]+W[i])continue;
			d[V[i]]=d[u]+W[i];q.push({-d[V[i]],V[i]});
		}
	}
}
void dfs(int u)
{
	if(f[u])return ;f[u]=true;
	for(int i=H[u];i;i=N[i])
	{
		if(d[V[i]]+W[i]==d[u]){ve.push_back(i);dfs(V[i]);}
	}
}
signed main()
{
//	freopen("b2.txt","r",stdin);
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m>>S>>T>>s>>t;
    for(int i=1;i<=m;i++){cin>>u>>v>>w;add(u,v,w);add(v,u,w);}
    dij(S);memset(f,false,sizeof(f));dfs(T);
    for(auto i:ve)W[i]=W[i^1]=0;
    dij(s);cout<<d[t];
    return 0;
}
//31pts WA
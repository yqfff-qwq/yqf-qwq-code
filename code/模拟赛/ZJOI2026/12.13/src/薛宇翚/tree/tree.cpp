#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=135;
int n,a[N],m,as,fa[N][15],d[N];
vector<int>g[N],h[N];
void dfs(int x,int f)
{
	fa[x][0]=f;
	d[x]=d[f]+1;
	for(int i=0;i<g[x].size();i++)
	{
		if(g[x][i]!=f)
		{
			dfs(g[x][i],x);
		}
	}
}
int lca(int u,int v)
{
	if(d[u]>d[v])
	{
		swap(u,v);
	}
	for(int i=14;i>=0;i--)
	{
		if(d[fa[v][i]]>=d[u])
		{
			v=fa[v][i];
		}
	}
	if(u==v)
	{
		return u;
	}
	for(int i=14;i>=0;i--)
	{
		if(fa[u][i]!=fa[v][i])
		{
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	return fa[u][0];
}
void check(int y)
{
	int ct=1;
	for(int i=1;i<=y;i++)
	{
		int su=0;
		if(h[i].size()==1)
		{
			ct=ct*a[h[i][0]]%m;
			continue;
		}
		int p=-1;
		for(int j=0;j<h[i].size();j++)
		{
			su+=a[h[i][j]];
			su%=m;
			for(int k=j+1;k<h[i].size();k++)
			{
				int q=lca(h[i][j],h[i][k]);
				if(p==-1)
				{
					p=q;
				}
				else if(p!=q)
				{
					return;
				}
			}
		}
		bool fl=1;
		for(int j=0;j<h[i].size();j++)
		{
			if(h[i][j]==p)
			{
				fl=0;
				break;
			}
		}
		if(fl)
		{
			return;
		}
		ct=ct*su%m;
	}
	as=(as+ct)%m;
}
void dfs2(int x,int y)
{
	if(x==n+1)
	{
		check(y);
		return;
	}
	for(int i=1;i<=y+1;i++)
	{
		h[i].push_back(x);
		dfs2(x+1,max(i,y));
		h[i].pop_back();
	}
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for(int j=1;j<15;j++)
	{
		for(int i=1;i<=n;i++)
		{
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
	dfs2(1,0);
	printf("%lld\n",as);
	return 0;
}

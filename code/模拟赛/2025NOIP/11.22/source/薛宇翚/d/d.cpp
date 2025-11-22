#include <bits/stdc++.h>
using namespace std;
const int N=355;
int n,v,p,f[N],a[N][N],fa[N],th[N];
vector<int>g[N];
bool vis[N];
int F(int x)
{
	return x==f[x]?x:F(f[x]);
}
void dfs2(int x,int y)
{
	fa[x]=y;
	for(int i=0;i<g[x].size();i++)
	{
		if(g[x][i]!=y)
		{
			dfs2(g[x][i],x);
		}
	}
}
void check()
{
	dfs2(1,0);
	for(int i=1;i<=n;i++)
	{
		th[i]=0;
	}
	for(int i=1;i<(1<<n);i++)
	{
		for(int j=1;j<=n;j++)
		{
			vis[j]=0;
		}
		int ct=0;
		for(int j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				ct++;
				int x=j+1;
				while(x)
				{
					vis[x]=1;
					x=fa[x];
				}
			}
		}
		int nu=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j])
			{
				nu++;
			}
		}
		th[ct]=max(th[ct],nu);
	}
	for(int i=1;i<=n;i++)
	{
		int &xx=a[i][th[i]];
		xx=(xx+1)%p;
	}
}
void dfs(int x,int y,int ct)
{
	if(x>n)
	{
		if(ct!=n-1)
		{
			return;
		}
		check();
		return;
	}
	if(y>n)
	{
		dfs(x+1,x+2,ct);
		return;
	}
	dfs(x,y+1,ct);
	if(F(x)!=F(y))
	{
		g[x].push_back(y);
		g[y].push_back(x);
		int u=F(x),v=F(y);
		f[u]=v;
		dfs(x,y+1,ct+1);
		f[u]=u;
		g[x].pop_back();
		g[y].pop_back();
	}
}
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	dfs(1,2,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N=155;
int n,v,p,f[N],as,a[N],h[N];
vector<int>g[N];
bool vis[N];
int F(int x)
{
	return x==f[x]?x:F(f[x]);
}
int H(int x)
{
	return x==h[x]?x:h[x]=H(h[x]);
}
void check()
{
	for(int j=0;j<(1<<n);j++)
	{
		for(int i=0;i<n;i++)
		{
			if((j>>i)&1)
			{
				vis[i+1]=1;
			}
			else
			{
				vis[i+1]=0;
			}
			h[i+1]=i+1;
		}
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				continue;
			}
			for(int j=0;j<g[i].size();j++)
			{
				if(vis[g[i][j]])
				{
					h[H(i)]=H(g[i][j]);
				}
			}
		}
		int ct=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]&&H(i)==i)
			{
				ct++;
			}
		}
		if(ct>1)
		{
			continue;
		}
		set<int>s;
		int mi=v+1;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			{
				s.insert(a[i]);
			}
			else
			{
				mi=min(mi,a[i]);
			}
		}
		int me=-1;
		for(int i=0;;i++)
		{
			if(s.find(i)==s.end())
			{
				me=i;
				break;
			}
		}
		if(me!=mi)
		{
			return;
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		cout<<"a["<<i<<"]="<<a[i]<<"\n";
		for(int j=0;j<g[i].size();j++)
		{
			cout<<"eg "<<i<<" "<<g[i][j]<<"\n";
		}
	}
	cout<<"\n";
	*/
	as=(as+1)%p;
}
void dfs2(int x)
{
	if(x>n)
	{
		check();
		return;
	}
	for(int i=0;i<=v;i++)
	{
		a[x]=i;
		dfs2(x+1);
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
		dfs2(1);
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
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n>>v>>p;
	if(v>=n)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	dfs(1,2,0);
	cout<<as<<"\n";
	return 0;
}
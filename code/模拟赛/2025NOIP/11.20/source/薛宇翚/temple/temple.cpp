#include <bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int n,a[N],b,mo,r,fa[N][25],d[N],arr[N],sa[N],mx[N];
vector<int>g[N];
map<int,int>s;
bool fl;
void dfs(int x,int y)
{
	fa[x][0]=25;
	d[x]=d[y]+1;
	sa[x]=arr[a[x]];
	arr[a[x]]=x;
	mx[x]=mx[y];
	if(d[sa[x]]>d[mx[x]])
	{
		mx[x]=sa[x];
	}
	for(int i=0;i<g[x].size();i++)
	{
		int v=g[x][i];
		if(v!=y)
		{
			dfs(v,x);
		}
	}
	arr[a[x]]=sa[x];
}
int lca(int x,int y)
{
	if(d[x]>d[y])
	{
		swap(x,y);
	}
	for(int i=24;i>=0;i--)
	{
		if(d[fa[y][i]]>=d[x])
		{
			y=fa[y][i];
		}
	}
	if(x==y)
	{
		return x;
	}
	for(int i=24;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
void dfs2(int x,int y,int z)
{
	if(fl)
	{
		return;
	}
	s[a[x]]++;
	if(x==z)
	{
		fl=1;
		for(map<int,int>::iterator it=s.begin();it!=s.end();it++)
		{
			if((it->second)>1)
			{
				printf("Yes\n");
				return;
			}
		}
		printf("No\n");
		return;
	}
	for(int i=0;i<g[x].size();i++)
	{
		if(g[x][i]!=y)
		{
			dfs2(g[x][i],x,z);
			if(fl)
			{
				return;
			}
		}
	}
	s[a[x]]--;
	if(!s[a[x]])
	{
		s.erase(a[x]);
	}
}
int main()
{
	freopen("temple.in","r",stdin);
	freopen("temple.out","w",stdout);
	cin>>n>>b>>mo;
	int las=0;
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
	r=1;
	for(int i=1;i<=n;i++)
	{
		if(g[i].size()==1)
		{
			r=i;
			break;
		}
	}
	dfs(r,0);
	for(int i=1;i<=24;i++)
	{
		for(int j=1;j<=n;j++)
		{
			fa[j][i]=fa[fa[j][i-1]][i-1];
		}
	}
	int q;
	cin>>q;
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		if(d[u]>d[v])
		{
			swap(u,v);
		}
		if(lca(u,v)==u)
		{
			//cout<<"!\n";
			printf(d[mx[v]]>=d[u]?"Yes\n":"No\n");
		}
		else
		{
			fl=0;
			s.clear();
			dfs2(u,0,v);
		}
	}
	return 0;
}

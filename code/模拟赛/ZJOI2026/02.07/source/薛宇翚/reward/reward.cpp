#include <bits/stdc++.h>
using namespace std;
#define int long long
void read(int &x)
{
	x=0;
	bool f=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f^=1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^'0');
		c=getchar();
	}
	if(f)
	{
		x=-x;
	}
}
const int N=5e5+100,B=22;
int n,q,a[N],b[N],dfn[N],sz[N],ct,fx[N],ft,as[N],fa[N][B],dep[N];
vector<int>g[N],h[N],inp[N],oup[N];
void dfs(int x)
{
	ct++;
	dfn[x]=ct;
	sz[x]=1;
	for(int i=0;i<g[x].size();i++)
	{
		int v=g[x][i];
		fa[v][0]=x;
		dep[v]=dep[x]+1;
		dfs(v);
		sz[x]+=sz[v];
	}
}
void update(int x,int r)
{
	for(int i=dfn[r];i<dfn[r]+sz[r];i++)
	{
		h[i].push_back(x);
	}
}
void adda(int x)
{
	if(!fx[x])
	{
		ft++;
	}
	fx[x]++;
}
void dela(int x)
{
	fx[x]--;
	if(!fx[x])
	{
		ft--;
	}
}
int lca(int x,int y)
{
	if(dep[x]>dep[y])
	{
		swap(x,y);
	}
	for(int i=B-1;i>=0;i--)
	{
		if(dep[fa[y][i]]>=dep[x])
		{
			y=fa[y][i];
		}
	}
	if(x==y)
	{
		return x;
	}
	for(int i=B-1;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
bool isvis[N];
int As2[N];
void dfs2(int x,int y)
{
	if(isvis[x])
	{
		y=max(y,sz[x]);
	}
	As2[x]=max(y-1,0ll);
	for(int i=0;i<g[x].size();i++)
	{
		dfs2(g[x][i],y);
	}
}
namespace specialB
{
	vector<int>dus[N];
	void main()
	{
		for(int i=1;i<=q;i++)
		{
			if(a[i]==b[i])
			{
				continue;
			}
			dus[a[i]].push_back(b[i]);
			dus[b[i]].push_back(a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			sort(dus[i].begin(),dus[i].end());
			dus[i].erase(unique(dus[i].begin(),dus[i].end()),dus[i].end());
			int as=dus[i].size();
			printf("%lld ",as);
		}
		printf("\n");
	}
}
signed main()
{
	freopen("reward.in","r",stdin);
	freopen("reward.out","w",stdout);
	read(n);
	read(q);
	bool juh=1;
	for(int i=2;i<=n;i++)
	{
		int x;
		read(x);
		g[x].push_back(i);
		juh&=(x==1);
	}
	bool exia=0;
	for(int i=1;i<=q;i++)
	{
		read(a[i]);
		read(b[i]);
		exia|=(a[i]==1||b[i]==1);
	}
	if(exia)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%lld ",n);
		}
		printf("\n");
		return 0;
	}
	if(juh)
	{
		specialB::main();
		return 0;
	}
	dep[1]=1;
	dfs(1);
	for(int j=1;j<B;j++)
	{
		for(int i=1;i<=n;i++)
		{
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
	bool Ofl=1;
	for(int i=1;i<=q;i++)
	{
		int Xx=lca(a[i],b[i]);
		if(Xx==a[i]||Xx==b[i])
		{
			isvis[Xx]=1;
		}
		else
		{
			Ofl=0;
			break;
		}
	}
	if(Ofl)
	{
		dfs2(1,-1);
		for(int i=1;i<=n;i++)
		{
			printf("%lld ",As2[i]);
		}
		printf("\n");
		return 0;
	}
	for(int i=1;i<=q;i++)
	{
		update(i,a[i]);
		update(i,b[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<h[i].size();j++)
		{
			int v=h[i][j];
			inp[dfn[a[v]]].push_back(i);
			oup[dfn[a[v]]+sz[a[v]]-1].push_back(i);
			inp[dfn[b[v]]].push_back(i);
			oup[dfn[b[v]]+sz[b[v]]-1].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<inp[i].size();j++)
		{
			int v=inp[i][j];
			adda(v);
		}
		if(fx[i])
		{
			as[i]=ft-1;
		}
		else
		{
			as[i]=ft;
		}
		for(int j=0;j<oup[i].size();j++)
		{
			int v=oup[i][j];
			dela(v);
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%lld ",as[dfn[i]]);
	}
	printf("\n");
	return 0;
}

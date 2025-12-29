#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x)
{
	bool f=0;
	x=0;
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
void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>=10)
	{
		write(x/10);
	}
	putchar((x%10)^'0');
}
const int N=2e5+100;
int fa[N],n,m,rt,mp[N];
vector<int>g[N];
void dfs(int x,int f)
{
	fa[x]=f;
	for(int i=0;i<g[x].size();i++)
	{
		if(g[x][i]!=f)
		{
			dfs(g[x][i],x);
		}
	}
}
int main()
{
	freopen("rplexq.in","r",stdin);
	freopen("rplexq.out","w",stdout);
	read(n);
	read(m);
	read(rt);
	for(int i=1;i<n;i++)
	{
		int u,v;
		read(u);
		read(v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<vector<int> >a(n+15,vector<int>(n+15,0));
	for(int i=1;i<=n;i++)
	{
		dfs(i,0);
		for(int j=1;j<=n;j++)
		{
			a[j][i]=fa[j];
		}
	}
	while(m--)
	{
		int l,r,x;
		read(l);
		read(r);
		read(x);
		for(int i=0;i<=n;i++)
		{
			mp[i]=0;
		}
		ll as=0;
		for(int j=l;j<=r;j++)
		{
			//cerr<<x<<" "<<j<<" "<<a[x][j]<<" "<<a[x][rt]<<"\n";
			if(a[x][j]!=a[x][rt]||x==rt)
			{
				mp[a[x][j]]++;
				as++;
			}
		}
		as*=as;
		for(int i=0;i<=n;i++)
		{
			as-=1ll*mp[i]*mp[i];
		}
		as>>=1;
		write(as);
		putchar('\n');
	}
	return 0;
}

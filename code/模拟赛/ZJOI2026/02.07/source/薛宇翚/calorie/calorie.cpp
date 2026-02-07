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
const int N=10111;
int n,m,d[N],a[N][211],f[N][1011];
vector<int>g[N];
bool vis[N][211];
int dfs(int p,int st)
{
	if(f[p][st]!=-1)
	{
		return f[p][st];
	}
	if(st==0)
	{
		return f[p][st]=0;
	}
	f[p][st]=0;
	for(int i=0;i<n;i++)
	{
		if((st>>i)&1)
		{
			for(int j=1;j<=m;j++)
			{
				f[p][st]=max(f[p][st],a[p][i+1]-(d[max(p,j)]-d[min(p,j)])+dfs(j,st^(1ll<<i)));
			}
		}
	}
	return f[p][st];
}
signed main()
{
	freopen("calorie.in","r",stdin);
	freopen("calorie.out","w",stdout);
	read(n);
	read(m);
	for(int i=2;i<=m;i++)
	{
		read(d[i]);
		d[i]+=d[i-1];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			read(a[i][j]);
		}
	}
	for(int j=1;j<=n;j++)
	{
		g[j].push_back(1);
		for(int i=2;i<=m;i++)
		{
			if(a[i][j]>a[g[j][0]][j])
			{
				g[j].clear();
				g[j].push_back(i);
			}
			else if(a[i][j]==a[g[j][0]][j])
			{
				g[j].push_back(i);
			}
		}
		for(int i=0;i<g[j].size();i++)
		{
			vis[g[j][i]][j]=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		bool ok=1;
		for(int j=1;j<=n;j++)
		{
			if(!vis[i][j])
			{
				ok=0;
				break;
			}
		}
		if(ok)
		{
			int as=0;
			for(int j=1;j<=n;j++)
			{
				as+=a[i][j];
			}
			printf("%lld\n",as);
			return 0;
		}
	}
	memset(f,-1,sizeof(f));
	int as=0;
	for(int i=1;i<=m;i++)
	{
		as=max(as,dfs(i,(1ll<<n)-1));
	}
	printf("%lld\n",as);
	return 0;
}

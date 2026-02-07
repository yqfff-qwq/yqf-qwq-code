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
const int N=1e6+100;
int n,a[N],le[N],dp[N];
vector<int>g[N];
bool cmp(int x,int y)
{
	return 1ll*le[x]*a[y]<1ll*le[y]*a[x];
}
void dfs(int x)
{
	int leth=0;
	for(int i=0;i<g[x].size();i++)
	{
		int v=g[x][i];
		dfs(v);
		dp[x]+=dp[v];
		leth+=le[v];
		a[x]+=a[v];
	}
	sort(g[x].begin(),g[x].end(),cmp);
	int pres=0;
	for(int i=0;i<g[x].size();i++)
	{
		int v=g[x][i];
		dp[x]+=1ll*pres*a[v];
		pres+=le[v];
	}
	dp[x]+=le[x]*a[x];
	le[x]+=leth;
}
signed main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n);
	for(int i=2;i<=n;i++)
	{
		int f;
		read(f);
		read(le[i]);
		g[f].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
	}
	dfs(1);
	printf("%lld\n",dp[1]);
	return 0;
}

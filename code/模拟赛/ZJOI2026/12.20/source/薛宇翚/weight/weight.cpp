#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353,N=3e5+100;
vector<int>g[N];
ll a[N],t,n,ct;
void dfs(int x,int y,ll z)
{
	z^=a[x];
	if(z<t)
	{
		ct++;
	}
	for(int i=0;i<g[x].size();i++)
	{
		int v=g[x][i];
		if(v!=y)
		{
			dfs(v,x,z);
		}
	}
}
int main()
{
	freopen("weight.in","r",stdin);
	freopen("weight.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	scanf("%lld",&t);
	ll as=1,tot=1;
	for(int i=1;i<=n;i++)
	{
		ct=0;
		dfs(i,0,0);
		as=1ll*as*ct%M;
		tot=1ll*tot*n%M;
	}
	tot=(tot-as+M)%M;
	tot=(tot%M+M)%M;
	printf("%lld\n",tot);
	return 0;
}

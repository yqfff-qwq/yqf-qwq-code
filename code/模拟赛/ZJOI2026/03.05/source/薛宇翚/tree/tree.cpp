#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pii;
const int N=1e4+100;
int n,k,t,fa[N];//,f[N];
ll c[N],val[N],as;
bool vis[N];
/*
int F(int x)
{
	return x==f[x]?x:f[x]=F(f[x]);
}
*/
bool cmp(pii x,pii y)
{
	return x>y;
}
void solve(ll x)
{
	for(int i=0;i<(1<<n);i++)
	{
		int jnt=0;
		for(int j=1;j<=n;j++)
		{
			//f[j]=j;
			vis[j]=((i>>(j-1))&1);
			jnt+=vis[j];
		}
		if(!vis[1]||jnt>k)
		{
			continue;
		}
		bool f=1;
		for(int j=2;j<=n;j++)
		{
			if(vis[j]&&!vis[fa[j]])
			{
				f=0;
				break;
			}
			if(vis[j]&&!c[j])
			{
				f=0;
				break;
			}
		}
		if(f)
		{
			//cerr<<i<<" ok\n";
			vector<pii>g;
			ll xx=x,kk=k;
			for(int j=1;j<=n;j++)
			{
				if(!vis[j])
				{
					continue;
				}
				//cerr<<j<<" ish\n";
				g.push_back(make_pair(val[j],c[j]-1));
				xx+=val[j];
				kk--;
			}
			if(kk<0)
			{
				continue;
			}
			sort(g.begin(),g.end(),cmp);
			for(int j=0;j<g.size();j++)
			{
				if(kk<=g[j].second)
				{
					xx+=1ll*kk*g[j].first;
					break;
				}
				kk-=g[j].second;
				xx+=1ll*g[j].first*g[j].second;
			}
			as=max(as,xx);
		}
	}
}
void dfs(int x,int y,ll z)
{
	if(x==n+1)
	{
		if(y)
		{
			return;
		}
		solve(z);
		return;
	}
	dfs(x+1,y,z);
	if(!y)
	{
		return;
	}
	for(int i=x;i;i=fa[i])
	{
		if(c[i]<=0)
		{
			return;
		}
	}
	for(int i=x;i;i=fa[i])
	{
		c[i]--;
		z+=val[i];
	}
	dfs(x+1,y-1,z);
	for(int i=x;i;i=fa[i])
	{
		c[i]++;
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d%d",&n,&k,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&c[i],&val[i]);
	}
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&fa[i]);
	}
	dfs(1,t,0ll);
	printf("%lld\n",as);
	return 0;
}

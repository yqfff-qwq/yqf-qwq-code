#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,M=125200,L=10010;
int n,m,b[M],ct;
ll d[N*L];
bool vis[N*L];
struct feg
{
	int u,v,w;
}a[M];
int calc(int lev,int v)
{
	return (lev-1)*N+v;
}
struct eg
{
	int v;
	ll w;
	eg(int V=0,ll W=0):v(V),w(W){}
	bool friend operator >(const eg &x,const eg &y)
	{
		return x.w>y.w;
	}
};
vector<eg>g[N*L];
int main()
{
	freopen("fly.in","r",stdin);
	freopen("fly.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		ct++;
		b[ct]=a[i].w;
	}
	sort(b+1,b+ct+1);
	int mt=unique(b+1,b+ct+1)-b-1;
	b[mt+1]=0x1f1f1f1f;
	for(int i=1;i<=m;i++)
	{
		a[i].w=lower_bound(b+1,b+mt+1,a[i].w)-b;
		int ufin=calc(a[i].w,a[i].u),vfin=calc(a[i].w,a[i].v);
		for(int j=1;j<=mt+1;j++)
		{
			int unod=calc(j,a[i].u),vnod=calc(j,a[i].v);
			if(a[i].w>=j)
			{
				g[unod].push_back(eg(vnod,b[j]));
				g[vnod].push_back(eg(unod,b[j]));
			}
			else
			{
				g[unod].push_back(eg(vfin,b[a[i].w]));
				g[vnod].push_back(eg(ufin,b[a[i].w]));
			}
		}
	}
	memset(d,0x3f,sizeof(d));
	d[calc(mt+1,1)]=0;
	priority_queue<eg,vector<eg>,greater<eg> >q;
	q.push(eg(calc(mt+1,1),0));
	while(!q.empty())
	{
		int u=q.top().v;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		if(u%N==n)
		{
			printf("%lld\n",d[u]);
			//while(1);
			return 0;
		}
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].v,w=g[u][i].w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				q.push(eg(v,d[v]));
			}
		}
	}
	return 0;
}

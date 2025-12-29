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
const int N=2e5+100,inf=0x3f3f3f3f3f3f3f3fll;
struct eg
{
	int v,w;
	eg(int vv=0,int ww=0):v(vv),w(ww){}
	bool friend operator >(const eg &x,const eg &y)
	{
		return x.w>y.w;
	}
};
vector<eg>g[N],h[N];
int n,m,s,t,ss,tt,du[N],dv[N],ds[N],dt[N],as;
bool vis[N];
void dij(int x,int d[])
{
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
		d[i]=inf;
	}
	d[x]=0;
	priority_queue<eg,vector<eg>,greater<eg> >q;
	q.push(eg(x,0));
	while(!q.empty())
	{
		int u=q.top().v;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(int i=0;i<g[u].size();i++)
		{
			eg y=g[u][i];
			if(d[y.v]>d[u]+y.w)
			{
				d[y.v]=d[u]+y.w;
				q.push(eg(y.v,d[y.v]));
			}
		}
	}
}
void dij2(int x,int d[])
{
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
		d[i]=inf;
		h[i].clear();
	}
	d[x]=0;
	priority_queue<eg,vector<eg>,greater<eg> >q;
	q.push(eg(x,0));
	while(!q.empty())
	{
		int u=q.top().v;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(int i=0;i<g[u].size();i++)
		{
			eg y=g[u][i];
			if(d[y.v]>d[u]+y.w)
			{
				d[y.v]=d[u]+y.w;
				q.push(eg(y.v,d[y.v]));
				h[y.v].clear();
				h[y.v].push_back(eg(u,y.w));
			}
			else if(d[y.v]==d[u]+y.w)
			{
				h[y.v].push_back(eg(u,y.w));
			}
		}
	}
}
void calc(int x)
{
	if(vis[x])
	{
		return;
	}
	vis[x]=1;
	dt[x]=dv[x];
	for(int i=0;i<h[x].size();i++)
	{
		calc(h[x][i].v);
		dt[x]=min(dt[x],dt[h[x][i].v]);
	}
	as=min(as,dt[x]+du[x]);
}
void cald(int x)
{
	if(vis[x])
	{
		return;
	}
	vis[x]=1;
	dt[x]=du[x];
	for(int i=0;i<h[x].size();i++)
	{
		cald(h[x][i].v);
		dt[x]=min(dt[x],dt[h[x][i].v]);
	}
	as=min(as,dt[x]+dv[x]);
}
signed main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	read(n);
	read(m);
	read(s);
	read(t);
	read(ss);
	read(tt);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		read(u);
		read(v);
		read(w);
		g[u].push_back(eg(v,w));
		g[v].push_back(eg(u,w));
	}
	dij(ss,du);
	dij(tt,dv);
	dij2(s,ds);
	as=du[tt];
	for(int i=1;i<=n;i++)
	{
		dt[i]=inf;
		vis[i]=0;
	}
	calc(t);
	for(int i=1;i<=n;i++)
	{
		dt[i]=inf;
		vis[i]=0;
	}
	cald(t);
	printf("%lld\n",as);
	return 0;
}

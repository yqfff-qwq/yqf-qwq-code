#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define PIII pair<int,pair<int,int> > 
using namespace std;
int n,m,s,t,V,U,ans=1e18;
int ne[400025],e[400025],h[100025],w[400025],idx;
void add(int x,int y,int z)
{
	ne[++idx]=h[x];
	h[x]=idx;
	e[idx]=y; 
	w[idx]=z;
}
int fa[100025],fz[100025],dist[100025];
void remove(int x)
{
	if(x==s) return;
	w[fa[x]]=0;
	if(e[fa[x]+1]==fz[x]) w[fa[x]+1]=0;
	else w[fa[x]-1]=0;
	remove(fz[x]);
}
void dij()
{
	priority_queue<PIII,vector<PIII>,greater<PIII> >q;
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	q.push({0,{s,-1}});
	
	while(!q.empty())
	{
		PIII T=q.top();
		q.pop();
		
		int vis=T.second.first,f=T.second.second,far=T.first;
		if(dist[vis]<far) continue; 
		if(vis==t) 
		{
			remove(t);
			return;
		}
//		cout<<"ILJ";
		
		for(int i=h[vis];i;i=ne[i])
		{
			if(dist[e[i]]>far+w[i])
			{
				fa[e[i]]=i;
				fz[e[i]]=vis;
				dist[e[i]]=far+w[i];
				q.push({dist[e[i]],{e[i],vis}});
			}
		}
	}
}
int dij2(int u,int v)
{
	priority_queue<PII,vector<PII>,greater<PII> >q;
	memset(dist,0x3f,sizeof(dist));
	dist[u]=0;
	q.push({0,u});
	
	while(!q.empty())
	{
		PII T=q.top();
		q.pop();
		
		int vis=T.second,far=T.first;
		if(dist[vis]<far) continue; 
		if(vis==v) return far;
//		cout<<"ILJ";
		
		for(int i=h[vis];i;i=ne[i])
		{
			if(dist[e[i]]>far+w[i])
			{
				dist[e[i]]=far+w[i];
				q.push({dist[e[i]],e[i]});
			}
		}
	}
}
int b[100025],tim;
void dfs(int x,int z,int lim)
{
	if(z>lim)
	{
		cout<<x<<" "<<1<<'\n';
		return;
	}
	if(x==t)
	{ 
//		cout<<"ILJ";
		if(lim==z)
		{
			ans=min(ans,dij2(U,V));
		}
		return;
	}
	
	for(int i=h[x];i;i=ne[i])
	{
		if(b[e[i]]==1) continue;
		b[e[i]]=1;
		int W=w[i];
		w[i]=0;
		if(i%2==1) w[i+1]=0;
		else w[i-1]=0;
		dfs(e[i],z+W,lim);
		b[e[i]]=0;
		w[i]=W;
		if(i%2==1) w[i+1]=W;
		else w[i-1]=W;
	}
	return;
}
struct ilj{
	int x,y,z;
}a[200025];
bool cmp(ilj s,ilj q)
{
	if(s.x!=q.x) return s.x<q.x;
	else if(s.y!=q.y) return s.y<q.y;
	else return s.z<q.z;
}
signed main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m>>s>>t>>U>>V;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(a[i].x==a[i].y) continue;
		add(a[i].x,a[i].y,a[i].z);
		add(a[i].y,a[i].x,a[i].z); 
		while(a[i].x==a[i+1].x&&a[i].y==a[i+1].y&&i<=m) i++;
	} 
//		for(int i=1;i<=n;i++)
//		{
//			cout<<i<<"\n";
//			for(int j=h[i];j;j=ne[j]) cout<<e[j]<<": "<<w[j]<<" ";
//			cout<<'\n';
//		}
	
//	if(n<=300)
//	{
////		cout<<"ILJ";
//		int z=dij2(s,t);
//		b[s]=1;
//		dfs(s,0,z);
//		cout<<ans<<'\n';
//	}
//	else
	{
		dij();
		int sum=dij2(U,V);
		cout<<sum<<'\n';
	}
	
	
	return 0;
}

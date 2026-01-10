#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+100;
int n,q;
ll a[N];
bool vis[N];
vector<int>g[N];
ll tr[N<<2],lz[N<<2];
struct qry
{
	int op,x,d,v,f,c;
	qry():op(0),x(0),d(0),v(0),f(0),c(0){}
}b[N];
void pushdown(int u,int l,int r)
{
	if(lz[u])
	{
		int mi=(l+r)>>1;
		tr[u<<1]+=1ll*(mi-l+1)*lz[u];
		tr[u<<1|1]+=1ll*(r-mi)*lz[u];
		lz[u<<1]+=lz[u];
		lz[u<<1|1]+=lz[u];
		lz[u]=0;
	}
}
void build(int u,int l,int r)
{
	lz[u]=0;
	if(l==r)
	{
		tr[u]=a[l];
		return;
	}
	int mi=(l+r)>>1;
	build(u<<1,l,mi);
	build(u<<1|1,mi+1,r);
	tr[u]=tr[u<<1]+tr[u<<1|1];
}
void update(int u,int l,int r,int x,int y,int z)
{
	if(x<=l&&r<=y)
	{
		tr[u]+=1ll*(r-l+1)*z;
		lz[u]+=z;
		return;
	}
	pushdown(u,l,r);
	int mi=(l+r)>>1;
	if(x<=mi)
	{
		update(u<<1,l,mi,x,y,z);
	}
	if(y>mi)
	{
		update(u<<1|1,mi+1,r,x,y,z);
	}
	tr[u]=tr[u<<1]+tr[u<<1|1];
}
ll query(int u,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)
	{
		return tr[u];
	}
	pushdown(u,l,r);
	int mi=(l+r)>>1;
	ll as=0;
	if(x<=mi)
	{
		as+=query(u<<1,l,mi,x,y);
	}
	if(y>mi)
	{
		as+=query(u<<1|1,mi+1,r,x,y);
	}
	return as;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&q);
	bool islk=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		islk&=(x==i-1);
		g[x].push_back(i);
		//g[i].push_back(x);
	}
	int ct=n;
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&b[i].op);
		if(b[i].op==3)
		{
			ct++;
			scanf("%d%d",&b[i].f,&b[i].c);
			islk&=(b[i].f==ct-1);
		}
		else
		{
			scanf("%d%d",&b[i].x,&b[i].d);
			if(b[i].op==1)
			{
				scanf("%d",&b[i].v);
			}
		}
	}
	if(islk)
	{
		build(1,1,ct);
		for(int i=1;i<=q;i++)
		{
			if(b[i].op==1)
			{
				update(1,1,ct,/*max(1,b[i].x-b[i].d)*/b[i].x,min(n,b[i].x+b[i].d),b[i].v);
			}
			else if(b[i].op==2)
			{
				printf("%lld\n",query(1,1,ct,/*max(1,b[i].x-b[i].d)*/b[i].x,min(n,b[i].x+b[i].d)));
			}
			else
			{
				n++;
				update(1,1,ct,n,n,b[i].c);
			}
		}
		return 0;
	}
	for(int i=1;i<=q;i++)
	{
		if(b[i].op==3)
		{
			n++;
			a[n]=b[i].c;
			//g[n].push_back(b[i].f);
			g[b[i].f].push_back(n);
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				vis[j]=0;
			}
			queue<pair<int,int> >q;
			q.push(make_pair(b[i].x,0));
			vis[b[i].x]=1;
			ll as=0;
			while(!q.empty())
			{
				pair<int,int>u=q.front();
				q.pop();
				//cout<<"qu "<<u.first<<"\n";
				if(b[i].op==1)
				{
					a[u.first]+=b[i].v;
				}
				else
				{
					as+=a[u.first];
				}
				if(u.second!=b[i].d)
				{
					for(int j=0;j<g[u.first].size();j++)
					{
						int v=g[u.first][j];
						if(!vis[v])
						{
							vis[v]=1;
							q.push(make_pair(v,u.second+1));
						}
					}
				}
			}
			if(b[i].op==2)
			{
				//cout<<"Q "<<i<<"\n";
				printf("%lld\n",as);
			}
			//cout<<"quwan\n";
		}
		//cout<<i<<" "<<b[i].op<<" "<<b[i].x<<" "<<b[i].d<<" "<<b[i].v<<"\n";
	}
	return 0;
}

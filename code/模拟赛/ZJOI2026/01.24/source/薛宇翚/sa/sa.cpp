#include <bits/stdc++.h>
using namespace std;
#define gc getchar()
void read(int &x)
{
	x=0;
	bool f=0;
	char c=gc;
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f^=1;
		}
		c=gc;
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^'0');
		c=gc;
	}
	if(f)
	{
		x=-x;
	}
}
const int M=998244353;
vector<int>a,c,d,p;
int n,m,as;
bool cmp(int x,int y)
{
	int ax=x,ay=y;
	while(ax<c.size()&&ay<c.size())
	{
		if(c[ax]!=c[ay])
		{
			return c[ax]<c[ay];
		}
		ax++;
		ay++;
	}
	if(ax==c.size()&&ay==c.size())
	{
		return 0;
	}
	if(ax==c.size()&&ay!=c.size())
	{
		return 1;
	}
	return 0;
}
void dfs(int x,int dmx,int dkd)
{
	if(x!=n+1)
	{
		for(int i=1;i<=n;i++)
		{
			c[x]=i;
			bool f=d[i];
			if(!f)
			{
				d[i]=1;
				dfs(x+1,max(dmx,i),dkd+1);
				d[i]=0;
			}
			else
			{
				dfs(x+1,max(dmx,i),dkd);
			}
		}
		return;
	}
	if(dmx!=dkd)
	{
		return;
	}
	for(int i=0;i<p.size();i++)
	{
		p[i]=i+1;
	}
	sort(p.begin(),p.end(),cmp);
	for(int i=0;i<p.size();i++)
	{
		if(p[i]!=a[i+1])
		{
			return;
		}
	}
	as=(as+1)%M;
}
int main()
{
	freopen("sa.in","r",stdin);
	freopen("sa.out","w",stdout);
	read(n);
	read(m);
	a.push_back(0);
	c.push_back(0);
	d.push_back(0);
	for(int i=1;i<=n;i++)
	{
		a.push_back(i);
		c.push_back(0);
		d.push_back(0);
		p.push_back(0);
	}
	c.push_back(0);
	while(m--)
	{
		int op,u,v;
		read(op);
		read(u);
		read(v);
		vector<int>b;
		b.push_back(0);
		if(!op)
		{
			for(int i=u;i<=v;i++)
			{
				b.push_back(a[i]);
			}
		}
		for(int i=1;i<u;i++)
		{
			b.push_back(a[i]);
		}
		if(op)
		{
			for(int i=v;i>=u;i--)
			{
				b.push_back(a[i]);
			}
		}
		for(int i=v+1;i<=n;i++)
		{
			b.push_back(a[i]);
		}
		swap(a,b);
	}
	dfs(1,0,0);
	cout<<as<<"\n";
	return 0;
}

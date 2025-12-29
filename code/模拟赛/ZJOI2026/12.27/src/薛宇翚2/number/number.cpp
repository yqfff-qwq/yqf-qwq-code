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
int vis[15],a[25],ct,d[25][2][2];
int dfs(int x,int y,int z)
{
	if(d[x][y][z]!=-1)
	{
		return d[x][y][z];
	}
	if(x==0)
	{
		return d[x][y][z]=z;
	}
	int as=0;
	if(!z)
	{
		as+=dfs(x-1,y&&(!a[x]),0);
	}
	for(int i=(z?0:1);i<=(y?a[x]:9);i++)
	{
		if(!vis[i])
		{
			as+=dfs(x-1,y&&(i==a[x]),1);
		}
	}
	return d[x][y][z]=as;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;
	read(t);
	while(t--)
	{
		for(int i=0;i<=10;i++)
		{
			vis[i]=0;
		}
		int n,m;
		read(n);
		read(m);
		//m=1;
		for(int i=1;i<=m;i++)
		{
			int x;
			read(x);
			vis[x]=-1;
		}
		ct=0;
		int pn=n;
		while(pn)
		{
			ct++;
			a[ct]=pn%10;
			pn/=10;
		}
		memset(d,-1,sizeof(d));
		int as=bool(!vis[0])+dfs(ct,1,0);
		printf("%lld\n",as);
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
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
typedef long long ll;
void readll(ll &x)
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
const int N=3e6+100;
vector<int>g[N];
int a[N];
int main()
{
	freopen("void.in","r",stdin);
	freopen("void.out","w",stdout);
	int T;
	read(T);
	while(T--)
	{
		int n,m;
		read(n);
		read(m);
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
			g[i].push_back(i);
		}
		for(int i=1;i<=m;i++)
		{
			int u,v;
			read(u);
			read(v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		bool f=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				a[j]=0;
			}
			for(int j=0;j<g[i].size();j++)
			{
				a[g[i][j]]++;
			}
			for(int j=i+1;j<=n;j++)
			{
				int ct=0;
				for(int k=0;k<g[j].size();k++)
				{
					ct+=a[g[j][k]];
				}
				if(ct%2==0)
				{
					printf("%d %d\n",i,j);
					f=1;
					break;
				}
			}
			if(f)
			{
				break;
			}
		}
	}
	return 0;
}
//荡胸生层云
//决眦入归鸟
#include <bits/stdc++.h>
using namespace std;
const int N=25,M=1e5+100;
int n,m,a[N],col[N];
long long as;
struct nd
{
	int a,x,b,y;
}c[M];
vector<nd>g[N];
void dfs(int x)
{
	if(x==n+1)
	{
		as++;
		return;
	}
	for(int i=0;i<3;i++)
	{
		bool f=1;
		for(int j=0;j<g[x].size();j++)
		{
			nd t=g[x][j];
			if(a[t.a]==t.x&&i==t.y)
			{
				f=0;
				break;
			}
		}
		if(f)
		{
			a[x]=i;
			dfs(x+1);
		}
	}
}
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool allz=1;
	for(int i=1;i<=m;i++)
	{
		nd t;
		int b;
		scanf("%d%d%d%d",&t.a,&t.x,&b,&t.y);
		g[b].push_back(t);
		c[i]=t;
		c[i].b=b;
		allz&=(t.x==0&&t.y==0);
	}
	if(allz)
	{
		as=0;
		for(int i=0;i<(1<<n);i++)
		{
			long long px=1;
			for(int j=0;j<n;j++)
			{
				if((i>>j)&1)
				{
					px<<=1;
					col[j+1]=1;
				}
				else
				{
					col[j+1]=0;
				}
			}
			bool f=1;
			for(int j=1;j<=m;j++)
			{
				if(col[c[j].a]==c[j].x&&col[c[j].b]==c[j].y)
				{
					f=0;
					break;
				}
			}
			if(f)
			{
				as+=px;
			}
		}
		printf("%lld\n",as);
		return 0;
	}
	dfs(1);
	printf("%lld\n",as);
	return 0;
}

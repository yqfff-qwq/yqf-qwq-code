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
const int N=222,M=1e9+7;
int n,m,a[N];
bool vis[N];
struct matrix
{
	int n,m,a[N][N];
	matrix(int nn=0,int mm=0):n(nn),m(mm)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				a[i][j]=0;
			}
		}
	}
	matrix friend operator *(const matrix &x,const matrix &y)
	{
		matrix z=matrix(x.n,y.m);
		for(int k=0;k<x.m;k++)
		{
			for(int i=0;i<x.n;i++)
			{
				for(int j=0;j<y.m;j++)
				{
					z.a[i][j]=(z.a[i][j]+1ll*x.a[i][k]*y.a[k][j]%M)%M;
				}
			}
		}
		return z;
	}
}dp,fp;
namespace specialA
{
	int ne[N],arr[N];
	void main()
	{
		memset(ne,-1,sizeof(ne));
		arr[m+1]=1;
		for(int i=m;i;i--)
		{
			arr[i]=1;
			for(int j=1;j<=m;j++)
			{
				if(ne[j]!=-1)
				{
					arr[i]=(arr[i]+arr[ne[j]])%M;
				}
			}
			ne[a[i]]=i;
		}
		int as=1;
		for(int i=1;i<=m;i++)
		{
			if(ne[i]!=-1)
			{
				as=(as+arr[ne[i]])%M;
			}
		}
		printf("%lld\n",as);
	}
}
namespace Baoli
{
	int as;
	void dfs(int x,vector<int>&y)
	{
		if(x==n+1)
		{
			as++;
			return;
		}
		set<vector<int> >S;
		for(int j=0;j<(1ll<<y.size());j++)
		{
			vector<int>z;
			for(int K=0;K<y.size();K++)
			{
				if((j>>K)&1)
				{
					z.push_back(y[K]);
				}
			}
			if(S.find(z)!=S.end())
			{
				continue;
			}
			dfs(x+1,z);
			S.insert(z);
		}
	}
	void main()
	{
		as=0;
		vector<int>arr;
		for(int i=1;i<=m;i++)
		{
			arr.push_back(a[i]);
		}
		dfs(2,arr);
		printf("%lld\n",as);
	}
}
signed main()
{
	freopen("message.in","r",stdin);
	freopen("message.out","w",stdout);
	read(n);
	read(m);
	bool ok=1,alla=1;
	for(int i=1;i<=m;i++)
	{
		read(a[i]);
		if(a[i]!=1)
		{
			alla=0;
		}
		if(vis[a[i]])
		{
			ok=0;
		}
		vis[a[i]]=1;
	}
	if(ok)
	{
		int as=1;
		for(int i=1;i<=m;i++)
		{
			as=as*n%M;
		}
		printf("%lld\n",as);
		return 0;
	}
	if(alla)
	{
		fp=matrix(m+1,m+1);
		for(int i=0;i<=m;i++)
		{
			for(int j=0;j<=i;j++)
			{
				fp.a[i][j]=1;
			}
		}
		dp=matrix(1,m+1);
		dp.a[0][m]=1;
		n--;
		while(n)
		{
			if(n&1)
			{
				dp=dp*fp;
			}
			fp=fp*fp;
			n>>=1;
		}
		int as=0;
		for(int i=0;i<=m;i++)
		{
			as+=dp.a[0][i];
		}
		printf("%lld\n",as);
		return 0;
	}
	if(n==2)
	{
		specialA::main();
		return 0;
	}
	Baoli::main();
	return 0;
}

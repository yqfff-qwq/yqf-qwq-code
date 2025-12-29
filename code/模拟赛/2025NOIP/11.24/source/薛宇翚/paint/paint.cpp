#include <bits/stdc++.h>
using namespace std;
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>=10)
	{
		write(x/10);
	}
	putchar((x%10)^'0');
}
const int N=4100;
const int M=N*N;
int f[M],n,m,q;
char a[N][N];
int calc(int x,int y)
{
	return x*N+y;
}
int F(int x)
{
	return x==f[x]?x:f[x]=F(f[x]);
}
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%s",a[i]);
	}
	while(q--)
	{
		int xl,yl,xr,yr;
		scanf("%d%d%d%d",&xl,&yl,&xr,&yr);
		xl--;
		yl--;
		xr--;
		yr--;
		for(int i=xl;i<=xr;i++)
		{
			for(int j=yl;j<=yr;j++)
			{
				int z=calc(i,j);
				f[z]=z;
			}
		}
		int as=(xr-xl+1)*(yr-yl+1);
		for(int i=xl;i<=xr;i++)
		{
			for(int j=yl;j<=yr;j++)
			{
				int z=calc(i,j);
				if(i>xl)
				{
					int zz=calc(i-1,j);
					if(a[i][j]==a[i-1][j]&&F(z)!=F(zz))
					{
						f[F(z)]=F(zz);
						as--;
					}
				}
				if(j>yl)
				{
					int zz=calc(i,j-1);
					if(a[i][j]==a[i][j-1]&&F(z)!=F(zz))
					{
						f[F(z)]=F(zz);
						as--;
					}
				}
			}
		}
		write(as);
		putchar('\n');
	}
	return 0;
}

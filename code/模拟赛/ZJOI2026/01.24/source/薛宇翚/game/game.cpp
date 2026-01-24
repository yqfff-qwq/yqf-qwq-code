#include <bits/stdc++.h>
using namespace std;
const int N=5e5+100;
bool f[55][55][55];
int a[N],n;
bool query(int x,int y,int z)
{
	int mx=max(x,max(y,z)),mn=min(x,min(y,z));
	return f[mx][x+y+z-mx-mn][mn];
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	for(int i=0;i<=50;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int k=0;k<=j;k++)
			{
				int ct=0,pi=i-1,pj=j+1;
				while(pi>=pj)
				{
					ct+=!query(pi,pj,k);
					pi--;
					pj++;
				}
				pi=i-1;
				int pk=k+1;
				while(pi>=pk)
				{
					ct+=!query(pi,j,pk);
					pi--;
					pk++;
				}
				pj=j-1;
				pk=k+1;
				while(pj>=pk)
				{
					ct+=!query(i,pj,pk);
					pj--;
					pk++;
				}
				f[i][j][k]=ct;
				//cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<"\n";
			}
		}
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		int as=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(query(a[i],a[j],a[k]))
					{
						as++;
					}
				}
			}
		}
		printf("%d\n",as);
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool f[55][55][55];
bool query(int x,int y,int z)
{
	int mx=max(x,max(y,z)),mn=min(x,min(y,z));
	return f[mx][x+y+z-mx-mn][mn];
}
int main()
{
	freopen("logs.txt","w",stdout);
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
				cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<"\n";
			}
		}
	}
	return 0;
}

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
int n,m,i,j,x,y,t,g[105][105];
int main()
{	freopen("mkgmtx.in","r",stdin);
	freopen("mkgmtx.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(g,0,sizeof(g));
	for (i=1;i<=m;i++) scanf("%d%d%d",&x,&y,&t),g[x][y]=t;
	for (i=1;i<=n;i++)
	{	printf("%d:\n",i);
		for (j=1;j<=n;j++)
			if (g[i][j]) printf("%d %d\n",j,g[i][j]);
		}
	return 0;
} 

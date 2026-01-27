#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int N=10005;
const int M=1000005;
int n,m,i,j,x,y,t,l,head[N],go[M],Next[M],cost[M];
inline void Add(int u,int v,int t) { Next[++l]=head[u],head[u]=l,go[l]=v,cost[l]=t; }
int main()
{	freopen("mkglist.in","r",stdin);
	freopen("mkglist.out","w",stdout);
	scanf("%d%d",&n,&m),l=0;
	for (i=1;i<=m;i++) scanf("%d%d%d",&x,&y,&t),Add(x,y,t);
	for (i=1;i<=n;i++)
	{	printf("%d:\n",i);
		for (j=head[i];j;j=Next[j])
			printf("%d %d\n",go[j],cost[j]);
		}
	return 0;
} 

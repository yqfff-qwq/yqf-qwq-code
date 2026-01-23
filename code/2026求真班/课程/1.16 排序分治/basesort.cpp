#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int N=100005;
int n,L,l,i,Ma,a[N],head[11],Next[N],go[N];
inline int B(int a,int b) { return a>b?a:b; }
inline void Add(int u,int v) { Next[++l]=head[u],head[u]=l,go[l]=v; }
inline void RadixSort(int a[],int n,int exp)
{	int i,j; memset(head,0,sizeof(head)),l=0;
	for (i=1;i<=n;i++) Add((a[i]/exp)%10,a[i]);
	for (i=9;i>=0;i--) for (j=head[i];j;j=Next[j]) a[n--]=go[j];
}
inline void BaseSort(int a[],int n,int L)
{	int i,t; for (t=1,i=1;i<=L;i++) RadixSort(a,n,t),t*=10;
}
int main()
{	scanf("%d", &n);
	for (Ma=0,i=1;i<=n;i++)
		scanf("%d",&a[i]),Ma=B(Ma,a[i]);
	for (L=0;Ma;Ma/=10) L++;
	BaseSort(a,n,L);
	for (i=1;i<=n;i++)
		printf("%d",a[i]),printf((i<n)?" ":"\n");
	return 0;
}

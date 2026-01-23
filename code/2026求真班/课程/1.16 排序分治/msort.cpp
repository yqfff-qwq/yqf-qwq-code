#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
int n,i,a[100005],b[100005];
inline void msort(int l,int r)
{	if (l==r) return;
	int i,j,u=l-1,m=(l+r)>>1;
	msort(l,m),msort(m+1,r);
	i=l,j=m+1;
	while ((i<=m)&&(j<=r))
	if (a[i]<a[j]) b[++u]=a[i++];
			  else b[++u]=a[j++];
	while (i<=m) b[++u]=a[i++];
	while (j<=r) b[++u]=a[j++];
	for (i=l;i<=r;i++) a[i]=b[i];
}
int main()
{	freopen("msort.in","r",stdin);
	freopen("msort.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	msort(1,n);
	for (i=1;i<n;i++) printf("%d ",a[i]);
	printf("%d\n",a[i]);
	return 0;
}

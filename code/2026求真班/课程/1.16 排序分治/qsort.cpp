//P1177
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
int n,i,a[100005];
inline void kp(int l,int r)
{	int t,i=l,j=r,m=a[(l+r)>>1];
	while (i<=j)
	{	while ((i<=j)&&(m>a[i])) i++;
		while ((i<=j)&&(m<a[j])) j--;
		if (i<=j)
		{	t=a[i],a[i]=a[j],a[j]=t;
			i++,j--;
			}
		}
	if (l<j) kp(l,j);
	if (i<r) kp(i,r);
}
int main()
{	freopen("qsort.in","r",stdin);
	freopen("qsort.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	kp(1,n);
	for (i=1;i<n;i++) printf("%d ",a[i]);
	printf("%d\n",a[i]);
	return 0;
}

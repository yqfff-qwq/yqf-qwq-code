#include <bits/stdc++.h>
using namespace std;
const int N=3e5+100;
int n,a[N],as[N],b[N],c[N],d[N];
char s[N];
int main()
{
	freopen("modification.in","r",stdin);
	freopen("modification.out","w",stdout);
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
	}
	do
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=(s[a[i]]-'0');
			c[i]=c[i-1]+(b[i]==0);
		}
		int ct=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]!=a[i-1]+1)
			{
				ct++;
			}
		}
		for(int i=n;i;i--)
		{
			d[i]=d[i+1]+b[i];
		}
		int mx=0;
		for(int i=0;i<=n;i++)
		{
			mx=max(mx,c[i]+d[i+1]);
		}
		for(int i=ct;i<=n;i++)
		{
			as[i]=max(as[i],mx);
		}
	}
	while(next_permutation(a+1,a+n+1));
	for(int i=1;i<=n;i++)
	{
		printf("%d ",as[i]);
	}
	return 0;
}

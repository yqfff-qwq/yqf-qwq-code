#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(ll &x)
{
	bool f=0;
	x=0;
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
const int N=9e5+100;
ll n,a[N],b[N],p[N],c[N],d[N],as;
int calc(int x,int y)
{
	if(a[x]>a[y])
	{
		return 1;
	}
	if(a[x]==a[y])
	{
		return 0;
	}
	return -1;
}
bool cmp(int x,int y)
{
	if(c[x]!=c[y])
	{
		return c[x]<c[y];
	}
	return a[x]<a[y];
}
ll myabs(ll x)
{
	return x<0?-x:x;
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		p[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		read(b[i]);
		c[i]=(i==1?0:calc(i,i-1))+(i==n?0:calc(i,i+1));
	}
	sort(b+1,b+n+1);
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		//cout<<i<<" "<<p[i]<<" "<<c[i]<<"\n";
		d[p[i]]=b[i];
	}
	for(int i=2;i<=n;i++)
	{
		as+=myabs(d[i]-d[i-1]);
	}
	printf("%lld\n",as);
	for(int i=1;i<=n;i++)
	{
		printf("%lld ",d[i]);
	}
	printf("\n");
	return 0;
}

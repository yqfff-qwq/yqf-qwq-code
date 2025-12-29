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
const int N=1200;
ll n,a[N],s[N];
set<ll>orz;
ll myabs(ll x)
{
	return x<0?-x:x;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		s[i]=s[i-1]+a[i];
	}
	ll sto=0x3f3f3f3f3f3f3f3fll;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			orz.insert(s[i]-s[j]);
		}
		for(int j=i+1;j<=n;j++)
		{
			ll su=s[j]-s[i];
			set<ll>::iterator it=orz.lower_bound(su);
			if(it!=orz.end())
			{
				sto=min(sto,myabs(su-(*it)));
			}
			if(it!=orz.begin())
			{
				it--;
				sto=min(sto,myabs(su-(*it)));
			}
		}
	}
	printf("%lld\n",sto);
	return 0;
}

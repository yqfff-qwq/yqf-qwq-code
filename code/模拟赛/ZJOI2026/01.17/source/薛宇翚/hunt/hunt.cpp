#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+100;
const ll inf=0x3f3f3f3f3f3f3f3fll;
ll n,a[N],b[N],c[N],p[N];
bool check(int pos,ll x,ll y,ll z,ll le)
{
	if(pos==n+1)
	{
		return 1;
	}
	for(int i=pos;i<=n;i++)
	{
		swap(p[pos],p[i]);
		ll A=a[p[pos]],B=b[p[pos]],C=c[p[pos]],X=x,Y=y,Z=z;
		if(X<=A+le&&Y<=B+le&&Z<=C+le)
		{
			if(X<A-le)
			{
				X=A-le;
			}
			if(Y<B-le)
			{
				Y=B-le;
			}
			if(Z<C-le)
			{
				Z=C-le;
			}
			if(check(pos+1,X,Y,Z,le))
			{
				return 1;
			}
		}
		swap(p[pos],p[i]);
	}
	return 0;
}
int main()
{
	freopen("hunt.in","r",stdin);
	freopen("hunt.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		p[i]=i;
	}
	ll l=0,r=5e9+100;
	while(l<r)
	{
		ll mi=(l+r)>>1;
		if(check(1,-inf,-inf,-inf,mi))
		{
			r=mi;
		}
		else
		{
			l=mi+1;
		}
	}
	printf("%lld\n",l);
	return 0;
}

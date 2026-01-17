#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+100,S=(1<<20)+7;
ll a[N],b[S],n,m;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	ll as=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ll xr=(a[i]^a[j]);
			as+=b[xr];
			b[xr]++;
			if(as>=3ll*m)
			{
				printf("%lld\n",m);
				return 0;
			}
		}
	}
	/*
	for(int i=0;i<S;i++)
	{
		ll x=1ll*b[i]*(b[i]-1)/2;
		as+=x;
	}
	*/
	as/=3;
	printf("%lld\n",min(as,m));
	return 0;
}

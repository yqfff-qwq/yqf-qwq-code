#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+100,M=998244353;
int n,m,q,a[N],b[N],c[N],h[N];
int main()
{
	freopen("stalemate.in","r",stdin);
	freopen("stalemate.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	for(int i=0;i<(1<<m);i++)
	{
		for(int j=1;j<=n;j++)
		{
			c[j]=0;
		}
		int et=0;
		for(int j=0;j<m;j++)
		{
			if((i>>j)&1)
			{
				c[a[j]]++;
				c[b[j]]++;
				et++;
			}
		}
		int ct=0,dt=0;
		for(int j=1;j<=n;j++)
		{
			if(c[j]>=2)
			{
				ct++;
			}
			if(c[j])
			{
				dt++;
			}
		}
		if(dt!=et)
		{
			continue;
		}
		h[ct]++;
		h[ct]%=M;
	}
	while(q--)
	{
		ll as=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			x%=M;
			as+=1ll*x*h[i];
			as%=M;
		}
		as=(as%M+M)%M;
		printf("%lld\n",as);
	}
	return 0;
}

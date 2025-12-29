#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=998244353,N=1e5+100;
bool vis[N];
int p[N],ph[N],ct,a[N];
void read(int &x)
{
	x=0;
	bool f=0;
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
signed main()
{
	freopen("bead.in","r",stdin);
	freopen("bead.out","w",stdout);
	ph[1]=1;
	for(int i=2;i<N;i++)
	{
		if(!vis[i])
		{
			ct++;
			p[ct]=i;
			ph[i]=i-1;
		}
		for(int j=1;j<=ct&&1ll*i*p[j]<N;j++)
		{
			vis[i*p[j]]=1;
			if(i%p[j]==0)
			{
				ph[i*p[j]]=ph[i]*p[j];
				break;
			}
			ph[i*p[j]]=ph[i]*(p[j]-1);
		}
	}
	int n,m;
	read(n);
	read(m);
	for(int i=1;i<=m;i++)
	{
		a[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		read(x);
		a[x]<<=1;
		a[x]%=M;
	}
	int as=0;
	for(int i=1;i<=m;i++)
	{
		int ct=1;
		for(int j=i;j<=m;j+=i)
		{
			ct=1ll*ct*a[j]%M;
		}
		//cout<<i<<" "<<ct<<" "<<ph[i]<<"\n";
		ct=(ct+M-1)%M;
		ct=1ll*ct*ph[i]%M;
		as=(as+ct)%M;
	}
	printf("%lld\n",as);
	return 0;
}

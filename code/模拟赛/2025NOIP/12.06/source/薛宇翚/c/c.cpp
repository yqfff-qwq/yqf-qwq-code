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
void readchar(char &c)
{
	do
	{
		c=getchar();
	}
	while(c<=32||c>126);
}
const int N=5010;
const ll inf=0x3f3f3f3f3f3f3f3fll;
ll n,a[N],b[N],t,k,d[N];
ll myabs(ll x)
{
	return x<0?-x:x;
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	read(t);
	read(n);
	read(k);
	for(int i=1;i<=n;i++)
	{
		char c;
		readchar(c);
		d[i]=(c=='H');
		read(a[i]);
		read(b[i]);
	}
	ll miv=inf,mxv=-inf;
	for(int i=0;i<(1<<n);i++)
	{
		vector<int>cg,ch,dg,dh;
		ll su=0;
		for(int j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				if(d[j+1])
				{
					ch.push_back(j+1);
				}
				else
				{
					cg.push_back(j+1);
				}
			}
			else if(d[j+1])
			{
				su+=b[j+1];
				dh.push_back(j+1);
			}
			else
			{
				su+=b[j+1];
				dg.push_back(j+1);
			}
		}
		if(ch.size()!=cg.size())
		{
			continue;
		}
		bool f=1;
		for(int j=0;j<ch.size();j++)
		{
			if(myabs(a[ch[j]]-a[cg[j]])>k)
			{
				f=0;
				break;
			}
		}
		if(!f)
		{
			continue;
		}
		for(int j=0;j<dh.size();j++)
		{
			for(int J=0;J<dg.size();J++)
			{
				if(myabs(a[dh[j]]-a[dg[J]])<=k)
				{
					f=0;
					break;
				}
			}
			if(!f)
			{
				break;
			}
		}
		if(f)
		{
			mxv=max(mxv,su);
			miv=min(miv,su);
		}
	}
	if(t==1)
	{
		printf("%lld\n",miv);
	}
	else
	{
		printf("%lld\n",mxv);
	}
	return 0;
}

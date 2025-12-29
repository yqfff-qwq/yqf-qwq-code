#include <bits/stdc++.h>
#define int long long
using namespace std;
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
	freopen("root.in","r",stdin);
	freopen("root.out","w",stdout);
	int t;
	read(t);
	while(t--)
	{
		int n,m,ct=0,as=0;
		read(n);
		read(m);
		for(int i=0;ct<10;i++)
		{
			int x=1ll*i*n+1;
			x^=(n-1);
			if(x<0||x>m)
			{
				ct++;
			}
			else
			{
				as++;
			}
		}
		printf("%lld\n",as);
	}
	return 0;
}

#include <bits/stdc++.h>
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
const int M=998244353,N=2e5+100;
int n,a[N],k;
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
signed main()
{
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	int t;
	read(t);
	while(t--)
	{
		read(n);
		read(k);
		int h=k;
		for(int i=1;i<=n;i++)
		{
			read(a[i]);
			h=gcd(h,a[i]);
		}
		int as=(k/h+1)%M;
		printf("%d\n",as);
	}
	return 0;
}

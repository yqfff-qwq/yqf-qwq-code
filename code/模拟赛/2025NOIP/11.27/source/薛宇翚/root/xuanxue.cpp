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
		int n,m;
		read(n);
		read(m);
		m/=n;
		cout<<m<<"\n";
	}
	return 0;
}

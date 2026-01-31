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
typedef long long ll;
void readll(ll &x)
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
const int N=2e6+100;
int n;
ll a[N];
int main()
{
	freopen("starlight.in","r",stdin);
	freopen("starlight.out","w",stdout);
	int T;
	read(T);
	while(T--)
	{
		read(n);
		for(int i=1;i<=n;i++)
		{
			readll(a[i]);
		}
		sort(a+1,a+n+1);
		int as=0;
		for(int i=2;i<=n;i++)
		{
			bool lego=bool(i==2),rigo=bool(i==n);
			for(int j=35;j>=0;j--)
			{
				int stp=((a[i-1]>>j)&1),stc=((a[i]>>j)&1);
				if(stp!=stc)
				{
					break;
				}
				if(!lego&&((a[i-2]>>j)&1)!=stp)
				{
					lego=1;
				}
				if(!rigo&&((a[i+1]>>j)&1)!=stp)
				{
					rigo=1;
				}
			}
			if(lego&&rigo)
			{
				as++;
			}
		}
		printf("%d\n",as);
	}
	return 0;
}
//岱宗夫如何
//齐鲁青未了
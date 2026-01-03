#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long x;
		scanf("%lld",&x);
		bool f=1;
		for(long long i=2;i<=x/i;i++)
		{
			if(x%i==0)
			{
				if(x%(i*i)!=0)
				{
					f=0;
					break;
				}
				while(x%i==0)
				{
					x/=i;
				}
			}
		}
		if(f&&x==1)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}

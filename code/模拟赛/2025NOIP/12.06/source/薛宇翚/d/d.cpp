#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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
int n,k,m;
const int N=2e5+100;
int a[N],b[N];
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	read(n);
	read(k);
	read(m);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
	}
	while(m--)
	{
		int op;
		read(op);
		if(op==1)
		{
			int p,v;
			read(p);
			read(v);
			a[p]=v;
		}
		else
		{
			int as=-1;
			for(int i=0;i<=k;i++)
			{
				b[i]=0;
			}
			int ct=0,j=0;
			for(int i=1;i<=n;i++)
			{
				while(j<n&&ct<k)
				{
					j++;
					if(!b[a[j]])
					{
						ct++;
					}
					b[a[j]]++;
				}
				if(ct<k)
				{
					break;
				}
				int le=j-i+1;
				if(as==-1||as>le)
				{
					as=le;
				}
				b[a[i]]--;
				if(!b[a[i]])
				{
					ct--;
				}
			}
			printf("%d\n",as);
		}
	}
	return 0;
}

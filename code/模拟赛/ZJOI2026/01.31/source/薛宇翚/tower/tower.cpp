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
const int N=1e7+100;
int n,m;
ll a[N],as;
bool vis[N];
void dfs(int x,ll y=0)
{
	if(y>=as)
	{
		return;
	}
	if(x==(n<<1)+1)
	{
		as=min(as,y);
		return;
	}
	for(int i=1;i<=(n<<1);i++)
	{
		if(vis[i])
		{
			continue;
		}
		vis[i]=1;
		for(int j=i+1;j<=(n<<1);j++)
		{
			if(vis[j])
			{
				continue;
			}
			vis[j]=1;
			dfs(x+2,max(y,(a[i]+a[j])%m));
			vis[j]=0;
		}
		vis[i]=0;
	}
}
int main()
{
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	int T;
	read(T);
	while(T--)
	{
		read(n);
		read(m);
		for(int i=1;i<=(n<<1);i++)
		{
			readll(a[i]);
		}
		as=0x3f3f3f3f3f3f3fll;
		dfs(1);
		printf("%lld\n",as);
	}
	return 0;
}
//造化钟神秀
//阴阳割昏晓
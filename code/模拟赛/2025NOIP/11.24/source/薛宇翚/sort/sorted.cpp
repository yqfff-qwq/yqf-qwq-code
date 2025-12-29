#include <bits/stdc++.h>
using namespace std;
void read(int &x)
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
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>=10)
	{
		write(x/10);
	}
	putchar((x%10)^'0');
}
const int N=1100;
int n,a[N];
bool vis[N];
vector<vector<int> >as;
int main()
{
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&a[i]!=i)
		{
			vector<int>tp;
			vis[i]=1;
			tp.push_back(i);
			int u=a[i];
			while(!vis[u])
			{
				tp.push_back(u);
				vis[u]=1;
				u=a[u];
			}
			as.push_back(tp);
		}
	}
	write(as.size());
	putchar('\n');
	for(int i=0;i<as.size();i++)
	{
		write(as[i].size());
		for(int j=0;j<as[i].size();j++)
		{
			putchar(' ');
			write(as[i][j]);
		}
		putchar('\n');
	}
	while(1);
	return 0;
}

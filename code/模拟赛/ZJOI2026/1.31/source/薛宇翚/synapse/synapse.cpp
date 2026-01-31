#include <bits/stdc++.h>
using namespace std;
#define int long long
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
const int N=2e6+100;
int n,l,a[N],as;
vector<int>As,cr;
void dfs(int x,int mi=0x3f3f3f3f3f3fll,int mx=-0x3f3f3f3f3f3fll)
{
	if(x==n)
	{
		int cur=max(mx,l-cr.back())-min(mi,l-cr.back());
		if(cur<as)
		{
			as=cur;
			As=cr;
			As.push_back(l);
		}
		return;
	}
	for(int i=max(cr.back()+1,a[x]);i<=a[x+1];i++)
	{
		cr.push_back(i);
		dfs(x+1,min(mi,i-cr[cr.size()-2]),max(mx,i-cr[cr.size()-2]));
		cr.pop_back();
	}
}
signed main()
{
	freopen("synapse.in","r",stdin);
	freopen("synapse.out","w",stdout);
	int T;
	read(T);
	while(T--)
	{
		as=0x3f3f3f3f3f3fll;
		read(l);
		read(n);
		for(int i=1;i<=n;i++)
		{
			read(a[i]);
		}
		cr.clear();
		cr.push_back(0);
		dfs(1);
		for(int i=0;i<=n;i++)
		{
			printf("%d ",As[i]);
		}
		printf("\n");
	}
	return 0;
}
//会当凌绝顶
//一览众山小
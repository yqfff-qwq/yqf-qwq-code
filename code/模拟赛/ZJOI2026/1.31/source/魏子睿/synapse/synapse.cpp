#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=2e6+10;
int a[N], ans[N], tmp[N], res=1e18;
int l, n;
void dfs(int x, int maxn, int minn)
{
	if(x==n)
	{
		maxn=max(maxn, l-tmp[x-1]);
		minn=min(minn, l-tmp[x-1]);
		if(maxn-minn<res)
		{
			res=maxn-minn;
			for(int i=1;i<n;i++) ans[i]=tmp[i];
		}
		return ;
	}
	if(maxn-minn>=res) return ;
	for(int i=a[x];i<=a[x+1];i++)
	{
		if(tmp[x-1]!=i)
		{
			tmp[x]=i;
			dfs(x+1, max(maxn, i-tmp[x-1]), min(minn, i-tmp[x-1]));
		}
	}
}
signed main()
{
	freopen("synapse.in", "r", stdin);
	freopen("synapse.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>l>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		res=1e18;
		ans[n]=l;
		dfs(1, 0, 1e18);
		for(int i=0;i<=n;i++)
			cout<<ans[i]<<' ';
		cout<<'\n';
	}
	return 0;
}

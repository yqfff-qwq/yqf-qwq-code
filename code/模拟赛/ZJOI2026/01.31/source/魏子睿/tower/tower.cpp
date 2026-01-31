#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e6+10;
int a[N];
bool used[N];
int n, m;
signed main()
{
	freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=2*n;i++) cin>>a[i];
		int ans=1e9;
		do
		{
			int res=0;
			for(int i=1;i<=n;i++)
			{
				res=max(res, (a[i]+a[i+n])%m);
				if(res>=ans) break;
			}
			ans=min(ans, res);	
		}
		while(next_permutation(a+1, a+1+2*n));
		cout<<ans<<'\n';
	}
	return 0;
}

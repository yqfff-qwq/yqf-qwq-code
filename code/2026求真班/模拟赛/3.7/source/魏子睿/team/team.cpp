#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=2e5+10;
int a[N];
signed main()
{
	freopen("team.in", "r", stdin);
	freopen("team.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1, a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int id=upper_bound(a+1, a+1+n, a[i]+5)-a-1;
		ans=max(ans, id-i+1);
	}
	cout<<ans;
	return 0;
}
/*
6 
1 10 17 12 15 2

10
1337 1337 1337 1337 1337 1337 1337 1337 1337 1337

6
1 1000 10000 10 100 1000000000
*/

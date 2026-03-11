#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("berry.in", "r", stdin);
	freopen("berry.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	{
		int x, y;
		cin>>x>>y;
		if(abs(x-y)>1) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
/*
4
2 1
5 0
0 0
4 8
*/

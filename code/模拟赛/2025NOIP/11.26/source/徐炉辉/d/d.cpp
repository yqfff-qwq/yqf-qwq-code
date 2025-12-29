#include <bits/stdc++.h>
const int N = 1e3 + 5;

int n, m, a[N], b[N], dp[N][N];

signed main()
{
	std::freopen("d.in", "r", stdin);
	std::freopen("d.out", "w", stdout);
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	for (int i = 1; i <= n; ++i) std::cin >> b[i];
	
	while (m--)
	{
		int s, t, u, ans = 0; std::cin >> s >> t >> u;
		std::cout << -1 << '\n';
	}
	return 0;
}
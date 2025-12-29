#include <bits/stdc++.h>

signed main()
{
	auto solve = [&] () -> void
	{
		int n, m, cnt = 0; std::cin >> n >> m;
		for (int i = 0; i <= m; ++i)
			cnt += ((i ^ (n - 1)) % n == 1);
		std::cout << cnt << '\n';
	};
	
	std::freopen("root.in", "r", stdin);
	std::freopen("root.ans", "w", stdout);
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	int T; std::cin >> T;
	while (T--) solve();
	return 0;
}

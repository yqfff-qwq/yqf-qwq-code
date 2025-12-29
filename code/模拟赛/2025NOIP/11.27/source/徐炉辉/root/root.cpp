#include <bits/stdc++.h>
#define int long long

signed main()
{
	auto solve = [&] () -> void
	{
		int n, m, cnt = 0; std::cin >> n >> m;
		
		for (int i = 0; i <= m / n + 1; ++i)
		{
			int t = i * n + 1;
			t ^= (n - 1);
			if (0 <= t && t <= m) ++cnt;
		}
		std::cout << cnt << '\n';
	};
	
	std::freopen("root.in", "r", stdin);
	std::freopen("root.out", "w", stdout);
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	int T; std::cin >> T;
	while (T--) solve();
	return 0;
}

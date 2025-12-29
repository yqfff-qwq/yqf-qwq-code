#include <bits/stdc++.h>
#define int long long
const int N = 2e5 + 5;

int n, k, a[N];

signed main()
{
	auto solve = [&] () -> void
	{
		std::cin >> n >> k;
		for (int i = 1; i <= n; ++i) std::cin >> a[i];
		std::cout << k + 1 << '\n';
	};
	
	std::freopen("easy.in", "r", stdin);
	std::freopen("easy.out", "w", stdout);
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	int T; std::cin >> T;
	while (T--) solve();
	return 0;
}

#include <bits/stdc++.h>

inline int rnd()
{
	int t = std::rand(), tt = std::rand();
	return (t << 15) + tt;
}

signed main()
{
	std::freopen("reflection.in", "w", stdout);
	std::srand(time(0));
	
	int n = (int)1e4, q = (int)1e4, c = 0; std::cout << n << ' ' << q << ' ' << c << '\n';
	for (int i = 1; i <= n; ++i) std::cout << rnd() % ((int)2e5) + 1 << ' '; std::cout << '\n';
	while (q--)
	{
		int l = rnd() % (n) + 1, r = rnd() % (n) + 1, x = rnd() % ((int)2e5) + 1;
		if (l > r) std::swap(l, r);
		std::cout << l << ' ' << r << ' ' << x << '\n';
	}
	
	return 0;
}

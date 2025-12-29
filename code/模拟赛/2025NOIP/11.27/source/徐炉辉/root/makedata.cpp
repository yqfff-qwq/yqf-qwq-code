#include <bits/stdc++.h>

inline int rnd()
{
	int t = std::rand(), tt = std::rand();
	return (t << 15) + tt;
}

signed main()
{
	std::freopen("root.in", "w", stdout);
	std::srand(time(0));
	
	std::cout << 10 << '\n';
	for (int i = 1; i <= 10; ++i)
	std::cout << rnd() % ((int)1e5 - 2) + 2 << ' ' << rnd() % ((int)1e5) + 1 << '\n';
	return 0;
}

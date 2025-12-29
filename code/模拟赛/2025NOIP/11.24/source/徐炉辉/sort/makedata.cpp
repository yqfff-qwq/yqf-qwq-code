#include <bits/stdc++.h>
const int N = 1e3 + 5;

bool vis[N];

inline int rnd()
{
	int t = std::rand(), tt = std::rand();
	return (t << 15) + tt;
}

signed main()
{
	std::freopen("sort.in", "w", stdout);
	std::srand(time(0));

	int n = (int)1e3; std::cout << n << '\n';
	for (int i = 1; i <= n; ++i) 
	{
		int t = rnd() % (n) + 1;
		while (vis[t]) t = rnd() % (n) + 1;
		vis[t] = 1;
		std::cout << t << ' ';
	}
	return 0;
}

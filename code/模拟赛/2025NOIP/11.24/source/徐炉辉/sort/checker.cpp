#include <bits/stdc++.h>
const int N = 1e3 + 5;

int n, t, a[N], b[N], c[N];

signed main()
{
	std::freopen("sort.out", "r", stdin);
	std::freopen("sort.res", "w", stdout);
	
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	
	std::cin >> t;
	while (t--)
	{
		int m; std::cin >> m;
		
		for (int i = 1; i <= n; ++i) c[i] = a[i];
		
		for (int i = 1; i <= m; ++i)
			std::cin >> b[i];
		
		for (int i = 1; i <= m; ++i)
			c[b[i % m + 1]] = a[b[i]];
			
		for (int i = 1; i <= n; ++i) a[i] = c[i];
	}
	
	for (int i = 1; i <= n; ++i) if (a[i] != i) return std::cout << "NO" << '\n', 0;
	std::cout << "YES" << '\n'; 
	return 0;
}

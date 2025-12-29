#include <bits/stdc++.h>
#define int long long
const int N = 2e5 + 5;

int n, k, a[N];

signed main()
{
	std::cin >> n;
//	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	
	for (int i = 1; i <= 100; ++i)
	{
		std::cout << ((i * n + 1) ^ (n - 1)) << ' ';
	}
	return 0;
}

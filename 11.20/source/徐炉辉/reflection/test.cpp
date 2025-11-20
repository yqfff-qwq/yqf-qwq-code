#include <bits/stdc++.h>
#define int long long
const int N = 1e5 + 5;

int n, q, c, a[N];

inline int f(const int &l, const int &r, const int &x)
{
	int res = x;
	for (int i = l; i <= r; ++i)
	{
		res = std::abs(a[i] - res);
	}
	return res;
}

signed main()
{
	std::freopen("reflection.in", "r", stdin);
	std::freopen("reflection.out", "w", stdout);
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	std::cin >> n >> q >> c;
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	while (q--)
	{
		int l, r, x; std::cin >> l >> r >> x;
		std::cout << f(l, r, x) << '\n';
	}
	return 0;
}

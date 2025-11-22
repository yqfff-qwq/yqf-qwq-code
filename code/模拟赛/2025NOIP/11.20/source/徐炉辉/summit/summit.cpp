#include <bits/stdc++.h>
#define int long long
const int N = 3e5 + 5, INF = 1e18;

int n, l, r, k, a[N], b[N], ans;

inline void check(const std::vector<int> &p, const std::vector<int> &q)
{
	for (int i = 0; i < k; ++i)
	{
		if (p[i] > q[i]) return ;
	}
	int res = 0;
	for (int i = 0; i < k; ++i)
	{
		res += (a[p[i]] + b[q[i]]);
	}
	ans = std::min(ans, res);
}

inline void dfs_q(const int &step, std::vector<int> res, std::vector<int> p)
{
	if (res.size() > k) return ;
	if (step == n + 1)
	{
		if (res.size() == k) check(p, res);
		return ;
	}
	dfs_q(step + 1, res, p);
	res.push_back(step), dfs_q(step + 1, res, p);
}

inline void dfs_p(const int &step, std::vector<int> res)
{
	if (res.size() > k) return ;
	if (step == n + 1)
	{
		if (res.size() == k) dfs_q(1, std::vector<int>(), res);
		return ;
	}
	dfs_p(step + 1, res);
	res.push_back(step), dfs_p(step + 1, res); res.pop_back();
}

signed main()
{
	std::freopen("summit.in", "r", stdin);
	std::freopen("summit.out", "w", stdout);
	
	auto solve = [&] () -> void
	{
		std::cin >> n >> l >> r;
		for (int i = 1; i <= n; ++i) std::cin >> a[i];
		for (int i = 1; i <= n; ++i) std::cin >> b[i];
		for (int i = l; i <= r; ++i)
		{
			k = i; ans = INF;
			dfs_p(1, std::vector<int>());
			std::cout << ans << ' ' << '\n';
		}
	};
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	int T; std::cin >> T;
	while (T--) solve();
	return 0;
}

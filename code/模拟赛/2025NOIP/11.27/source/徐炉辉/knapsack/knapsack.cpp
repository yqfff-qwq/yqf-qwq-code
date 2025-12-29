#include <bits/stdc++.h>
#define int long long
const int N = 5e5 + 5;

int n, M, v[N], m[N], ans;

inline void dfs(const int &step, const int &sum_v, const int &sum_m, std::vector<int> res)
{
	if (sum_m > M) return ;
	if (step == n + 1)
	{
		if (sum_m <= M)
		{
			for (int i : res)
				for (int j : res) 
					if (i % j != 0 && j % i != 0) return ;
			ans = std::max(ans, sum_v);
		}
		return ;
	}
	dfs(step + 1, sum_v, sum_m, res);
	res.push_back(m[step]);
	dfs(step + 1, sum_v + v[step], sum_m + m[step], res);
	res.pop_back();
}

signed main()
{
	std::freopen("knapsack.in", "r", stdin);
	std::freopen("knapsack.out", "w", stdout);
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	std::cin >> n >> M;
	for (int i = 1; i <= n; ++i) std::cin >> v[i] >> m[i];
	
	dfs(1, 0, 0, std::vector<int>());
	
	std::cout << ans << '\n';
	
	return 0;
}

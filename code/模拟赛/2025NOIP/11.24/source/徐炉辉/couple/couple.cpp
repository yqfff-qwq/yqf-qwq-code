#include <bits/stdc++.h>
const int N = 1e5 + 5;

int n;
struct node
{
	int x, y;
} p[N];

inline void dfs(const int &x, const int &y, std::vector<std::pair<int, int>> res)
{
	if (y == 0)
	{
		{
			int tx = x - 1;
			res.push_back(std::make_pair(tx, y));
			dfs(tx, y, res); res.pop_back();
		}
		{
			int tx = x + 1;
			res.push_back(std::make_pair(tx, y));
			dfs(tx, y, res); res.pop_back();
		}
		{
			int ty = y - 1;
			res.push_back(std::make_pair(x, ty));
			dfs(x, ty, res); res.pop_back();
		}
		{
			int ty = y + 1;
			res.push_back(std::make_pair(x, ty));
			dfs(x, ty, res); res.pop_back();
		}
	}
	
}

inline void dfs(const int &step, std::vector<int> A, std::vector<int> B)
{
	if (step == n + 1)
	{
		for (int i : A) std::cerr << i << ' '; std::cerr << '\n';
		for (int i : B) std::cerr << i << ' '; std::cerr << '\n';
		std::cerr << '\n';
		return ;
	}
	A.push_back(step); dfs(step + 1, A, B); A.pop_back();
	B.push_back(step); dfs(step + 1, A, B); B.pop_back();
}

inline void solve()
{
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> p[i].x >> p[i].y;
	
	dfs(1, std::vector<int>(), std::vector<int>());
}

signed main()
{
//	std::freopen("couple.in", "r", stdin);
//	std::freopen("couple.out", "w", stdout);
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	int T; std::cin >> T;
	while (T--) solve();
	return 0;
}
/*
1
3
1 2
2 3
3 1
*/

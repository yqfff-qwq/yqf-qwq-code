#include <bits/stdc++.h>
const int N = 1e3 + 5;
int n, a[N], cnt; bool vis[N];
std::vector<int> e[N], t;
std::vector<std::vector<int> > ans;

inline void dfs(const int &u, const int &aim)
{
	if (u == aim && vis[u]) return ;
	vis[u] = 1; t.push_back(u);
	for (int v : e[u])
	{
		if (!vis[v]) dfs(v, aim);
	}
}

signed main()
{
	std::freopen("sort.in", "r", stdin);
	std::freopen("sort.out", "w", stdout);
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] == i)
		{
			vis[i] = 1;
			continue;
		}
		e[i].push_back(a[i]);
	}
	
	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i])
		{
			t.clear();
			dfs(i, i);
			ans.push_back(t);
		}
	}
	
	std::cout << ans.size() << '\n';
	for (auto i : ans)
	{
		std::cout << i.size() << ' ';
		for (int j : i) std::cout << j << ' ';
		std::cout << '\n';
	}
	return 0;
}

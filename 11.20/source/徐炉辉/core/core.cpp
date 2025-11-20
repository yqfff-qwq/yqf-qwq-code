#include <bits/stdc++.h>
const int N = 1e6 + 5;

int n, m, k, ans;
std::string s[N], t[N];

inline bool check(std::string a)
{
	std::stack<int> sta; int res = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		if (a[i] == '(') sta.push(i);
		else if (a[i] == ')' && !sta.empty()) sta.pop(), ++res;
	}
	if (res != k / 2) return false;
	return true;
}

inline void dfs(const int &step, const std::string &res, const int ss, const int tt, std::string t)
{
	if (step == k - (ss + tt) + 1)
	{
		if (check(res + t)) ++ans;
		return ;
	}
	std::string tmp = res;
	tmp = tmp + ')';
	dfs(step + 1, tmp, ss, tt, t);
	tmp = res; tmp = tmp + '(';
	dfs(step + 1, tmp, ss, tt, t);
}

inline int f(const int &i, const int &j)
{
	int ss = s[i].size(), tt = t[j].size();
	std::string a = s[i];
	dfs(1, a, ss, tt, t[j]);
}

signed main()
{
	std::freopen("core.in", "r", stdin);
	std::freopen("core.out", "w", stdout);
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	int id; std::cin >> id;
	std::cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) std::cin >> s[i];
	for (int i = 1; i <= m; ++i) std::cin >> t[i];
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			f(i, j);
	
	std::cout << ans << '\n';
	return 0;
}

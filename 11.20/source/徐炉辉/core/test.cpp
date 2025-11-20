#include <bits/stdc++.h>
const int N = 1e6 + 5;

int n, m, k, ans;
std::string s[N], t[N];

inline int f(std::string a)
{
//	std::string a = s[i] + t[j];
	std::stack<int> sta; int res = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		if (a[i] == '(') sta.push(i);
		else if (a[i] == ')' && !sta.empty()) sta.pop(), ++res;
	}
	if (res != k / 2) return false;
	return true;
}

signed main()
{
//	std::freopen("core.in", "r", stdin);
//	std::freopen("core.out", "w", stdout);
	
//	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	k = 6;
	
	while (1)
	{
		std::string s; std::cin >> s;
		std::cout << f(s) << '\n';	
	}	
	
//	int id; std::cin >> id;
//	std::cin >> n >> m >> k;
//	for (int i = 1; i <= n; ++i) std::cin >> s[i];
//	for (int i = 1; i <= m; ++i) std::cin >> t[i];
//	
//	for (int i = 1; i <= n; ++i)
//		for (int j = 1; j <= m; ++j)
//			ans += f(i, j);
	
	std::cout << ans << '\n';
	return 0;
}

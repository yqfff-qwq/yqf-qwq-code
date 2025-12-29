#include <bits/stdc++.h>
const int N = 1e3 + 5, M = 1e4 + 5;

int n, M, v[N], m[N], dp[N][M];
std::vector<int> e[N];

signed main()
{
	std::cin >> n >> M;
	for (int i = 1; i <= n; ++i) std::cin >> v[i] >> m[i];
	
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
		{
			if (m[i] % m[j] == 0 || m[j] % m[i] == 0)
			{
				e[i].push_back(j);
				e[j].push_back(i);
			}
		}
		
	for (int u = 1; u <= n; ++u)
		for (int v : e[u]) std::cerr << u << ' ' << v << '\n';
		
	for (int i = 1; i <= n; ++i) dp[i][1] = w[i];
	
	return 0;
}
/*
6 10
1 1
5 2
200 6
9 2
6 2
100 1
*/

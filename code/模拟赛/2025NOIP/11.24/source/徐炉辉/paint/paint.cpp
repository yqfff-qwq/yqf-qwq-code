#include <bits/stdc++.h>
const int N = 4e3 + 5;
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};


int n, m, q; bool vis[N][N];
char ch[N][N]; int xl, yl, xr, yr; 

inline void dfs(const int &x, const int &y)
{
	vis[x][y] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int tx = x + dx[i], ty = y + dy[i];
		if (tx < xl || tx > xr || ty < yl || ty > yr || ch[x][y] != ch[tx][ty] || vis[tx][ty]) continue;
		dfs(tx, ty);
	}
}

signed main()
{
	std::freopen("paint.in", "r", stdin);
	std::freopen("paint.out", "w", stdout);
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	std::cin >> n >> m >> q;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			std::cin >> ch[i][j];
			
	while (q--)
	{
		std::cin >> xl >> yl >> xr >> yr;
		for (int i = xl; i <= xr; ++i)
			for (int j = yl; j <= yr; ++j)
				vis[i][j] = 0;
		
		int cnt = 0;
		
		for (int i = xl; i <= xr; ++i)
			for (int j = yl; j <= yr; ++j)
			{
				if (!vis[i][j])
				{
					dfs(i, j);
					++cnt;
				}
			}
		std::cout << cnt << '\n';
	}
	return 0;
}
/*
4 8 9
ABBAAAAA
ABAAAABA
CAADABBA
AAAAAAAA
1 1 4 8
3 5 3 8
1 3 2 4
1 4 2 5
1 1 3 3 
4 4 4 4
2 6 4 8
3 5 4 6
1 6 3 8
*/

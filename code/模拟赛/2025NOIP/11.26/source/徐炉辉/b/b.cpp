#include <bits/stdc++.h>
#define int long long
const int N = 2e5 + 5, INF = 1e18;

int n, m, s, t, U, V, res = INF;
std::vector<std::pair<int, int> > e[N];

int dis[N], dis_s[N], dis_t[N], ans; bool vis[N];
inline void dijkstra(const int &s)
{
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
	for (int i = 1; i <= n; ++i) dis[i] = INF, vis[i] = 0; dis[s] = 0, q.push(std::make_pair(0, s));
	while (!q.empty())
	{
		int u = q.top().second; q.pop();
		if (vis[u]) continue; vis[u] = 1;
		for (auto i : e[u])
		{
			int v = i.first, w = i.second;
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				q.push(std::make_pair(dis[v], v));
			}
		}
	}
//	return dis[t];
}

inline void dfs(const int &u, const int &sum)
{
	if (dis_s[u] + dis_t[u] == dis_s[t]) 
	{
//		std::cerr << u << ' ' << sum <<  '\n';
		res = std::min(res, sum);
		return ;
	}
		
	for (auto i : e[u])
	{
		int v = i.first, w = i.second;
		if (vis[v]) continue;
		vis[v] = 1; dfs(v, sum + w);
	}
}

signed main()
{
	std::freopen("b.in", "r", stdin);
	std::freopen("b.out", "w", stdout);
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	std::cin >> n >> m;
	std::cin >> s >> t; 
	std::cin >> U >> V;
	
	for (int i = 1, u, v, w; i <= m; ++i)
	{
		std::cin >> u >> v >> w;
		e[u].push_back(std::make_pair(v, w));
		e[v].push_back(std::make_pair(u, w));
	}
	
	dijkstra(s); for (int i = 1; i <= n; ++i) dis_s[i] = dis[i]; // for (int i = 1; i <= n; ++i) std::cout << dis_s[i] << ' '; std::cout << '\n';
	
	dijkstra(t); for (int i = 1; i <= n; ++i) dis_t[i] = dis[i]; // for (int i = 1; i <= n; ++i) std::cout << dis_t[i] << ' '; std::cout << '\n';
	
	for (int i = 1; i <= n; ++i) vis[i] = 0; res = INF; dfs(U, 0); ans += res; // std::cerr << res << '\n';
//	std::cerr << 1 << '\n';
	for (int i = 1; i <= n; ++i) vis[i] = 0; res = INF; dfs(V, 0); ans += res; // std::cerr << res << '\n';
	
	std::cout << ans << '\n';
	
	return 0;
}
/*
6 6
1 6
1 4
1 2 1
2 3 1
3 5 1
2 4 3
4 5 2
5 6 1

8 8 
5 7
6 8
1 2 2
2 3 3
3 4 4
1 4 0
1 5 5
2 6 6
3 7 7
4 8 8
*/
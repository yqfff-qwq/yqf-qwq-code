#include <bits/stdc++.h>
#define int long long
using node = std::tuple<int, int, int>; 
const int N = 2e5 + 5, INF = 1e18;

int n, m, s, t, U, V, res = INF;
std::vector<std::pair<int, int> > e[N];
std::vector<node> edge;

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

class dsu
{
private:
	std::vector<int> fa;
	
public:
	dsu(std::size_t n ) : fa(n + 5) { std::iota(fa.begin(), fa.end(), 0); }
	
	inline int find(const int &x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
	inline void merge(const int &x, const int &y) { fa[find(x)] = find(y); }
	inline bool is_merge(const int&x, const int &y) { return find(x) == find(y); }	
};

inline bool cmp(const node &_, const node &__)
{ return std::get<2>(_) < std::get<2>(__); }

inline int kruskal()
{
	int res = 0, cnt = 0; dsu T(n);
	std::sort(edge.begin(), edge.end(), cmp);
	for (auto i : edge)
	{
		int u = std::get<0>(i), v = std::get<1>(i), w = std::get<2>(i);
		if (!T.is_merge(u, v))
		{
			T.merge(u, v);
			e[u].push_back(std::make_pair(v, w));
			e[v].push_back(std::make_pair(u, w));
			if (cnt == n - 1) return res;
		}
	}
	return 0;
}

signed main()
{
//	std::freopen("b.in", "r", stdin);
//	std::freopen("b.out", "w", stdout);
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	std::cin >> n >> m;
	std::cin >> s >> t; 
	std::cin >> U >> V;
	
	for (int i = 1, u, v, w; i <= m; ++i)
	{
		std::cin >> u >> v >> w;
//		e[u].push_back(std::make_pair(v, w));
//		e[v].push_back(std::make_pair(u, w));
		edge.push_back(std::make_tuple(u, v, w));
	}
	
	kruskal();
	
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
1 4 1
1 5 5
2 6 6
3 7 7
4 8 8
*/
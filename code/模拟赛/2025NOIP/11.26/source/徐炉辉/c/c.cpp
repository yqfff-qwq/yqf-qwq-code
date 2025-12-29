#include <bits/stdc++.h>
using node = std::tuple<int, int, int>;
const int N = 3e2 + 5, INF = 1e9;

int n, k, h[N], c[N], max = 0, ans = INF;
std::vector<node> edge;

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
			res += w; ++cnt;
			if (cnt == n - 1) return res;
		}
	}
	return 0;
}

inline void dfs(const int &step, const int &sum)
{
	if (step == n + 1)
	{
//		for (int i = 1; i <= n; ++i) std::cerr << h[i] << ' '; 
		edge.clear();
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (h[i] > h[j])
				{
					edge.push_back(std::make_tuple(i, j, c[i]));
				}
			}
		}
		
		ans = std::min(ans, sum + kruskal());
		return ;
	}
	for (int i = h[step]; i <= max; ++i)
	{
		int t = h[step];
		h[step] = i;
		dfs(step + 1, sum + (i - h[step]) * k);
		h[step] = t;
	}
}

signed main()
{
	std::freopen("c.in", "r", stdin);
	std::freopen("c.out", "w", stdout);
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i) std::cin >> h[i], max = std::max(max, h[i]);
	for (int i = 1; i <= n; ++i) std::cin >> c[i];
	
	dfs(1, 0);
	
	std::cout << ans << '\n';
	
	return 0;
}
/*
5 2
0 6
1 1
0 5
2 1
1 2
*/
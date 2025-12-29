#include <bits/stdc++.h>
#define int long long
const int N = 2e5 + 5;

int n, q, rt, fa[N], siz[N];
std::vector<int> e[N];

namespace Tree
{
	int dep[N], dfn[N], idx[N], num;
	inline void dfs(const int &u, const int &f)
	{
		dep[u] = dep[f] + 1, fa[u] = f;
		dfn[u] = ++num, idx[num] = u, siz[u] = 1;
		for (int v : e[u])
		{
			if (f == v) continue;
			dfs(v, u);
			siz[u] += siz[v];
		}
	}
	
	struct cmin { int operator()(const int &x, const int &y) { return dep[x] < dep[y] ? x : y; } };
	
	template <typename operate>
	class ST
	{
	private:
		operate op;
		int st[20][N];
	
	public:
		inline void init()
		{
			for (int i = 1; i <= n; ++i) st[0][i] = dfn[i];
			for (int i = 1; i <= std::__lg(n); ++i)
				for (int j = 1; j <= n - (1 << i) + 1; ++j)
					st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		}
		
		inline int ask(const int &l, const int &r)
		{
			int p = std::__lg(r - l + 1);
			return op(st[p][l], st[p][r - (1 << p) + 1]);
		}
	} ; ST<cmin> T;
	
	inline void init(const int &rt) { dfs(rt, 0), T.init(); }
	inline int lca(const int &u, const int &v)
	{
		if (u == v) return u;
		return fa[T.ask(std::min(idx[u], idx[v]) + 1, std::max(idx[u], idx[v]))];
	}
}
using namespace Tree;

inline void dfs(const int &u, const int &f, const int &l, const int &r)
{
	for (int v : e[u])
	{
		if (v == f) continue;
		dfs(v, u, l, r);
		siz[u] += siz[v];
	}
	siz[u] += (l <= u && u <= r);
}

signed main()
{
	std::freopen("rplexq.in", "r", stdin);
	std::freopen("rplexq.out", "w", stdout);
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	std::cin >> n >> q >> rt;
	for (int i = 1, u, v; i < n; ++i)
	{
		std::cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	
	init(rt);

	while (q--)
	{
		int l, r, x; std::cin >> l >> r >> x;
		for (int i = 1; i <= n; ++i) siz[i] = 0;
		dfs(x, fa[x], l, r);
		
		int cnt = 0; 
		int flag = 0;
		
		std::vector<int> t;
		
		for (int i : e[x])
		{
			if (i == fa[x]) continue;
			if (siz[i] != 0) ++flag, t.push_back(siz[i]);
		}
		
		if (!flag) {
			std::cout << 0 << '\n';
			continue;
		}

		for (int i = 0; i < t.size(); ++i)
			for (int j = i + 1; j < t.size(); ++j)
				cnt += t[i] * t[j];
		
		if (l <= x && x <= r && flag >= 1)
		{
			cnt += siz[x] - 1;
		}
		
		std::cout << cnt << '\n';
	}
	return 0;
}
/*
10 10 7
4 2
10 4
3 2
6 10
9 2
7 3
1 4
8 2
5 3
8 10 10
2 6 2
3 6 2
4 6 4
3 10 2
8 8 10
3 10 4
2 3 2
2 6 4
1 7 10

*/

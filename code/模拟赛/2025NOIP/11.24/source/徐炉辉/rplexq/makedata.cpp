#include <bits/stdc++.h>
using node = std::tuple<int, int, int>;
const int N = 1e3 + 5, mod = 1e9 + 7;

inline int rnd()
{
	int t = std::rand(), tt = std::rand();
	return (t << 15) + tt;
}

class dsu
{
private:
	std::vector<int> fa;
	
public:
	dsu(std::size_t n) : fa(n + 5) { std::iota(fa.begin(), fa.end(), 0); }
	
	inline int find(const int &x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
	inline void merge(const int &x, const int &y) { fa[find(x)] = find(y); }
	inline bool is_merge(const int &x, const int &y) { return find(x) == find(y); }
} ;

std::vector<node> edge;
std::vector<int> e[N]; int n, q;

inline void kurskal()
{
	dsu T(n); int cnt = 0;
	std::sort(edge.begin(), edge.end(), [](const node &_, const node &__) { return std::get<2>(_) < std::get<2>(__); });
	for (auto i : edge)
	{
		int u = std::get<0>(i), v = std::get<1>(i), w = std::get<2>(i);
		if (!T.is_merge(u, v))
		{
			T.merge(u, v);
			e[u].push_back(v); ++cnt;
			if (cnt == n - 1) return ;
		}
	}
}

signed main()
{
	std::freopen("rplexq.in", "w", stdout);
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	std::srand(time(0));
	
	n = 10, q = 10; std::cout << n << ' ' << q << ' ' << 1 << '\n';
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			edge.push_back(std::make_tuple(i, j, rnd() % mod));
	
	kurskal();
	
	for (int i = 1; i <= n; ++i)
		for (int j : e[i]) std::cout << i << ' ' << j << '\n';

//	for (int i = 1; i < n; ++i) std::cout << i << ' ' << i + 1 << '\n';
		
	while (q--)
	{
		int l = rnd() % n + 1, r = rnd() % n + 1, x = rnd() % n + 1;
		if (l > r) std::swap(l, r);
		std::cout << l << ' ' << r << ' ' << x << '\n';
	}
	return 0;
}

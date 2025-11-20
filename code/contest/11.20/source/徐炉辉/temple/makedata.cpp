#include <bits/stdc++.h>
using node = std::tuple<int, int, int>;
const int N = 1e5 + 5;

int n;

std::vector<node> edge;
std::vector<std::pair<int, int>> e;

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
};

inline void kurskal()
{
	dsu T(n);
	std::sort(edge.begin(), edge.end(), [](const node &_, const node &__) { return std::get<2>(_) < std::get<2>(__); });
	for (auto i : edge)
	{
		int u = std::get<0>(i), v = std::get<1>(i), w = std::get<2>(i);
		if (!T.is_merge(u, v))
		{
			T.merge(u, v);
			e.push_back(std::make_pair(u, v));
		}
	}
}

signed main()
{
	std::freopen("template.in", "w", stdout);
	std::srand(time(0));
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	n = 10; std::cout << n << '\n';
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			edge.push_back(std::make_tuple(i, j, rnd()%((int)1e9) + 1));
	
	kurskal();
	
	for (auto i : e) std::cout << i.first << ' ' << i.second << '\n';
	return 0;
}

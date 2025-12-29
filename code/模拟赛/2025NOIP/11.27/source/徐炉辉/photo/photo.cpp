#include <bits/stdc++.h>
const int N = 1e4 + 5;

int n, t, vis[N];

struct node { int l, r; } a[N];

signed main()
{
	std::freopen("photo.in", "r", stdin);
	std::freopen("photo.out", "w", stdout);
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	std::cin >> n >> t; int max = 0;
	for (int i = 1; i <= n; ++i) std::cin >> a[i].l >> a[i].r, max = std::max(max, a[i].r);
	
	std::sort(a + 1, a + 1 + n, [](const node &_, const node &__) { return _.l < __.l; });
	
	int pos = 1;
	
//	for (int i = 1; i <= n; ++i) std::cerr << a[i].l << ' ' << a[i].r << '\n';
	
	while (pos <= n)
	{
		int tmp = pos; //std::cerr << tmp << ' ';
		while (a[pos].l == a[pos + 1].l && a[pos].r == a[pos + 1].r) ++pos; 
		//std::cerr << pos << ' ' << '\n';
		if (a[tmp].r - a[tmp].l + 1 < pos - tmp + 1 && pos != tmp) return std::cout << "no" << '\n', 0;
		++pos;
	}
	
	std::cout << "yes" << '\n';
	for (int i = 1; i <= n; ++i) std::cout << a[i].l << ' '; 
	
	return 0;
}

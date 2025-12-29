#include <bits/stdc++.h>
#define REP(i, l, r) for (int i = (l); i <= (r); ++ i)
#define DEP(i, r, l) for (int i = (r); i >= (l); -- i)
#define CUP(i, l, r) for (int i = (l); i < (r); ++ i)
#define CDW(i, r, l) for (int i = (r) - 1; i >= (l); -- i)
#define fi first
#define se second
#define pb emplace_back
#define mems(x, v) memset((x), (v), sizeof(x))
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define ppc(x) __builtin_popcount(x)
using namespace std;
namespace Milkcat {
	typedef long long LL;
	typedef pair<LL, LL> pii;
	const int N = 1e6 + 5;
	LL n, m, rs, a[N], b[N], h[N];
	vector<LL> t, s[N];
	int main() {
		cin >> n >> m;
		REP(i, 1, n) cin >> a[i] >> b[i], t.pb(b[i]);
		sort(ALL(t)), t.erase(unique(ALL(t)), t.end());
		REP(i, 1, n) {
			int x = lower_bound(ALL(t), b[i]) - t.begin() + 1;
			s[x].pb(a[i]);
		}
		DEP(i, SZ(t), 1)
			h[i] = m / t[i - 1], m %= t[i - 1];
		REP(i, 1, SZ(t)) {
			auto &v = s[i]; sort(ALL(v));
			LL p = 0, q = 0, d = (i < SZ(t) ? t[i] / t[i - 1] : -1);
			while (h[i] && SZ(v))
				rs += v.back(), h[i] --, v.pop_back();
			while (SZ(v)) {
				p += v.back(), q ++, v.pop_back();
				if (q == d) s[i + 1].pb(p), p = q = 0;
			}
			if (q > 0) s[i + 1].pb(p);
		}
		cout << rs << '\n';
		return 0;
	}
}
int main() {
	freopen("knapsack.in", "r", stdin);
	freopen("knapsack.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T = 1;
	while (T --) Milkcat::main();
	return 0;
}
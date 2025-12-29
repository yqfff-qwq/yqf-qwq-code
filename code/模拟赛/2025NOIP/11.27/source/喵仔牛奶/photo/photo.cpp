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
	int n, m, k, p, a[N], b[N], o[N], f[N], fa[N], pr[N], d[N], c[N];
	vector<int> t, g[N]; set<int> s;
	int fnd(int x) { return (fa[x] == x ? x : fa[x] = fnd(fa[x])); }
	bool slv() {
		int c = 0, p = 1;
		REP(i, 2, n) {
			int w = f[p] + (t[i] - t[p] + k - 1) / k;
			if (f[i] > w) f[i] = w, c = 1;
			int A = f[i] - t[i] / k, B = f[p] - t[p] / k;
			if (A < B || A == B && t[i] % k > t[p] % k) p = i;
		}
		REP(i, 1, n) fa[i] = i, pr[i] = d[i] = 0;
		DEP(i, n - 1, 1) {
			for (int j : g[i]) {
				int x = fnd(j), y = pr[x]; d[x] ++;
				if (y > 0 && d[x] >= f[x] - f[y])
					fa[y] = x, d[x] += d[y], pr[x] = pr[y];
			}
			int x = fnd(i + 1);
			if (f[x] - d[x] < f[i]) f[i] = f[x] - d[x], c = 1;
			if (f[i] < f[x] - d[x]) pr[x] = i;
			else fa[i] = x;
		}
		return c;
	}
	int main() {
		cin >> m >> k;
		REP(i, 1, m) {
			cin >> a[i] >> b[i], o[i] = i;
			a[i] --, b[i] -= k, t.pb(a[i]), t.pb(b[i]);
		}
		sort(ALL(t)), t.erase(unique(ALL(t)), t.end()), n = SZ(t);
		REP(i, 1, m) {
			a[i] = lower_bound(ALL(t), a[i]) - t.begin() + 1;
			b[i] = lower_bound(ALL(t), b[i]) - t.begin() + 1;
			g[a[i]].pb(b[i]);
		}
		t.insert(t.begin(), 0);
		REP(i, 1, n) f[i] = (i < n ? 1e9 : 0);
		REP(i, 1, n)
			if (!slv() || f[n] < 0) break;
		if (slv()) { cout << "no\n"; return 0; }
		cout << "yes\n";
		REP(i, 2, n) {
			p = max(p, t[i - 1] + 1);
			int x = f[i] - f[i - 1];
			REP(j, 1, x) s.insert(p), p += k;
		}
		sort(o + 1, o + 1 + m, [&](int x, int y) {
			return b[x] < b[y];
		});
		REP(i, 1, m) {
			auto it = s.upper_bound(t[a[o[i]]]);
			c[o[i]] = *it, s.erase(it);
		}
		REP(i, 1, m) cout << c[i] << ' ';
		cout << '\n';
		return 0;
	}
}
int main() {
	freopen("photo.in", "r", stdin);
	freopen("photo.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T = 1;
	while (T --) Milkcat::main();
	return 0;
}

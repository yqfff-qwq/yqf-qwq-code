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
	LL n, m, rs;
	int main() {
		cin >> n >> m, m ++, rs = 0;
		DEP(i, 60, 0) {
			if (!(m >> i & 1)) continue;
			LL l = ((m ^ (n - 1)) >> i ^ 1) << i, r = l + (1LL << i) - 1;
			rs += (r + n - 1) / n - (l + n - 2) / n;
		}
		cout << rs << '\n';
		return 0;
	}
}
int main() {
	freopen("root.in", "r", stdin);
	freopen("root.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T = 1; cin >> T;
	while (T --) Milkcat::main();
	return 0;
}
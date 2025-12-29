#include <bits/stdc++.h>
#define REP(i, l, r) for (int i = (l); i <= (r); ++ i)
#define DEP(i, r, l) for (int i = (r); i >= (l); -- i)
#define fi first
#define se second
#define pb emplace_back
#define mems(a, v) memset((a), (v), sizeof(a))
#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()
using namespace std;
namespace Milkcat {
	typedef long long LL;
	typedef pair<LL, LL> pii;
	const int N = 2e3 + 5, T = 1e3;
	LL x, y, z, A, B, d[N][N][3][3];
	queue<tuple<int, int, int, int>> q;
	LL len(int t) { return (!t ? x : (t < 2 ? y : z)); }
	void chk(int x, int y, int t1, int t2, int w) {
		if (abs(x) > 1e3 || abs(y) > 1e3) return;
		if (d[x + T][y + T][t1][t2] < 0)
			d[x + T][y + T][t1][t2] = w + 1, q.emplace(x, y, t1, t2);
	}
	int main() {
		cin >> x >> y >> z >> A >> B;
		if (x == y && y == z) {
			if (A % x || B % x) cout << "impossible\n";
			else cout << max(A / x, -A / x) + max(B / x, -B / x) << '\n';
			return 0;
		}
		mems(d, -1), d[T][T][0][1] = 0, q.emplace(0, 0, 0, 1);
		while (SZ(q)) {
			auto [P, Q, t1, t2] = q.front(); q.pop();
			int t3 = 3 - t1 - t2, c = len(t3), w = d[P + T][Q + T][t1][t2];
			if (P == A && Q == B && len(t1) == x && len(t2) == y)
				cout << w << '\n', exit(0);
			chk(P, Q + c, t1, t3, w), chk(P + c, Q, t3, t2, w);
			chk(P, Q - c, t1, t3, w), chk(P - c, Q, t3, t2, w);
		}
		cout << "impossible\n";
		return 0;
	}
}
int main() {
	freopen("island.in", "r", stdin);
	freopen("island.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	while (T --) Milkcat::main();
	return 0;
}
#include <bits/stdc++.h>
#define REP(i, l, r) for (int i = (l); i <= (r); ++ i)
#define DEP(i, r, l) for (int i = (r); i >= (l); -- i)
#define fi first
#define se second
#define pb emplace_back
#define mems(x, v) memset((x), (v), sizeof(x))
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
namespace Milkcat {
    typedef long long LL;
    typedef pair<LL, LL> pii;
    const int N = 1e6 + 5;
    LL n, rs, a[N], b[N], c[N], mn[N], d[N]; char x;
    void chkmin(LL &x, LL y) { (x > y) && (x = y); }
    LL slv(int l, int r, LL w) {
        LL rs = 1e18, s = 0, t = w;
        d[l - 1] = (a[l - 1] ? 0 : 1e18);
        DEP(i, r, l) chkmin(t, c[i]), d[i] = c[i] + t * (i - l);
        REP(i, l, r) chkmin(d[i], d[i - 1]);
        DEP(i, r, l) {
            chkmin(rs, s + c[i] + d[i]);
            chkmin(w, c[i]), s += w;
        }
        return min(rs, s);
    }
    int main() {
        cin >> n, rs = 0;
        REP(i, 1, n) cin >> x, a[i] = x - '0';
        REP(i, 1, n) cin >> x, b[i] = x - '0';
        REP(i, 1, n) cin >> c[i];
        a[n + 1] = b[n + 1] = 0, mn[n + 1] = 1e18;
        DEP(i, n, 1) {
            if (a[i] && !b[i]) { cout << "-1\n"; return 0; }
            mn[i] = (b[i] ? min(mn[i + 1], c[i]) : 1e18);
        }
        REP(i, 1, n) {
            if (!b[i] || a[i]) continue;
            int r = i;
            while (b[r + 1] && !a[r + 1]) r ++;
            rs += slv(i, r, mn[r + 1]), i = r;
        }
        cout << rs << '\n';
        return 0;
    }
}
int main() {
	  freopen("pom.in", "r", stdin);
	  freopen("pom.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; cin >> T;
    while (T --) Milkcat::main();
    return 0;
}
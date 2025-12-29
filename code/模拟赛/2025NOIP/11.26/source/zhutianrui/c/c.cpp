// To scale the heights, one must embrace the fall.
#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define pb emplace_back
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 305, M = N * 2, inf = 1e16, mod = 1e9 + 7;
int n, K, f[N][N], g[N][N], b[M];
struct pos {
    int h, c;
    bool operator < (pos x) const {
        return h == x.h ? c < x.c : h < x.h;
    }
} a[N];
vector<pii> t[M]; // c, id
template<class T> void ckmin(T &x, T y) { if (x > y) x = y; }
template<class T> void ckmax(T &x, T y) { if (x < y) x = y; }
signed main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> K;
    F(i, 1, n) cin >> a[i].h >> a[i].c, b[i] = a[i].h;
    sort(b + 1, b + n + 1);
    F(i, 2, n * 2) b[i] = max(b[i], b[i - 1] + 1);
    F(i, 1, n) a[i].h = lower_bound(b + 1, b + n * 2 + 1, a[i].h) - b;
    sort(a + 1, a + n + 1); F(i, 1, n) t[a[i].h].pb(a[i].c, i);

    memset(f, 0x3f, sizeof f); f[0][0] = 0;
    int mn = inf, sum = 0, ans = inf;
    F(i, 1, n * 2) {
        F(j, 0, n) F(k, 0, n) {
            __int128 val = f[j][k] + (__int128)k * K * (b[i] - b[i - 1]);
            if (val < inf) f[j][k] = val; else f[j][k] = inf;
        }
        memset(g, 0x3f, sizeof g);
        int len = t[i].size(); sum += len;
        if (!len) {
            F(j, 0, n) F(k, 0, n) ckmin(g[j][k - min(j, k)], f[j][k]);
        } else {
            if (mn == inf) {
                F(k, 0, n) ckmin(g[1][len + k - 1], f[0][k]);
            } else {
                F(j, 0, n) F(k, 0, n)
                    ckmin(g[j][len + k - 1 - min(j - 1, len + k - 1)], f[j][k]);
            }
            mn = min(mn, t[i][0].fi);
            F(j, 0, n) F(k, 0, n) ckmin(g[j + 1][k], g[j][k] + mn);
        }
        memcpy(f, g, sizeof g);
        // F(j, 0, n) F(k, 0, n) {
        //     if (g[j][k] < inf) {
        //         cerr << "g[" << j << "][" << k << "] = " << g[j][k] << endl;
        //     }
        // }
        // cerr << endl;
        if (sum == n) {
            // cerr << b[i] << endl;
            F(j, 0, n) ans = min(ans, f[j][0]);
        }
    }
    cout << ans << '\n';
    return 0;
}
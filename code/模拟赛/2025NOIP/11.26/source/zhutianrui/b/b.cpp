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

const int N = 200005, M = (N << 1), inf = 1e16, mod = 1e9 + 7;
int n, m, ans = inf, S, T, U, V, d[4][N], vis[N], ind[N], h[2][N];
vector<pii> G[N], g[N];
void dijkstra(int s, int *f) {
    memset(f, 0x3f, sizeof f);
    memset(vis, 0, sizeof vis);
    priority_queue<pii> q;
    f[s] = 0, q.push({0, s});
    while (q.size()) {
        int u = q.top().se; q.pop();
        if (vis[u]) continue; vis[u] = 1;
        for (auto [v, w] : G[u]) {
            if (f[u] + w < f[v]) {
                f[v] = f[u] + w, q.push({-f[v], v});
            }
        }
    }
}
signed main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> S >> T >> U >> V;
    F(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        // cerr << u << ' ' << v << ' ' << w << endl;
        G[u].pb(v, w), G[v].pb(u, w);
    }
    memset(d, 0x3f, sizeof d);
    dijkstra(S, d[0]), dijkstra(T, d[1]);
    dijkstra(U, d[2]), dijkstra(V, d[3]);
    ans = d[2][V];
    // F(i, 1, n) cerr << d[0][i] << ' '; cerr << endl;
    F(i, 1, n) for (auto [j, k] : G[i])
        if (d[0][i] + k + d[1][j] == d[0][T])
            g[i].pb(j, k), ind[j]++;
    queue<int> q;
    q.push(S);
    memset(h, 0x3f, sizeof h);
    while (q.size()) {
        int u = q.front(); q.pop();
        h[0][u] = min(h[0][u], d[2][u]);
        h[1][u] = min(h[1][u], d[3][u]);
        ans = min(ans, h[0][u] + d[3][u]);
        ans = min(ans, h[1][u] + d[2][u]);
        // cerr << u << ' ' << dis[u] << ' ' << d[3][u] << endl;
        for (auto [v, w] : g[u]) {
            h[0][v] = min(h[0][v], h[0][u]);
            h[1][v] = min(h[1][v], h[1][u]);
            if (!--ind[v]) q.push(v);
        }
    }
    cout << ans << '\n';
    return 0;
}
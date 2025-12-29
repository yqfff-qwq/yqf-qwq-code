#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define RAP(i,a)      for(auto i=(a).begin();i<=(a).end();i++)
#define REP(i,a,b)    for(auto i=(a);i<=(b);i++)
#define DEP(i,a,b)    for(auto i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(auto i=(a);i<=(b);i+=c)
#define DEPc(i,a,b,c) for(auto i=(a);i>=(b);i-=c)
#define MAX(a,b)  (a)=max((a),(b))
#define MIN(a,b)  (a)=min((a),(b))
#define ADD(a,b)  (a)=((a)+(b))%mod
#define SUB(a,b)  (a)=(((a)-(b))%mod+mod)%mod
#define MUL(a,b)  (a)=(((a)*(b))%mod+mod)%mod
#define SZ(a)     ((int)(a).size())
#define ALL(a)    (a).begin(),(a).end()
#define ppc(x)    __builtin_popcountll(x)
#define ctz(x)    __builtin_ctz(x)
#define DBG(x)     cerr<<#x<<": "<<x<<endl
#define AST(x,l,r) assert(x>=l),assert(x<=r)
#define int long long
using namespace std;
typedef pair<int,int> pii;

namespace Yyydrasil {

    const int inf = 0x3f3f3f3f3f3f3f3f;
    const int N = 1e5 + 5, M = 2e5 + 5;
    int n, m, S, T, U, V, u, v, w, ans;
    vector<pii> edge[N];

    vector<int> node, g1[N], g2[N];
    queue<int> qnode;
    int visnode[N];
    int visg1[N], visg2[N], disg1[N], disg2[N], distoU[N];
    queue<int> cnode;

    priority_queue<pii, vector<pii>, greater<pii>> q;
    int dis[N], vis[N];
    void dijkstra(int s) {
        REP(i, 1, n) dis[i] = inf; dis[s] = 0;
        REP(i, 1, n) vis[i] = false;
        q.push({0, s});
        while (!q.empty()) {
            int u = q.top().second; q.pop();
            if (vis[u]) continue; vis[u] = true;
            for (auto i : edge[u]) {
                int v = i.fi, w = i.se;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.push({dis[v], v});
                }
            }
        }
    }

    void main() {
        cin >> n >> m;
        cin >> S >> T;
        cin >> U >> V;
        REP(i, 1, m) {
            cin >> u >> v >> w;
            edge[u].pb(v, w);
            edge[v].pb(u, w);
        }
        dijkstra(T);
        node.pb(S), qnode.push(S); visnode[S] = true;
        while (!qnode.empty()) {
            int u = qnode.front(); qnode.pop();
            for (auto i : edge[u]) {
                int v = i.fi, w = i.se;
                if (dis[v] == dis[u] - w) {
                    if (!visnode[v]) {
                        node.pb(v);
                        qnode.push(v);
                        visnode[v] = true;
                    }
                    g1[u].pb(v);
                    g2[v].pb(u);
                }
            }
        }
        dijkstra(U);
        sort(ALL(node), [](int x, int y) { return dis[x] < dis[y]; });
        for (auto u : node) visg1[u] = 0, disg1[u] = inf;
        for (auto u : node) {
            if (!visg1[u]) {
                visg1[u] = true;
                disg1[u] = dis[u];
                cnode.push(u);
            }
            while (!cnode.empty()) {
                int u = cnode.front(); cnode.pop();
                for (auto v : g1[u]) {
                    if (!visg1[v]) {
                        visg1[v] = true;
                        disg1[v] = disg1[u];
                        cnode.push(v);
                    }
                }
            }
        }
        for (auto u : node) visg2[u] = 0, disg2[u] = inf;
        for (auto u : node) {
            if (!visg2[u]) {
                visg2[u] = true;
                disg2[u] = dis[u];
                cnode.push(u);
            }
            while (!cnode.empty()) {
                int u = cnode.front(); cnode.pop();
                for (auto v : g2[u]) {
                    if (!visg2[v]) {
                        visg2[v] = true;
                        disg2[v] = disg2[u];
                        cnode.push(v);
                    }
                }
            }
        }
        for (auto u : node) {
            distoU[u] = min(disg1[u], disg2[u]);
        }
        dijkstra(V); ans = dis[U];
        for (auto u : node) {
            MIN(ans, distoU[u] + dis[u]);
        }
        cout << ans << '\n';
    }
}

signed main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}

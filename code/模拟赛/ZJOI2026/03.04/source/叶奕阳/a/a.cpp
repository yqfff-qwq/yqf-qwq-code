#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define REP(i,a,b)    for(int i=(a);i<=(b);i++)
#define DEP(i,a,b)    for(int i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(int i=(a);i<=(b);i+=c)
#define DEPc(i,a,b,c) for(int i=(a);i>=(b);i-=c)
#define MIN(a,b) ((a)=min((a),(b)))
#define MAX(a,b) ((a)=max((a),(b)))
#define ADD(a,b) ((a)=((a)+(b))%mod)
#define MUL(a,b) ((a)=((a)*(b))%mod)
#define ALL(a)   (a).begin(),(a).end()
#define SZ(a)    (a).size()
#define int long long
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

namespace Yyydrasil {

    const int mxN = 2e5 + 5, mxM = 2e5 + 5, mxQ = 2e5 + 5;
    struct E { int u, v, w, id; } edge[mxM];
    int n, m, q, u, v, w, l, r, rt, sum, k[mxN], ans[mxN];

    int fa[mxN];
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    vector<int> sons[mxN];
    void kruskal() {
        sort(edge + 1, edge + 1 + m, [](E a, E b) { return a.w < b.w; });
        REP(i, 1, n + m) fa[i] = i;
        REP(i, 1, m) {
            int u = find(edge[i].u);
            int v = find(edge[i].v);
            int w = edge[i].w;
            int id = edge[i].id;
            if (u != v) {
                sons[n + id].pb(u);
                sons[n + id].pb(v);
                sum += w;
                k[n + id] = w;
                fa[u] = n + id;
                fa[v] = n + id;
                rt = n + id;
            }
        }
    }

    int sz[mxN];
    void dfs(int u, int f) {
        if (!SZ(sons[u])) return sz[u] = 1, void();
        fa[u] = f, sz[u] = 0;
        for (auto v : sons[u]) if (v != fa[u]) dfs(v, u);
        sort(ALL(sons[u]), [](int x, int y) { return sz[x] > sz[y]; });
    }

    set<int> leaf;
    vector<pii> chan[mxN];
    void dfs_add_add(int u) {
        if (!SZ(sons[u])) {
            leaf.insert(u);
        } else {
            dfs_add_add(sons[u][0]);
            dfs_add_add(sons[u][1]);
        }
    }
    void dfs_add(int u, int U) {
        // cerr << "dfs_add: " << u << ' ' << SZ(sons[u]) << ' ' << U << '\n';
        if (!SZ(sons[u])) {
            // cerr << "find: " << u << '\n';
            // cerr << SZ(chan[U]) << '\n';
            if (leaf.lower_bound(u) != leaf.end()) chan[U].pb({u, *leaf.lower_bound(u)});
            if (leaf.upper_bound(u) != leaf.begin()) chan[U].pb({*(--leaf.upper_bound(u)), u});
        } else {
            dfs_add(sons[u][0], U);
            dfs_add(sons[u][1], U);
        }
    }
    void dfs2(int u) {
        if (!SZ(sons[u])) return leaf.insert(u), void();
        // cerr << u << ' ' << "###" << ' ' << SZ(sons[u]) << '\n';
        dfs2(sons[u][1]), leaf.clear();
        dfs2(sons[u][0]);
        // cerr << "Start Calc " << u << '\n';
        dfs_add(sons[u][1], u);
        dfs_add_add(sons[u][1]);
        // cerr << "End\n";
    }

    struct M { int r, w; };
    vector<M> ch[mxN];
    struct Q { int l, id; };
    vector<Q> qry[mxN];

    struct tree {
        int tree[mxN];
        int lowbit(int x) { return x & -x; }
        void add(int x, int k) {
            while (x <= n) {
                tree[x] += k;
                x += lowbit(x);
            }
        }
        int qry(int x) {
            int res = 0;
            while (x) {
                res += tree[x];
                x -= lowbit(x);
            } return res;
        }
    } tree;

    void main() {
        cin >> n >> m >> q;
        REP(i, 1, m) {
            cin >> u >> v >> w, u++, v++;
            edge[i] = {u, v, w, i};
        }
        kruskal();
        // REP(i, n + 1, n + m) cerr << k[i] << '\n';
        dfs(rt, 0);
        dfs2(rt);
        // cerr << "###\n";
        REP(i, n + 1, n + m) {
            sort(ALL(chan[i]), [](pii a, pii b) { return a.se < b.se; });
            if (SZ(chan[i])) {
                sort(ALL(chan[i]), [](pii a, pii b) { 
                    if (a.se != b.se) return a.se < b.se;
                    return a.fi > b.fi; 
                });
                vector<pii> tmp;
                int mxl = 0;
                for (auto p : chan[i]) {
                    if (p.fi > mxl) {
                        mxl = p.fi;
                        tmp.pb(p);
                    }
                }
                chan[i] = tmp;
                chan[i].pb({n + 1, n + 1});
                REP(j, 0, SZ(chan[i]) - 2) {
                    pii a = chan[i][j];
                    pii b = chan[i][j + 1];
                    ch[a.se].pb({a.fi, k[i]});
                    ch[b.se].pb({a.fi, -k[i]});
                }
            }
        }
        REP(i, 1, q) {
            cin >> l >> r;
            l++, r++;
            qry[r].pb({l, i});
        }
        REP(i, 1, n) {
            for (auto c : ch[i]) tree.add(1, c.w), tree.add(c.r + 1, -c.w);
            for (auto q : qry[i]) ans[q.id] = sum - tree.qry(q.l);
        }
        REP(i, 1, q) {
            cout << ans[i] << '\n';
        }
    }
}

signed main() {
    freopen("a.in", "r", stdin) ? void() : void();
    freopen("a.out", "w", stdout) ? void() : void();
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}

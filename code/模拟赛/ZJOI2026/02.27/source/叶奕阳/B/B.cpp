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

    const int mxN = 1e6 + 5;
    int n, m, q, op, u, v, w, x, b, c;
    vector<pii> edge[mxN];

    const int mxNM = 1e8 + 5;
    int fa[mxNM];
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    int id(pii x) { return (x.fi - 1) * m + x.se + 1; }
    void merge(pii x, pii y) { fa[find(id(x))] = find(id(y)); }
    bool qry(pii x, pii y) { return find(id(x)) == find(id(y)); }

    int fa2[mxN];
    bool val[mxN];
    int find2(int x) { return x == fa2[x] ? x : fa2[x] = find2(fa2[x]); }
    void merge2(int x, int y, int w) { x = find2(x), y = find2(y), fa2[x] = y, val[y] |= val[x], val[y] |= (w % m != 0); }
    bool qry2(int x, int y, int w) { x = find2(x), y = find2(y); return (x == y) && (w == 0 || val[x]); }
    bool isprime(int x) {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0 && i != x) return false;
        } return true;
    }

    vector<int> node[mxN], sum[mxN];
    int p1[mxN], p2[mxN];

    void main() {
        cin >> n >> m >> q;
        if ((n <= 100 && m <= 100 && q <= 100) || (m == 2)) {
            REP(i, 1, n * m) fa[i] = i;
            REP(i, 1, q) {
                cin >> op;
                if (op == 1) {
                    cin >> u >> v >> w;
                    edge[u].pb({v, w});
                    edge[v].pb({u, w});
                    REP(k, 1, 2 * m){
                        int s = 1ll * k * w % m;
                        if (k % 2 == 0) {
                            REP(c, 0, m - 1) {
                                merge({u, c}, {u, (c + s) % m});
                                merge({v, c}, {v, (c + s) % m});
                            }
                        } else {
                            REP(c, 0, m - 1) {
                                merge({u, c}, {v, (c + s) % m});
                                merge({v, c}, {u, (c + s) % m});
                            }
                        }
                    }
                } else {
                    cin >> u >> v >> x >> b >> c; x %= m;
                    int res = 0;
                    REP(k, 1, c) {
                        res += qry({u, 0}, {v, x});
                        x = (x + b) % m;
                    }
                    cout << res << '\n';
                }
            }
        } else if (isprime(m)) {
            REP(i, 1, n) fa2[i] = i, val[i] = 0;
            REP(i, 1, q) {
                cin >> op;
                if (op == 1) {
                    cin >> u >> v >> w;
                    merge2(u, v, w);
                } else {
                    cin >> u >> v >> x >> b >> c; x %= m;
                    int res = 0;
                    REP(k, 1, c) {
                        res += qry2(u, v, x);
                        x = (x + b) % m;
                    }
                    cout << res << '\n';
                }
            }
        } else {
            REP(i, 1, n) node[i].pb(i), sum[i].pb(0), p1[i] = i, p2[i] = 0;
            REP(i, 1, q) {
                cin >> op;
                if (op == 1) {
                    cin >> u >> v >> w;
                    if (SZ(node[u]) < SZ(node[v])) swap(u, v);
                    int len = SZ(node[u]);
                    REP(i, 0, SZ(node[v]) - 1) {
                        node[u].pb(node[v][i]);
                        sum[u].pb(sum[u].back() + sum[v][i]);
                        p1[node[v][i]] = u;
                        p2[node[v][i]] = len++;
                    }
                } else {
                    cin >> u >> v >> x >> b >> c; x %= m;
                    int res = 0;
                    REP(k, 1, c) {
                        if (p1[u] == p1[v]) {
                            int s = sum[p1[u]][SZ(sum[p1[u]]) - 1];
                            int s1 = sum[p1[u]][p2[u]] - sum[p1[v]][p2[v]];
                            int s2 = s + s1;
                            if (s1 == x || s2 == x) res++;
                        }
                        x = (x + b) % m;
                    }
                    cout << res << '\n';
                }
            }
        }
    }
}

signed main() {
    freopen("B.in", "r", stdin) ? void() : void();
    freopen("B.out", "w", stdout) ? void() : void();
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}

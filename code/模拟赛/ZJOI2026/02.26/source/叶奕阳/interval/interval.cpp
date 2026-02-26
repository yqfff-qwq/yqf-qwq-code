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

    const int inf = 0x3f3f3f3f3f3f3f3f;
    const int mxN = 1e5 + 5;
    int n, m, op, l[mxN], r[mxN], a, b;
    int gl[mxN], gr[mxN];
    set<pii> segs;
    
    int fa[mxN];
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

    struct seg {
        int id;
        int L() { return l[id]; }
        int R() { return r[id]; }
        friend bool operator < (seg a, seg b) { return l[a.id] < l[b.id]; }
        void merge(int y) {
            // cout << l[y] << ' ' << r[y] << " into " << l[id] << ' ' << r[id] << '\n';
            MIN(l[id], l[y]), MAX(r[id], r[y]);
            fa[find(y)] = id;
        }
    }; set<seg> s[mxN];

    bool in(int a, int l, int r) { return l < a && a < r; }

    vector<pair<seg, pii>> chan;
    void dfs(int u, seg &x) {
        // cout << "in dfs: " << l[u] << ' ' << r[u] << '\n';
        for (auto i = begin(s[u]); i != end(s[u]); i++) {
            seg v = *i;
            if ((x.R() <= v.L() || v.R() <= x.L()) || 
                (x.L() <= v.L() && v.R() <= x.R())) {
                chan.pb({v, {u, x.id}});
                // cout << l[v.id] << ' ' << r[v.id] << " belongs to " << l[x.id] << ' ' << r[x.id] << '\n';
            } else {
                chan.pb({v, {u, n + 1}});
                // cout << "delete " << l[v.id] << ' ' << r[v.id] << '\n';
                dfs(v.id, x);
            }
        }
        x.merge(u);
    }

    void add_seg(seg x) {
        // cout << "add_seg: " << x.id << ' ' << l[x.id] << ' ' << r[x.id] << '\n';
        for (auto i = begin(s[0]); i != end(s[0]); i++) {
            seg v = *i;
            if (x.R() <= v.L() || v.R() <= x.L()) continue;
            if (x.L() == v.L() && v.R() == x.R()) {
                x.merge(v.id);
            } else if (x.L() <= v.L() && v.R() <= x.R()) {
                chan.pb({v, {0, x.id}});
            } else {
                chan.pb({v, {0, n + 1}});
                dfs(v.id, x);
            }
        }
        // cout << "RE: End of the x: " << l[x.id] << ' ' << r[x.id] << '\n';
        // cout << '\n';
        for (auto c : chan) {
            s[c.se.fi].erase(c.fi);
            s[c.se.se].insert(c.fi);
            // cout << c.se.fi << " erase " << l[c.fi.id] << ' ' << r[c.fi.id] << '\n';
            // cout << c.se.se << " insert " << l[c.fi.id] << ' ' << r[c.fi.id] << '\n';
        } chan.clear();
        s[0].insert(x);
        // cout << "Now s[0]: ";
        // for (auto v : s[0]) cout << l[v.id] << ',' << r[v.id] << ' ';
        // cout << '\n';
    }

    bool qry_seg(int a, int b) {
        // cout << "qry_seg: " << a << ' ' << b << '\n';
        a = find(a), b = find(b);
        // cout << a << " : " << l[a] << ' ' << r[a] << '\n';
        // cout << b << " : " << l[b] << ' ' << r[b] << '\n';
        if (a == b && ((l[find(a)] != gl[a] || r[find(a)] != gr[a]) && (l[find(a)] == gl[a] && r[find(a)] == gr[a]))) return false;
        return a == b || in(l[a], l[b], r[b]) || in(r[a], l[b], r[b]);
    }
    
    void print_tree(int u) {
        for (auto v : s[u]) {
            // cout << l[u] << ' ' << r[u] << " to " << l[v.id] << ' ' << r[v.id] << '\n';
            print_tree(v.id);
        }
    }

    void main() {
        l[0] = -inf, r[0] = inf;
        cin >> n;
        REP(i, 1, n) fa[i] = i;
        REP(i, 1, n) {
            cin >> op;
            if (op == 1) {
                m++;
                cin >> l[m] >> r[m];
                l[m] = l[m] * 2 + 1;
                r[m] = r[m] * 2;
                if (segs.find({l[m], r[m]}) != segs.end()) continue;
                segs.insert({l[m], r[m]});
                gl[m] = l[m], gr[m] = r[m];
                add_seg({m});
            } else {
                cin >> a >> b;
                if (in(gl[a], gl[b], gr[b]) || in(gr[a], gl[b], gr[b])) {
                    cout << "YES" << '\n';
                } else if (gl[a] == gl[b] && gr[a] == gr[b]) {
                    cout << ((a == b || ((l[find(a)] != gl[a] || r[find(a)] != gr[a]) && (l[find(a)] != gl[a] || r[find(a)] != gr[a]))) ? "YES" : "NO") << "\n"; 
                } else {
                    cout << (qry_seg(a, b) ? "YES" : "NO") << '\n';
                }
            }
            print_tree(0);
        }
    }
}

signed main() {
    freopen("interval.in", "r", stdin) ? void() : void();
    freopen("interval.out", "w", stdout) ? void() : void();
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}

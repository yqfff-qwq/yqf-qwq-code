#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define RAP(i,a)      for(auto i=(a).begin();i!=(a).end();i++)
#define REP(i,a,b)    for(register int i=(a);i<=(b);i++)
#define DEP(i,a,b)    for(register int i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(register int i=(a);i<=(b);i+=(c))
#define DEPc(i,a,b,c) for(register int i=(a);i>=(b);i-=(c))
#define ADD(a,b) (a)=((a)+(b))%mod
#define SUB(a,b) (a)=((a)-(b)+mod)%mod
#define MUL(a,b) (a)=(((a)%mod)*((b)%mod))%mod
#define MAX(a,b) (a)=max((a),(b))
#define MIN(a,b) (a)=min((a),(b))
#define ALL(a)   (a).begin(),(a).end()
#define SZ(a)    ((int)a.size())
#define ppc(x)   __builtin_popcount(x)
#define DBG(x)   cerr<<#x<<' '<<(x)<<'\n'
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

namespace Yyydrasil {

    inline int read() {
        int x = 0; char ch = getchar();
        while (ch < '0' || ch > '9')   ch = getchar();
        while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
        return x;
    }

    int c[10], totc;
    inline void write(int x) {
        while (x > 9) c[++totc] = x % 10, x /= 10;
        c[++totc] = x % 10, x /= 10;
        while (totc) putchar(c[totc--] ^ 48);
    }

    const int mxN = 5e5 + 5;
    int n, q, fa, a, b;
    vector<int> edge[mxN];
    vector<int> gift[mxN];

    int l[mxN], r[mxN], tot;
    inline void dfs(int u) {
        l[u] = (++tot);
        for (auto v : edge[u]) dfs(v);
        r[u] = tot;
    }

    struct segtree {
        int sum[mxN * 4];
        vector<pii> chan;
        #define lp  (p << 1)
        #define rp  (lp | 1)
        #define mid ((l + r) >> 1)
        #define ls  lp, l, mid
        #define rs  rp, mid + 1, r
        inline void start() { chan.pb({-1, -1}); }
        inline void change(int x, int k) { chan.pb({x, sum[x]}), sum[x] = k; }
        inline void undo() {
            pii c = chan.back(); chan.pop_back();
            while (c.fi != -1) {
                sum[c.fi] = c.se;
                c = chan.back(); chan.pop_back();
            }
        }
        inline void pushup(int p) { change(p, sum[lp] + sum[rp]); }
        inline void build(int p, int l, int r) {
            cout << flush;
            if (l == r) return sum[p] = 1, void();
            build(ls), build(rs), pushup(p);
        }
        inline void del(int p, int l, int r, int a, int b) {
            if (p == 1) start();
            if (b < l || r < a || sum[p] == 0) return;
            if (a <= l && r <= b) return change(p, 0);
            del(ls, a, b), del(rs, a, b), pushup(p);
        }
    } tree;

    int ans[mxN];
    inline void solve(int u) {
        for (auto b : gift[u]) tree.del(1, 1, n, l[b], r[b]);
        tree.del(1, 1, n, l[u], l[u]);
        ans[u] = n - tree.sum[1] - 1;
        tree.undo();
        for (auto v : edge[u]) solve(v);
        for (auto b : gift[u]) tree.undo();
    }

    inline void main() {
        n = read(), q = read();
        REP(i, 2, n) fa = read(), edge[fa].pb(i);
        REP(i, 1, q) a = read(), b = read(), gift[a].pb(b), gift[b].pb(a);
        REP(i, 1, n) if (SZ(gift[i])) gift[i].pb(i);
        dfs(1), tree.build(1, 1, n);
        solve(1);
        REP(i, 1, n) write(ans[i]), putchar(' ');
        putchar('\n');
    }
}

signed main() {
    freopen("reward.in", "r", stdin);
    freopen("reward.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}

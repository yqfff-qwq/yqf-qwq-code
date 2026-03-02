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
    const int mxN = 3e5 + 5, mxM = 6e5 + 5, mxP = 3e5 + 5;
    int n, m, p, u[mxM], v[mxM], w[mxM], genw[mxM];
    int mnr[mxP], len[mxP];
    int Q, L, R, X;

    vector<int> bw;
    void discrete() {
        REP(i, 1, m) bw.pb(w[i]);
        sort(ALL(bw)), bw.erase(unique(ALL(bw)), bw.end());
        REP(i, 1, m) {
            int x = lower_bound(ALL(bw), w[i]) - bw.begin() + 1;
            genw[x] = w[i];
            w[i] = x;
        } p = SZ(bw) - 1;
    }

    struct undo_mqs {
        int sum;
        vector<pii> stk;
        vector<int> edge[mxN];
        bool vis[mxN];
        void init(int n) {
            REP(i, 1, n) vis[i] = false; vis[1] = true;
            sum = n - 1;
            vector<pii>().swap(stk);
        }
        void startdo() { stk.pb({inf, inf}); }
        void cedge(int u, int v) { stk.pb({1e9, u}), edge[u].pb(v); }
        void cvis(int u) { stk.pb({2e9, u}), vis[u] = true; }
        void csum(int k) { stk.pb({0, sum}), sum = k; }
        void undo() {
            pii c;
            while (c = stk.back(), stk.pop_back(), c.fi != inf) {
                if (c.fi == 0) sum = c.se;
                else if (c.fi == 1e9) edge[c.se].pop_back();
                else if (c.fi == 2e9) vis[c.se] = false;
            }
        }
        void dfs(int u) {
            cvis(u);
            csum(sum - 1);
            for (auto v : edge[u]) {
                if (!vis[v]) dfs(v);
            }
        }
        void merge(int x, int y) {
            cedge(x, y);
            if (vis[x] && !vis[y]) {
                dfs(y);
            }
        }
    } mqs;

    vector<pii> edge[mxP];
    void solve(int ql, int qr, int sl, int sr) {
        // cout << ql << ' ' << qr << ' ' << sl << ' ' << sr << '\n';
        if (ql > qr) return;
        if (sl == sr) {
            REP(i, ql, qr) mnr[i] = sl;
            return;
        }
        int qmid = (ql + qr) >> 1, smid = max(qmid, sl) - 1, totdo = 0;
        REP(i, qmid, min(sl - 1, qr)) {
            // cout << "add: " << i << '\n';
            for (auto e : edge[i]) /*cout << e.fi << ' ' << e.se << '\n', */totdo++, mqs.startdo(), mqs.merge(e.fi, e.se);
        }
        while (mqs.sum != 1) {
            smid++;
            // cout << "add: " << smid << '\n';
            for (auto e : edge[smid]) /*cout << e.fi << ' ' << e.se << '\n', */totdo++, mqs.startdo(), mqs.merge(e.fi, e.se);
        }
        while (totdo > 0) mqs.undo(), totdo--;
        // cout << "qmid = " << qmid << " , smid = " << smid << '\n';
        mnr[qmid] = smid;
        int ql1 = ql, qr1 = qmid - 1, sl1 = sl, sr1 = smid;
        int ql2 = qmid + 1, qr2 = qr, sl2 = smid, sr2 = sr;

        REP(i, qmid, min(qr, sl - 1)) for (auto e : edge[i]) totdo++, mqs.startdo(), mqs.merge(e.fi, e.se);
        solve(ql1, qr1, sl1, sr1);
        while (totdo > 0) mqs.undo(), totdo--;

        REP(i, max(qr + 1, sl), smid - 1) for (auto e : edge[i]) totdo++, mqs.startdo(), mqs.merge(e.fi, e.se);
        solve(ql2, qr2, sl2, sr2);
        while (totdo > 0) mqs.undo(), totdo--;
    }

    struct sgt1 {
        int mn[mxP * 4];
        #define lp  (p << 1)
        #define rp  (lp | 1)
        #define mid ((l + r) >> 1)
        #define ls  lp, l, mid
        #define rs  rp, mid + 1, r
        void pushup(int p) { mn[p] = min(mn[lp], mn[rp]); }
        void build(int p, int l, int r) {
            if (l == r) return mn[p] = len[l], void();
            build(ls), build(rs), pushup(p);
        }
        int qrymn(int p, int l, int r, int a, int b) {
            if (b < l || r < a)   return inf;
            if (a <= l && r <= b) return mn[p];
            return min(qrymn(ls, a, b), qrymn(rs, a, b));
        }
    } tree1;

    struct sgt2 {
        int mn[mxP * 4];
        #define lp  (p << 1)
        #define rp  (lp | 1)
        #define mid ((l + r) >> 1)
        #define ls  lp, l, mid
        #define rs  rp, mid + 1, r
        void pushup(int p) { mn[p] = min(mn[lp], mn[rp]); }
        void build(int p, int l, int r) {
            if (l == r) return mn[p] = mnr[l], void();
            build(ls), build(rs), pushup(p);
        }
        int qrymn(int p, int l, int r, int a, int b) {
            if (b < l || r < a)   return inf;
            if (a <= l && r <= b) return mn[p];
            return min(qrymn(ls, a, b), qrymn(rs, a, b));
        }
    } tree2;

    void main() {
        cin >> n >> m >> p;
        REP(i, 1, m) cin >> u[i] >> v[i] >> w[i];
        REP(i, 2, n) m++, u[m] = i - 1, v[m] = i, w[m] = inf;
        discrete();
        REP(i, 1, m) edge[w[i]].pb({u[i], v[i]});
        // REP(i, 1, p + 1) {
        //     cout << "Edge of " << i << '\n';
        //     for (auto e : edge[i]) cout << e.fi << ' ' << e.se << '\n';
        //     // edge[w[i]].pb({u[i], v[i]});
        // }

        // REP(i, 1, p) {
        //     if (680952524 <= genw[i] && genw[i] <= 948829619) {
        //         cout << "Ndoe: " << i << '\n';
        //         for (auto e : edge[i]) {
        //             cout << e.fi << ' ' << e.se << '\n';
        //         }
        //     }
        // }
        
        mqs.init(n), solve(1, p, 1, p + 1);
        REP(i, 1, p) mnr[i] = genw[mnr[i]];
        REP(i, 1, p) len[i] = mnr[i] - genw[i] + 1;
        // REP(i, 1, p) cout << genw[i] << ' '; cout << '\n';
        // REP(i, 1, p) cout << mnr[i] << ' '; cout << '\n';
        // REP(i, 1, p) cout << len[i] << ' '; cout << '\n';
        tree1.build(1, 1, p);
        tree2.build(1, 1, p);
        cin >> Q;
        REP(i, 1, Q) {
            cin >> L >> R >> X; int mxlen = (R - L + 1) + X;
            int l1 = lower_bound(genw + 1, genw + 1 + p, L - X) - genw;
            int r1 = upper_bound(genw + 1, genw + 1 + p, L) - genw - 1;
            int l2 = lower_bound(genw + 1, genw + 1 + p, L) - genw;
            int r2 = upper_bound(genw + 1, genw + 1 + p, R + X) - genw - 1;
            // cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << ' ' << tree1.qrymn(1, 1, p, l1, r1) << ' ' << tree2.qrymn(1, 1, p, l2, r2) << '\n';
            if (tree1.qrymn(1, 1, p, l1, r1) <= mxlen || tree2.qrymn(1, 1, p, l2, r2) <= R + X) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
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

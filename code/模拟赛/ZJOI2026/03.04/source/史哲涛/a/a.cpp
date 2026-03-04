#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int f[200010];
inline int fnd(int x){return x == f[x]? x : f[x] = fnd(f[x]);}
int fa[200010];
int w[200010];
array<int, 2> ch[200010];

// int sz[200010], dep[200010];
// void dfs(int u){
//     dep[u] = dep[fa[u]] + 1;
//     sz[u] = 1;
//     if (ch[u][0]){
//         dfs(ch[u][0]), dfs(ch[u][1]);
//         sz[u] += sz[ch[u][0]] + sz[ch[u][1]];
//         if (sz[ch[u][0]] < sz[ch[u][1]])swap(ch[u][0], ch[u][1]);
//     }
// }
// int top[200010], dfn[200010], tot, rk[200010];
// void dfs2(int u, int tp){
//     top[u] = tp; dfn[u] = ++tot; rk[tot] = u;
//     if (ch[u][0]){
//         dfs2(ch[u][0], tp);
//         dfs2(ch[u][1], ch[u][1]);
//     }
// }
// void bd(){
//     int rt = n + n - 1;
//     dfs(rt);
//     dfs2(rt, rt);
// }
// int lca(int u, int v){
//     while (top[u] ^ top[v]){
//         if (dep[top[u]] < dep[top[v]])swap(u, v);
//         u = fa[top[u]];
//     }
//     return dep[u] < dep[v]? u : v;
// }
// int lcawd(int u, int v){
//     return w[lca(rk[u], rk[v])];
// }

int wf[200010], tot, dfn[200010];
void dfs(int u){
    dfn[u] = ++tot;
    wf[tot] = w[fa[u]];
    if (ch[u][0])dfs(ch[u][0]), dfs(ch[u][1]);
}
int mx[20][200010];
void bd(){
    dfs(n + n - 1);
    copy_n(wf + 1, tot, mx[0] + 1);
    for (int i = 1; 1 << i <= tot; ++i)
        for (int j = 1; j + (1 << i) - 1 <= tot; ++j)
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
}
int lcawd(int u, int v){
    assert(u != v);
    if (u > v)swap(u, v);
    int t = __lg(v - u + 1);
    return max(mx[t][u], mx[t][v - (1 << t) + 1]);
}

int main(){
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    // freopen("7.in", "r", stdin);
    // freopen(".out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;
    long long s = 0;
    {
        vector<tuple<int, int, int> > edg;
        while (m--){
            int u, v, w;
            cin >> u >> v >> w;
            edg.emplace_back(w, ++u, ++v);
        }
        sort(edg.begin(), edg.end());
        iota(f + 1, f + n + n + 1, 1);
        int t = n;
        for (auto wuv : edg){
            int w = get<0>(wuv);
            int u = get<1>(wuv);
            int v = get<2>(wuv);
            u = fnd(u), v = fnd(v);
            if (u == v)continue;
            ++t;
            f[u] = f[v] = t;
            fa[u] = fa[v] = t;
            ch[t] = {u, v};
            ::w[t] = w;
            s += w;
        }
        assert(t == n + n - 1);
    }
    bd();
    // while (q--){
    //     int l, r;
    //     cin >> l >> r; ++l, ++r;
    //     vector<int> df(dfn + l, dfn + r + 1);
    //     sort(df.begin(), df.end());
    //     long long rs = s;
    //     for (int i = 1, _ = df.size(); i < _; ++i)
    //         rs -= lcawd(df[i - 1], df[i]);
    //     cout << rs << "\n";
    // }
    struct Qry { int l, r, id; };
    static Qry qr[200010];
    for (int i = 1; i <= q; ++i){
        int l, r;
        cin >> l >> r;
        qr[i] = {++l, ++r, i};
    }
    int S = q / sqrt(n); if (S < 1)S = 1; if (S > n)S = n;
    static int bt[200010];
    for (int i = 1; i <= n; ++i)bt[i] = (i - 1) / S + 1;
    static int Lp[200010], Rp[200010];
    for (int i = 1; i <= bt[n]; ++i)Lp[i] = Rp[i - 1] + 1, Rp[i] = min(n, Rp[i - 1] + S);
    sort(qr + 1, qr + q + 1, [&](Qry a, Qry b){
        return bt[a.l] == bt[b.l]? a.r > b.r : bt[a.l] < bt[b.l];
    });
    static long long rs[200010];
    fill_n(rs + 1, q, s);
    static pair<int, int> st[200010];
    for (int i = 1; i <= n; ++i)st[i] = {dfn[i], i};
    for (int i = 1; i <= bt[n]; ++i)sort(st + Lp[i], st + Rp[i] + 1);
    long long sm = 0;
    static int nx[400010], pr[400010];
    vector<pair<int, int> > idq(st + 1, st + n + 1);
    sort(idq.begin(), idq.end());
    for (int i = 1, L = 1, R = 0, lb = 0; i <= q; ++i){
        if (bt[qr[i].l] == bt[qr[i].r]){
            int b = bt[qr[i].l];
            int p = 0;
            for (int j = Lp[b]; j <= Rp[b]; ++j)
                if (st[j].second >= qr[i].l && st[j].second <= qr[i].r){
                    if (p)rs[qr[i].id] -= lcawd(p, st[j].first);
                    p = st[j].first;
                }
            continue;
        }
        if (lb != bt[qr[i].l]){
            L = Lp[bt[qr[i].l]], R = n;
            int p = 0;
            sm = 0;
            for (auto wq : idq)
                if (wq.second >= L){
                    if (p)sm += lcawd(p, wq.first);
                    nx[p] = wq.first;
                    pr[wq.first] = p;
                    p = wq.first;
                }
            nx[p] = 0;
            lb = bt[qr[i].l];
        }
        auto del = [&](int u, long long &sm){
            if (pr[u])sm -= lcawd(pr[u], u);
            if (nx[u])sm -= lcawd(u, nx[u]);
            nx[pr[u]] = nx[u];
            pr[nx[u]] = pr[u];
            if (pr[u] && nx[u])sm += lcawd(pr[u], nx[u]);
        };
        auto pb = [&](int u){
            nx[pr[u]] = u;
            pr[nx[u]] = u;
        };
        while (R > qr[i].r)
            del(dfn[R--], sm);
        int LL = L; long long ssm = sm;
        while (LL < qr[i].l){
            del(dfn[LL++], ssm);
        }
        rs[qr[i].id] -= ssm;
        while (LL > L)pb(dfn[--LL]);
    }
    for (int i = 1; i <= q; ++i)cout << rs[i] << "\n";
    return 0;
}
/*
cd 史哲涛
cd a
g++ a.cpp -o a -std=c++11 -O2
./a <1.in >.out
diff .out 1.ans -w
./a <2.in >.out
diff .out 2.ans -w
./a <3.in >.out
diff .out 3.ans -w
./a <4.in >.out
diff .out 4.ans -w
./a <5.in >.out
diff .out 5.ans -w
./a <6.in >.out
diff .out 6.ans -w
./a <7.in >.out
diff .out 7.ans -w

./a <060-g7-all11.in >.out
diff .out 060-g7-all11.ans -w

*/
#include <bits/stdc++.h>
#define file_name "C"
struct prg_timer {
    using csc = std::chrono::steady_clock;const csc::time_point bg;static auto now(){ return csc::now(); } prg_timer() : bg(now()) { }
    void prttm(){ std::clog << "time use = " << std::chrono::duration_cast<std::chrono::milliseconds>(now() - bg).count() << "ms" << std::endl; }
    ~prg_timer(){ prttm(); }
} tmr;
using namespace std;bool SZT_MEM_BG;

int n, q, k;
namespace S1 {
    int s[3010];
    int lwb[3010];
    void add(int x, int v){
        while (x <= n){
            s[x] ^= v;
            x += lwb[x];
        }
    }
    int qry(int x){
        int ret = 0;
        while (x){
            ret ^= s[x];
            x -= lwb[x];
        }
        return ret;
    }
    void sol1(){
        for (int i = 1; i <= n; ++i)lwb[i] = i % k? i % k : lwb[i / k] * k;
        while (q--){
            int op;
            cin >> op;
            if (op == 1){
                int x, v;
                cin >> x >> v;
                add(x, v);
            } else {
                int x;
                cin >> x;
                cout << qry(x) << "\n";
            }
        }
        exit(0);
    }
}
namespace S2 {
    int s[200010];
    void add(int x, int v){
        while (x <= n){
            s[x] ^= v;
            x += x & -x;
        }
    }
    int qry(int x){
        int ret = 0;
        while (x){
            ret ^= s[x];
            x &= x - 1;
        }
        return ret;
    }
    void sol2(){
        while (q--){
            int op;
            cin >> op;
            if (op == 1){
                int x, v;
                cin >> x >> v;
                add(x, v);
            } else {
                int x;
                cin >> x;
                cout << qry(x) << "\n";
            }
        }
        exit(0);
    }
}

namespace S3 {
    int lwb[200010];
    int f[200010];
    vector<int> c[200010];
    int bt[200010];

    int sz[200010], wt[200010], dep[200010];
    void dfs(int u){
        sz[u] = 1;
        for (int v : c[u])dep[v] = dep[u] + 1, dfs(v), sz[u] += sz[v], sz[v] > sz[wt[u]] && (wt[u] = v);
    }
    int top[200010], dfn[200010], tot;
    void dfs2(int u, int tp){
        top[u] = tp; dfn[u] = ++tot;
        if (wt[u])dfs2(wt[u], tp);
        for (int v : c[u])if (v ^ wt[u])dfs2(v, v);
    }

    namespace bit {
        int v[200010];
        void md(int p, int x){
            for (; p <= n; p += p & -p)v[p] ^= x;
        }
        int gt(int p){
            int r = 0;
            for (; p; p &= p - 1)r ^= v[p];
            return r;
        }
    }

    void md(int l, int r, int x){
        bit::md(l, x);
        bit::md(r + 1, x);
    }
    int gt(int p){
        return bit::gt(p);
    }

    // int v[200010];
    // void md(int l, int r, int x){
    //     for (int i = l; i <= r; ++i)v[i] ^= x;
    // }
    // int gt(int p){
    //     return v[p];
    // }

    void add(int x, int v){
        // while (x){
        //     md(dfn[x], dfn[x], v);
        //     x = f[x];
        // }
        while (x){
            md(dfn[top[x]], dfn[x], v);
            x = f[top[x]];
        }
    }
    int qry(int x){
        int ret = 0;
        while (x){
            ret ^= gt(dfn[x]);
            x -= lwb[x];
        }
        return ret;
    }
    void sol3(){
        for (int i = 1; i <= n; ++i)lwb[i] = i % k? i % k : lwb[i / k] * k;
        for (int x = 1; x <= n; ++x)f[x] = x + lwb[x];
        for (int x = 1; x <= n; ++x)if (f[x] <= n)c[f[x]].emplace_back(x); else f[x] = 0;
        for (int i = n; i; --i)if (!f[i])bt[i] = i; else bt[i] = bt[f[i]];
        for (int i = 1; i <= n; ++i)if (bt[i] == i)dfs(i), dfs2(i, i);
        while (q--){
            int op;
            cin >> op;
            if (op == 1){
                int x, v;
                cin >> x >> v;
                add(x, v);
            } else {
                int x;
                cin >> x;
                cout << qry(x) << "\n";
            }
        }
    }
}

bool SZT_MEM_ED;int main(){
    // freopen(file_name".in", "r", stdin);
    // freopen(file_name".out", "w", stdout);
    freopen(file_name"4.in", "r", stdin);
    freopen(".out", "w", stdout);
    const double static_local_mem_use = fabs(&SZT_MEM_ED - &SZT_MEM_BG) / 1024 / 1024;
    clog << "static local mem use = " << static_local_mem_use << "M" << endl;
    assert(static_local_mem_use < 64);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> q >> k;
    if (n <= 3000 && q <= 3000)S1::sol1(); // 17pts
    if (n <= 2e5 && k == 2)S2::sol2(); // 15pts
    if (n <= 2e5)S3::sol3(); // 43pts

    return 0;
}
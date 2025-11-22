#include <vector>

namespace trdec {

    // 分块，返回关键点列表，满足从关键点的儿子处断开后每个连通块 <= B
    template <typename _Enum_Child>
        inline std::vector<std::size_t> select(
            _Enum_Child &&enum_child, std::size_t root, std::size_t n, std::size_t B
        ){
            std::vector<std::size_t> cnt(n); // 直接子关键点数量
            std::vector<std::size_t> sz(n); // 连通块大小
            std::vector<std::size_t> kp; // 关键点列表
            auto dfs = [&](auto &&slf, std::size_t u) -> void {
                sz[u] = 1;
                for (std::size_t v : enum_child(u)){
                    slf(slf, v);
                    sz[u] += sz[v];
                    cnt[u] += cnt[v];
                }
                if (cnt[u] > 1 || sz[u] > B || u == root){
                    kp.emplace_back(u);
                    cnt[u] = sz[u] = 1;
                }
            };
            dfs(dfs, root);
            return kp;
        }

}


#include <bits/stdc++.h>
using namespace std;
int n, bas, md, a[100010];
vector<int> e[100010];
int f[100010];
void dfs(int u, int fa){
    f[u] = fa;
    if (fa)e[u].erase(find(e[u].begin(), e[u].end(), fa));
    for (int v : e[u])dfs(v, u);
}
int kp[100010];
int fkp[100010];//father kpoint
bitset<100010> bs[1010], T;
void dfs2(int u, int fp){
    T.flip(a[u]);
    fkp[u] = fp;
    if (kp[u])fp = u, bs[kp[u]] = T;
    for (int v : e[u])dfs2(v, fp);
    T.flip(a[u]);
}
namespace trspl {
    int sz[100010], wt[100010];
    inline void dfs(int u){
        sz[u] = 1;
        for (int v : e[u])dfs(v), sz[u] += sz[v], sz[v] > sz[wt[u]] && (wt[u] = v);
    }
    int top[100010], dfn[100010], tot, dep[100010];
    inline void dfs2(int u, int tp){
        top[u] = tp; dep[u] = dep[f[u]] + 1;
        dfn[u] = ++tot;
        if (wt[u])dfs2(wt[u], tp);
        for (int v : e[u])if (v ^ wt[u])dfs2(v, v);
    }
    inline void bd(){
        dfs(1);
        dfs2(1, 1);
    }
    inline int lca(int u, int v){
        while (top[u] ^ top[v]){
            if (dep[top[u]] < dep[top[v]])swap(u, v);
            u = f[top[u]];
        }
        return dep[u] < dep[v]? u : v;
    }
}
int main(){
    freopen("temple.in", "r", stdin);
    freopen("temple.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> bas >> md;
    for (int i = 1; i <= n; ++i)cin >> a[i];
    for (int i = 1, u, v; i < n; ++i){
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs(1, 0);
    int tot = 0;
    for (int u : trdec::select([](int u) -> std::vector<int>& {return e[u];}, 1, n + 1, sqrt(n)))
        kp[u] = ++tot;
    dfs2(1, 0);
    trspl::bd();
    int q;
    cin >> q;
    int ha = 0;
    while (q--){
        int u, v;
        cin >> u >> v; u ^= ha, v ^= ha;
        int l = trspl::lca(u, v);
        T.reset();
        auto ins = [&](int u){
            while (!kp[u])T.flip(a[u]), u = f[u];
            T ^= bs[kp[u]];
        };
        ins(u); ins(v);
        T.flip(a[l]);
        bool ys = T.count() < trspl::dep[u] + trspl::dep[v] - trspl::dep[l] * 2 + 1;
        ha = (1ll * ha * bas + ys) % md;
        cout << (ys? "Yes" : "No") << "\n";
    }
    return 0;
}
/*
7 0 1
3 1 4 1 5 3 2
1 3
2 3
4 3
5 1
6 2
7 5
5
6 4
2 4
1 5
7 2
1 1
*/
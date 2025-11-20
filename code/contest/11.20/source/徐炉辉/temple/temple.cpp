#include <bits/stdc++.h>
const int N = 1e5 + 5;

int n, q, base, mod, a[N], tot[N], cnt[N];
std::vector<int> e[N];

namespace Tree
{
    int dep[N], fa[N], dfn[N], idx[N], num;
    inline void dfs(const int &u, const int &f)
    {
        dfn[++num] = u, idx[u] = num;
        dep[u] = dep[f] + 1, fa[u] = f;
        for (int v : e[u])
        {
            if (f == v) continue;
            dfs(v, u);
        }
    }

    struct cmin { inline int operator()(const int &x, const int &y) { return dep[x] < dep[y] ? x : y; }};

    template <typename operate>
    class ST
    {
    private:
        operate op;
        int st[20][N];

    public:
        inline void init(int a[])
        {
            for (int i = 1; i <= n; ++i) st[0][i] = a[i];
            for (int i = 1; i <= std::__lg(n); ++i)
                for (int j = 1; j <= n - (1 << i) + 1; ++j)
                    st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }

        inline int ask(const int &l, const int &r)
        {
            int p = std::__lg(r - l + 1);
            return op(st[p][l], st[p][r - (1 << p) + 1]);
        }
    }; 
    ST<cmin> T;

    inline void init(const int &rt = 1)
    { dfs(rt, 0), T.init(dfn); }

    inline int lca(const int &u, const int &v)
    {
        if (u == v) return u;
        return fa[T.ask(std::min(idx[u], idx[v]) + 1, std::max(idx[u], idx[v]))];
    }

    inline int dis(const int &u, const int &v)
    { return (dep[u] + dep[v] - (dep[lca(u, v)] << 1) + 1); }
}
using namespace Tree;

std::bitset<N> sum[N], res;

signed main()
{
    std::freopen("temple.in", "r", stdin);
    std::freopen("temple.out", "w", stdout);

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    auto dfs = [&] (auto &&self, const int &u, const int &f) -> void
    {
        sum[u] = sum[f], sum[u][a[u]].flip();
        for (int v : e[u])
        {
            if (f == v) continue;
            self(self, v, u);
        }
    };

    std::cin >> n >> base >> mod;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1, u, v; i < n; ++i) 
    {
        std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    init(); 
    dfs(dfs, 1, 0);

    std::cin >> q;
    while (q--)
    {
        int u, v; std::cin >> u >> v;
        int LCA = lca(u, v);
        std::cerr << LCA << '\n';
        res = sum[u] ^ sum[v];
        res[a[LCA]].flip();
        std::cout << (res.count() == dis(u, v) ? "No" : "Yes") << '\n';
    }
    return 0;
}
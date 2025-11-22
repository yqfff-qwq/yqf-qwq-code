#include <bits/stdc++.h>
const int N = 1e5 + 5;
int n, q, base, mod, a[N], vis[N];

std::vector<int> e[N], path;

inline void dfs(const int &u, const int &f, std::vector<int> res, const int &aim)
{
    if (u == aim) 
    {
        path = res;
        return ;
    }
    for (int v : e[u])
    {
        if (f == v) continue;
        res.push_back(v);
        dfs(v, u, res, aim);
        res.pop_back();
    }
}

signed main()
{
    std::freopen("temple.in", "r", stdin);
    std::freopen("temple.out", "w", stdout);

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    std::cin >> n >> base >> mod;
    
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    
    for (int i = 1, u, v; i < n; ++i)
    {
        std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    std::cin >> q;
    
    while (q--)
    {
        int l, r; std::cin >> l >> r; bool flag = 0;
        if (l == r) { std::cout << "No" << '\n'; continue; }
        path.clear(); dfs(l, 0, std::vector<int>({l}), r);
        
        for (int i = 1; i <= n; ++i) vis[i] = 0;
        for (int i : path) ++vis[a[i]];
        for (int i = 1; i <= n; ++i) if (vis[i] == 2) { flag = 1; break;}
        
        std::cout << (flag ? "Yes" : "No") << '\n';
    }
    return 0;
}

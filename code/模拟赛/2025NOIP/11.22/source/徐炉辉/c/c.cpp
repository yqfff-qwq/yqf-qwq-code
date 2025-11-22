#include <bits/stdc++.h>

const int N = 2e2 + 5;

int n, v, mod, cnt, ans; bool vis[N],  flag = 1;
std::vector<int> e[N], val;

inline void dfs(const int &u, const int &f)
{
    vis[u] = 1; ++cnt;
    for (int i : e[u])
    {
        if (f == v && vis[v]) continue;
        dfs(v, u);
    }
}

inline void check(const int &step, std::vector<int> res)
{
    if (step == n + 1)
    {
        for (int i = 1; i <= n; ++i) vis[i] = 1;
        for (int i : res) vis[i] = 0; cnt = 0;

        for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i, 0);

        if (cnt != res.size()) return ;

        int mex = 0, min = v + 1;
        for (int i = 1; i <= n; ++i)
        {
            if (vis[i]) min = std::min(min, val[i]);
        }

        std::vector<int> tmp;
        for (int i : res) tmp.push_back(val[i]);

        std::sort(tmp.begin(), tmp.end());
        for (int i : tmp) 
        {
            if (mex + 1 == i) ++mex;
        }

        if (mex != min) flag = 0;
        return ;
    }
    check(step + 1, res);
    res.push_back(step);
    check(step + 1, res);
}

inline void dfs(const int &step, std::vector<int> res)
{
    if (step == n + 1)
    {
        val.clear();
        val.push_back(0);
        for (int i : res) val.push_back(i);
        flag = 1;
        check(1, std::vector<int>());
        ans += flag;
        return ;
    }
    for (int i = 0; i <= v; ++i)
    {
        res.push_back(i);
        dfs(step + 1, res);
        res.pop_back();
    }
}

inline void add(const int &u, const int &v) 
{
    e[u].push_back(v);
    e[v].push_back(u);
}

signed main()
{
    std::freopen("c.in", "r", stdin);
    std::freopen("c.out", "w", stdout);

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    std::cin >> n >> v >> mod;
    
    if (n == 2)
    {
        for (int i = 1; i <= n; ++i) e[i].clear();
        e[1].push_back(2);
        e[2].push_back(1);
        dfs(1, std::vector<int>());
    }
    if (n == 3)
    {
        for (int i = 1; i <= n; ++i) e[i].clear();
        add(1, 2); add(2, 3);
        dfs(1, std::vector<int>());
        for (int i = 1; i <= n; ++i) e[i].clear();
        add(1, 3); add(3, 2);
        dfs(1, std::vector<int>());
        for (int i = 1; i <= n; ++i) e[i].clear();
        add(2, 1); add(1, 3);
        dfs(1, std::vector<int>());
    }
    if (n == 4)
    {
        for (int i = 1; i <= n; ++i) e[i].clear();
        add(1, 2); add(2, 3); add(3, 4);
        dfs(1, std::vector<int>());
        for (int i = 1; i <= n; ++i) e[i].clear();
        add(1, 2); add(2, 4); add(4, 3);
        dfs(1, std::vector<int>());
        for (int i = 1; i <= n; ++i) e[i].clear();
        add(1, 3); add(3, 2); add(2, 4);
        dfs(1, std::vector<int>());
        for (int i = 1; i <= n; ++i) e[i].clear();
        add(1, 3); add(3, 4); add(4, 2);
        dfs(1, std::vector<int>());
        for (int i = 1; i <= n; ++i) e[i].clear();
        add(1, 4); add(4, 2); add(2, 3); 
        dfs(1, std::vector<int>());
        for (int i = 1; i <= n; ++i) e[i].clear();
        add(1, 4); add(4, 3); add(3, 2);
        dfs(1, std::vector<int>());
        for (int i = 1; i <= n; ++i) e[i].clear();
        add(2, 1); add(1, 4); add(4, 3);
        dfs(1, std::vector<int>());
        for (int i = 1; i <= n; ++i) e[i].clear();
        add(2, 1); add(1, 3); add(3, 4);
        dfs(1, std::vector<int>());
        for (int i = 1; i <= n; ++i) e[i].clear();
        add(2, 3); add(3, 4); add(4, 1);
        dfs(1, std::vector<int>());
        for (int i = 1; i <= n; ++i) e[i].clear();
        add(2, 3); add(3, 1); add(1, 4);
        dfs(1, std::vector<int>());
        for (int i = 1; i <= n; ++i) e[i].clear();
        add(2, 4); add(4, 3); add(3, 1);
        dfs(1, std::vector<int>());
        for (int i = 1; i <= n; ++i) e[i].clear();
        add(2, 4); add(4, 2); add(3, 1);
        dfs(1, std::vector<int>());
     
        
        for (int i = 1; i <= n; ++i) e[i].clear();
        add(1, 2); add(1, 3); add(1, 4);
        dfs(1, std::vector<int>());
        for (int i = 1; i <= n; ++i) e[i].clear();
        add(2, 1); add(2, 3); add(2, 4);
        dfs(1, std::vector<int>());
        for (int i = 1; i <= n; ++i) e[i].clear();
        add(3, 1); add(3, 2); add(3, 4);
        dfs(1, std::vector<int>());
        for (int i = 1; i <= n; ++i) e[i].clear();
        dfs(4, 1); dfs(4, 2); dfs(4, 3);
        dfs(1, std::vector<int>());
    }

    dfs(1, std::vector<int>());
    std::cout << ans << '\n';
    return 0;
}
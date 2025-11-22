#include <bits/stdc++.h>
const int N = 3e3 + 5;

int n, m, k, s1, s2, a[N], sum, ans; bool vis[N], flag = 0;
std::vector<int> e[N], path, ans_path;

inline void dfs(const int &u)
{
    vis[u] = 1;
    if (e[u].size() <= k) return (flag = 1), void(0);
    path.push_back(u); sum += a[u]; 
    for (int v : e[u])
    {
        if (!vis[v]) dfs(v);
    }
}

inline void dfs(const int &step, const int &sum, const int &aim, const int &n, const std::vector<int> &num)
{
    if (step == n)
    {
        if (sum == aim) ++ans;
        return ;
    }
    dfs(step + 1, sum + a[num[step]], aim, n, num);
    dfs(step + 1, sum, aim, n, num);
}


signed main()
{
    std::freopen("b.in", "r", stdin);
    std::freopen("b.out", "w", stdout);

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    std::cin >> n >> m >> k >> s1 >> s2;
    for (int i = 1, u, v; i <= m; ++i)
    {
        std::cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) std::cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            flag = 0; sum = 0; dfs(i);
            if (!flag)
            {
                if (sum > ans)
                {
                    ans = sum;
                    ans_path = path;
                }
            }
        }
    }
    if (ans > 0)
    {
        std::sort(ans_path.begin(), ans_path.end());
        for (int i : ans_path) std::cout << i << ' ';
        std::cout << '\n';
        return 0;
    }

    for (int i = 1, op, x, y; i <= s1 + s2; ++i)
    {
        std::cin >> op >> x >> y;
        if (op == 1) a[x] = y;
        else
        {
            std::vector<int> tmp; ans = 0;
            for (int j : e[x]) tmp.push_back(j);
            int cnt = e[x].size();
            dfs(0, 0, y, cnt, tmp);
            std::cout << ans << '\n';
        }
    }

    return 0;
}
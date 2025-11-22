#include <bits/stdc++.h>
#define int long long
const int mod = 998244353;

std::vector<int> res;

inline bool check(const int &x)
{
    int t = x;
    while (t)
    {
        int tmp = t % 10;
        if (tmp == 1 || tmp == 4 || tmp == 5) return false;
        t /= 10;
    }
    return true;
}

signed main()
{
    std::freopen("a.in", "r", stdin);
    std::freopen("a.ans", "w", stdout);

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    for (int i = 0; i <= (int)1e5; ++i)
    {
        if (check(i)) res.push_back(i % mod);
    }

    int T; std::cin >> T;
    while (T--) 
    {
        int x; std::cin >> x;
        std::cout << res[x - 1] << '\n';
    }
    return 0;
}
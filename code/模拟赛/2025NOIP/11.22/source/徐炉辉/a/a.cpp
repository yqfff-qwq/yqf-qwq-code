#include <bits/stdc++.h>
#define int long long
const int mod = 998244353;
const int t[] = {0, 2, 3, 6, 7, 8, 9};

std::vector<int> res;

inline void solve()
{
    res.clear();
    int x; std::cin >> x; --x;
    while (x)
    {
        res.push_back(t[x % 7]);
        x /= 7;
    }
    if (res.empty()) return std::cout << 0 << '\n', void(0);
    int ans = 0, t = 1;
    for (int i : res)
    {
        ans = (ans + i * t % mod) % mod;
        t = (t * 10) % mod;
    }
    std::cout << ans << '\n';
}

signed main()
{
    std::freopen("a.in", "r", stdin);
    std::freopen("a.out", "w", stdout);

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
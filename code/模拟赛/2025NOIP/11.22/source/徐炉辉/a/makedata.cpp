#include <bits/stdc++.h>

inline int rnd()
{
    int t = std::rand(), tt = std::rand();
    return (t << 15) + tt;
}

signed main()
{
    std::freopen("a.in", "w", stdout);

    std::srand(time(0));

    int T = (int)1e3; std::cout << T << '\n';
    for (int i = 1; i <= T; ++i) std::cout << rnd() % ((int)1e3) + 1 << '\n';
    return 0;
}
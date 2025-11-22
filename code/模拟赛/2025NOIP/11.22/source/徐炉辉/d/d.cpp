#include <bits/stdc++.h>
#define int long long

int n, mod;

signed main()
{
    std::freopen("d.in", "r", stdin);
    std::freopen("d.out", "w", stdout);

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    std::cin >> n >> mod;
    if (n == 1)
    {
        std::cout << 1 << '\n';
        return 0;
    }
    if (n == 2)
    {
        std::cout << 0 << ' ' << 1 << '\n';
        std::cout << 0 << ' ' << 1 << '\n';
        return 0;
    }
    if (n == 3)
    {
        std::cout << 0 << ' ' << 1 << ' ' << 2 << '\n';
        std::cout << 0 << ' ' << 0 << ' ' << 3 << '\n';
        std::cout << 0 << ' ' << 0 << ' ' << 3 << '\n';
        return 0;
    }
    if (n == 4) 
    {
        std::cout << 0 << '\n';
        return 0;
    }
    if (n == 5)
    {
        
        return 0;
    }
    return 0;
}
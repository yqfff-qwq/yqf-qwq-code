#include <iostream>
using namespace std;
int n;
long long p = 1, x, y;
long long ans;
int main()
{
    freopen("wota.in", "r", stdin);
    freopen("wota.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if (n < 5) {
        cout << n * (n - 1) / 2;
        return 0;
    }
    while (p * 5 <= n)
        p *= 10;
    for (long long i = 1; i <= 9; i++) {
        x = max(i * p - 1 - n, 1ll);
        y = min(i * p - 1 - 1, (long long)n);
        if (x < y)
            ans += (y - x + 1) / 2;
    }
    cout << ans;
    return 0;
}
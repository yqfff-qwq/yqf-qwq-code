#include <cmath>
#include <iostream>
using namespace std;
int n;
long long a[510];
long long ans;
int main()
{
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++)
                ans = max(a[i] | a[j] | a[k], ans);
    cout << ans;
    return 0;
}
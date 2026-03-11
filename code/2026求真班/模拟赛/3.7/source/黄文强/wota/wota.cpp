#include <bits/stdc++.h>
// #pragma GCC optimize(3)
#define ll long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
const int N = 100005;
inline bool pd(ll n) {
    while (n % 10 == 9)
        n /= 10;
    return n < 5;
}
inline ll mer(ll n) {
    ll w = 0, kkk = 9;
    while (n >= kkk) {
        --w;
        ll m = kkk + 1;
        if (n >= m + kkk) --w;
        if (n >= m * 2 + kkk) --w;
        if (n >= m * 3 + kkk) --w;
        if (n >= m * 4 + kkk) --w;
        kkk = kkk * 10 + 9;
    }
    return w;
}
inline void solve() {
    ll n;
    cin >> n;
    if (n < 5) {
        if (n == 1) cout << "I AK IOI";
        if (n == 2) cout << 1;
        if (n == 3) cout << 3;
        if (n == 4) cout << 6;
        return;
    }
    ll w = 5, ans = mer(n), k = 0;
    while (n >= w * 10)
        w *= 10, ++k;
    n -= w - 1;
    ans += (1 + n / (w * 2)) * (n / (w * 2)) / 2 * (w * 2) + (n - (w * 2) * (n / (w * 2))) * (n / (w * 2) + 1) + k * 5;
    cout << ans << endl;
    return;
}
int main() {
    freopen("wota.in", "r", stdin);
    freopen("wota.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin>>T;
    while (T--)
        solve();
    return 0;
}
#include <bits/stdc++.h>
// #pragma GCC optimize(3)
#define ll long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
const int N = 510;
int n;
ll a[N], ans;
inline void solve() {
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) rep(j, 1, n) rep(k, 1, n) ans = max(ans, a[i] | a[j] | a[k]);
    cout << ans << endl;
    return;
}
int main() {
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin>>T;
    while (T--)
        solve();
    return 0;
}
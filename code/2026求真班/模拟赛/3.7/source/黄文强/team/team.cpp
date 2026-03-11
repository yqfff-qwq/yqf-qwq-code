#include <bits/stdc++.h>
// #pragma GCC optimize(3)
#define ll long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
const int N = 200005;
int n, a[N];
inline void solve() {
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, ans = 1;
    rep(r, 2, n) {
        while (a[r] - a[l] > 5)
            ++l;
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
    return;
}
int main() {
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin>>T;
    while (T--)
        solve();
    return 0;
}
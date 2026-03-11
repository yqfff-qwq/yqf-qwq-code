#include <bits/stdc++.h>
// #pragma GCC optimize(3)
#define ll long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
const int N = 100005;
int n;
ll x, y;
inline void solve() {
    cin >> x >> y;
    if (abs(x - y) > 1)
        cout << "Yes\n";
    else
        cout << "No\n";
    return;
}
int main() {
    freopen("berry.in", "r", stdin);
    freopen("berry.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1;
    cin>>T;
    while (T--)
        solve();
    return 0;
}
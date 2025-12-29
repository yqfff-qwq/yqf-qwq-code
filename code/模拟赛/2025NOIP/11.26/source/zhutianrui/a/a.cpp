#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i <= (b); i ++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)
#define int long long
using namespace std;

const int N = 2e5 + 5;

int n, m, a[N];

signed main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    n = s.size();
    int ans = 1;
    F(i, 1, n - 1) {
        if (s[i] != s[i - 1]) break;
        ans++;
    }
    cout << ans << '\n';
    return 0;
}
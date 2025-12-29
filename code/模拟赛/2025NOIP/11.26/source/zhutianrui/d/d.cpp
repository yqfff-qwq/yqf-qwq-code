#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i <= (b); i ++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)
#define int long long
using namespace std;

const int N = 2e5 + 5;

int n, m, a[N], b[N], to[20][N], st[20][N], stk[N], s[N], jp[20][N];
int qry(int l, int r) {
    int k = __lg(r - l + 1);
    return max(st[k][l], st[k][r - (1 << k) + 1]);
}
signed main() {
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    F(i, 1, n) cin >> a[i], st[0][i] = a[i], a[i] += a[i - 1];
    F(i, 1, 19) F(j, 1, n - (1 << i) + 1)
        st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
    F(i, 1, n) cin >> b[i];
    // int top = 0; stk[0] = n + 1;
    // dF(i, n, 1) {
    //     while (top && b[stk[top]] >= b[i]) top--;
    //     to[0][i] = stk[top], stk[++top] = i;
    // }
    // to[0][n + 1] = n + 1;
    // F(i, 1, 19) F(j, 1, n + 1)
    //     to[i][j] = to[i - 1][to[i - 1][j]];
    // F(i, 1, n) {
    //     int val = s[to[0][i] - 1] - s[i - 1];
    //     jp[0][i] = val * b[i];
    // }
    // F(i, 1, 19) F(j, 1, n + 1) {
    //     int x = jp[i - 1][j], p = to[i - 1][j];
    //     jp[i][j] = x + jp[i - 1][p];
    // }
    while (m--) {
        int s, t, u, ans = 0, rem = 0;
        cin >> s >> t >> u;
        if (qry(s, t - 1) > u) {
            cout << "-1\n";
            continue;
        }
        while (s != t) {
            // cerr << s << endl;
            int i = s, sum = 0, p = -1, mn = 0;
            while (i < t && sum + a[i] - a[i - 1] <= u) {
                sum += a[i] - a[i - 1]; i++;
                // cerr <<  ' ' << i << endl;
                if (b[i] < b[s]) { p = i; break; }
                if (!mn || b[i] < b[mn]) mn = i;
            } 
            if (p == -1) {
                if (i == t) {
                    mn = t;
                    ans += b[s] * (a[t - 1] - a[s - 1] - rem), s = t;
                    rem = u - (a[mn - 1] - a[s - 1]);
                } else {
                    // assert(mn > 0);
                    ans += b[s] * (u - rem);
                    rem = u - (a[mn - 1] - a[s - 1]);
                    s = mn;
                }
            } else {
                ans += b[s] * (a[p - 1] - a[s - 1] - rem), s = p;
                rem = 0;
            }
            // cerr << "ans = " << ans << endl;
            // cerr << "rem = " << rem << endl;
        }
        cout << ans << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, a[1100], vis[1100];

void dfs(int g) {
    if (g > n) {
        bool f = 1;
        int cnt = 0;

        for (int i = 1; i <= n; i++) {
            if (vis[i] == -1) {
                f = 0;
                break;
            }

            if (vis[i] == 1)
                cnt++;
            else if (!cnt) {
                f = 0;
                break;
            } else
                cnt--;
        }

        if (f && !cnt) {
            for (int i = 1; i <= n; i++)
                if (vis[i] == 1)
                    cout << '(';
                else
                    cout << ')';

            exit(0);
        }

        return;
    }

    if (vis[g] != -1)
        dfs(g + 1);
    else {
        if (vis[g] == -1 && vis[a[g]] == -1) {
            vis[g] = 1, vis[a[g]] = 2;
            dfs(g + 1);
            vis[g] = -1, vis[a[g]] = -1;
        }

        if (g != a[a[g]])
            dfs(g + 1);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i], vis[i] = -1;

    dfs(1);
    return 0;
}
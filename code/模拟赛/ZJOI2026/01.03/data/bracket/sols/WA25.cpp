#include <bits/stdc++.h>
#define int long long
using namespace std;
int p[105], n, num[105][105], cn[105], cnHuan, huan[105], len, pre[105];
bool boo[105], vis[105];
char ch[105];
void find(int x) {
    if (boo[x])
        return;

    num[cnHuan][++cn[cnHuan]] = x, boo[x] = 1;
    find(p[x]);
}
void dfs(int now) {
    if (now > len) {
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + (ch[i] == '(');

            if (pre[i] < i - pre[i])
                return;
        }

        for (int i = 1; i <= n; i++)
            cout << ch[i];

        exit(0);
    }

    for (int i = 1; i <= cn[now]; i++)
        ch[num[now][i]] = (i & 1 ? '(' : ')');

    dfs(now + 1);

    for (int i = 1; i <= cn[now]; i++)
        ch[num[now][i]] = (i & 1 ? ')' : '(');

    dfs(now + 1);
}
signed main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> p[i];

    for (int i = 1; i <= n; i++) {
        if (boo[i])
            continue;

        cnHuan++, find(i);

        if (cn[cnHuan] == 2)
            ch[min(num[cnHuan][1], num[cnHuan][2])] = '(', ch[max(num[cnHuan][1], num[cnHuan][2])] = ')';
        else
            huan[++len] = cnHuan;

        //for (int j = 1;j <= cn[cnHuan];j++) cout << num[cnHuan][j] << " ";
        //puts("");
    }

    dfs(1);
    return 0;
}
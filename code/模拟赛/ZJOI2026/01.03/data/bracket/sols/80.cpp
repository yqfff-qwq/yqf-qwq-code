#include <bits/stdc++.h>
const int N = 105;
using namespace std;
int n, tot;

int p[N], vis[N];
char s[N];
vector<int> a[N];
inline void ck() {
    int t = 0;

    for (register int i = 1; i <= n; ++i)
        if ((t += (s[i]^')') ? 1 : -1) < 0)
            return;

    puts(s + 1);
    exit(0);
}
inline void dfs(const int &u) { //第u个环的情况
    if (u > tot)
        return ck();

    register int len = a[u].size();

    if (!(len ^ 2))
        s[a[u][0]] = '(', s[a[u][1]] = ')', dfs(u + 1); //长度为2

    for (register int i = 0; i ^ len; ++i) {
        s[a[u][i]] = (i & 1 ? '(' : ')'); //交替
    }

    dfs(u + 1);

    //另一种情况
    for (register int i = 0; i ^ len; ++i) {
        s[a[u][i]] = (i & 1 ? ')' : '(');
    }

    dfs(u + 1);
}
int main() {
    scanf("%d", &n);

    for (register int i = 1; i <= n; ++i)
        scanf("%d", p + i);

    for (register int i = 1; i <= n; ++i) {
        register int x;

        if (!vis[x = i]) {
            tot++;//记录环的个数

            while (!vis[x]) {
                vis[x] = 1;
                a[tot].push_back(x);
                x = p[x]; //加入环
            }
        }
    }

    dfs(1);
    return 0;
}
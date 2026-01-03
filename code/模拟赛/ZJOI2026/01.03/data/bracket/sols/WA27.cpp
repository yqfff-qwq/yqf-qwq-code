// https://loj.ac/p/6043
// 2s 1GB
#include <cstdio>
#include <vector>

using i64 = long long ;

const int N = 105 ;

int n;
int p[N], ans[N];
bool v[N];

void FindRing(int u, std::vector<int> &ring) {
    if (!v[u]) {
        v[u] = 1;
        ring.push_back(u);
        FindRing(p[u], ring);
    }
}

bool vis[N];
int id;
int dfs(int u, bool can) {

    if (u == id) {

        if (ans[n])
            return 0;

        bool ok = 1 ;

        ans[u] = 0;
        int sum = 0;
        int cnt = 0;

        for (int i = 1; i <= n; i++)
            if (v[i]) {
                cnt++;
                sum += ans[i];

                if (sum * 2 < cnt) {
                    ok = 0;
                    break;
                }
            }

        if (ok)
            return 1;

        if (!vis[p[u]]) {
            cnt = 0;
            ok = 1;
            ans[u] = 1;
            sum = 0;

            for (int i = 1; i <= n; i++)
                if (v[i]) {
                    sum += ans[i];

                    if (sum * 2 < i) {
                        ok = 0;
                        break;
                    }
                }

            return ok;
        }

        return 0;
    }

    if (can) {
        ans[u] = 1, vis[u] = 1;

        if (!vis[p[u]] && dfs(p[u], 0))
            return 1;

        vis[u] = 0;
    }

    ans[u] = 0;

    if (dfs(p[u], 1))
        return 1;

    return 0;
}

int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", p + i);

    std::vector<int> ring;

    for (int i = 1; i <= n; i++)
        if (!v[i]) {
            ring.clear();
            FindRing(i, ring);

            if ((int)ring.size() == 2) {
                ans[ring[0]] = 1;
                ans[ring[1]] = 0;
                continue;
            }

            id = *ring.rbegin();
            dfs(i, 1);
        }

    for (int i = 1; i <= n; i++)
        printf("%c", ans[i] == 1 ? '(' : ')');

    return 0;
}
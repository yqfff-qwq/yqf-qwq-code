#include <bits/stdc++.h>
using namespace std;

const int N = 3005, M = 1e6 + 5, MOD = 998244353, YMAX = 3005;

int n, m, k, s1, s2;
vector<int> g[N];
int a[N];
int deg[N];
bool alive[N];
int ord[N], pos[N]; // peeling 顺序，pos[x] 是 x 在 ord 中的位置
vector<int> forwardNeigh[N], backwardNeigh[N];
int dp[N][YMAX]; // dp[x] 是 pref[x] 的背包数组

void solvePart1() {
    // 读图
    cin >> n >> m >> k >> s1 >> s2;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 初始化度数
    for (int i = 1; i <= n; i++) {
        deg[i] = g[i].size();
        alive[i] = true;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] <= k) {
            q.push(i);
            alive[i] = false;
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (alive[v]) {
                deg[v]--;
                if (deg[v] <= k) {
                    alive[v] = false;
                    q.push(v);
                }
            }
        }
    }

    vector<int> remain;
    for (int i = 1; i <= n; i++) {
        if (alive[i]) remain.push_back(i);
    }

    if (!remain.empty()) {
        sort(remain.begin(), remain.end());
        for (int i = 0; i < (int)remain.size(); i++) {
            if (i > 0) cout << " ";
            cout << remain[i];
        }
        cout << endl;
        exit(0);
    }
}

void buildPeelingOrder() {
    // 重新初始化
    for (int i = 1; i <= n; i++) {
        deg[i] = g[i].size();
        alive[i] = true;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] <= k) {
            q.push(i);
            alive[i] = false;
        }
    }
    int idx = n;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ord[idx--] = u;
        for (int v : g[u]) {
            if (alive[v]) {
                deg[v]--;
                if (deg[v] <= k) {
                    alive[v] = false;
                    q.push(v);
                }
            }
        }
    }
    // 剩下的点（实际上不会剩下，因为第一部分已判断）
    for (int i = 1; i <= n; i++) {
        if (alive[i]) ord[idx--] = i;
    }

    for (int i = 1; i <= n; i++) pos[ord[i]] = i;
}

void precomputeForwardBackward() {
    for (int i = 1; i <= n; i++) {
        for (int v : g[i]) {
            if (pos[v] > pos[i]) {
                // v 在 i 之后（peeling 顺序中位置大的是后删除的）
                forwardNeigh[i].push_back(v);
            } else {
                backwardNeigh[i].push_back(v);
            }
        }
    }
}

void precomputeDP() {
    for (int i = 1; i <= n; i++) {
        int x = ord[i]; // 按 peeling 顺序从后往前
        memset(dp[x], 0, sizeof(dp[x]));
        dp[x][0] = 1;
        for (int v : forwardNeigh[x]) {
            // v 在 x 之前（peeling 顺序中位置大）
            int av = a[v];
            for (int j = YMAX - 1; j >= av; j--) {
                dp[x][j] = (dp[x][j] + dp[x][j - av]) % MOD;
            }
        }
    }
}

void update(int x, int oldVal, int newVal) {
    // 更新所有以 x 为向前邻居的点
    for (int u : backwardNeigh[x]) {
        // u 在 x 之后，x 是 u 的向前邻居
        // 撤销 oldVal
        for (int j = oldVal; j < YMAX; j++) {
            dp[u][j] = (dp[u][j] - dp[u][j - oldVal] + MOD) % MOD;
        }
        // 加入 newVal
        for (int j = YMAX - 1; j >= newVal; j--) {
            dp[u][j] = (dp[u][j] + dp[u][j - newVal]) % MOD;
        }
    }
    a[x] = newVal;
}

int query(int x, int y) {
    int ans = 0;
    int limit = (1 << backwardNeigh[x].size());
    for (int mask = 0; mask < limit; mask++) {
        int sum = 0;
        for (int i = 0; i < (int)backwardNeigh[x].size(); i++) {
            if (mask >> i & 1) {
                sum += a[backwardNeigh[x][i]];
            }
        }
        if (sum <= y) {
            ans = (ans + dp[x][y - sum]) % MOD;
        }
    }
    return ans;
}

int main() {
	freopen("b1.in","r",stdin);
	freopen("w2.out","w",stdout); 
    ios::sync_with_stdio(false);
    cin.tie(0);

    solvePart1();

    // 第二部分
    buildPeelingOrder();
    precomputeForwardBackward();
    precomputeDP();

    while (s1 + s2--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            update(x, a[x], y);
        } else {
            cout << query(x, y) << "\n";
        }
    }

    return 0;
}

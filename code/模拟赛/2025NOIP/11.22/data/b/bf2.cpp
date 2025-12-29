#include <bits/stdc++.h>
using namespace std;

const int N = 3005, MOD = 998244353, YMAX = 3005;

int n, m, k, s1, s2;
vector<int> g[N];
int a[N];
int deg[N];
bool alive[N];
int dp[N][YMAX]; // dp[x][s] 表示从x的邻居中选子集，和为s的方案数

void solvePart1() {
    cin >> n >> m >> k >> s1 >> s2;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) cin >> a[i];

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

// 预处理所有点的背包
void precomputeAllDP() {
    for (int x = 1; x <= n; x++) {
        // 初始化背包
        memset(dp[x], 0, sizeof(dp[x]));
        dp[x][0] = 1;
        
        // 对x的所有邻居做0-1背包
        for (int v : g[x]) {
            int val = a[v];
            for (int j = YMAX - 1; j >= val; j--) {
                dp[x][j] = (dp[x][j] + dp[x][j - val]) % MOD;
            }
        }
    }
}

// 修改点权后，暴力更新所有相关点的背包
void update_brute(int x, int oldVal, int newVal) {
    // 更新所有以x为邻居的点的背包
    for (int u : g[x]) {
        // 先撤销oldVal的影响
        vector<int> temp(YMAX);
        for (int j = 0; j < YMAX; j++) {
            temp[j] = dp[u][j];
        }
        
        // 正向撤销（相当于逆向背包）
        for (int j = oldVal; j < YMAX; j++) {
            temp[j] = (temp[j] - temp[j - oldVal] + MOD) % MOD;
        }
        
        // 再加入newVal
        for (int j = YMAX - 1; j >= newVal; j--) {
            temp[j] = (temp[j] + temp[j - newVal]) % MOD;
        }
        
        // 复制回dp[u]
        for (int j = 0; j < YMAX; j++) {
            dp[u][j] = temp[j];
        }
    }
    
    a[x] = newVal;
}

int query_fast(int x, int y) {
    return dp[x][y];
}

int main() {
	freopen("b1.in","r",stdin);
	freopen("wt.out","w",stdout); 
    ios::sync_with_stdio(false);
    cin.tie(0);

    solvePart1();

    // 预处理所有点的背包
    precomputeAllDP();

    while (s1 + s2--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            int oldVal = a[x];
            update_brute(x, oldVal, y);
        } else {
            cout << query_fast(x, y) << "\n";
        }
    }

    return 0;
}

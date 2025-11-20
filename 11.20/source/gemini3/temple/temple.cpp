#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>

using namespace std;

// 题解要求: 空间2G，一看就bitset [cite: 306]
// 复杂度: O(N^2/w) 
const int MAXN = 100005;
const int LOGN = 18;

int n, q;
long long base, mod;
int a[MAXN];
vector<int> adj[MAXN];

// LCA 相关
int depth[MAXN], up[MAXN][LOGN];
// Bitset 维护根到节点的路径异或和
// 注意：开启 O2 优化后 bitset 效率较高
bitset<MAXN> path_bits[MAXN]; 

void dfs(int u, int p, int d) {
    depth[u] = d;
    up[u][0] = p;
    
    // 继承父亲的 bitset 并异或当前权值
    path_bits[u] = path_bits[p];
    path_bits[u].flip(a[u]); // 异或操作: 0->1, 1->0

    for (int i = 1; i < LOGN; i++)
        up[u][i] = up[up[u][i-1]][i-1];
        
    for (int v : adj[u]) {
        if (v != p) dfs(v, u, d + 1);
    }
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOGN - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) u = up[u][i];
    }
    if (u == v) return u;
    for (int i = LOGN - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int main() {
    // 优化 IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (fopen("temple.in", "r")) {
        freopen("temple.in", "r", stdin);
        freopen("temple.out", "w", stdout);
    }

    if (!(cin >> n >> base >> mod)) return 0;

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 初始化 bitset，0号位通常不用，或者根据题目a_i范围调整
    // 题目 a_i <= n
    dfs(1, 1, 0);

    cin >> q;
    long long hashans = 0;
    string last_ans = "";

    for (int i = 1; i <= q; i++) {
        long long u_prime, v_prime;
        cin >> u_prime >> v_prime;

        if (i > 1) {
            // 滚动更新 hashans
             long long val = (last_ans == "Yes" ? 1 : 0);
             hashans = (hashans * base + val) % mod;
        }

        int u = u_prime ^ hashans;
        int v = v_prime ^ hashans;

        int lca = get_lca(u, v);
        int dist = depth[u] + depth[v] - 2 * depth[lca] + 1;

        // 题解核心逻辑:
        // 路径上的异或和 = path_bits[u] ^ path_bits[v] ^ (1 << a[lca])
        // 因为 lca 被异或了两次（从u到root, 从v到root），所以需要再异或回来一次
        
        // 注意：bitset 的 ^ 操作符产生一个新的 bitset
        // 空间消耗较大，但在 2GB 限制内 (100000 * 100000 bits = 1.25GB)
        // 为了防止栈溢出或临时变量过多，尽量直接操作
        
        // 临时 bitset
        bitset<MAXN> res = path_bits[u] ^ path_bits[v];
        res.flip(a[lca]); // 补回 LCA 的值
        
        // 如果 popcount == 路径长度，说明没有重复（每个值都只出现了一次）
        // 如果有重复，重复值会异或抵消，导致 popcount < dist
        if (res.count() == dist) {
             // 题目问是否有两个节点权值相同
             // 如果 count == dist，说明各不相同 -> No
             cout << "No\n";
             last_ans = "No";
        } else {
             // 有重复 -> Yes
             cout << "Yes\n";
             last_ans = "Yes";
        }
    }

    return 0;
}
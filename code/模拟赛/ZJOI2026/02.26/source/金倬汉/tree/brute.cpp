#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int MAXN = 2005;
int n;
vector<int> adj[MAXN];
int w[MAXN];
int cache[MAXN];
bool is_full[MAXN];
long long ans[MAXN];

// 模拟一单位水流到节点 u 的物理过程
void pour(int u, long long current_time) {
    if (is_full[u]) return;

    int p_u = 0; // 统计未满儿子的个数 p(u)
    for (int v : adj[u]) {
        if (!is_full[v]) p_u++;
    }
    
    if (p_u > 0) {
        cache[u]++;
        // 当缓存流量达到未满儿子数量时，均分给每个未满儿子1单位流量
        if (cache[u] == p_u) {
            cache[u] = 0;
            for (int v : adj[u]) {
                if (!is_full[v]) {
                    pour(v, current_time);
                }
            }
        }
    } else {
        // p(u) == 0 时，自己开始蓄水（注意0号根节点无容量，只作为分配器）
        if (u != 0) {
            cache[u]++;
            if (cache[u] == w[u]) {
                is_full[u] = true;
                ans[u] = current_time; // 记录变满的时刻（即总耗水量）
            }
        }
    }
}

int main() {
    // 适配与待测程序相同的 IO
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p >> w[i];
        adj[p].push_back(i);
    }
    
    long long time = 0;
    int full_count = 0;
    
    // 一滴一滴注水，直到 1~n 号节点全部变满
    while (full_count < n) {
        time++;
        pour(0, time);
        
        full_count = 0;
        for (int i = 1; i <= n; i++) {
            if (is_full[i]) full_count++;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}
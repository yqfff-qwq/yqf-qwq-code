#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 5;
const int MAXTREES = 130; // 5^3 = 125

int n, mod;
int tree_count = 0;

// 存储所有树的邻接表
int trees[MAXTREES][MAXN + 1][MAXN + 1];
int tree_size[MAXTREES];

// 从 Prüfer 序列构建树
void build_tree_from_prufer(const int prufer[], int n, int tree_id) {
    int degree[MAXN + 1];
    for (int i = 1; i <= n; i++) degree[i] = 1;
    
    for (int i = 0; i < n - 2; i++) {
        degree[prufer[i]]++;
    }
    
    // 初始化邻接矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            trees[tree_id][i][j] = 0;
        }
    }
    
    for (int i = 0; i < n - 2; i++) {
        int x = prufer[i];
        for (int j = 1; j <= n; j++) {
            if (degree[j] == 1) {
                trees[tree_id][x][j] = 1;
                trees[tree_id][j][x] = 1;
                degree[x]--;
                degree[j]--;
                break;
            }
        }
    }
    
    // 最后剩下两个度数为1的节点
    int u = -1, v = -1;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1) {
            if (u == -1) u = i;
            else v = i;
        }
    }
    trees[tree_id][u][v] = 1;
    trees[tree_id][v][u] = 1;
    
    tree_size[tree_id] = n;
}

// 递归生成所有 Prüfer 序列
void generate_prufer_sequences(int idx, int prufer[], int n) {
    if (idx == n - 2) {
        build_tree_from_prufer(prufer, n, tree_count);
        tree_count++;
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        prufer[idx] = i;
        generate_prufer_sequences(idx + 1, prufer, n);
    }
}

// 生成所有 n 个点的无根树
void generate_all_trees(int n) {
    if (n == 1) {
        // 单节点树
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                trees[0][i][j] = 0;
            }
        }
        tree_size[0] = 1;
        tree_count = 1;
        return;
    }
    
    int prufer[MAXN];
    generate_prufer_sequences(0, prufer, n);
}

// BFS 建立树结构
void build_tree_structure(int tree_id, int parent[], int depth[]) {
    bool visited[MAXN + 1] = {false};
    int queue[MAXN + 1];
    int front = 0, rear = 0;
    
    queue[rear++] = 1;
    visited[1] = true;
    parent[1] = 0;
    depth[1] = 0;
    
    while (front < rear) {
        int u = queue[front++];
        for (int v = 1; v <= n; v++) {
            if (trees[tree_id][u][v] && !visited[v]) {
                visited[v] = true;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                queue[rear++] = v;
            }
        }
    }
}

// 计算给定树的 ans(T, k)
void compute_ans(int tree_id, int maxk, int result[]) {
    int parent[MAXN + 1], depth[MAXN + 1];
    build_tree_structure(tree_id, parent, depth);
    
    for (int k = 1; k <= maxk; k++) {
        bool covered[MAXN + 1] = {false};
        covered[1] = true;
        int total_covered = 1;
        
        for (int op = 0; op < k; op++) {
            int best_leaf = -1;
            int best_gain = -1;
            
            // 找收益最大的叶子
            for (int i = 1; i <= n; i++) {
                if (covered[i]) continue;
                
                // 计算从 i 到第一个已覆盖节点的路径长度
                int cur = i;
                int gain = 0;
                while (cur != 0 && !covered[cur]) {
                    gain++;
                    cur = parent[cur];
                }
                
                if (gain > best_gain) {
                    best_gain = gain;
                    best_leaf = i;
                }
            }
            
            if (best_gain <= 0) break;
            
            // 覆盖路径
            int cur = best_leaf;
            while (cur != 0 && !covered[cur]) {
                covered[cur] = true;
                total_covered++;
                cur = parent[cur];
            }
        }
        
        result[k] = total_covered;
    }
}

int main() {
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout); 
    cin >> n >> mod;
    
    if (n > 5) {
        // 对于 n > 5 输出全0
        for (int k = 1; k <= n; k++) {
            for (int m = 1; m <= n; m++) {
                cout << "0";
                if (m < n) cout << " ";
            }
            cout << endl;
        }
        return 0;
    }
    
    generate_all_trees(n);
    
    // 初始化计数数组
    int cnt[MAXN + 1][MAXN + 1] = {0};
    
    // 对每棵树计算 ans(T, k)
    for (int i = 0; i < tree_count; i++) {
        int result[MAXN + 1];
        compute_ans(i, n, result);
        for (int k = 1; k <= n; k++) {
            int m = result[k];
            if (m >= 1 && m <= n) {
                cnt[k][m] = (cnt[k][m] + 1) % mod;
            }
        }
    }
    
    // 输出结果
    for (int k = 1; k <= n; k++) {
        for (int m = 1; m <= n; m++) {
            cout << cnt[k][m];
            if (m < n) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}

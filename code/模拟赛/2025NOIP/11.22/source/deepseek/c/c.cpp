#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;

typedef long long ll;

ll mod;

// 并查集
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        parent[y] = x;
        return true;
    }
};

// 生成所有n个点的树
vector<vector<vector<int>>> generate_trees(int n) {
    vector<vector<vector<int>>> trees;
    
    // 生成所有可能的边（无向）
    vector<pair<int, int>> all_edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            all_edges.push_back(make_pair(i, j));
        }
    }
    
    int m = all_edges.size();
    
    // 枚举所有n-1条边的组合
    vector<vector<int>> combinations;
    vector<int> comb(n - 1);
    
    function<void(int, int)> generate_combinations = [&](int start, int depth) {
        if (depth == n - 1) {
            combinations.push_back(comb);
            return;
        }
        for (int i = start; i <= m - (n - 1 - depth); i++) {
            comb[depth] = i;
            generate_combinations(i + 1, depth + 1);
        }
    };
    
    generate_combinations(0, 0);
    
    // 检查每个组合是否构成树
    for (int i = 0; i < combinations.size(); i++) {
        DSU dsu(n);
        bool valid = true;
        vector<vector<int>> adj(n);
        
        for (int j = 0; j < n - 1; j++) {
            int idx = combinations[i][j];
            int u = all_edges[idx].first;
            int v = all_edges[idx].second;
            if (!dsu.unite(u, v)) {
                valid = false;
                break;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        if (valid) {
            trees.push_back(adj);
        }
    }
    
    return trees;
}

// 计算连通块的mex
int calculate_mex(const vector<int>& values, const set<int>& S) {
    int max_val = 0;
    for (int u : S) {
        if (values[u] > max_val) max_val = values[u];
    }
    
    vector<bool> exists(max_val + 2, false);
    for (int u : S) {
        if (values[u] <= max_val) {
            exists[values[u]] = true;
        }
    }
    
    for (int i = 0; i < exists.size(); i++) {
        if (!exists[i]) return i;
    }
    return exists.size();
}

// 计算补集的最小值
int calculate_min_complement(const vector<int>& values, const set<int>& S, int V) {
    int min_val = V + 1;
    for (int i = 0; i < values.size(); i++) {
        if (S.find(i) == S.end()) {
            if (values[i] < min_val) {
                min_val = values[i];
            }
        }
    }
    return min_val;
}

// 检查S是否是连通块
bool is_connected_component(const vector<vector<int>>& tree, const set<int>& S) {
    if (S.empty()) return false;
    
    int n = tree.size();
    vector<bool> visited(n, false);
    
    // 从S中的第一个点开始BFS
    int start = *S.begin();
    visited[start] = true;
    vector<int> queue;
    queue.push_back(start);
    
    for (int i = 0; i < queue.size(); i++) {
        int u = queue[i];
        for (int j = 0; j < tree[u].size(); j++) {
            int v = tree[u][j];
            if (S.find(v) != S.end() && !visited[v]) {
                visited[v] = true;
                queue.push_back(v);
            }
        }
    }
    
    return queue.size() == S.size();
}

// 检查赋值是否合法
bool check_assignment(const vector<vector<int>>& tree, const vector<int>& values, int V) {
    int n = tree.size();
    
    // 枚举所有非空子集
    for (int mask = 1; mask < (1 << n); mask++) {
        set<int> S;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                S.insert(i);
            }
        }
        
        // 检查S是否是连通块
        if (is_connected_component(tree, S)) {
            int mex_S = calculate_mex(values, S);
            int min_complement = calculate_min_complement(values, S, V);
            
            if (mex_S != min_complement) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout); 
    int N, V;
    cin >> N >> V >> mod;
    
    if (V >= N) {
        cout << 0 << endl;
        return 0;
    }
    
    // 生成所有树
    auto trees = generate_trees(N);
    
    // 生成所有可能的权值分配
    vector<vector<int>> assignments;
    vector<int> current(N);
    
    function<void(int)> generate_assignments = [&](int depth) {
        if (depth == N) {
            assignments.push_back(current);
            return;
        }
        for (int val = 0; val <= V; val++) {
            current[depth] = val;
            generate_assignments(depth + 1);
        }
    };
    
    generate_assignments(0);
    
    ll total = 0;
    
    // 对每棵树和每个权值分配检查合法性
    for (int i = 0; i < trees.size(); i++) {
        const auto& tree = trees[i];
        for (int j = 0; j < assignments.size(); j++) {
            const auto& assignment = assignments[j];
            if (check_assignment(tree, assignment, V)) {
                total = (total + 1) % mod;
            }
        }
    }
    
    cout << total << endl;
    
    return 0;
}

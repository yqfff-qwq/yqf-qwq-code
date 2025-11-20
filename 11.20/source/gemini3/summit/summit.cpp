/*
    题目: 山顶
    来源: solution.pdf [cite: 22, 26, 31]
    方法: WQS二分 + 反悔贪心 (优先队列优化)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;
int T_cases;
int n, l_limit, r_limit;
vector<int> A, B;

struct Element {
    long long cost;
    int type; // 1 for A (New Pair), 0 for Regret B (Swap)
    
    // 优先队列默认是大根堆，我们需要小根堆 (pop 最小 cost)
    // 题解要求: 贡献相同时，优先选第一种匹配 (Type 1) 
    // 所以在 'greater' 逻辑中，(cost, 1) 应该比 (cost, 0) "更小" (排在前面)
    bool operator>(const Element& other) const {
        if (cost != other.cost) return cost > other.cost;
        // cost 相等，我们希望 1 排在 0 前面
        // greater 返回 true 表示 this > other (this 会沉底)
        // 我们希望 1 在前 (Top)，所以 1 应该 "小于" 0
        return type < other.type; 
    }
};

pair<int, long long> check(long long lambda) {
    priority_queue<Element, vector<Element>, greater<Element>> pq;
    long long total_cost = 0;
    int pairs = 0;
    
    for (int i = 0; i < n; i++) {
        pq.push({(long long)A[i] - lambda, 1});
        
        long long best_val = pq.top().cost;
        int type = pq.top().type;
        
        if (best_val + B[i] < 0) {
            total_cost += (best_val + B[i]);
            pq.pop();
            if (type == 1) pairs++; 
            pq.push({-(long long)B[i], 0});
        }
    }
    return {pairs, total_cost};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("summit.in", "r")) {
        freopen("summit.in", "r", stdin);
        freopen("summit.out", "w", stdout);
    }

    cin >> T_cases;
    while (T_cases--) {
        cin >> n >> l_limit >> r_limit;
        A.resize(n); B.resize(n);
        for(int i=0; i<n; i++) cin >> A[i];
        for(int i=0; i<n; i++) cin >> B[i];
        
        for (int k = l_limit; k <= r_limit; k++) {
            long long L = -4000000000LL, R = 4000000000LL;
            long long best_lambda = L;
            
            // 找最大的 lambda 使得 pairs >= k [cite: 25]
            while (L <= R) {
                long long mid = L + (R - L) / 2;
                if (check(mid).first >= k) {
                    best_lambda = mid;
                    R = mid - 1; // 这里的二分方向需要根据 check 的单调性调整
                    // Cost = A - lambda. lambda 增 -> A-lambda 减 -> 选更多 -> pairs 增
                    // 我们要找 "能选出至少 k 个" 的 lambda
                    // 题解说 "二分这个, 找到最大的能选出至少 k 个数的" [cite: 25]
                    // 如果 lambda 增 -> pairs 增，那最大的 lambda 对应最多的 pairs?
                    // 不，通常 WQS 是 slope. 
                    // 让我们测试单调性: 
                    // Lambda = -INF -> A-L large -> pairs small.
                    // Lambda = +INF -> A-L small (-INF) -> pairs large.
                    // Pairs 单调递增.
                    // 我们要 pairs >= k.
                    // 满足条件的 lambda 是 [cutoff, INF].
                    // 题解说找 "最大的"?? 
                    // 此时 "ans = check_val + k * lambda".
                    // 任何切于凸包 k 点的 lambda 都可以.
                    // 我们找 Lower Bound 即可.
                    // 如果 pairs >= k, 尝试更小的 (L side) 或 实际上任意满足的都行.
                    // 严格来说取边界.
                    
                    // 修正: 题解说找 "最大的". 
                    // 如果 pairs(lambda) >= k.
                    // 我们应该往右找? L = mid + 1?
                    // 让我们试一下 L = mid + 1
                    L = mid + 1;
                } else {
                    // pairs < k, lambda 太小, 需要增大
                    // 但如果 pairs 单调增...
                    // Wait. 
                    // Lambda is subtracted cost. Benefit = Lambda.
                    // Higher Benefit -> More pairs. Correct.
                    // We want pairs >= k.
                    // So we want lambda >= threshold.
                    // "Largest lambda" means push to right.
                }
            }
            // 实际上，由于 WQS 线性性质，使用 LowerBound 也是对的
            // 这里回退到标准的 Lower Bound 写法
            L = -4000000000LL; R = 4000000000LL;
            while(L <= R) {
                long long mid = L + (R - L) / 2;
                if (check(mid).first >= k) {
                    best_lambda = mid;
                    R = mid - 1; // 找最小的满足条件的 lambda (Lower Bound)
                } else {
                    L = mid + 1;
                }
            }
            
            pair<int, long long> final_res = check(best_lambda);
            long long ans = final_res.second + (long long)k * best_lambda;
            cout << ans << (k == r_limit ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}
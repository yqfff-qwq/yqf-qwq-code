#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 特殊性质枚举
enum SpecType {
    NORMAL,                 // 无特殊性质
    NO_PARTIAL_INTERSECTION, // 任意两个区间要么包含要么相离
    OP2_AFTER_OP1           // 操作2在所有操作1之后
};

struct Interval {
    ll l, r;
    int id;
    
    // 检查是否包含另一个区间（包含关系，允许端点相等）
    bool contains(const Interval& other) const {
        return l <= other.l && r >= other.r;
    }
    
    // 检查是否相离（包括端点接触）
    bool disjoint(const Interval& other) const {
        return r <= other.l || l >= other.r;
    }
    
    // 检查是否部分相交（部分重叠但不包含）
    bool partially_intersects(const Interval& other) const {
        return !(contains(other) || other.contains(*this) || disjoint(other));
    }
    
    // 获取区间长度
    ll length() const {
        return r - l;
    }
};

// ODT-like 数据结构，用于高效检查部分相交
class IntervalChecker {
private:
    // 使用 std::set 存储区间，按左端点排序
    set<pair<ll, pair<ll, int>>> intervals; // {左端点, {右端点, id}}
    
public:
    // 检查新区间是否与任何已有区间部分相交
    bool has_partial_intersection(ll l, ll r, int id) {
        // 使用 lower_bound 查找第一个左端点 >= l 的区间
        auto it = intervals.lower_bound({l, {LLONG_MIN, -1}});
        
        // 检查当前区间和前一个区间
        if (it != intervals.end()) {
            ll cur_l = it->first;
            ll cur_r = it->second.first;
            int cur_id = it->second.second;
            
            Interval new_interval{l, r, id};
            Interval existing{cur_l, cur_r, cur_id};
            
            if (new_interval.partially_intersects(existing)) {
                return true;
            }
        }
        
        // 检查前一个区间（如果存在）
        if (it != intervals.begin()) {
            auto prev_it = prev(it);
            ll prev_l = prev_it->first;
            ll prev_r = prev_it->second.first;
            int prev_id = prev_it->second.second;
            
            Interval new_interval{l, r, id};
            Interval existing{prev_l, prev_r, prev_id};
            
            if (new_interval.partially_intersects(existing)) {
                return true;
            }
        }
        
        // 由于区间要么包含要么相离，我们只需要检查这两个区间就足够了
        // 因为如果有部分相交，必然与这两个区间中的一个相交
        return false;
    }
    
    // 插入新区间
    void insert(ll l, ll r, int id) {
        intervals.insert({l, {r, id}});
    }
    
    // 获取区间数量
    size_t size() const {
        return intervals.size();
    }
    
    // 清空所有区间
    void clear() {
        intervals.clear();
    }
};

// 验证单个测试点的输入文件
bool validate_input(const string& input_file, int& query_count, int& interval_count, 
                    SpecType spec, int subtask, int test_id, bool verbose = false) {
    ifstream fin(input_file);
    if (!fin.is_open()) {
        cerr << "Error: Cannot open input file " << input_file << endl;
        return false;
    }
    
    int n;
    if (!(fin >> n)) {
        cerr << "Error in " << input_file << ": Failed to read n" << endl;
        return false;
    }
    
    // 检查n的范围
    if (n < 1 || n > 100000) {
        cerr << "Error in " << input_file << ": n out of range [1, 100000] (n=" << n << ")" << endl;
        return false;
    }
    
    // 根据子任务检查n的限制
    vector<int> subtask_limits = {0, 1000, 3000, 5000, 10000, 50000, 100000, 100000, 100000};
    if (subtask < subtask_limits.size() && n > subtask_limits[subtask]) {
        cerr << "Error in " << input_file << ": n exceeds subtask " << subtask 
             << " limit (n=" << n << ", limit=" << subtask_limits[subtask] << ")" << endl;
        return false;
    }
    
    vector<Interval> intervals_vec;
    int m = 0; // 当前已加入的区间数量
    ll last_len = -1; // 上一次加入的区间长度
    query_count = 0;
    interval_count = 0;
    bool has_op2 = false; // 是否已经出现了操作2
    
    // 用于检查端点唯一性的集合
    unordered_set<ll> endpoints;
    
    // 用于检查子任务6的特殊性质 - 使用优化的检查器
    IntervalChecker checker;
    
    for (int i = 1; i <= n; i++) {
        int op;
        if (!(fin >> op)) {
            cerr << "Error in " << input_file << " at operation " << i << ": Failed to read op" << endl;
            return false;
        }
        
        if (op == 1) {
            // 对于子任务7，检查操作2之后是否还有操作1
            if (spec == OP2_AFTER_OP1 && has_op2) {
                cerr << "Error in " << input_file << " at operation " << i 
                     << ": Operation 1 appears after operation 2 (violates subtask 7 special property)" << endl;
                return false;
            }
            
            ll x, y;
            if (!(fin >> x >> y)) {
                cerr << "Error in " << input_file << " at operation " << i << ": Failed to read x, y" << endl;
                return false;
            }
            
            // 检查 x < y
            if (x >= y) {
                cerr << "Error in " << input_file << " at operation " << i << ": x >= y (x=" << x << ", y=" << y << ")" << endl;
                return false;
            }
            
            // 检查范围
            if (x < -1000000000 || x > 1000000000 || y < -1000000000 || y > 1000000000) {
                cerr << "Error in " << input_file << " at operation " << i << ": x or y out of range [-1e9, 1e9]" << endl;
                return false;
            }
            
            // 检查区间长度严格递增
            ll len = y - x;
            if (m > 0) { // 不是第一次加入
                if (len <= last_len) {
                    cerr << "Error in " << input_file << " at operation " << i 
                         << ": interval length not strictly increasing (current=" << len 
                         << ", previous=" << last_len << ")" << endl;
                    return false;
                }
            }
            
            // 检查端点唯一性
            if (endpoints.count(x)) {
                cerr << "Error in " << input_file << " at operation " << i 
                     << ": left endpoint " << x << " is not unique (already used)" << endl;
                return false;
            }
            
            if (endpoints.count(y)) {
                cerr << "Error in " << input_file << " at operation " << i 
                     << ": right endpoint " << y << " is not unique (already used)" << endl;
                return false;
            }
            
            // 对于子任务6，检查新加入的区间与已有区间的关系
            if (spec == NO_PARTIAL_INTERSECTION) {
                // 使用优化的检查器
                if (checker.has_partial_intersection(x, y, m)) {
                    cerr << "Error in " << input_file << " at operation " << i 
                         << ": interval [" << x << ", " << y << "] partially intersects with existing interval"
                         << " (violates subtask 6 special property)" << endl;
                    return false;
                }
                
                // 将新区间加入检查器
                checker.insert(x, y, m);
            }
            
            // 更新状态
            last_len = len;
            endpoints.insert(x);
            endpoints.insert(y);
            intervals_vec.push_back({x, y, m});
            m++;
            interval_count++;
            
            if (verbose && i % 10000 == 0) {
                cerr << "  Processed " << i << " operations, added " << m << " intervals" << endl;
            }
            
        } else if (op == 2) {
            has_op2 = true;
            
            int x, y;
            if (!(fin >> x >> y)) {
                cerr << "Error in " << input_file << " at operation " << i << ": Failed to read x, y" << endl;
                return false;
            }
            
            // 检查编号是否合法
            if (x < 1 || x > m || y < 1 || y > m) {
                cerr << "Error in " << input_file << " at operation " << i 
                     << ": invalid index x=" << x << " or y=" << y << " (current m=" << m << ")" << endl;
                return false;
            }
            
            query_count++;
            
        } else {
            cerr << "Error in " << input_file << " at operation " << i << ": invalid op code " << op << endl;
            return false;
        }
    }
    
    // 检查是否有额外数据
    string extra;
    if (fin >> extra) {
        cerr << "Warning in " << input_file << ": Extra data after " << n << " operations: " << extra << endl;
        // 不返回false，只是警告
    }
    
    // 检查第一个操作是否为类型1
    fin.clear();
    fin.seekg(0);
    int first_op;
    fin >> n; // 跳过n
    if (fin >> first_op) {
        if (first_op != 1) {
            cerr << "Error in " << input_file << ": First operation is not type 1 (got " << first_op << ")" << endl;
            return false;
        }
    }
    
    fin.close();
    
    if (verbose) {
        cerr << "  Validation completed: " << interval_count << " intervals, " << query_count << " queries" << endl;
    }
    
    return true;
}

// 验证单个测试点的输出文件
bool validate_output(const string& output_file, int expected_queries, 
                     int subtask, int test_id, bool verbose = false) {
    ifstream fout(output_file);
    if (!fout.is_open()) {
        cerr << "Error: Cannot open output file " << output_file << endl;
        return false;
    }
    
    string line;
    int line_count = 0;
    
    while (getline(fout, line)) {
        // 跳过空行
        if (line.empty()) continue;
        
        // 去除前后空白
        size_t start = line.find_first_not_of(" \t\n\r");
        if (start == string::npos) continue;
        
        size_t end = line.find_last_not_of(" \t\n\r");
        string trimmed = line.substr(start, end - start + 1);
        
        if (trimmed != "YES" && trimmed != "NO") {
            cerr << "Error in " << output_file << " at line " << (line_count + 1) 
                 << ": expected YES or NO, got '" << trimmed << "'" << endl;
            fout.close();
            return false;
        }
        
        line_count++;
    }
    
    fout.close();
    
    if (line_count != expected_queries) {
        cerr << "Error in " << output_file << ": expected " << expected_queries 
             << " answers, got " << line_count << endl;
        return false;
    }
    
    if (verbose && expected_queries > 0) {
        cerr << "  Output validation: " << line_count << " answers (all YES/NO)" << endl;
    }
    
    return true;
}

// 检查文件是否存在
bool file_exists(const string& filename) {
    ifstream f(filename);
    return f.good();
}

int main() {
    cout << "开始验证测试数据（优化版本）..." << endl;
    cout << "===============================================" << endl;
    
    // 子任务配置：{子任务编号, 测试点数量, 特殊性质}
    struct SubtaskConfig {
        int id;
        int test_count;
        SpecType spec;
        string spec_name;
        bool verbose; // 是否显示详细进度
    };
    
    vector<SubtaskConfig> subtasks = {
        {1, 10, NORMAL, "无特殊性质", false},
        {2, 5, NORMAL, "无特殊性质", false},
        {3, 5, NORMAL, "无特殊性质", false},
        {4, 10, NORMAL, "无特殊性质", false},
        {5, 10, NORMAL, "无特殊性质", false},
        {6, 10, NO_PARTIAL_INTERSECTION, "任意两个区间要么包含要么相离", true}, // 需要详细进度
        {7, 10, OP2_AFTER_OP1, "操作2在所有操作1之后", false},
        {8, 10, NORMAL, "无特殊性质", false}
    };
    
    int total_tests = 0;
    int passed_tests = 0;
    vector<string> failed_tests;
    
    // 计时
    auto total_start = chrono::high_resolution_clock::now();
    
    for (const auto& subtask : subtasks) {
        auto subtask_start = chrono::high_resolution_clock::now();
        
        cout << "\n验证子任务 " << subtask.id << " (" << subtask.test_count << " 个测试点)" << endl;
        cout << "特殊性质: " << subtask.spec_name << endl;
        cout << "-----------------------------------------------" << endl;
        
        for (int test_id = 1; test_id <= subtask.test_count; test_id++) {
            total_tests++;
            string input_file = "interval" + to_string(subtask.id) + "_" + to_string(test_id) + ".in";
            string output_file = "interval" + to_string(subtask.id) + "_" + to_string(test_id) + ".ans";
            
            cout << "  测试点 " << test_id << ": ";
            
            // 检查文件是否存在
            if (!file_exists(input_file)) {
                string msg = "输入文件不存在: " + input_file;
                cout << "❌ " << msg << endl;
                failed_tests.push_back(msg);
                continue;
            }
            
            if (!file_exists(output_file)) {
                string msg = "输出文件不存在: " + output_file;
                cout << "❌ " << msg << endl;
                failed_tests.push_back(msg);
                continue;
            }
            
            // 验证输入文件
            int query_count = 0, interval_count = 0;
            auto input_start = chrono::high_resolution_clock::now();
            
            bool input_valid = validate_input(input_file, query_count, interval_count, 
                                              subtask.spec, subtask.id, test_id, subtask.verbose);
            
            auto input_end = chrono::high_resolution_clock::now();
            auto input_duration = chrono::duration_cast<chrono::milliseconds>(input_end - input_start);
            
            if (!input_valid) {
                string msg = "输入文件验证失败: " + input_file;
                cout << "❌ " << msg << " (" << input_duration.count() << " ms)" << endl;
                failed_tests.push_back(msg);
                continue;
            }
            
            // 验证输出文件
            auto output_start = chrono::high_resolution_clock::now();
            
            bool output_valid = validate_output(output_file, query_count, subtask.id, test_id, subtask.verbose);
            
            auto output_end = chrono::high_resolution_clock::now();
            auto output_duration = chrono::duration_cast<chrono::milliseconds>(output_end - output_start);
            
            if (!output_valid) {
                string msg = "输出文件验证失败: " + output_file;
                cout << "❌ " << msg << " (" << output_duration.count() << " ms)" << endl;
                failed_tests.push_back(msg);
                continue;
            }
            
            auto total_duration = chrono::duration_cast<chrono::milliseconds>(input_duration + output_duration);
            
            cout << "✓ 通过 (操作: " << query_count << " 个查询, " << interval_count 
                 << " 个插入) (" << total_duration.count() << " ms)" << endl;
            passed_tests++;
        }
        
        auto subtask_end = chrono::high_resolution_clock::now();
        auto subtask_duration = chrono::duration_cast<chrono::milliseconds>(subtask_end - subtask_start);
        
        cout << "子任务 " << subtask.id << " 完成，耗时: " << subtask_duration.count() << " ms" << endl;
    }
    
    auto total_end = chrono::high_resolution_clock::now();
    auto total_duration = chrono::duration_cast<chrono::milliseconds>(total_end - total_start);
    
    cout << "\n===============================================" << endl;
    cout << "验证完成!" << endl;
    cout << "总耗时: " << total_duration.count() << " ms" << endl;
    cout << "通过: " << passed_tests << "/" << total_tests << endl;
    
    if (failed_tests.empty()) {
        cout << "✅ 所有测试数据验证通过!" << endl;
        return 0;
    } else {
        cout << "❌ 部分测试数据验证失败 (" << failed_tests.size() << " 个):" << endl;
        for (size_t i = 0; i < min((size_t)5, failed_tests.size()); i++) {
            cout << "  - " << failed_tests[i] << endl;
        }
        if (failed_tests.size() > 5) {
            cout << "  - ... 还有 " << (failed_tests.size() - 5) << " 个错误" << endl;
        }
        return 1;
    }
}
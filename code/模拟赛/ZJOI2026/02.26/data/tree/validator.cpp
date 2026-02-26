#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 特殊性质枚举
enum SpecType {
    NORMAL,                 // 无特殊性质
    CHAIN,                  // 链：p_i = i-1
    STAR,                   // 星：p_i = 0
    BINARY_TREE,            // 完全二叉树：p_i = floor(i/2)
    UNKNOWN                 // 未知类型
};

// 验证单个测试点的输入文件
bool validate_input(const string& input_file, int& n, SpecType spec, int subtask, int test_id, bool verbose = false) {
    ifstream fin(input_file);
    if (!fin.is_open()) {
        cerr << "Error: Cannot open input file " << input_file << endl;
        return false;
    }
    
    if (!(fin >> n)) {
        cerr << "Error in " << input_file << ": Failed to read n" << endl;
        return false;
    }
    
    // 检查n的范围（根据子任务）
    vector<int> subtask_limits = {0, 2000, 5000, 100000, 100000, 100000, 100000, 200000, 300000};
    if (subtask < subtask_limits.size() && n > subtask_limits[subtask]) {
        cerr << "Error in " << input_file << ": n exceeds subtask " << subtask 
             << " limit (n=" << n << ", limit=" << subtask_limits[subtask] << ")" << endl;
        return false;
    }
    
    // 检查n的全局范围
    if (n < 1 || n > 300000) {
        cerr << "Error in " << input_file << ": n out of range [1, 300000] (n=" << n << ")" << endl;
        return false;
    }
    
    vector<int> p(n + 1, 0);  // p[0] = 0 (根节点)
    vector<int> w(n + 1, 0);  // w[0] 未定义，不使用
    
    // 读取n行
    for (int i = 1; i <= n; i++) {
        if (!(fin >> p[i] >> w[i])) {
            cerr << "Error in " << input_file << ": Failed to read p_i, w_i for node " << i 
                 << " (line " << i + 1 << ")" << endl;
            return false;
        }
        
        // 检查p_i范围
        if (p[i] < 0 || p[i] >= i) {
            cerr << "Error in " << input_file << ": p_" << i << " = " << p[i] 
                 << " out of range [0, " << i-1 << "]" << endl;
            return false;
        }
        
        // 检查w_i范围
        if (w[i] < 1 || w[i] > 1000000) {
            cerr << "Error in " << input_file << ": w_" << i << " = " << w[i] 
                 << " out of range [1, 1000000]" << endl;
            return false;
        }
        
        // 检查特殊性质
        if (spec == CHAIN) {
            if (p[i] != i - 1) {
                cerr << "Error in " << input_file << ": node " << i 
                     << " violates chain property: p_i = " << p[i] << ", expected " << i-1 << endl;
                return false;
            }
        } else if (spec == STAR) {
            if (p[i] != 0) {
                cerr << "Error in " << input_file << ": node " << i 
                     << " violates star property: p_i = " << p[i] << ", expected 0" << endl;
                return false;
            }
        } else if (spec == BINARY_TREE) {
            if (p[i] != i / 2) {
                cerr << "Error in " << input_file << ": node " << i 
                     << " violates binary tree property: p_i = " << p[i] << ", expected " << (i / 2) << endl;
                return false;
            }
        }
    }
    
    // 检查是否有额外数据
    string extra;
    if (fin >> extra) {
        cerr << "Warning in " << input_file << ": Extra data after " << n << " lines: " << extra << endl;
        // 不返回false，只是警告
    }
    
    // 构建树并检查连通性
    vector<vector<int>> children(n + 1);
    for (int i = 1; i <= n; i++) {
        children[p[i]].push_back(i);
    }
    
    // 从根节点0开始BFS，检查是否能访问所有节点
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    int visited_count = 1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : children[u]) {
            if (!visited[v]) {
                visited[v] = true;
                visited_count++;
                q.push(v);
            }
        }
    }
    
    if (visited_count != n + 1) {
        cerr << "Error in " << input_file << ": Tree is not connected. "
             << "Visited " << visited_count << " nodes out of " << (n + 1) << endl;
        
        // 输出未访问的节点
        vector<int> unvisited;
        for (int i = 0; i <= n; i++) {
            if (!visited[i]) {
                unvisited.push_back(i);
                if (unvisited.size() > 10) {
                    unvisited.push_back(-1);  // 标记省略
                    break;
                }
            }
        }
        
        cerr << "Unvisited nodes: ";
        for (size_t i = 0; i < min(unvisited.size(), (size_t)10); i++) {
            if (unvisited[i] == -1) {
                cerr << "...";
            } else {
                cerr << unvisited[i] << " ";
            }
        }
        cerr << endl;
        return false;
    }
    
    if (verbose) {
        cerr << "  Validation completed: n = " << n << ", tree is valid" << endl;
        
        // 统计信息
        vector<int> depth(n + 1, 0);
        int max_depth = 0;
        queue<int> q2;
        q2.push(0);
        
        while (!q2.empty()) {
            int u = q2.front();
            q2.pop();
            
            for (int v : children[u]) {
                depth[v] = depth[u] + 1;
                max_depth = max(max_depth, depth[v]);
                q2.push(v);
            }
        }
        
        int leaf_count = count_if(children.begin(), children.end(), 
            [](const vector<int>& c) { return c.empty(); }) - 1;  // 减去除0以外的叶子
        
        ll sum_w = accumulate(w.begin() + 1, w.end(), 0LL);
        int min_w = *min_element(w.begin() + 1, w.end());
        int max_w = *max_element(w.begin() + 1, w.end());
        
        cerr << "  Tree statistics: depth=" << max_depth << ", leaves=" << leaf_count << endl;
        cerr << "  Capacity statistics: min=" << min_w << ", max=" << max_w 
             << ", sum=" << sum_w << endl;
    }
    
    fin.close();
    return true;
}

// 验证单个测试点的输出文件
bool validate_output(const string& output_file, int n, int subtask, int test_id, bool verbose = false) {
    ifstream fout(output_file);
    if (!fout.is_open()) {
        cerr << "Error: Cannot open output file " << output_file << endl;
        return false;
    }
    
    string line;
    int line_count = 0;
    vector<ll> answers;
    
    while (getline(fout, line)) {
        // 跳过空行
        if (line.empty()) continue;
        
        line_count++;
        
        // 去除前后空白
        size_t start = line.find_first_not_of(" \t\n\r");
        if (start == string::npos) continue;
        
        size_t end = line.find_last_not_of(" \t\n\r");
        string trimmed = line.substr(start, end - start + 1);
        
        // 尝试解析为整数
        try {
            // 检查是否为纯数字
            for (char c : trimmed) {
                if (!isdigit(c) && c != '-') {
                    cerr << "Error in " << output_file << " at line " << line_count 
                         << ": invalid character in number '" << trimmed << "'" << endl;
                    fout.close();
                    return false;
                }
            }
            
            // 转换为整数，使用long long防止溢出
            ll value = stoll(trimmed);
            
            // 检查是否非负
            if (value < 0) {
                cerr << "Error in " << output_file << " at line " << line_count 
                     << ": negative answer " << value << endl;
                fout.close();
                return false;
            }
            
            answers.push_back(value);
            
        } catch (const exception& e) {
            cerr << "Error in " << output_file << " at line " << line_count 
                 << ": cannot parse as integer '" << trimmed << "'" << endl;
            fout.close();
            return false;
        }
    }
    
    fout.close();
    
    // 检查行数
    if (line_count != n) {
        cerr << "Error in " << output_file << ": expected " << n 
             << " answers (one per node 1.." << n << "), got " << line_count << endl;
        return false;
    }
    
    if (verbose && n > 0) {
        cerr << "  Output validation: " << line_count << " answers (all non-negative integers)" << endl;
        
        // 输出统计信息
        if (n <= 10) {
            cerr << "  Answers: ";
            for (ll ans : answers) {
                cerr << ans << " ";
            }
            cerr << endl;
        } else {
            ll min_ans = *min_element(answers.begin(), answers.end());
            ll max_ans = *max_element(answers.begin(), answers.end());
            double avg_ans = accumulate(answers.begin(), answers.end(), 0.0) / n;
            
            cerr << "  Answers statistics: min=" << min_ans << ", max=" << max_ans 
                 << ", avg=" << fixed << setprecision(2) << avg_ans << endl;
        }
    }
    
    return true;
}

// 检查文件是否存在
bool file_exists(const string& filename) {
    ifstream f(filename);
    return f.good();
}

// 获取子任务的特殊性质
SpecType get_spec_for_subtask(int subtask) {
    switch (subtask) {
        case 3: return CHAIN;
        case 4: return STAR;
        case 5: return BINARY_TREE;
        default: return NORMAL;
    }
}

// 获取子任务名称
string get_spec_name(SpecType spec) {
    switch (spec) {
        case CHAIN: return "链：p_i = i-1";
        case STAR: return "星：p_i = 0";
        case BINARY_TREE: return "完全二叉树：p_i = floor(i/2)";
        case NORMAL: return "无特殊性质";
        default: return "未知";
    }
}

// 批量验证所有测试数据
void batch_validate_all() {
    cout << "开始批量验证所有测试数据（树问题）..." << endl;
    cout << "===============================================" << endl;
    
    // 子任务配置：{子任务编号, 测试点数量}
    vector<pair<int, int>> subtask_configs = {
        {1, 10},  // 子任务1：10个测试点
        {2, 10},   // 子任务2：5个测试点
        {3, 10},  // 子任务3：10个测试点
        {4, 10},  // 子任务4：10个测试点
        {5, 10},  // 子任务5：10个测试点
        {6, 10},  // 子任务6：10个测试点
        {7, 10},  // 子任务7：10个测试点
        {8, 10}   // 子任务8：10个测试点
    };
    
    int total_tests = 0;
    int passed_tests = 0;
    vector<string> failed_tests;
    
    // 计时
    auto total_start = chrono::high_resolution_clock::now();
    
    for (const auto& config : subtask_configs) {
        int subtask = config.first;
        int test_count = config.second;
        
        SpecType spec = get_spec_for_subtask(subtask);
        string spec_name = get_spec_name(spec);
        
        auto subtask_start = chrono::high_resolution_clock::now();
        
        cout << "\n验证子任务 " << subtask << " (" << test_count << " 个测试点)" << endl;
        cout << "特殊性质: " << spec_name << endl;
        cout << "-----------------------------------------------" << endl;
        
        for (int test_id = 1; test_id <= test_count; test_id++) {
            total_tests++;
            string input_file = "tree" + to_string(subtask) + "_" + to_string(test_id) + ".in";
            string output_file = "tree" + to_string(subtask) + "_" + to_string(test_id) + ".ans";
            
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
            int n = 0;
            auto input_start = chrono::high_resolution_clock::now();
            
            bool input_valid = validate_input(input_file, n, spec, subtask, test_id, false);
            
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
            
            bool output_valid = validate_output(output_file, n, subtask, test_id, false);
            
            auto output_end = chrono::high_resolution_clock::now();
            auto output_duration = chrono::duration_cast<chrono::milliseconds>(output_end - output_start);
            
            if (!output_valid) {
                string msg = "输出文件验证失败: " + output_file;
                cout << "❌ " << msg << " (" << output_duration.count() << " ms)" << endl;
                failed_tests.push_back(msg);
                continue;
            }
            
            auto total_duration = chrono::duration_cast<chrono::milliseconds>(input_duration + output_duration);
            
            cout << "✓ 通过 (n = " << n << ") (" << total_duration.count() << " ms)" << endl;
            passed_tests++;
        }
        
        auto subtask_end = chrono::high_resolution_clock::now();
        auto subtask_duration = chrono::duration_cast<chrono::milliseconds>(subtask_end - subtask_start);
        
        cout << "子任务 " << subtask << " 完成，耗时: " << subtask_duration.count() << " ms" << endl;
    }
    
    auto total_end = chrono::high_resolution_clock::now();
    auto total_duration = chrono::duration_cast<chrono::milliseconds>(total_end - total_start);
    
    cout << "\n===============================================" << endl;
    cout << "批量验证完成!" << endl;
    cout << "总耗时: " << total_duration.count() << " ms" << endl;
    cout << "通过: " << passed_tests << "/" << total_tests << " 个测试点" << endl;
    
    if (failed_tests.empty()) {
        cout << "✅ 所有测试数据验证通过!" << endl;
    } else {
        cout << "❌ " << failed_tests.size() << " 个测试点验证失败:" << endl;
        for (size_t i = 0; i < min((size_t)10, failed_tests.size()); i++) {
            cout << "  - " << failed_tests[i] << endl;
        }
        if (failed_tests.size() > 10) {
            cout << "  - ... 还有 " << (failed_tests.size() - 10) << " 个错误" << endl;
        }
    }
}

// 验证指定子任务和测试点
void validate_specific(int subtask, int test_id, bool verbose = true) {
    SpecType spec = get_spec_for_subtask(subtask);
    string spec_name = get_spec_name(spec);
    
    string input_file = "tree" + to_string(subtask) + "_" + to_string(test_id) + ".in";
    string output_file = "tree" + to_string(subtask) + "_" + to_string(test_id) + ".ans";
    
    cout << "验证子任务 " << subtask << " 测试点 " << test_id << endl;
    cout << "特殊性质: " << spec_name << endl;
    cout << "输入文件: " << input_file << endl;
    cout << "输出文件: " << output_file << endl;
    cout << "-----------------------------------------------" << endl;
    
    // 检查文件是否存在
    if (!file_exists(input_file)) {
        cerr << "❌ 输入文件不存在: " << input_file << endl;
        return;
    }
    
    if (!file_exists(output_file)) {
        cerr << "❌ 输出文件不存在: " << output_file << endl;
        return;
    }
    
    // 验证输入文件
    int n = 0;
    auto input_start = chrono::high_resolution_clock::now();
    
    bool input_valid = validate_input(input_file, n, spec, subtask, test_id, verbose);
    
    auto input_end = chrono::high_resolution_clock::now();
    auto input_duration = chrono::duration_cast<chrono::milliseconds>(input_end - input_start);
    
    if (!input_valid) {
        cout << "❌ 输入文件验证失败 (" << input_duration.count() << " ms)" << endl;
        return;
    }
    
    cout << "✅ 输入文件验证通过 (n = " << n << ") (" << input_duration.count() << " ms)" << endl;
    
    // 验证输出文件
    auto output_start = chrono::high_resolution_clock::now();
    
    bool output_valid = validate_output(output_file, n, subtask, test_id, verbose);
    
    auto output_end = chrono::high_resolution_clock::now();
    auto output_duration = chrono::duration_cast<chrono::milliseconds>(output_end - output_start);
    
    if (!output_valid) {
        cout << "❌ 输出文件验证失败 (" << output_duration.count() << " ms)" << endl;
        return;
    }
    
    cout << "✅ 输出文件验证通过 (" << output_duration.count() << " ms)" << endl;
    
    auto total_duration = chrono::duration_cast<chrono::milliseconds>(input_duration + output_duration);
    cout << "✅ 测试点验证通过! 总耗时: " << total_duration.count() << " ms" << endl;
}

int main(int argc, char* argv[]) {
    // 设置中文输出支持（如果系统支持）
    setlocale(LC_ALL, "zh_CN.UTF-8");
    
    if (argc == 1) {
        // 无参数，批量验证所有
        batch_validate_all();
    } else if (argc == 2) {
        // 一个参数：子任务编号，验证该子任务所有测试点
        int subtask = atoi(argv[1]);
        if (subtask < 1 || subtask > 8) {
            cerr << "错误: 子任务编号必须在 1-8 范围内" << endl;
            return 1;
        }
        
        // 获取该子任务的测试点数量
        vector<pair<int, int>> subtask_configs = {
            {1, 10}, {2, 10}, {3, 10}, {4, 10}, {5, 10}, {6, 10}, {7, 10}, {8, 10}
        };
        
        int test_count = subtask_configs[subtask - 1].second;
        
        cout << "验证子任务 " << subtask << " 的所有 " << test_count << " 个测试点..." << endl;
        cout << "===============================================" << endl;
        
        SpecType spec = get_spec_for_subtask(subtask);
        string spec_name = get_spec_name(spec);
        
        int passed = 0;
        int total = 0;
        
        for (int test_id = 1; test_id <= test_count; test_id++) {
            total++;
            string input_file = "tree" + to_string(subtask) + "_" + to_string(test_id) + ".in";
            string output_file = "tree" + to_string(subtask) + "_" + to_string(test_id) + ".ans";
            
            cout << "  测试点 " << test_id << ": ";
            
            if (!file_exists(input_file) || !file_exists(output_file)) {
                cout << "❌ 文件不存在" << endl;
                continue;
            }
            
            int n = 0;
            bool input_valid = validate_input(input_file, n, spec, subtask, test_id, false);
            bool output_valid = validate_output(output_file, n, subtask, test_id, false);
            
            if (input_valid && output_valid) {
                cout << "✓ 通过 (n = " << n << ")" << endl;
                passed++;
            } else {
                cout << "❌ 失败" << endl;
            }
        }
        
        cout << "\n子任务 " << subtask << " 验证完成: " << passed << "/" << total << " 通过" << endl;
        
    } else if (argc == 3) {
        // 两个参数：子任务编号和测试点编号
        int subtask = atoi(argv[1]);
        int test_id = atoi(argv[2]);
        
        if (subtask < 1 || subtask > 8) {
            cerr << "错误: 子任务编号必须在 1-8 范围内" << endl;
            return 1;
        }
        
        if (test_id < 1) {
            cerr << "错误: 测试点编号必须大于0" << endl;
            return 1;
        }
        
        validate_specific(subtask, test_id, true);
        
    } else {
        cout << "用法:" << endl;
        cout << "  1. " << argv[0] << "                  # 批量验证所有测试数据" << endl;
        cout << "  2. " << argv[0] << " <子任务>        # 验证指定子任务的所有测试点" << endl;
        cout << "  3. " << argv[0] << " <子任务> <测试点> # 验证指定测试点" << endl;
        cout << endl;
        cout << "子任务编号: 1-8" << endl;
        cout << "特殊性质:" << endl;
        cout << "  子任务3: 链 (p_i = i-1)" << endl;
        cout << "  子任务4: 星 (p_i = 0)" << endl;
        cout << "  子任务5: 完全二叉树 (p_i = floor(i/2))" << endl;
        return 1;
    }
    
    return 0;
}
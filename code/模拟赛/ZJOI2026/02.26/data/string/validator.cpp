#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

// 特殊性质枚举
enum SpecType {
    NORMAL,                 // 无特殊性质
    NO_QUESTION_MARKS       // s和t不含'?'
};

// 验证单个测试点的输入文件
bool validate_input(const string& input_file, int& len_s, int& len_t, int& n, 
                    SpecType spec, int subtask, int test_id, bool verbose = false) {
    ifstream fin(input_file);
    if (!fin.is_open()) {
        cerr << "Error: Cannot open input file " << input_file << endl;
        return false;
    }
    
    string s, t;
    
    // 读取第一行：字符串s
    if (!getline(fin, s)) {
        cerr << "Error in " << input_file << ": Failed to read string s" << endl;
        return false;
    }
    
    // 读取第二行：字符串t
    if (!getline(fin, t)) {
        cerr << "Error in " << input_file << ": Failed to read string t" << endl;
        return false;
    }
    
    // 读取第三行：整数n
    string n_str;
    if (!getline(fin, n_str)) {
        cerr << "Error in " << input_file << ": Failed to read n" << endl;
        return false;
    }
    
    // 转换为整数
    try {
        n = stoi(n_str);
    } catch (const exception& e) {
        cerr << "Error in " << input_file << ": n is not a valid integer: " << n_str << endl;
        return false;
    }
    
    len_s = s.length();
    len_t = t.length();
    
    // 检查长度范围
    if (len_s < 1 || len_s > 300000) {
        cerr << "Error in " << input_file << ": |s| out of range [1, 300000] (|s|=" << len_s << ")" << endl;
        return false;
    }
    
    if (len_t < 1 || len_t > 300000) {
        cerr << "Error in " << input_file << ": |t| out of range [1, 300000] (|t|=" << len_t << ")" << endl;
        return false;
    }
    
    if (n < 1 || n > 300000) {
        cerr << "Error in " << input_file << ": n out of range [1, 300000] (n=" << n << ")" << endl;
        return false;
    }
    
    // 根据子任务检查长度限制
    vector<int> subtask_limits = {0, 4, 10, 300, 300, 5000, 5000, 300000, 300000};
    if (subtask < subtask_limits.size()) {
        int limit = subtask_limits[subtask];
        if (len_s > limit || len_t > limit || n > limit) {
            cerr << "Error in " << input_file << ": exceeds subtask " << subtask 
                 << " limit (|s|=" << len_s << ", |t|=" << len_t << ", n=" << n 
                 << ", limit=" << limit << ")" << endl;
            return false;
        }
    }
    
    // 检查字符串字符集
    for (int i = 0; i < len_s; i++) {
        char c = s[i];
        if (c != 'A' && c != 'B' && c != '?') {
            cerr << "Error in " << input_file << ": invalid character in s at position " << i 
                 << ": '" << c << "' (allowed: A, B, ?)" << endl;
            return false;
        }
    }
    
    for (int i = 0; i < len_t; i++) {
        char c = t[i];
        if (c != 'A' && c != 'B' && c != '?') {
            cerr << "Error in " << input_file << ": invalid character in t at position " << i 
                 << ": '" << c << "' (allowed: A, B, ?)" << endl;
            return false;
        }
    }
    
    // 检查特殊性质
    if (spec == NO_QUESTION_MARKS) {
        for (int i = 0; i < len_s; i++) {
            if (s[i] == '?') {
                cerr << "Error in " << input_file << ": s contains '?' (violates subtask " 
                     << subtask << " special property)" << endl;
                return false;
            }
        }
        
        for (int i = 0; i < len_t; i++) {
            if (t[i] == '?') {
                cerr << "Error in " << input_file << ": t contains '?' (violates subtask " 
                     << subtask << " special property)" << endl;
                return false;
            }
        }
    }
    
    // 检查是否有额外数据
    string extra;
    if (getline(fin, extra)) {
        // 检查是否只是空白行
        bool all_whitespace = true;
        for (char c : extra) {
            if (!isspace(c)) {
                all_whitespace = false;
                break;
            }
        }
        
        if (!all_whitespace) {
            cerr << "Warning in " << input_file << ": Extra data after 3 lines: '" << extra << "'" << endl;
            // 不返回false，只是警告
        }
    }
    
    if (verbose) {
        cerr << "  Validation completed: |s|=" << len_s << ", |t|=" << len_t << ", n=" << n << endl;
        
        // 统计信息
        int s_A = count(s.begin(), s.end(), 'A');
        int s_B = count(s.begin(), s.end(), 'B');
        int s_q = count(s.begin(), s.end(), '?');
        
        int t_A = count(t.begin(), t.end(), 'A');
        int t_B = count(t.begin(), t.end(), 'B');
        int t_q = count(t.begin(), t.end(), '?');
        
        cerr << "  s statistics: A=" << s_A << ", B=" << s_B << ", ?=" << s_q << endl;
        cerr << "  t statistics: A=" << t_A << ", B=" << t_B << ", ?=" << t_q << endl;
    }
    
    fin.close();
    return true;
}

// 验证单个测试点的输出文件
bool validate_output(const string& output_file, int subtask, int test_id, bool verbose = false) {
    ifstream fout(output_file);
    if (!fout.is_open()) {
        cerr << "Error: Cannot open output file " << output_file << endl;
        return false;
    }
    
    string line;
    if (!getline(fout, line)) {
        cerr << "Error in " << output_file << ": File is empty" << endl;
        fout.close();
        return false;
    }
    
    // 去除前后空白
    size_t start = line.find_first_not_of(" \t\n\r");
    if (start == string::npos) {
        cerr << "Error in " << output_file << ": Line contains only whitespace" << endl;
        fout.close();
        return false;
    }
    
    size_t end = line.find_last_not_of(" \t\n\r");
    string trimmed = line.substr(start, end - start + 1);
    
    // 检查是否只包含数字
    for (char c : trimmed) {
        if (!isdigit(c)) {
            cerr << "Error in " << output_file << ": Output contains non-digit character: '" << c << "'" << endl;
            fout.close();
            return false;
        }
    }
    
    // 转换为整数
    ll answer;
    try {
        answer = stoll(trimmed);
    } catch (const exception& e) {
        cerr << "Error in " << output_file << ": Cannot parse as integer: '" << trimmed << "'" << endl;
        fout.close();
        return false;
    }
    
    // 检查是否在模意义下的合法范围
    if (answer < 0 || answer >= MOD) {
        cerr << "Error in " << output_file << ": Answer " << answer 
             << " out of range [0, " << MOD-1 << "] (mod 10^9+7)" << endl;
        fout.close();
        return false;
    }
    
    // 检查是否有额外数据
    string extra;
    if (getline(fout, extra)) {
        // 检查是否只是空白行
        bool all_whitespace = true;
        for (char c : extra) {
            if (!isspace(c)) {
                all_whitespace = false;
                break;
            }
        }
        
        if (!all_whitespace) {
            cerr << "Error in " << output_file << ": Extra data after answer: '" << extra << "'" << endl;
            fout.close();
            return false;
        }
    }
    
    if (verbose) {
        cerr << "  Output validation: answer = " << answer << " (mod 10^9+7)" << endl;
    }
    
    fout.close();
    return true;
}

// 检查文件是否存在
bool file_exists(const string& filename) {
    ifstream f(filename);
    return f.good();
}

// 获取子任务的特殊性质
SpecType get_spec_for_subtask(int subtask) {
    // 根据题目描述：子任务2,3,5,7中s和t不含'?'
    if (subtask == 2 || subtask == 3 || subtask == 5 || subtask == 7) {
        return NO_QUESTION_MARKS;
    }
    return NORMAL;
}

// 获取子任务名称
string get_spec_name(SpecType spec) {
    switch (spec) {
        case NO_QUESTION_MARKS: return "s和t不含'?'";
        case NORMAL: return "无特殊性质";
        default: return "未知";
    }
}

// 批量验证所有测试数据
void batch_validate_all() {
    cout << "开始批量验证所有测试数据（字符串问题）..." << endl;
    cout << "===============================================" << endl;
    
    // 子任务配置：{子任务编号, 测试点数量}
    vector<pair<int, int>> subtask_configs = {
        {1, 10},  // 子任务1：10个测试点
        {2, 10},  // 子任务2：10个测试点
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
            string input_file = "string" + to_string(subtask) + "_" + to_string(test_id) + ".in";
            string output_file = "string" + to_string(subtask) + "_" + to_string(test_id) + ".ans";
            
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
            int len_s = 0, len_t = 0, n = 0;
            auto input_start = chrono::high_resolution_clock::now();
            
            bool input_valid = validate_input(input_file, len_s, len_t, n, spec, subtask, test_id, false);
            
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
            
            bool output_valid = validate_output(output_file, subtask, test_id, false);
            
            auto output_end = chrono::high_resolution_clock::now();
            auto output_duration = chrono::duration_cast<chrono::milliseconds>(output_end - output_start);
            
            if (!output_valid) {
                string msg = "输出文件验证失败: " + output_file;
                cout << "❌ " << msg << " (" << output_duration.count() << " ms)" << endl;
                failed_tests.push_back(msg);
                continue;
            }
            
            auto total_duration = chrono::duration_cast<chrono::milliseconds>(input_duration + output_duration);
            
            cout << "✓ 通过 (|s|=" << len_s << ", |t|=" << len_t << ", n=" << n << ") (" << total_duration.count() << " ms)" << endl;
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
    
    string input_file = "string" + to_string(subtask) + "_" + to_string(test_id) + ".in";
    string output_file = "string" + to_string(subtask) + "_" + to_string(test_id) + ".ans";
    
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
    int len_s = 0, len_t = 0, n = 0;
    auto input_start = chrono::high_resolution_clock::now();
    
    bool input_valid = validate_input(input_file, len_s, len_t, n, spec, subtask, test_id, verbose);
    
    auto input_end = chrono::high_resolution_clock::now();
    auto input_duration = chrono::duration_cast<chrono::milliseconds>(input_end - input_start);
    
    if (!input_valid) {
        cout << "❌ 输入文件验证失败 (" << input_duration.count() << " ms)" << endl;
        return;
    }
    
    cout << "✅ 输入文件验证通过 (|s|=" << len_s << ", |t|=" << len_t << ", n=" << n << ") (" << input_duration.count() << " ms)" << endl;
    
    // 验证输出文件
    auto output_start = chrono::high_resolution_clock::now();
    
    bool output_valid = validate_output(output_file, subtask, test_id, verbose);
    
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
    // 设置中文输出支持
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
            string input_file = "string" + to_string(subtask) + "_" + to_string(test_id) + ".in";
            string output_file = "string" + to_string(subtask) + "_" + to_string(test_id) + ".ans";
            
            cout << "  测试点 " << test_id << ": ";
            
            if (!file_exists(input_file) || !file_exists(output_file)) {
                cout << "❌ 文件不存在" << endl;
                continue;
            }
            
            int len_s = 0, len_t = 0, n = 0;
            bool input_valid = validate_input(input_file, len_s, len_t, n, spec, subtask, test_id, false);
            bool output_valid = validate_output(output_file, subtask, test_id, false);
            
            if (input_valid && output_valid) {
                cout << "✓ 通过 (|s|=" << len_s << ", |t|=" << len_t << ", n=" << n << ")" << endl;
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
        cout << "  子任务2,3,5,7: s和t不含'?'" << endl;
        cout << "  其他子任务: 无特殊性质" << endl;
        return 1;
    }
    
    return 0;
}
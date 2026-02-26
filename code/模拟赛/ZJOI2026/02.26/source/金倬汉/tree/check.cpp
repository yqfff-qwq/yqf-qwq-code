#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// 随机数据生成器
void generate_data(int n, int v) {
    ofstream fout("tree.in");
    fout << n << "\n";
    for (int i = 1; i <= n; i++) {
        // 保证形成以 0 为根的树，直接令父节点 p 随机在 [0, i-1] 之间即可
        int p = rand() % i; 
        int w = rand() % v + 1; // 随机容量 [1, V]
        fout << p << " " << w << "\n";
    }
    fout.close();
}

int main(int argc, char* argv[]) {
    // 检查参数
    if (argc != 3) {
        cout << "Usage: ./check <N> <V>\n";
        cout << "Example: ./check 15 10\n";
        return 1;
    }
    
    int N = stoi(argv[1]);
    int V = stoi(argv[2]);
    srand(time(nullptr));

    cout << "[1/2] Compiling tree.cpp..." << endl;
    if (system("g++ tree.cpp -o tree_test -O2 -std=c++14")) {
        cout << "Error: Failed to compile tree.cpp!" << endl;
        return 1;
    }
    
    cout << "[2/2] Compiling brute.cpp..." << endl;
    if (system("g++ brute.cpp -o brute_test -O2 -std=c++14")) {
        cout << "Error: Failed to compile brute.cpp!" << endl;
        return 1;
    }

    cout << "--------------------------------------" << endl;
    cout << "Start testing with max N=" << N << ", max V=" << V << endl;

    int test_cases = 0;
    while (true) {
        test_cases++;
        int current_n = rand() % N + 1;
        
        // 1. 生成随机数据
        generate_data(current_n, V);

        // 2. 运行被测代码（你的 tree.cpp 编译出的是 tree_test）
        system("./tree_test");
        system("mv tree.out tree_fast.out"); // 备份结果防止被覆盖

        // 3. 运行暴力验证代码
        system("./brute_test");
        system("mv tree.out tree_brute.out"); // 备份结果防止被覆盖

        // 4. 使用 diff 比较差异（-b -B 忽略空格和空行）
        if (system("diff -b -B tree_fast.out tree_brute.out > diff.log")) {
            cout << "❌ Wrong Answer on Test Case " << test_cases << "!" << endl;
            cout << "Check [tree.in] for the input." << endl;
            cout << "Check [tree_fast.out] for your output." << endl;
            cout << "Check [tree_brute.out] for the expected output." << endl;
            break;
        }
        
        if (test_cases % 10 == 0) {
            cout << "✅ Accepted " << test_cases << " cases..." << endl;
        }
    }

    return 0;
}
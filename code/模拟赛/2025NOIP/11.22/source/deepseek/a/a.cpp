#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

// 数字映射：0->0, 1->2, 2->3, 3->6, 4->7, 5->8, 6->9
int mapping[7] = {0, 2, 3, 6, 7, 8, 9};

long long solve(long long n) {
    if (n == 1) return 0; // 第1小的是0
    
    n--; // 从0开始计数
    
    // 转换为七进制
    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 7);
        n /= 7;
    }
    
    // 反转并映射到实际数字
    long long result = 0;
    for (int i = digits.size() - 1; i >= 0; i--) {
        result = (result * 10 + mapping[digits[i]]) % MOD;
    }
    
    return result;
}

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        long long n;
        cin >> n;
        cout << solve(n) << '\n';
    }
    
    return 0;
}

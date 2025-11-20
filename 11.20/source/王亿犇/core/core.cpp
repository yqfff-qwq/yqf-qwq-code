#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace W1ngD1nGa5ter {

class Process {
  // std::vector<long long> fact, ifac;
  long long C(long long n, long long m) {
    if (n < m || m < 0) {
      return 0;
    }
    long long res{1};
    for (long long i{n}; i > n - m; --i) {
      res *= i;
    }
    for (long long i{m}; i; --i) {
      res /= i;
    }
    return res;
    // return fact[n] / (fact[n - m] * fact[m]);
  }

public:
  // Process() {
  //   constexpr int maxn = 1000000;
  //   fact.resize(maxn + 1);
  //   for (int i{}; i < maxn; ++i) {
  //     fact[i] = fact[i - 1] * i;
  //   }
  // }
  int operator()() {
    int id;
    std::cin >> id;
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::string> a(n), b(m);
    std::vector<int> rest_a(n), rest_b(m);
    for (int i{}; i < n; ++i) {
      std::cin >> a[i];
      rest_a[i] = 0;
      for (char c : a[i]) {
        if (c == '(') {
          ++rest_a[i];
        } else if (rest_a[i] > 0) {
          --rest_a[i];
        } else {
          --i;
          --n;
          break;
        }
      }
    }
    for (int i{}; i < m; ++i) {
      std::cin >> b[i];
      std::reverse(b.begin(), b.end());
      rest_b[i] = 0;
      for (char c : b[i]) {
        if (c == ')') {
          ++rest_a[i];
        } else if (rest_b[i] > 0) {
          --rest_b[i];
        } else {
          --i;
          --m;
          break;
        }
      }
    }
    long long ans{};
    for (int i{}; i < n; ++i) {
      for (int j{}; j < m; ++j) {
        long long rest = k - (a[i].length() + b[j].length());
        if (rest < 0) {
          continue;
        }
        // int l_bracket = (rest - (rest_a[i] - rest_b[j])) >> 1;
        // int r_bracket = (rest + (rest_a[i] - rest_b[j])) >> 1;
        // auto dfs = [](auto &&dfs, int lrest, int rrest, int cur, int limit, int left) -> int {
        //   if (lrest == 0 && rrest == 0) {
        //     return 1;
        //   }
        //   if (limit < left) {
        //     return 0;
        //   }
        //   int res{};
        //   if (lrest) {
        //     res += dfs(dfs, lrest - 1, rrest, cur);
        //   }
        // };
        long long pair = (rest - (rest_a[i] + rest_b[j])) >> 1;
        long long all = rest_a[i] + rest_b[j];
        ans += (pair + 1) * pair / 2 * C(all + pair, pair);
      }
    }
    std::cout << ans << '\n';
    return 0;
  }
};

} // namespace W1ngD1nGa5ter

int main() {
  if (std::freopen("core.in", "r", stdin) == nullptr ||
      std::freopen("core.out", "w", stdout) == nullptr) {
    return 1;
  }
  std::cin.tie(nullptr)->sync_with_stdio(false);
  W1ngD1nGa5ter::Process Main;
  int _T{1};
  // std::cin >> _T;
  while (_T--) {
    Main();
  }
  std::cout << std::flush;
  return 0;
}
#include <iostream>
#include <vector>

namespace W1ngD1nGa5ter {
class Process {
  static constexpr int MOD = 998244353;
  static constexpr int BASE = 7;
  static constexpr int MAP[BASE] {0, 2, 3, 6, 7, 8, 9};
public:
  int operator()() {
    long long n;
    std::cin >> n;
    --n;
    std::vector<int> a;
    long long ans{};
    while (n) {
      a.emplace_back(MAP[n % BASE]);
      n /= BASE;
    }
    while (!a.empty()) {
      ans = ((ans << 3) + (ans << 1) + a.back()) % MOD;
      a.pop_back();
    }
    std::cout << ans << '\n';
    return 0;
  }
};
} // namespace W1ngD1nGa5ter

int main() {
  if (std::freopen("a.in", "r", stdin) == nullptr ||
      std::freopen("a.out", "w", stdout) == nullptr)
    return 1;
  std::cin.tie(nullptr)->sync_with_stdio(false);
  W1ngD1nGa5ter::Process Main;
  int _t{1};
  std::cin >> _t;
  while (_t--) {
    int ret = Main();
    if (ret)
      return ret;
  }
  std::cout << std::flush;
  return 0;
}
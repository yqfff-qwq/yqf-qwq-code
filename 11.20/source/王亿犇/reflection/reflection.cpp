#include <iostream>
#include <vector>

namespace W1ngD1nGa5ter {

class Process {
public:
  int operator()() {
    int n, q, c;
    std::cin >> n >> q >> c;
    std::vector<int> a(n);
    for (int i{}; i < n; ++i) {
      std::cin >> a[i];
    }
    int ans{};
    while (q--) {
      int l, r, x;
      std::cin >> l >> r >> x;
      l ^= c * ans, r ^= c * ans, x ^= c * ans;
      ans = x;
      for (int i{l}; i <= r; ++i) {
        ans = abs(ans - a[i - 1]);
      }
      std::cout << ans << '\n';
    }
    return 0;
  }
};

} // namespace W1ngD1nGa5ter

int main() {
  if (std::freopen("reflection.in", "r", stdin) == nullptr ||
      std::freopen("reflection.out", "w", stdout) == nullptr) {
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
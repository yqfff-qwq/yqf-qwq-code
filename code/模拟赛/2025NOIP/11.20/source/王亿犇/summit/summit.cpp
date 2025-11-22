#include <iostream>
#include <limits>
#include <vector>

namespace W1ngD1nGa5ter {

class Process {
public:
  int operator()() {
    int n, l, r;
    std::cin >> n >> l >> r;
    std::vector<int> a(n), b(n);
    for (int i{}; i < n; ++i) {
      std::cin >> a[i];
    }
    for (int i{}; i < n; ++i) {
      std::cin >> b[i];
    }
    std::vector<std::vector<long long>> f(
        n + 1,
        std::vector<long long>(n + 1, std::numeric_limits<long long>::max()));
    for (int i{}; i < n; ++i) {
      for (int j{i}; j < n; ++j) {
        f[i][j] = a[i] + b[j];
      }
    }
    if (l == 1) {
      long long ans{std::numeric_limits<long long>::max()};
      for (int i{}; i < n; ++i) {
        for (int j{i}; j < n; ++j) {
          ans = std::min(ans, f[i][j]);
        }
      }
      std::cout << ans << " \n";
    }
    for (int cnt{2}; cnt <= r; ++cnt) {
      std::vector<std::vector<long long>> g(
          n + 1,
          std::vector<long long>(n + 1, std::numeric_limits<long long>::max()));
      long long ans{std::numeric_limits<long long>::max()};
      for (int i{}; i < n; ++i) {
        for (int j{i}; j < n; ++j) {
          for (int k{}; k < i; ++k) {
            for (int l{k}; l < j; ++l) {
              g[i][j] = std::min(g[i][j], f[k][l]);
            }
          }
          if (g[i][j] == std::numeric_limits<long long>::max()) {
            continue;
          }
          ans = std::min(ans, g[i][j] += a[i] + b[j]);
        }
      }
      f = std::move(g);
      if (cnt >= l) {
        std::cout << ans << " \n";
      }
    }
    return 0;
  }
};

} // namespace W1ngD1nGa5ter

int main() {
  if (std::freopen("summit.in", "r", stdin) == nullptr ||
      std::freopen("summit.out", "w", stdout) == nullptr) {
    return 1;
  }
  std::cin.tie(nullptr)->sync_with_stdio(false);
  W1ngD1nGa5ter::Process Main;
  int _T{1};
  std::cin >> _T;
  while (_T--) {
    Main();
  }
  std::cout << std::flush;
  return 0;
}
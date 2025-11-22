#include <iostream>
#include <vector>

namespace W1ngD1nGa5ter {

class Process {
public:
  int operator()() {
    int n, mod;
    std::cin >> n >> mod;
    std::vector<std::vector<int>> e(n + 1);
    std::vector<int> a(n + 1);
    std::vector<std::vector<int>> res(n + 1, std::vector<int>(n + 1));
    std::vector<int> mem(n + 1);
    auto ans = [&](int k) {
      if (k > n) {
        return;
      }
    };
    auto dfs = [&](auto &&dfs, int idx) -> void {
      if (!idx) {
        std::fill(mem.begin(), mem.end(), 0);
        ans(1);
        for (size_t i{1}; i < mem.size(); ++i) {
          ++res[i][mem[i]];
          if (res[i][mem[i]] >= mod) {
            res[i][mem[i]] -= mod;
          }
        }
        return;
      }
      for (int i{}; i < idx; ++i) {
        a[idx] = i;
        e[a[idx]].emplace_back(i);
        dfs(dfs, idx - 1);
        e[a[idx]].pop_back();
      }
    };
    dfs(dfs, n - 1);
    for (int k{1}; k <= n; ++k) {
      for (int m{1}; m <= n; ++m) {
        std::cout << res[k][m] << " \n"[m == n];
      }
    }
    return 0;
  }
};

} // namespace W1ngD1nGa5ter

int main() {
  if (std::freopen("d.in", "r", stdin) == nullptr ||
      std::freopen("d.out", "w", stdout) == nullptr)
    return 1;
  std::cin.tie(nullptr)->sync_with_stdio(false);
  W1ngD1nGa5ter::Process Main;
  int _T{1};
  // std::cin >> _T;
  while (_T--) {
    int ret = Main();
    if (ret)
      return ret;
  }
  std::cout << std::flush;
  return 0;
}
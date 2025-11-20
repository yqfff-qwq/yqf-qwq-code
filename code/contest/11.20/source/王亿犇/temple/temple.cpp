#include <algorithm>
#include <iostream>
#include <vector>

namespace W1ngD1nGa5ter {

class Process {
public:
  int operator()() {
    int n, base, mod;
    std::cin >> n >> base >> mod;
    std::vector<int> a(n + 1);
    for (int i{1}; i <= n; ++i) {
      std::cin >> a[i];
    }
    std::vector<std::vector<int>> e(n + 1);
    for (int i{1}; i < n; ++i) {
      int x, y;
      std::cin >> x >> y;
      e[x].emplace_back(y);
      e[y].emplace_back(x);
    }
    std::vector<bool> vis(n + 1);
    auto dfs = [&a, &e, &vis](auto &&dfs, int u, int fa, int tar) -> bool {
      if (vis[a[u]]) {
        return false;
      }
      vis[a[u]] = true;
      if (u == tar) {
        return true;
      }
      for (int v : e[u]) {
        if (v == fa) {
          continue;
        }
        if (dfs(dfs, v, u, tar)) {
          return true;
        }
      }
      vis[a[u]] = false;
      return false;
    };
    int hashans{};
    int q;
    std::cin >> q;
    for (int i{1}; i <= q; ++i) {
      int u, v;
      std::cin >> u >> v;
      u ^= hashans, v ^= hashans;
      bool ans{};
      std::fill(vis.begin(), vis.end(), false);
      ans = !dfs(dfs, u, u, v);
      std::cout << (ans ? "Yes" : "No") << '\n';
      hashans = (hashans * base + ans) % mod;
    }
    return 0;
  }
};

} // namespace W1ngD1nGa5ter

int main() {
  if (std::freopen("temple.in", "r", stdin) == nullptr ||
      std::freopen("temple.out", "w", stdout) == nullptr) {
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
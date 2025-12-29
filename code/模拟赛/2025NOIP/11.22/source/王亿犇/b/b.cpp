#include <iostream>
#include <queue>
#include <vector>

namespace W1ngD1nGa5ter {

class Process {
  static constexpr int MOD = 998244353;

public:
  int operator()() {
    int n, m, k, s1, s2;
    std::cin >> n >> m >> k >> s1 >> s2;
    std::vector<std::vector<int>> e(n + 1);
    for (int i{}; i < m; ++i) {
      int u, v;
      std::cin >> u >> v;
      e[u].emplace_back(v);
      e[v].emplace_back(u);
    }
    {
      std::vector<int> deg(n + 1);
      for (int u{1}; u <= n; ++u) {
        deg[u] = e[u].size();
      }
      std::queue<int> q;
      for (int i{1}; i <= n; ++i) {
        if (deg[i] <= k) {
          q.emplace(i);
        }
      }
      int rest{n};
      std::vector<bool> vis(n + 1);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = true;
        --rest;
        for (int v : e[u]) {
          if (--deg[v] == k) {
            q.emplace(v);
          }
        }
      }
      if (rest) {
        for (int i{1}; i <= n; ++i) {
          if (!vis[i]) {
            std::cout << i << ' ';
          }
        }
        std::cout << '\n';
        return 0;
      }
    }
    std::vector<int> a(n + 1);
    for (int i{1}; i <= n; ++i) {
      std::cin >> a[i];
    }
    int q = s1 + s2;
    while (q-- && s2) {
      int op;
      std::cin >> op;
      switch (op) {
      case 1: {
        --s1;
        int x, y;
        std::cin >> x >> y;
        a[x] = y;
      } break;
      case 2: {
        --s2;
        int x, y;
        std::cin >> x >> y;
        std::vector<int> f(y + 1);
        f[0] = 1;
        for (int i : e[x]) {
          for (int j{y}; j >= a[i]; --j) {
            f[j] = (f[j] + f[j - a[i]]) % MOD;
          }
        }
        std::cout << f[y] << '\n';
      } break;
      default:
        return 1;
      }
    }
    return 0;
  }
};

} // namespace W1ngD1nGa5ter

int main() {
  if (std::freopen("b.in", "r", stdin) == nullptr ||
      std::freopen("b.out", "w", stdout) == nullptr)
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
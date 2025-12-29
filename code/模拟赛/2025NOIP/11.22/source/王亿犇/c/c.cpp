#include <iostream>
#include <vector>

namespace W1ngD1nGa5ter {

class Process {
public:
  int operator()() {
    int n, v, p;
    std::cin >> n >> v >> p;
    v = std::min(v, n - 1);
    long long ans{};
    std::vector<int> a(n + 1);
    std::vector<std::vector<int>> e(n + 1);
    auto check = [&]() -> void {
      for (int i{1}; i <= n; ++i) {
        std::vector<int> dis(n + 1);
        auto distance = [&](auto &&dfs, int u, int fa) -> void {
          for (int v : e[u]) {
            if (v == fa) {
              continue;
            }
            dis[v] = dis[u] + 1;
            dfs(dfs, v, u);
          }
        };
        distance(distance, i, i);
        for (int j{1}; j < i; ++j) {
          // int inner = dis[j] - 1;
          int outer = n - dis[j] - 1;
          // std::cerr << i << ' ' << j << '\n';
          // std::cerr << outer << '\n';
          for (int k{std::max(0, outer) + 2}; k <= v; ++k) {
            // int rest = n - k;
            // int number_rest = k - outer;
            long long cur{1};
            for (int x{k - 2}; x > k - 2 - outer; --x) {
              cur *= x;
            }
            for (int x{outer}; outer; --outer) {
              cur /= x;
            }
            cur %= p;
            int rest{n - k};
            long long tmp{k - outer};
            // std::cerr << rest << ' ' << tmp << '\n';
            while (rest) {
              if (rest & 1) {
                cur = cur * tmp % p;
              }
              tmp = tmp * tmp % p;
              rest >>= 1;
            }
            ans = ((cur << 1) % p + ans) % p;
            // (ans += C(k - 2, outer) * pow(number_rest, rest) % p) %= p;
          }
        }
      }
    };
    auto dfs = [&](auto &&dfs, int idx) -> void {
      if (!idx) {
        check();
      }
      for (int i{}; i < idx; ++i) {
        a[idx] = i;
        e[a[idx]].emplace_back(i);
        e[i].emplace_back(a[idx]);
        dfs(dfs, idx - 1);
        e[a[idx]].pop_back();
        e[i].pop_back();
      }
    };
    dfs(dfs, n - 1);
    std::cout << ans << '\n';
    return 0;
  }
};

} // namespace W1ngD1nGa5ter

int main() {
  if (std::freopen("c.in", "r", stdin) == nullptr ||
      std::freopen("c.out", "w", stdout) == nullptr)
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
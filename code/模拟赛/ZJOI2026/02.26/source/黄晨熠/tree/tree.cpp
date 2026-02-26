#include <bits/stdc++.h>

using u32 = unsigned;
using u64 = unsigned long long;
using i64 = long long;

constexpr i64 inf = 1E18;

int main() {
  freopen("tree.in", "r", stdin);
  freopen("tree.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> p(n + 1), w(n + 1);
  std::vector<std::vector<int>> adj(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i] >> w[i];
    adj[p[i]].push_back(i);
  }

  std::vector<i64> f(n + 1);
  for (int i = n; i; i--) {
    f[i] += w[i];
    f[p[i]] += f[i];
  }

  const int logn = std::__lg(n) + 1;
  std::vector<std::vector<int>> fa(n + 1, std::vector<int>(logn, -1));
  std::vector<std::vector<i64>> val(n + 1, std::vector<i64>(logn));

  std::vector<i64> d(n + 1), lim(n + 1);
  std::vector<std::vector<i64>> vec(n + 1);
  std::vector<std::vector<i64>> sum(n + 1);
  for (int i = 0; i <= n; i++) {
    i64 s = 0;
    for (auto j : adj[i]) {
      vec[i].push_back(f[j]);
      s += f[j];
    }
    std::sort(vec[i].begin(), vec[i].end());
    sum[i].resize(vec[i].size() + 1);
    for (int j = 0; j < vec[i].size(); j++) {
      sum[i][j + 1] = sum[i][j] + vec[i][j];
    }
    if (!vec[i].empty()) {
      d[i] = s - vec[i].back();
      lim[i] = vec[i].size() > 1 ? vec[i][vec[i].size() - 2] : -inf;
    }
  }

  for (int i = 1; i <= n; i++) {
    d[i] += d[p[i]];
  }
  for (int i = 0; i <= n; i++) {
    lim[i] += d[i];
    val[i][0] = lim[i];
  }

  for (int i = 1; i <= n; i++) {
    fa[i][0] = p[i];
    for (int j = 1; j < logn && fa[i][j - 1] != -1; j++) {
      fa[i][j] = fa[fa[i][j - 1]][j - 1];
      val[i][j] = std::max(val[i][j - 1], val[fa[i][j - 1]][j - 1]);
    }
  }

  auto calc = [&](int x, i64 c) {
    int it = lower_bound(vec[x].begin(), vec[x].end(), c) - vec[x].begin();
    i64 ans = sum[x][it];
    ans += 1LL * (vec[x].size() - it) * c;
    // ans -= c;
    return ans;
  };

  for (int i = 1; i <= n; i++) {
    i64 c = f[i];
    int x = i;
    while (true) {
      for (int j = logn - 1; j >= 0; j--) {
        if (fa[x][j] >= 1 && c + d[p[x]] > val[p[x]][j]) {
          c += d[p[x]] - d[fa[p[x]][j]];
          x = fa[x][j];
        }
      }
      x = p[x];
      c = calc(x, c);
      if (x == 0) {
        break;
      }
    }
    std::cout << c << "\n";
  }

  return 0;
}
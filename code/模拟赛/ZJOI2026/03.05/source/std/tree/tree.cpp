#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

constexpr i64 inf = 1E18;

void chkmax(i64 &x, i64 y) {
  if (x < y) {
    x = y;
  }
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k, t;
  std::cin >> n >> k >> t;

  std::vector<int> c(n), v(n);
  std::vector<i64> s(n);
  for (int i = 0; i < n; i++) {
    std::cin >> c[i] >> v[i];
    s[i] = v[i];
  }

  std::vector<int> p(n, -1);
  std::vector<std::vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    std::cin >> p[i];
    p[i]--;
    s[i] += s[p[i]];
    adj[p[i]].push_back(i);
  }

  int cur = 0;
  std::vector<int> e(n * 2);
  std::vector<int> l(n), r(n);
  auto dfs = [&](auto self, int x) -> void {
    l[x] = cur;
    e[cur++] = x;
    for (auto y : adj[x]) {
      self(self, y);
    }
    r[x] = cur;
    e[cur++] = x;
  };
  dfs(dfs, 0);

  std::vector<std::vector<i64>> sum(n);

  auto merge = [&](auto f, auto g) {
    int n = f.size(), m = g.size();
    std::vector<i64> h(n + m);
    int i = 0, j = 0;
    while (i < n || j < m) {
      if (j == m || (i < n && f[i] > g[j])) {
        h[i + j] = f[i];
        i++;
      } else {
        h[i + j] = g[j];
        j++;
      }
    }
    while (h.size() > t) {
      h.pop_back();
    }
    return h;
  };

  for (int i = n - 1; i >= 0; i--) {
    sum[i].push_back(s[i]);
    for (auto j : adj[i]) {
      sum[i] = merge(sum[i], sum[j]);
    }
  }

  for (int i = 0; i < n; i++) {
    sum[i].insert(sum[i].begin(), 0);
    sum[i].resize(t + 1);
    for (int j = 1; j <= t; j++) {
      sum[i][j] += sum[i][j - 1];
    }
  }

  std::vector f(n * 2 + 1, std::vector(k + 1, std::vector<i64>(t + 1, -inf)));
  f[0][k][t] = 0;
  for (int i = 0; i < n * 2; i++) {
    if (l[e[i]] == i) {
      for (int l = 0; l <= t; l++) {
        std::deque<int> q;
        for (int j = k; j >= 0; j--) {
          if (!q.empty() && q.front() - j > c[e[i]] - l) {
            q.pop_front();
          }
          if (!q.empty()) {
            chkmax(f[i + 1][j][l], f[i][q.front()][l] + 1LL * (q.front() - j) * v[e[i]]);
          }
          while (!q.empty() && f[i][q.back()][l] + 1LL * (q.back() - j) * v[e[i]] < f[i][j][l]) {
            q.pop_back();
          }
          q.push_back(j);
        }
      }
      int cur = r[e[i]] + 1;
      for (int j = 0; j <= k; j++) {
        auto solve = [&](auto self, int l, int r, int L, int R) -> void {
          if (l > r) {
            return;
          }
          int m = (l + r) / 2, p;
          i64 v = -inf;
          for (int x = std::max(m, L); x <= R; x++) {
            if (v < f[i][j][x] + sum[e[i]][x - m]) {
              p = x;
              v = f[i][j][x] + sum[e[i]][x - m];
            }
          }
          chkmax(f[cur][j][m], v);
          self(self, l, m - 1, L, p);
          self(self, m + 1, r, p, R);
        };
        solve(solve, 0, t, 0, t);
      }
    } else {
      for (int l = 0; l <= t; l++) {
        std::deque<int> q1, q2;
        for (int j = k; j >= 0; j--) {
          while (!q1.empty() && f[i][q1.back()][l] + 1LL * (q1.back() - j) * v[e[i]] < f[i][j][l]) {
            q1.pop_back();
          }
          q1.push_back(j);
          if (!q1.empty() && q1.front() - j > l) {
            q1.pop_front();
          }
          if (!q1.empty()) {
            chkmax(f[i + 1][j][l], f[i][q1.front()][l] + 1LL * (q1.front() - j) * v[e[i]]);
          }
          while (!q2.empty() && f[i][q2.back()][l] + 1LL * (q2.back() - j) * v[e[i]] < f[i][j][l]) {
            q2.pop_back();
          }
          q2.push_back(j);
          if (!q2.empty() && q2.front() - j >= l) {
            q2.pop_front();
          }
          if (!q2.empty()) {
            chkmax(f[i + 1][j][l - 1], f[i][q2.front()][l] + 1LL * (q2.front() - j) * v[e[i]] + s[e[i]]);
          }
        }
      }
    }
  }
  i64 ans = -inf;
  for (int i = 0; i <= k; i++) {
    ans = std::max(ans, f[n * 2][i][0]);
  }
  std::cout << ans << "\n";

  return 0;
}
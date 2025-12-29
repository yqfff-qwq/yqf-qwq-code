#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

struct DSU {
  std::vector<int> l, r, val;
  DSU(int n) : l(n), r(n), val(n) {
    std::iota(l.begin(), l.end(), 0);
    std::iota(r.begin(), r.end(), 0);
  }
  void init(int n) {
    for (int i = 0; i < n; i++) {
      l[i] = r[i] = i;
      val[i] = 0;
    }
  }
  int find(int x) {
    if (r[x] != x) r[x] = find(r[x]);
    return r[x];
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    val[x] += val[y], r[y] = x, l[x] = l[y];
    return true;
  }
};

int main() {
  freopen("photo.in", "r", stdin);
  freopen("photo.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, t;
  std::cin >> n >> t;

  std::vector<int> v;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i] >> b[i];
    a[i]--;
    b[i] -= t;
    v.push_back(a[i]);
    v.push_back(b[i]);
  }
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());

  const int m = v.size();
  std::vector<std::vector<int>> vec(m);
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    b[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin();
    vec[a[i]].push_back(b[i]);
  }

  DSU dsu(m);
  std::vector<int> dis(m), tmp(m);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      tmp[j] = dis[j];
    }
    int u = 0;
    for (int j = 1; j < m; j++) {
      if (dis[j] > dis[u] + (v[j] - v[u] + t - 1) / t) {
        dis[j] = dis[u] + (v[j] - v[u] + t - 1) / t;
      }
      if (dis[u] - v[u] / t > dis[j] - v[j] / t || dis[u] - v[u] / t == dis[j] - v[j] / t && v[u] % t < v[j] % t) {
        u = j;
      }
    }
    dsu.init(m);
    for (int j = m - 2; j >= 0; j--) {
      for (auto k : vec[j]) {
        int x = dsu.find(k);
        dsu.val[x]--;
        for (int p = dsu.l[x] - 1; p > j; p = dsu.l[p] - 1) {
          if (dis[p] > dis[x] + dsu.val[x]) {
            dsu.merge(x, p);
          } else {
            break;
          }
        }
      }
      int x = dsu.find(j + 1);
      dis[j] = std::min(dis[j], dis[x] + dsu.val[x]);
    }
    bool ok = true;
    for (int i = 0; i < m; i++) {
      ok = ok && (dis[i] == tmp[i]);
    }
    if (ok) {
      std::cout << "yes\n";
      int lst = -1;
      std::vector<int> c;
      for (int i = 0; i + 1 < m; i++) {
        int x = dis[i + 1] - dis[i];
        for (int j = 0; j < x; j++) {
          if (lst == -1) {
            lst = v[i] + 1;
          } else {
            lst = std::max(v[i] + 1, lst + t);
          }
          c.push_back(lst);
        }
      }
      std::vector<int> ord(n);
      std::iota(ord.begin(), ord.end(), 0);
      std::sort(ord.begin(), ord.end(),
        [&](int x, int y) {
          return a[x] < a[y];
        });
      std::vector<int> ans(n);
      std::priority_queue<std::array<int, 2>> h;
      for (int i = 0, j = 0; i < n; i++) {
        while (j < n && v[a[ord[j]]] + 1 <= c[i]) {
          h.push({-b[ord[j]], ord[j]});
          j++;
        }
        int y = h.top()[1];
        h.pop();
        ans[y] = c[i];
      }
      for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
      }
      return 0;
    }
    if (dis[m - 1] < 0) {
      std::cout << "no\n";
      return 0;
    }
  }
  
  std::cout << "no\n";

  return 0;
}
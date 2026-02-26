#include <bits/stdc++.h>

using u32 = unsigned;
using u64 = unsigned long long;
using i64 = long long;

struct DSU {
  std::vector<int> p, sz;
  DSU(int n) : p(n), sz(n, 1) {
    std::iota(p.begin(), p.end(), 0);
  }
  int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    sz[x] += sz[y], p[y] = x;
    return true;
  }
  int size(int x) {
    return sz[find(x)];
  }
};

constexpr int N = 2E5;

int cur = 0;
DSU dsu(N);
std::vector<std::array<int, 2>> a[N * 4];

struct Node {
  int mx = -1;
} tr[N * 4];

Node operator+ (Node a, Node b) {
  Node c;
  c.mx = std::max(a.mx, b.mx);
  return c;
}

void pull(int p) {
  tr[p] = tr[p * 2] + tr[p * 2 + 1];
}

int L, R;

void insert(int p, int l, int r) {
  if (l == r) {
    a[p].push_back({R, cur});
    tr[p].mx = R;
    return;
  }
  int m = (l + r) / 2;
  if (L <= m) {
    insert(p * 2, l, m);
  } else {
    insert(p * 2 + 1, m + 1, r);
  }
  pull(p);
}

void modify0(int p, int l, int r, int x, int y) {
  int c = tr[p].mx;
  if (l > x || c <= x) {
    return;
  }
  if (l == r) {
    while (!a[p].empty()) {
      auto [q, id] = a[p].back();
      if (x == l && y == q) {
        break;
      }
      if (x < q) {
        a[p].pop_back();
        L = std::min(L, l);
        R = std::max(R, q);
        dsu.merge(cur, id);
      } else {
        break;
      }
    }
    tr[p].mx = a[p].empty() ? -1 : a[p].back()[0];
    return;
  }
  int m = (l + r) / 2;
  modify0(p * 2, l, m, x, y);
  modify0(p * 2 + 1, m + 1, r, x, y);
  pull(p);
}

void modify1(int p, int l, int r, int x, int y) {
  int c = tr[p].mx;
  if (l >= y || c < y) {
    return;
  }
  if (l == r) {
    while (!a[p].empty()) {
      auto [q, id] = a[p].back();
      if (x == l && y == q) {
        break;
      }
      if (y <= q) {
        a[p].pop_back();
        L = std::min(L, l);
        R = std::max(R, q);
        dsu.merge(cur, id);
      } else {
        break;
      }
    }
    tr[p].mx = a[p].empty() ? -1 : a[p].back()[0];
    return;
  }
  int m = (l + r) / 2;
  modify1(p * 2, l, m, x, y);
  modify1(p * 2 + 1, m + 1, r, x, y);
  pull(p);
}

int main() {
  freopen("interval.in", "r", stdin);
  freopen("interval.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> a;
  std::vector<int> op(n), x(n), y(n);
  for (int i = 0; i < n; i++) {
    std::cin >> op[i] >> x[i] >> y[i];
    if (op[i] == 1) {
      a.push_back(x[i]);
      a.push_back(y[i]);
    }
  }
  std::sort(a.begin(), a.end());
  a.erase(std::unique(a.begin(), a.end()), a.end());

  for (int i = 0; i < n; i++) {
    if (op[i] == 1) {
      x[i] = lower_bound(a.begin(), a.end(), x[i]) - a.begin();
      y[i] = lower_bound(a.begin(), a.end(), y[i]) - a.begin();
    }
  }
  const int m = a.size();

  std::vector<int> cl(n), cr(n);
  for (int i = 0; i < n; i++) {
    if (op[i] == 1) {
      L = x[i];
      R = y[i];
      modify0(1, 0, m - 1, x[i], y[i]);
      modify1(1, 0, m - 1, x[i], y[i]);
      insert(1, 0, m - 1);
      cl[cur] = L;
      cr[cur] = R;
      cur++;
    } else {
      x[i]--;
      y[i]--;
      int px = dsu.find(x[i]), py = dsu.find(y[i]);
      if (px == py || (cl[px] >= cl[py] && cr[px] <= cr[py] && px <= py)) {
        std::cout << "YES\n";
      } else {
        std::cout << "NO\n";
      }
    }
  }

  return 0;
}
#include <bits/stdc++.h>
#define dbg(a...) fprintf(stderr, a)
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(1e6 + 5);
int n, m, a[N], pl[N], pr[N], pre[N];
struct FenwickTree {
  int c[N], t[N], cnt;
  void clear() {
    cnt++;
  }
  void add(int p, int x) {
    for (; p; p -= p & -p) {
      if (t[p] != cnt) t[p] = cnt, c[p] = 0;
      c[p] += x;
    }
  }
  int ask(int p) {
    int r = 0;
    for (; p <= n; p += p & -p) {
      if (t[p] != cnt) t[p] = cnt, c[p] = 0;
      r += c[p];
    }
    return r;
  }
} fen;
struct Data {
  int a, b, c, id, x;
  bool operator<(const Data &r) const {
    return a < r.a || a == r.a && id < r.id;
  }
} p[N << 1], q[N << 1];
int ans[N];
void solve(int l, int r) {
  if (l == r) return;
  int m = l + r >> 1;
  solve(l, m), solve(m + 1, r);
  int i = l, j = m + 1;
  fen.clear();
  for (int k = l; k <= r; k++) {
    if (j > r || i <= m && (p[i].b < p[j].b || p[i].b == p[j].b && p[i].id < p[j].id)) {
      q[k] = p[i++];
      if (q[k].id == -1) {
	fen.add(q[k].c, q[k].x);
      }
    } else {
      q[k] = p[j++];
      if (q[k].id != -1) {
	ans[q[k].id] += fen.ask(q[k].c);
      }
    }
  }
  for (int k = l; k <= r; k++) {
    p[k] = q[k];
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::vector<std::array<int, 3>> q(m);
  int tot = 0;
  for (int i = 0; i < m; i++) {
    auto &[r, l, id] = q[i];
    std::cin >> l >> r;
    id = i;
    p[++tot] = {l - 1, r, l, id, 0};
  }
  for (int i = 1; i <= n + 1; i++) {
    pl[i] = n + 1;
    pr[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    smin(pl[a[i]], i);
    pre[i] = pr[a[i]];
    smax(pr[a[i]], i);
  }
  
  for (int i = 1; i <= n; i++) {
    p[++tot] = {pre[i], std::max(pr[a[i] + 1], i), std::min(pl[a[i] + 1], i), -1, 1};
    // p[++tot] = {pre[i], i, i, -1, -1};
  }
  std::sort(p + 1, p + 1 + tot);
  solve(1, tot);
  // for (int i = 1; i <= tot; i++) {
  //   if (p[i].id == -1) continue;
  //   for (int j = 1; j <= tot; j++) {
  //     if (p[j].id != -1) continue;
  //     if (p[j].a <= p[i].a && p[j].b <= p[i].b && p[j].c >= p[i].c)
  // 	ans[p[i].id] += p[j].x;
  //   }
  // }
  int cnt = 0;
  for (int i = 1; i <= n; i++) cnt += pr[i] > 0;
  for (int i = 0; i < m; i++) ans[i] += cnt;
  std::sort(q.begin(), q.end());
  fen.clear();
  for (int i = 0, j = 0; i <= n && j < m; i++) {
    if (i && i == pr[a[i]]) fen.add(pl[a[i]], -1);
    while (j < m && q[j][0] == i) {
      auto [r, l, id] = q[j];
      ans[id] += fen.ask(l);
      j++;
    }
  }
  // std::cerr << "cnt = " << cnt << "\n";
  for (int i = 0; i < m; i++) std::cout << ans[i] << "\n";
  return 0;
}
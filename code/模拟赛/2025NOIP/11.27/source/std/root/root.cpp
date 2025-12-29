#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
  i64 n, m;
  std::cin >> n >> m;

  i64 ans = m / n;
  for (i64 k = m / n; k <= (m + n - 1) / n; k++) {
    if (((n - 1) ^ (1 + k * n)) <= m) {
      ans++;
    }
  }
  std::cout << ans << "\n";
}

int main() {
  freopen("root.in", "r", stdin);
  freopen("root.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
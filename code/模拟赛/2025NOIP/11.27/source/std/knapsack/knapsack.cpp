#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
  freopen("knapsack.in", "r", stdin);
  freopen("knapsack.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  i64 M;
  std::cin >> N >> M;

  std::vector<i64> v(N), m(N);
  for (int i = 0; i < N; i++) {
    std::cin >> v[i] >> m[i];
  }

  std::vector<int> ord(N);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(),
    [&](int i, int j) {
      return m[i] < m[j];
    });

  i64 ans = 0;
  std::vector<i64> f;
  for (int i = 0; i < N; i++) {
    int j = i;
    while (j < N && m[ord[i]] == m[ord[j]]) {
      f.push_back(v[ord[j]]);
      j++;
    }
    std::sort(f.begin(), f.end());
    M /= m[ord[i]] / (i ? m[ord[i - 1]] : 1);
    if (j < N) {
      i64 p = m[ord[j]] / m[ord[i]];
      i64 t = M % p;
      while (!f.empty() && t > 0) {
        ans += f.back();
        f.pop_back();
        t--;
      }
      i64 s = 0;
      std::reverse(f.begin(), f.end());
      std::vector<i64> nf;
      for (int i = 0; i < f.size(); i++) {
        s += f[i];
        if ((i + 1) % p == 0 || i == f.size() - 1) {
          nf.push_back(s);
          s = 0;
        }
      }
      f = nf;
    } else {
      while (!f.empty() && M > 0) {
        ans += f.back();
        f.pop_back();
        M--;
      }
    }
    i = j - 1;
  }
  std::cout << ans << "\n";

  return 0;
}
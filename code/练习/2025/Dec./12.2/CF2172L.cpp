// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define REP(i, l, r)  for(int i = (l);i <= (r);i++)
#define DEP(i, r, l)  for(int i = (r);i >= (l);i--)

void read(){}
template<typename T1, typename ...T2>inline void read(T1 &x, T2 &...oth) {
  x = 0;
  int ch = getchar(), f = 0;
  while(ch < '0' or '9' < ch) {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while('0' <= ch and ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  if(f) x = -x;
  read(oth...);
  return;
}

namespace YZLK{
  const int N = 3e3 + 10;
  const int inf = 1e9;
  int n, m, k;
  char c[N];
  int a[N];
  int f[N][N][2];
  int dp[N][N];
  int h[N];
  void main() {
    read(n, m, k);
    scanf("%s", c + 1);
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = 0;
    c[0] = '#';
    REP(i, 1, n)  a[i] = (c[i] != c[i - 1]);
    REP(i, 1, k) {
      int l = 0;
      for(int j = i;j <= n;j += k)  h[++l] = a[j];
      REP(j, 1, l)  REP(w, 0, min(m, l))  f[j][w][0] = f[j][w][1] = -inf;
      f[l][0][h[l]] = h[l];
      if ((n - k + 1) % k == i % k) f[l][1][h[l] ^ 1] = h[l] ^ 1;
      DEP(j, l, 2)
        REP(w, 0, min(l, m)){
          f[j - 1][w][h[j - 1]] = max(f[j - 1][w][h[j - 1]], max(f[j][w][0], f[j][w][1]) + h[j - 1]);
          if(h[j - 1])  f[j - 1][w + 1][0] = max(f[j - 1][w + 1][0], max(f[j][w][0] + 1, f[j][w][1] - 1));
          else          f[j - 1][w + 1][1] = max(f[j - 1][w + 1][1], max(f[j][w][0] + 1, f[j][w][1] - 1) + 1);
        }
      if (i == 1) {
        REP(w, 0, min(l, m))  f[1][w][0]++;
      }
      REP(j, 0, m) {
        REP(w, 0, min({j, m, l})) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - w] + max(f[1][w][1], f[1][w][0]));
        }
      }
    }
    int ans = 0;
    REP(i, 0, m)    ans = max(ans, dp[k][i]);
    cout << ans << "\n";
    return;
  }
}

signed main() {
//   freopen("knapsack.in", "r", stdin);
//   freopen("knapsack.out", "w", stdout);
  
  // cin.tie(nullptr) -> sync_with_stdio(false);
  int T = 1;
//   read(T);
  while(T--) {
    YZLK::main();
  }

  // fclose(stdin);
  // fclose(stdout);

  return 0;
}
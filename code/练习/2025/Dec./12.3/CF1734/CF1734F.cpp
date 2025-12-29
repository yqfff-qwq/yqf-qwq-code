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
  const int N = 1e2 + 10;
  int n, m;
  int a[N], b[N];
  int f[N][2][N][2];
  int dfs(int p, int x, int d, bool lim) {
    if (p == 60)  return !lim * (d ^ x);
    if (~f[p][x][d][lim]) return f[p][x][d][lim];
    int ans = 0;
    REP(i, 0, 1) {
      bool lm = (i > b[p] or lim and i >= b[p]);
      int s = (a[p] + i + d);
      ans += dfs(p + 1, x ^ (s + i & 1), s >= 2, lm);
    }
    return f[p][x][d][lim] = ans;
  }
  void main() {
    read(n, m);
    m--;
    REP(i, 0, 60) a[i] = ((n >> i) & 1), b[i] = ((m >> i) & 1); 
    memset(f, -1, sizeof(f));
    cout << dfs(0, 0, 0, 0) << "\n";
    return;
  }
}

signed main() {
//   freopen("knapsack.in", "r", stdin);
//   freopen("knapsack.out", "w", stdout);
  
  // cin.tie(nullptr) -> sync_with_stdio(false);
  int T = 1;
  read(T);
  while(T--) {
    YZLK::main();
  }

  // fclose(stdin);
  // fclose(stdout);

  return 0;
}
// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <random>
#include <string.h>
using namespace std;

// #define int long long
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
  const int M = 5e2 + 2;
  const int K = 251000;
  const int inf = 1e9;
  void Min(int &x, int y) {
    x = min(x, y);
    return;
  }
  int a[M];
  int n;
  int mxx = 0;
  int f[K + 10][3][3], g[K + 10][3][3];
  void main() {
    mxx = 0;
    read(n);
    memset(a, 0, sizeof(a));
    int r = 0, c = 0;
    REP(i, 1, n)  read(r, c), a[r] = max(a[r], c), mxx = max(mxx, r);

    REP(i, 0, K)
      REP(j, 0, 2)
        REP(k, 0, 2)  f[i][j][k] = g[i][j][k] = inf;
    int mx = 1;

    f[0][1][1] = 0;
    REP(i, 1, mxx) {
      REP(j, 0, mx - 1) {
        Min(g[j + 1 + a[i] * 2][1][1], f[j][1][1] + 1);
        Min(g[j + 1][1][1], f[j][1][1] + 1 + a[i] * 2);
        Min(g[j + 1][1][2], f[j][1][2] + 1 + a[i]);
        Min(g[j + 1 + a[i]][2][1], f[j][1][1] + 1);
        Min(g[j + 1 + a[i]][0][1], f[j][1][1] + 1);
        Min(g[j + 1][1][0], f[j][1][1] + 1 + a[i]);

        Min(g[j + 2 + a[i] * 2][2][2], f[j][2][2] + 2);
        Min(g[j + 2][2][2], f[j][2][2] + 2 + a[i] * 2);
        Min(g[j + 2][2][0], f[j][2][2] + 2 + a[i] * 2);
        Min(g[j + 2 + a[i] * 2][0][2], f[j][2][2] + 2);

        Min(g[j][0][1], f[j][0][1] + 1 + 2 * a[i]);
        Min(g[j][0][0], f[j][0][1] + 1 + a[i]);
        Min(g[j][0][2], f[j][0][1] + 1 + a[i]);

        Min(g[j + 1 + a[i] * 2][1][0], f[j][1][0]);
        Min(g[j + 1 + a[i]][2][0], f[j][1][0]);
        Min(g[j + 1 + a[i]][0][0], f[j][1][0]);

        Min(g[j + 2 + a[i] * 2][2][0], f[j][2][0]);
        Min(g[j + 2 + a[i] * 2][0][0], f[j][2][0]);

        Min(g[j][0][2], f[j][0][2] + 2 + a[i] * 2);
        Min(g[j][0][0], f[j][0][2] + 2 + a[i] * 2);

        Min(g[j + 1 + a[i] * 2][1][2], f[j][1][2] + 2);
        Min(g[j + 1][1][2], f[j][1][2] + 2 + a[i] * 2);
        Min(g[j + 1 + a[i]][0][2], f[j][1][2] + 2);
        Min(g[j + 1 + a[i]][2][2], f[j][1][2] + 2);
        Min(g[j + 1][1][0], f[j][1][2] + 2 + a[i] * 2);

        Min(g[j + 2 + a[i] * 2][2][1], f[j][2][1] + 1);
        Min(g[j + 2][2][1], f[j][2][1] + 1 + a[i] * 2);
        Min(g[j + 2][2][0], f[j][2][1] + 1 + a[i]);
        Min(g[j + 2][2][2], f[j][2][1] + 1 + a[i]);
        Min(g[j + 2 + a[i] * 2][0][1], f[j][2][1] + 1);

        
      }
      mx += 2 + 2 * a[i];
      mx = min(mx, K);
      REP(j, 0, mx)
        REP(k, 0, 2)
          REP(q, 0, 2) {
            f[j][k][q] = g[j][k][q];
            g[j][k][q] = inf;
          }
    }


    int ans = inf;
    REP(i, 0, K) ans = min(ans, max(i, f[i][0][0]));
    cout << ans << "\n";
    return;
  }
}


signed main() {
  freopen("couple.in", "r", stdin);
  freopen("couple.out", "w", stdout);
  
  // cin.tie(nullptr) -> sync_with_stdio(false);
  int T = 1;
  read(T);
  while(T--) {
    YZLK::main();
  }

  fclose(stdin);
  fclose(stdout);

  return 0;
}
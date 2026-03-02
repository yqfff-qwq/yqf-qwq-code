#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <bitset>
using namespace std;

#define REP(i,l,r)  for(int i = l;i <= r;i++)
#define DEP(i,r,l)  for(int i = r;i >= l;i--)
#define ll long long
#define pii std::pair<int, int>
#define pb push_back
#define fi first
#define se second

void read(){}
template<typename T1, typename ...T2>inline void read(T1 &x, T2 &...oth) {
  x = 0;
  int ch = getchar(), f = 0;
  while(ch < '0' or ch > '9') {
    if (ch == '-')  f = 1;
    ch = getchar();
  }
  while('0' <= ch and ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  if (f)  x = -x;
  read(oth...);
}


namespace YZLK{
  const int mod = 998244353;
  const int N = (1 << 21) + 10;
  const int M = 1e3 + 10;
  int n, m, q;
  int p[N];
  int f[M][M];
  int s[M][M];
  bool vis[M];
  int g(int x, int y) {
    int mx = 0;
    REP(i, 0, m - 1) {
      REP(j, 0, m)  vis[j] = 0;
      REP(j, x, y)  vis[p[j] ^ i] = 1;
      int sum = 0;
      REP(j, 0, m)  if (!vis[j])  {sum = j;break;}
      mx = std::max(mx, sum);
    }
    return mx;
  }
  void main() {
    read(n, q);
    m = 1 << n;
    REP(i, 1, m) {
      read(p[i]);
    }
    REP(i, 1, m) {
      REP(j, i, m) {
        f[i][j] = g(i, j);
      }
    }
    // REP(i, 1, m) {
    //   REP(j, 1, m)  std::cout << f[i][j] << " \n"[j == m];
    // }
    REP(i, 1, m) {
      REP(j, 1, m)  s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + f[i][j];
    }
    while(q--) {
      int l1, r1, l2, r2;
      read(l1, r1, l2, r2);
      std::cout << s[r1][r2] - s[l1 - 1][r2] - s[r1][l2 - 1] + s[l1 - 1][l2 - 1] << '\n';
    }
    return;
  }
}

signed main() {
  freopen("ds.in", "r", stdin);
  freopen("ds.out", "w", stdout);
  int T = 1;
  // read(T);
  while(T--) {
    YZLK::main();
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
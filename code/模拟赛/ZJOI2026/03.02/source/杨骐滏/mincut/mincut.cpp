#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <bitset>
using namespace std;

#define int long long
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
  const int N = 2e5 + 10;
  const int H = 60;
  int n, m, s, t;
  struct node{
    int u, v, w;
  }a[N];
  struct basis{
    int b[H + 10];
    int t[H + 10];
    void clear() {
      DEP(i, H, 0)  b[i] = t[i] = 0;
    }
    void insert(int x, int tm) {
      DEP(i, H, 0) {
        if (!((x >> i) & 1))  continue;
        if (tm > t[i]) {
          std::swap(x, b[i]);
          std::swap(tm, t[i]);
        }
        x ^= b[i];
      }
      return;
    }
    int query(int x, int tm) {
      DEP(i, H, 0) {
        if (t[i] > tm)  x = std::min(x, x ^ b[i]);
      }
      return x;
    }
  }B;
  int nxtu[N], nxtv[N];
  int val[N], lst[N];
  void main() {
    read(n, m, s, t);
    REP(i, 1, m) {
      read(a[i].u, a[i].v, a[i].w);
    }
    REP(i, 1, n)  lst[i] = m + 1, val[i] = 0;
    DEP(i, m, 1) {
      nxtu[i] = lst[a[i].u];
      lst[a[i].u] = i;
      nxtv[i] = lst[a[i].v];
      lst[a[i].v] = i;
    }
    B.clear();
    REP(i, 1, m) {
      val[a[i].u] ^= a[i].w;
      val[a[i].v] ^= a[i].w;
      if (a[i].u != s and a[i].u != t)  B.insert(val[a[i].u], nxtu[i]);
      if (a[i].v != s and a[i].v != t)  B.insert(val[a[i].v], nxtv[i]);
      std::cout << B.query(val[s], i) << '\n';
    }
    return;
  }
}

signed main() {
  freopen("mincut.in", "r", stdin);
  freopen("mincut.out", "w", stdout);
  int T = 1;
  read(T);
  while(T--) {
    YZLK::main();
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
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
  const int N = 1e6 + 10;
  int n, m, s, t;
  struct node{
    int u, v;
    ll w;
  }a[N];
  int p[N];
  ll c[N];
  void main() {
    read(n, m, s, t);
    REP(i, 1, n)  p[i] = i;
    REP(i, 1, n) {
      if (s < i)  p[i]--;
      if (t < i)  p[i]--;
    }
    REP(i, 0, (1 << n)) c[i] = 0;
    p[s] = n - 1, p[t] = n;
    REP(i, 1, m) {
      read(a[i].u, a[i].v, a[i].w);
      a[i].u = p[a[i].u], a[i].v = p[a[i].v];
    }
    s = n - 1, t = n;
    REP(i, 1, m) {
      REP(j, 0, (1 << (n - 2)) - 1) {
        int x, y;
        if (a[i].u >= n - 1) {
          x = (a[i].u == n);
        } else  x = (j >> (a[i].u - 1)) & 1;
        if (a[i].v >= n - 1) {
          y = (a[i].v == n);
        } else  y = (j >> (a[i].v - 1)) & 1;
        if (x != y) c[j] ^= a[i].w;
      }
      ll mn = 1e18;
      REP(j, 0, (1 << (n - 2)) - 1) mn = std::min(mn, c[j]);
      std::cout << mn << '\n';
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
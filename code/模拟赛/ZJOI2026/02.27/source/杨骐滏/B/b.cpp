#include <bits/stdc++.h>

#define REP(i,l,r)  for(int i = l;i <= r;i++)
#define DEP(i,r,l)  for(int i = r;i >= l;i--)
#define ll long long
#define pb push_back
#define fi first
#define se second
#define int long long

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
  int n, m, q;
  int f[N], d[N], L[N], R[N];
  int g[N];
  int find(int x) {
    if (f[x] == x)  return f[x];
    int fa = find(f[x]);
    d[x] += d[f[x]];
    f[x] = fa;
    return fa;
  }
  void merge(int a, int b, int c) {
    int x = find(a), y = find(b);
    if (x == y) {
      g[x] = std::__gcd(g[x], std::__gcd(d[a] + d[b] + c, c));
    } else {
      f[x] = y;
      d[x] = c - d[a] - d[b];
      g[y] = std::__gcd(g[y], std::__gcd(g[x], c));
    }
    return;
  }
  int exgcd(int a, int b, int &x, int &y) {
    if (!b) {return x = 1, y = 0, a;}
    int d = exgcd(b, a % b, y, x);
    return y -= a / b * x, d;
  }
  int floor(int a, int b) {
    return (a - (a % b + b) % b) / b;
  }
  void main() {
    read(n, m, q);
    REP(i, 1, n)  f[i] = i;
    while(q--) {
      int op, u, v, w, b, c;
      read(op, u, v, w);
      if (op == 1)  merge(u, v, w);
      else {
        read(b, c);
        w %= m;
        int x = find(u), y = find(v);
        if (x != y) {puts("0");continue;}
        g[x] = abs(g[x]);
        int gcd = std::__gcd(g[x], m);
        int ds = (d[u] + d[v]) % m;
        int xt, yt;
        int p = exgcd(gcd, -b, xt, yt);
        if ((w - ds) % p) {puts("0");continue;}
        int dt = (w - ds) / p;
        p = abs(p);
        xt *= dt, yt *= dt;
        int k = floor(-yt * p + gcd - 1, gcd);
        yt += k * (gcd / p);
        if (yt >= c)  puts("0");
        else          std::cout << floor((c - yt) * p + gcd - 1, gcd) << '\n';
      }
    }
    return;
  }
}

signed main() {
  freopen("interval.in", "r", stdin);
  freopen("interval.out", "w", stdout);
  int T = 1;
  // read(T);
  while(T--) {
    YZLK::main();
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
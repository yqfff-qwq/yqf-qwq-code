#include <bits/stdc++.h>

#define REP(i,l,r)  for(int i = l;i <= r;i++)
#define DEP(i,r,l)  for(int i = r;i >= l;i--)
#define ll long long
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
  const int N = 4e6 + 10;
  int n;
  ll f[N], L[N], R[N];
  std::vector<int> ve[N];
  int find(int x) {
    if (f[x] < 0) return x;
    return f[x] = find(f[x]);
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (-f[u] < -f[v])  std::swap(u, v);
    f[u] += f[v];
    f[v] = u;
    L[u] = std::min(L[u], L[v]);
    R[u] = std::max(R[u], R[v]);
    return;
  }
  void mg(ll u, ll v, ll x, ll l = 0, ll r = N - 10) {
    for(auto i:ve[u]) merge(i, v);
    ve[u].clear();
    if (r - l <= 1) return;
    int mid = (l + r) >> 1;
    if (x < mid)  mg(u << 1, v, x, l, mid);
    else          mg(u << 1 | 1, v, x, mid, r);
    return;
  }
  void add(ll u, ll ql, ll qr, ll v, ll l = 0, ll r = N - 10) {
    if (ql <= l and r <= qr)  return ve[u].pb(v), void();
    if (qr <= l or r <= ql) return;
    int mid = (l + r) >> 1;
    add(u << 1, ql, qr, v, l, mid);
    add(u << 1 | 1, ql, qr, v, mid, r);
    return;
  }
  void main() {
    read(n);
    int cnt = 0;
    REP(i, 1, n) {
      int op, x, y;
      read(op, x, y);
      if (op == 1) {
        cnt++;
        L[cnt] = x;
        R[cnt] = y;
        f[cnt] = -1;
        mg(1, cnt, x);
        mg(1, cnt, y);
        ll z = find(cnt);
        add(1, L[z] + 1, R[z], z);
      } else {
        int u = find(x), v = find(y);
        if (u == v) puts("YES");
        else if ((L[v] < L[u] and L[u] < R[v]) or (L[v] < R[u] and R[u] < R[v]))  puts("YES");
        else        puts("NO");
      }
    }
    return;
  }
}

signed main() {
//   freopen("interval.in", "r", stdin);
//   freopen("interval.out", "w", stdout);
  int T = 1;
  // read(T);
  while(T--) {
    YZLK::main();
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
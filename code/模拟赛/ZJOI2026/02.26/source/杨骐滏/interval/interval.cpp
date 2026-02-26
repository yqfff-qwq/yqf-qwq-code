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
  const int N = 2e5 + 10;
  ll f[N], L[N], R[N];
  int find(int x) {
    if (f[x] < 0) return f[x];
    return f[x] = find(f[x]);
  }
  void merge(int u, int v) {
    int u = find(u), v = find(v);
    if (u == v) return;
    if (-f[u] < -f[v])  std::swap(u, v);
    f[u] += f[v];
    f[v] = u;
    L[u] = std::min(L[u], L[v]);
    R[u] = std::max(R[u], R[v]);
    return;
  }
  
  void main() {
    
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
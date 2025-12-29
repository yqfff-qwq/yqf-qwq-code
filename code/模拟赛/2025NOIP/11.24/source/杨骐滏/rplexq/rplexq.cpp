// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
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
  const int N = 2e5 + 10;
  int n, m, r;
  int dg[N];
  
  int he[N], to[N << 1], ne[N << 1], tot;
  void add(int u,int v) {
    ne[++tot] = he[u];
    to[tot] = v;
    he[u] = tot;
    return;
  }

/*
  struct node{
    int l, r, x, y;
    int id;
  }a[N];
  int ans[N];
  int idx;
  int id[N], di[N];
  void idfs(int u, int ff) {
    for(int i = he[u];i;i = ne[i]) {
      int v = to[i];
      if (v == ff)  continue;
      idfs(v, u);
      di[u] = ++idx, id[idx] = u;
    }
    return;
  }
  struct tree{
    int tr[N];
    int lowbit(int x) {return x & -x;}
    void add(int x, int k) {
      while(x <= n) {
        tr[x] += k;
        x += lowbit(x);
      }
      return;
    }
    int q(int x) {
      int ans = 0;
      while(x) {
        ans += tr[x];
        x -= lowbit(x);
      }
      return ans;
    }
  }tr;
*/

  int dep[N], st[N][20];
  int dfn[N];
  int idx;
  int get(int x, int y) {
    return dep[x] < dep[y] ? x : y;
  }
  void dfs(int u, int ff) {
    st[dfn[u] = ++idx][0] = ff;
    dep[u] = dep[ff] + 1;
    for(int i = he[u];i;i = ne[i]) {
      int v = to[i];
      if (v == ff)  continue;
      dfs(v, u);
    }
    return;
  }
  int lca(int u, int v) {
    if (u == v) return u;
    u = dfn[u], v = dfn[v];
    if (u > v)  swap(u, v);
    u++;
    int k = __lg(v - u + 1);
    return get(st[u][k], st[v - (1 << k) + 1][k]);
  }
  void solve() {
    dfs(r, 0);
    REP(j, 1, 19) {
      for(int i = 1;i + (1 << j) - 1 <= n;i++)  st[i][j] = get(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    int ans = 0;
    while(m--) {
      ans = 0;
      int l, r, x;
      read(l, r, x);
      REP(i, l, r) {
        REP(j, i + 1, r) {
          if (lca(i, j) == x)  ans++;
        }
      }
      cout << ans << "\n";
    }
    return;
  }


  void main() {
    read(n, m, r);
    int mx = 0;
    REP(i, 1, n - 1) {
      int u, v;
      read(u, v);
      add(u, v), add(v, u);
      dg[u]++, dg[v]++;
      mx = max(mx, max(dg[u], dg[v]));
    }
    
    if (n <= 1e5) {
      solve();
      return;
    }


    return;
  }
}


signed main() {
  freopen("rplexq.in", "r", stdin);
  freopen("rplexq.out", "w", stdout);
  
  // cin.tie(nullptr) -> sync_with_stdio(false);
  int T = 1;
  // read(T);
  while(T--) {
    YZLK::main();
  }

  fclose(stdin);
  fclose(stdout);

  return 0;
}
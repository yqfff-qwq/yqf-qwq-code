// #include <bits/stdc++.h>
#include <iostream>
#include <queue>

// #define int long long
#define ll long long
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define REP(i, l, r)    for(int i = (l);i <= (r);i++)
#define DEP(i, r, l)    for(int i = (r);i >= (l);i--)

void read() {}
template<typename T1, typename ...T2>inline void read(T1 &x, T2 &...oth) {
    x = 0;
    int ch = getchar(), f = 0;
    while(ch < '0' or '9' < ch) {
        if (ch == '-')  f = 1;
        ch = getchar();
    }
    while('0' <= ch and ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    if (f)  x = -x;
    read(oth...);
    return;
}

namespace YZLK{
  const int N = 1e5 + 10;
  const int M = 2e5 + 10;
  const ll inf = 1e18;
  int n, m, s, t, x, y;
  int he[M], ne[M << 1], to[M << 1], c[M << 1], tot;
  ll ds[N], dt[N], dy[N], dx[N];
  bool vis[N], vs[N];
  ll ans;
  void add(int u, int v, int w) {
    ne[++tot] = he[u];
    he[u] = tot;
    to[tot] = v;
    c[tot] = w;
    return;
  }
  struct Node{
    int y;
    ll w;
    bool operator < (const Node &e) const{
      return e.w < w;
    }
  };
  struct nd{
    int y;
    ll s1, s2;//s1:当前最短路，s2:在当前节点的最短路中从u到这条路径的最短距离
    bool operator < (const nd &e) const{
      return (e.s1 == s1 ? e.s2 < s2 : e.s1 < s1);
    }
  };
  std::priority_queue<Node> q;
  std::priority_queue<nd> p;
  void dij(int st, ll d[]) {
    REP(i, 0, N - 10) vis[i] = 0, d[i] = inf;
    d[st] = 0;
    q.push({st, 0});
    while(!q.empty()) {
      auto t = q.top();
      q.pop();
      auto u = t.y;
      if (vis[u]) continue;
      vis[u] = 1;
      for(int i = he[u];i;i = ne[i]) {
        int v = to[i];
        ll w = c[i];
        if (d[u] + w < d[v]) {
          d[v] = d[u] + w;
          q.push({v, d[v]});
        }
      }
    }
    return;
  }

  void dijs(int st) {
    REP(i, 0, N - 10) vis[i] = 0, ds[i] = inf, dt[i] = inf;
    ds[st] = 0;
    dt[st] = dx[st];
    p.push({st, 0, dt[st]});
    while(!p.empty()) {
      auto t = p.top();
      p.pop();
      auto u = t.y;
      if (vis[u]) continue;
      vis[u] = 1;
      for(int i = he[u];i;i = ne[i]) {
        int v = to[i];
        ll w = c[i];
        if (ds[u] + w <= ds[v]) {
          if (ds[u] + w < ds[v]) {
            ds[v] = ds[u] + w;
            dt[v] = std::min(dx[v], dt[u]);
            p.push({v, ds[v], dt[v]});
          }
          else {
            if (dt[v] > dt[u]) {
              dt[v] = std::min(dt[u], dx[v]);
              p.push({v, ds[v], dt[v]});
            }
          }
        }
      }
    }
    return;
  }
  void dfs(int u) {
    // std::cout << u << " " << dt[u] << "\n";
    vs[u] = 1;
    ans = std::min(ans, dt[u] + dy[u]);
    for(auto i = he[u];i;i = ne[i]) {
      int v = to[i];
      if (vs[v])  continue;
      ll w = c[i];
      if (ds[v] + w == ds[u]) {
        dfs(v);
      }
    }
  }
  void main() {
    read(n, m);
    read(s, t);
    read(x, y);
    REP(i, 1, m) {
      int u, v, w;
      read(u, v, w);
      add(u, v, w);
      add(v, u, w);
    }
    dij(x, dx);
    dij(y, dy);
    ans = dx[y];
    dijs(s);
    dfs(t);
    std::swap(s, t);
    REP(i, 0, n)  vs[i] = 0;
    dijs(s);
    dfs(t);
    std::cout << ans << "\n";
    return;
  }
}

signed main() {
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);

  // std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1;
  // read(T);
  while(T--) {
    YZLK::main();
  }

  fclose(stdin);
  fclose(stdout);
  return 0;
}



/*
不要忘记longlong

*/
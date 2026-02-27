#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
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
  const int N = 2e5 + 10;
  const int M = 1e2 + 10;
  int n, m, q;
  std::vector<pii> ve[N];
  bool vis[M][M];
  void bfs(int x, int y) {
    std::queue<pii> q;
    vis[x][0] = 1;
    q.push({x, 0});
    while(!q.empty()) {
      auto t = q.front();
      q.pop();
      for(auto it:ve[t.fi]) {
        int v = it.fi, w = it.se;
        if (!vis[v][(w + t.se) % m]) {
          vis[v][(w + t.se) % m] = 1;
          q.push({v, (w + t.se) % m});
        }
      }
    }
    return;
  }
  void solve2() {
    while(q--) {
      int op, u, v, x, b, c;
      read(op, u, v, x);
      if (op == 1) {
        ve[u].pb({v, x});
        ve[v].pb({u, x});
      } else {
        read(b, c);
        REP(i, 1, n) {
          REP(j, 0, m - 1)  vis[i][j] = 0;
        }
        bfs(u, v);
        int cnt = 0;
        REP(i, 1, c) {
          if (vis[v][x])  cnt++;
          x = (x + b) % m;
        }
        std::cout << cnt << '\n';
      }
    }
  }
  void solve1() {
    while(q--) {
      int op, u, v, x, b, c;
      read(op, u, v, x);
      if (op == 1) {
        
      } else {
        read(b, c);
        std::cout << c << '\n';
      }
    }
    return;
  }
  int f[N], s[N];
  
  void main() {
    read(n, m, q);
    if (n <= 100 and q <= 100) {
      solve2();
      return;
    }
    if (m == 2) {
      solve1();
      return;
    }
    else {
      solve1();
      return;
    }
    return;
  }
}

signed main() {
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int T = 1;
  // read(T);
  while(T--) {
    YZLK::main();
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define int long long
#define ll long long
#define pii pair<int, int>
#define REP(i, l, r)    for(int i = (l);i <= (r);i++)
#define DEP(i, r, l)    for(int i = (r);i >= (l);i--)
#define pb push_back
#define fi first
#define se second

void read() {}
template <typename T1, typename ...T2> inline void read(T1 &x, T2 &...oth) {
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
    return;
}

namespace YZLK{
  const int N = 1e4 + 10;
  int n, t;
  struct node{
    int a, b, id;
  }a[N];
  int d[N];
  struct nd{
    int id, b;
    bool operator < (const nd &e) const{
      return e.b < b;
    }
  };
  bool f = 0;
  bool vis[N];
  void dfs(int tt, int now) {
    if (f) return;
    if (tt == n + 1) return f = 1, void();
    REP(i, 1, n) {
      if (f)  return;
      if (vis[i]) continue;
      if (a[i].b >= now + 1 + t) {
        vis[i] = 1;
        d[i] = std::max(now + 1, a[i].a);
        dfs(tt + 1, d[i] + t - 1);
        vis[i] = 0;
      }
    }
    return;
  }
  std::priority_queue<nd> q;
  void main() {
    read(n, t);
    REP(i, 1, n) {
      read(a[i].a, a[i].b), a[i].id = i;
      if (a[i].b - a[i].a < t)  return puts("no"), void();
    }
    std::sort(a + 1, a + n + 1, [](node a, node b) {
      return (a.a == b.a ? a.b < b.b : a.a < b.a);
    });
    if (t == 1) {
      int now = -1;
      bool flag = 1;
      int idx = 1;
      q.push({1, a[1].b});
      REP(i, 2, n) {
        if (a[i].a == a[1].a) q.push({i, a[i].b}), idx++;
        else                  break;
      }
      while(idx < n) {
        // std::cout << idx << "\n";
        while(!q.empty()) {
          // std::cerr << 11 << "\n";
          auto it = q.top();
          q.pop();
          int p = it.id;
          if (now + 1 >= a[p].b)  {flag = 0;break;}
          now = std::max(now + 1, a[p].a);
          d[a[p].id] = now;
          // std::cerr << 33 << "\n";
          while(idx < n and a[idx + 1].a <= now + 1)  idx++, q.push({idx, a[idx].b});
          // std::cerr << 22 << '\n';
        }

        if (!flag)  break;
        if (idx == n) break;
        idx++;
        q.push({idx, a[idx].b});
        while(idx < n and a[idx].a == a[idx + 1].a) idx++, q.push({idx, a[idx].b});
      }
      if (!flag)  return puts("no"), void();
      puts("yes");
      REP(i, 1, n)       std::cout << d[i] << " ";
      return;
    }
    if (n <= 10) {
      dfs(1, -1);
      if (!f) return puts("no"), void();
      puts("yes");
      REP(i, 1, n)  std::cout << d[i] << " ";
      return;
    }

    return;
  }
}

signed main() {
    freopen("photo.in","r",stdin);
    freopen("photo.out","w",stdout);
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
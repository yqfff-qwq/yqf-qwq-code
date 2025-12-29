// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_set>
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
  const int N = 4e3 + 10;
  int n, m, q;
  char c[N][N];
  int s1[N][N], s2[N][N];
  int sum[N][N];
  int pi(int x, int y) {
    return (x - 1) * m + y;
  }
  pii pt(int x) {
    return (pii){x / m + 1, x % m};
  }
  struct dsu{
    int fa[N * N];
    void init(int x) {
      REP(i, 0, x + 1)  fa[i] = i;
      return;
    }
    int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);};
    bool merge(int u, int v) {
      int x = find(u), y = find(v);
      if (x == y) return 0;
      fa[x] = y;
      return 1;
    }
  }d;
  void main() {
    read(n, m, q);
    d.init(n * m);
    REP(i, 1, n) {
      scanf("%s", c[i] + 1);
    }
    REP(i, 1, n) {
      REP(j, 1, m - 1) {
        int ss = (c[i][j] == c[i][j + 1]);
        if (!ss and i != 1 and i != n) d.merge(pi(i - 1, j), pi(i, j));
        s1[i][j] = s1[i - 1][j] + s1[i][j - 1] - s1[i - 1][j - 1] + ss;
      }
    }
    REP(i, 1, n - 1) {
      REP(j, 1, m) {
        int ss = (c[i][j] == c[i + 1][j]);
        if (!ss and j != 1 and j != m)  d.merge(pi(i, j - 1), pi(i, j));
        s2[i][j] = s2[i - 1][j] + s2[i][j - 1] - s2[i - 1][j - 1] + ss;
      }
    }

    REP(i, 1, n - 1) {
      REP(j, 1, m - 1) {
        pii p = pt(d.find(pi(i, j)));
        sum[p.fi][p.se] = 1;
      }
    }
    REP(i, 1, n - 1) {
      REP(j, 1, m - 1)  sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + sum[i][j];
    }
    auto ch = [&](pii p, int xl, int yl, int xr, int yr) -> bool {
      return xl <= p.fi and p.fi <= xr and yl <= p.se and p.se <= yr;
    };
    unordered_set<int> st;
    while(q--) {
      int xl, yl, xr, yr;
      read(xl, yl, xr, yr);
      int V = (xr - xl + 1) * (yr - yl + 1);
      int E = (s1[xr][yr - 1] - s1[xr][yl - 1] - s1[xl - 1][yr - 1] + s1[xl - 1][yl - 1]) + (s2[xr - 1][yr] - s2[xr - 1][yl - 1] - s2[xl - 1][yr] + s2[xl - 1][yl - 1]);
      int R = sum[xr - 1][yr - 1] - sum[xl - 1][yr - 1] - sum[xr - 1][yl - 1] + sum[xl - 1][yl - 1];
      st.clear();
      if (xr != 1) {
        REP(i, yl, yr - 1) {
          if (c[xl][i] != c[xl][i + 1]) {
            int p = d.find(pi(xl, i));
            if (ch(pt(p), xl, yl, xr - 1, yr - 1))  st.insert(p);
          }
        }
        REP(i, yl, yr - 1) {
          if (c[xr][i] != c[xr][i + 1]) {
            int p = d.find(pi(xr - 1, i));
            if (ch(pt(p), xl, yl, xr - 1, yr - 1))  st.insert(p);
          }
        }
      }
      
      if (yr != 1) {
        REP(i, xl, xr - 1) {
          if (c[i][yl] != c[i + 1][yl]) {
            int p = d.find(pi(i, yl));
            if (ch(pt(p), xl, yl, xr - 1, yr - 1))  st.insert(p);
          }
        }
        REP(i, xl, xr - 1) {
          if (c[i][yr] != c[i + 1][yr]) {
            int p = d.find(pi(i, yr - 1));
            if (ch(pt(p), xl, yl, xr - 1, yr - 1))  st.insert(p);
          }
        }
      }
      
      R -= st.size();
      cout << V - E + R << "\n";
    }
    return;
  }
}


signed main() {
  freopen("paint.in", "r", stdin);
  freopen("paint.out", "w", stdout);
  
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

/*
4 8 9 
ABBAAAAA
ABAAAABA
CAADABBA
AAAAAAAA
1 1 4 8
3 5 3 8
1 3 2 4
1 4 2 5
1 1 3 3
4 4 4 4 
2 6 4 8 
3 5 4 6
1 6 3 8
*/
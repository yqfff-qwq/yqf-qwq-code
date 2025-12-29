// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define int long long
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
  const int N = 5e5 + 10;
  int n, M;
  struct node{
    int v, m;
  }a[N];
  vector<int> b[50];
  vector<int> c;
  int cnt;
  void main() {
    read(n, M);
    REP(i, 1, n) {
      read(a[i].v, a[i].m);
    }
    sort(a + 1, a + n + 1, [](node a, node b) {
      return (a.m == b.m ? a.v > b.v : a.m < b.m);
    });
    c.pb(0);
    REP(i, 1, n) {
      if (a[i].m != a[i - 1].m) cnt++, c.pb(a[i].m);
      b[cnt].pb(a[i].v);
    }
    if (c[1] > 1) {
      M = M / c[1];
      DEP(i, cnt, 1)  c[i] = c[i] / c[1];
    }
    int ans = 0;
    int m = M;
    REP(i, 1, cnt) {
      sort(b[i].begin(), b[i].end(), std::greater<int>());
      if (cnt == i) {
        for(auto v:b[i]) {
          if (m < c[i]) break;
          ans += v;
          m -= c[i];
        }
        break;
      }
      int p = m % c[i + 1];
      int idx = 0;
      int len = b[i].size();
      REP(j, 0, len - 1) {
        if (p < c[i]) break;
        ans += b[i][j];
        idx++;
        p -= c[i];
      }
      
      for(int j = idx;j <= len - 1;j += (c[i + 1] / c[i])) {
        int sum = 0;
        REP(k, j, min(len - 1, j + (c[i + 1] / c[i]) - 1))  sum += b[i][k];
        b[i + 1].pb(sum);
      }
      m -= p;
        // cout << ans << " " << m << "\n";
    }


    std::cout << ans << '\n';
    return;
  }
}

signed main() {
  freopen("knapsack.in", "r", stdin);
  freopen("knapsack.out", "w", stdout);
  
  // cin.tie(nullptr) -> sync_with_stdio(false);
  int T = 1;
//   read(T);
  while(T--) {
    YZLK::main();
  }

  // fclose(stdin);
  // fclose(stdout);

  return 0;
}
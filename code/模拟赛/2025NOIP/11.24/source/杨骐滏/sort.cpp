// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
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
  const int N = 1e3 + 10;
  int n;
  int p[N];
  int vis[N];
  int h[N];
  int q[N], cnt, len[N];
  void main() {
    read(n);
    REP(i, 1, n)  read(p[i]);
    REP(i, 1, n) {
      if (!vis[i]) {
        cnt++;
        vis[i] = i;
        q[cnt] = i;
        int d = p[i];
        int tot = 0;
        while(d != i) {
          tot++;
          vis[d] = i;
          d = p[d];
        }
        len[cnt] = tot + 1;
        if (tot == 0) {
          cnt--;
        }
      }
    }
    if (cnt <= 2) {
      cout << cnt << "\n";
      REP(i, 1, cnt) {
        cout << len[i] << " ";
        int d = p[q[i]];
        cout << q[i] << " ";
        while(d != q[i]) {
          cout << d << " ";
          d = p[d];
        }
        puts("");
      }
      return;
    }
    cout << 2 << "\n";
    cout << cnt << " ";
    int sum = 0;
    REP(i, 1, cnt) {
      cout << q[i] << " ";
      sum += len[i];
      h[i] = p[q[i]];
    }
    REP(i, 1, cnt)  p[q[(i % cnt + 1)]] = h[i];
    puts("");

    cout << sum << " ";
    int d = p[q[1]];
    cout << q[1] << " ";
    while(d != q[1]) {
      cout << d << " ";
      d = p[d];
    }
    return;
  }
}


signed main() {
  freopen("sort.in", "r", stdin);
  freopen("sort.out", "w", stdout);
  
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
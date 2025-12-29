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
  const int N = 2e6 + 10;
  int n, m;
  int len;
  int a[N];
  struct node{
    int r, x;
    int id, op;
  }q[N * 3];
  int ans[N];
  struct tree{
    int tr[N];
    int lowbit(int x) {return x & -x;}
    void add(int x, int k) {
      while(x <= N - 1) {
        tr[x] += k;
        x += lowbit(x);
      }
      return;
    }
    int query(int x) {
      int sum = 0;
      while(x) {
        sum += tr[x];
        x -= lowbit(x);
      }
      return sum;
    }
  }tr;
  void main() {
    read(n, m);
    REP(i, 1, n)  read(a[i]), q[++len] = {i, 0};
    REP(i, 1, m) {
      int l, r, x;
      read(l, r, x);
      q[++len] = {r, x, i, 1};
      q[++len] = {l - 1, x, i, -1};
    }
    sort(q + 1, q + len + 1, [](node a, node b) {
      return a.r == b.r ? a.x < b.x : a.r < b.r;
    });
    REP(i, 1, len) {
      if (q[i].x == 0)  tr.add(a[q[i].r], 1);
      else {
        int sum = tr.query(q[i].x);
        ans[q[i].id] += q[i].op * sum;
      }
    }
    REP(i, 1, m)  cout << ans[i] << "\n";
    return;
  }
}


signed main() {
  // freopen("paint.in", "r", stdin);
  // freopen("paint.out", "w", stdout);
  
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


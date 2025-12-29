// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
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
  const int N = 4e2 + 10;
  int n;
  int b[N];
  int a[N][N];
  void main() {
    read(n);
    REP(i, 1, n)  read(b[i]);
    REP(i, 1, n) {
      REP(j, 1, n)  a[i][j] = (j - 1) * (i - 1) % n;
    }
    REP(i, 1, n) {
      int x = b[i] - a[i][i];
      REP(j, 1, n)  a[i][j] = (a[i][j] + x + n) % n;
    }
    REP(i, 1, n)
      REP(j, 1, n)  cout << a[i][j] << " \n"[j == n];
    return;
  }
}

signed main() {
//   freopen("knapsack.in", "r", stdin);
//   freopen("knapsack.out", "w", stdout);
  
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
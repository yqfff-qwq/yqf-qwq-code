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
  const int N = 2e5 + 10;
  int n, k;
  int a[N];
  int s[N];
  void main() {
    read(n, k);
    REP(i, 1, n)  read(a[i]);
    s[k - 1] = a[k - 1], s[k + 1] = a[k + 1];
    REP(i, k + 2, n)  s[i] = s[i - 1] + a[i];
    DEP(i, k - 2, 0)  s[i] = s[i + 1] + a[i];
    int l = k - 1, r = k + 1, s1 = a[k], s2 = a[k];//s1/s2:左侧/右侧的最大后缀/前缀和
    while(l >= 1 and r <= n) {
      bool flag = 0;
      while(l >= 1 and s[l] + s2 >= 0)  s1 = max(s1, a[k] + s[l]), l--, flag = 1;
      while(r <= n and s[r] + s1 >= 0)  s2 = max(s2, a[k] + s[r]), r++, flag = 1;
      if (!flag)  return puts("NO"), void();
    }
    puts("YES");
    return;
  }
}

signed main() {
//   freopen("knapsack.in", "r", stdin);
//   freopen("knapsack.out", "w", stdout);
  
  // cin.tie(nullptr) -> sync_with_stdio(false);
  int T = 1;
  read(T);
  while(T--) {
    YZLK::main();
  }

  // fclose(stdin);
  // fclose(stdout);

  return 0;
}
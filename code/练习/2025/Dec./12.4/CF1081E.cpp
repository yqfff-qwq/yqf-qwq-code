// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#include <cmath>
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
  const int N = 1e5 + 10;
  int n;
  int f[N];
  int a[N];
  int b[N], c[N];
	void main() {
    read(n);
    REP(i, 1, N - 5)  f[i] = i * i;
    REP(i, 1, N - 5)  c[i] = f[i] - f[i - 1];
    REP(i, 1, n / 2)  read(b[i]);
    int s = 0, sum = 0;//s:前面是哪个数的平方 sum:前面的完全平方数
    int l = 1, r = 1;//x是哪两个完全平方数的差
    REP(i, 1, n / 2) {
      l = r = s + 2;
      int ss = c[l];

      while(ss != b[i] and l <= r) {
        if (ss < b[i])  r++, ss += c[r];
        if (ss > b[i])  ss -= c[l], l++;
      }

      if (l > r)  return puts("No"), void();
      a[i * 2 - 1] = (f[l - 1] - sum);
      a[i * 2] = b[i];
      s = r;
      sum = f[r];
    }
    puts("Yes");
    REP(i, 1, n)  cout << a[i] << " ";
    puts("");
    return;
  }
}

signed main() {
//   freopen("knapsack.in", "r", stdin);
//   freopen("knapsack.out", "w", stdout);
  
  // cin.tie(nullptr) -> sync_with_stdio(false);
  int T = 1;
  // read(T);
  while(T--) {
    YZLK::main();
  }

  // fclose(stdin);
  // fclose(stdout);

  return 0;
}
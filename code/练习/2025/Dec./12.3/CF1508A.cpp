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
  int n;
  char c[4][N];
  int s[10][10];
  void main() {
    read(n);
    scanf("%s", c[1] + 1);
    scanf("%s", c[2] + 1);
    scanf("%s", c[3] + 1);
    s[1][0] = s[1][1] = s[2][0] = s[2][1] = s[3][0] = s[3][1] = 0;
    REP(i, 1, n * 2) {
      if (c[1][i] == '1') s[1][1]++;
      else                s[1][0]++;
      if (c[2][i] == '1') s[2][1]++;
      else                s[2][0]++;
      if (c[3][i] == '1') s[3][1]++;
      else                s[3][0]++;
    }
    
    // REP(i, 1, 3)
    //   REP(j, 0, 1)  cout << s[i][j] << " \n"[j == 1];

    int p1 = 1, p2 = 2, p = 1;
    if (s[1][1] >= n and s[2][1] >= n)  p1 = 1, p2 = 2, p = 1;
    if (s[1][0] >= n and s[2][0] >= n)  p1 = 1, p2 = 2, p = 0;
    if (s[1][1] >= n and s[3][1] >= n)  p1 = 1, p2 = 3, p = 1;
    if (s[1][0] >= n and s[3][0] >= n)  p1 = 1, p2 = 3, p = 0;
    if (s[2][1] >= n and s[3][1] >= n)  p1 = 2, p2 = 3, p = 1;
    if (s[2][0] >= n and s[3][0] >= n)  p1 = 2, p2 = 3, p = 0;

    // cout << p1 << " " << p2 << " " << p << "\n";

    int idx = 1;
    REP(i, 1, 2 * n) {
      if (idx > 2 * n)            {cout << c[p1][i];continue;}
      if (c[p2][idx] == c[p1][i]) {cout << c[p1][i];idx++;continue;}
      if (c[p1][i] - '0' != p)    {cout << c[p1][i];continue;}
      while(idx <= 2 * n and c[p2][idx] - '0' != p)  cout << c[p2][idx], idx++;
      cout << c[p1][i];
      idx++;
    }

    while(idx <= 2 * n) cout << c[p2][idx], idx++;

    puts("");
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
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
  const int N = 2e3 + 10;
  int n;
  int a[N];
  vector<int> ans[N];
  int sz[N];
  vector<int> ve[N];
  void main() {
    read(n);
    cout << "? 1" << endl;
    REP(i, 1, n) {
      read(a[i]);
      if (a[i] == 1)  ans[1].pb(i);
      if (a[i]) {
        sz[a[i] & 1]++;
        ve[a[i] & 1].pb(i);
      }
    }
    
    int k = 0;
    if (sz[0] > sz[1])  k = 1;
    for(auto i:ve[k]) {
      cout << "? " << i << endl;
      REP(j, 1, n) {
        int d;
        read(d);
        if (d == 1) ans[i].pb(j);
      }
    }

    cout << "!" << endl;
    REP(i, 1, n)
      for(auto j:ans[i]) if (j != 1)  cout << i << " " << j << "\n";
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
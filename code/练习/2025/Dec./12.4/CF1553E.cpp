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
  const int N = 3e5 + 10;
  int p[N];
  int n, m;
  int cnt[N];
  int d[N];
  vector<int> ans;
  int vis[N];
	void main() {
    ans.clear();
    read(n, m);
    REP(i, 0, n)  cnt[i] = 0;
    REP(i, 1, n)  read(p[i]), cnt[(i - p[i] + n) % n]++;
    // REP(i, 1, n)  cout << cnt[i] << " ";
    // puts("");
    REP(i, 0, n - 1) {
      if (cnt[i] < n - 2 * m)  continue;
      REP(j, 1, n)  d[p[j]] = (j - i - 1 + n) % n + 1, vis[j] = 0;
      vis[0] = 0;
      int ct = 0;
      // REP(j, 1, n)  cout << d[j] << " ";
      // puts("");
      REP(j, 1, n) {
        if (vis[j]) continue;
        vis[j] = j;
        ct++;
        int q = d[j];
        bool flag = 0;
        while(q != j) {
          vis[q] = j;
          q = d[q];
          flag = 1;
        }
      }
      /*
      1 2 3 4
      4 1 2 3
      3 4 1 2
      2 3 4 1


      2 3 1 4
      3 1 4 2
      1 4 2 3
      4 2 3 1

      4 2 3 1
      */
      // cout << i << " " << ct << "\n";
      if (n - ct <= m) ans.pb(i);
    }
    cout << ans.size() << " ";
    sort(ans.begin(), ans.end());
    for(auto it:ans)  cout << it << " ";
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
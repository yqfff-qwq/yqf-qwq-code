// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
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
  const int N = 3e2 + 10;
  const int inf = 1e13;
  int n, k;
  int h[N], hh[N], len, c[N];
  int mc[N], mh[N];
  int cnt[N];
  int dp[N][N][N];
  void main() {
    read(n, k);
    REP(i, 1, n)    read(h[i], c[i]), hh[++len] = h[i];
    sort(hh + 1, hh + len + 1);
    REP(i, 2, len)  hh[i] = max(hh[i], hh[i - 1] + 1);
    REP(i, 1, n)    h[i] = lower_bound(hh + 1, hh + len + 1, h[i]) - hh;
    REP(i, 1, len)  mc[i] = inf;
    REP(i, 1, n)    mh[h[i]]++, mc[h[i]] = min(mc[h[i]], c[i]);
	  mc[0] = inf;
    REP(i, 1, len) {
        mc[i] = min(mc[i], mc[i - 1]), cnt[i] = cnt[i - 1] + mh[i];
    }
    REP(i, 0, len) {
        REP(j, 0, n + 2) {
            REP(p, 0, n + 2)    dp[i][j][p] = inf;
        }
    }
    dp[1][1][mh[1] - 1] = 0;
    REP(i, 1, len - 1) {
        REP(j, 0, n) {
            DEP(p, max(0ll, cnt[i] - 1), 0) {
                int sum = p + mh[i + 1], ss;
                if (p and (hh[i + 1] - hh[i]) * k > inf)    ss = inf + 1;
                else    ss = p * (hh[i+1] - hh[i]) * k;
                if(!i)  sum--;
                if(sum <= j)  dp[i+1][j][0] = std::min(dp[i+1][j][0], dp[i][j][p] + ss);
                else{
                  dp[i + 1][j][sum - j] = min(dp[i + 1][j][sum - j],dp[i][j][p] + ss);
                  dp[i + 1][j + 1][sum - j - 1] = min(dp[i+1][j + 1][sum - j-1], dp[i+1][j][sum - j] + mc[i]);
            }
          }
      }
    }
    int ans = inf;
    REP(i, 0, n)    ans = min(ans, dp[len][i][0]);
    cout << ans << "\n";
    return;
  }
}

signed main() {
//   freopen("couple.in", "r", stdin);
//   freopen("couple.out", "w", stdout);
  
  // cin.tie(nullptr) -> sync_with_stdio(false);
  int T = 1;
//   read(T);
  while(T--) {
    YZLK::main();
  }

  fclose(stdin);
  fclose(stdout);

  return 0;
}
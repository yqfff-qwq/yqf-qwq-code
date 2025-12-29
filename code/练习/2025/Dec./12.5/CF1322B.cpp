#include <iostream>
#include <algorithm>

// using namespace std;

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
  const int N = 4e5 + 10;
  int n;
  int a[N], b[N];
  /*
  [(1<<i),(1<<(i+1))-1]
  [3*(1<<i),2*((1<<(i+1))-1)]
  */
  int query(int x, int y) {
    // std::cout << x << ' ' << y << "\n";
    if (x > y)  return 0;
    int cnt = 0;
    int l = 1, r = 1;
    DEP(i, n, 1) {
      while(l <= n and b[l] + b[i] < x)   l++;
      while(r <= n and b[r] + b[i] <= y)  r++;
      cnt += (r - l - (l <= i and i < r));
    }
    return (cnt >> 1) & 1;
  }



	void main() {
    read(n);
    REP(i, 1, n)  read(a[i]);
    int ans = 0;
    REP(i, 0, 25) {
      REP(j, 1, n)  b[j] = (a[j] & ((1ll << (i + 1)) - 1));
      std::sort(b + 1, b + n + 1);
      int cnt = query(1ll << i, (1ll << (i + 1)) - 1) ^ query(3 * (1ll << i), 2 * ((1ll << (i + 1)) - 1));
      ans += cnt * (1ll << i);
    }
    std::cout << ans << "\n";
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
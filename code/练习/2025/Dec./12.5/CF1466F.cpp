#include <iostream>
#include <algorithm>
#include <vector>

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
  const int N = 5e5 + 10;
  const int M = 1e6 + 10;
  const int mod = 1e9 + 7;
  int n, m, tot;
  int pw[N];
  std::vector<int> ve[N];
  void init() {
    pw[0] = 1;
    REP(i, 1, N - 10) pw[i] = pw[i - 1] * 2 % mod;
    return;
  }
  std::vector<int> ans;
  struct dsu{
    int fa[M], sz[M];
    void init(int x) {
      REP(i, 0, x + 1)  fa[i] = i, sz[i] = 1;
    }
    int find(int x) {
      return (x == fa[x] ? fa[x] : fa[x] = find(fa[x]));
    }
    bool merge(int u, int v) {
      int x = find(u), y = find(v);
      if (x == y) return 0;
      if (sz[x] > sz[y])  std::swap(x, y);
      fa[x] = y;
      sz[y] += sz[x];
      return 1;
    }
  }d;

	void main() {
    init();
    read(n, m);
    tot = m + 1;
    d.init(M - 10);
    REP(i, 1, n) {
      int ln, x;
      read(ln);
      REP(j, 1, ln) {
        read(x);
        ve[i].pb(x);
      }
      if (ln == 1)  ve[i].pb(tot);
      if (d.merge(ve[i][0], ve[i][1]))  ans.pb(i);
    }

    std::cout << pw[ans.size()] << " " << ans.size() << "\n";
    for(auto it:ans)  std::cout << it << " ";
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
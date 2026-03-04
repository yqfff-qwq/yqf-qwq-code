#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>

#define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
#define MAX(a, b) (a) = max((a), (b))
#define MIN(a, b) (a) = min((a), (b))
#define pii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ull unsigned long long
#define ll long long
#define X(_) (_)
#define Y(_) (dp[_] + _ * _)
#define B(_) (dp[_] - _ * _)
#define K(_) (2 * _)

void read(){}
template<typename T1,typename ...T2>inline void read(T1 &x,T2 &...oth)
{
  x=0;
  int f=0,ch=getchar();
  while(ch<'0'||ch>'9')
  {
    if(ch=='-')
    {
      f=1;
    }
    ch=getchar();
  }
  while('0'<=ch&&ch<='9')
  {
    x=(x<<3)+(x<<1)+(ch^48);
    ch=getchar();
  }
  if(f)
  {
    x=-x;
  }
  read(oth...);
}

namespace YZLK{
  const int N = 1e5 + 10;
  const int M = 2e5 + 10;
  int n, m, q;
  bool f4 = 1, f5 = 1, f6 = 1, f3 = 1;
  struct edge{
    int u, v, w;
  }ed[N];
  struct query{
    int l, r;
  }qy[M];
  std::vector<pii> ve[N];
  struct dsu{
    int fa[N];
    void init(int x) {
      REP(i, 0, x)  fa[i] = i;
      return;
    }
    int find(int x) {
      return (fa[x] == x ? fa[x] : fa[x] = find(fa[x]));
    }
  }d;
  int ans = 0, sum = 0;
  void dfs1(int u, int fa, int mx, int l, int r) {
    if (l <= u and u <= r)  ans += mx, mx = 0;
    for(auto v:ve[u]) {
      if (v.fi == fa)  continue;
      dfs1(v.fi, u, std::max(mx, v.se), l, r);
    }
    return;
  }
  void solve1() {
    while(q--) {
      int l, r;
      read(l, r);
      l++, r++;
      ans = 0;
      dfs1(l, l, 0, l, r);
      std::cout << sum - ans << '\n';
    }
    return;
  }
  int st[N][21], fa[N][21], dep[N];
  void dfs2(int u, int f) {
    fa[u][0] = f;
    dep[u] = dep[f] + 1;
    for(auto v:ve[u]) {
      if (v.fi == f) continue;
      st[v.fi][0] = v.se;
      dfs2(v.fi, u);
    }
    return;
  }
  void solve3() {
    dfs2(1, 0);
    REP(j, 1, 20) {
      REP(i, 1, n)  st[i][j] = std::max(st[i][j - 1], st[fa[i][j - 1]][j - 1]), fa[i][j] = fa[fa[i][j - 1]][j - 1];
    }
    REP(i, 1, q) {
      int l = qy[i].l, r = qy[i].r;
      ans = 0;
      if (dep[l] < dep[r])  std::swap(l, r);
      DEP(j, 20, 0) {
        if (dep[fa[l][j]] >= dep[r]) {
          ans = std::max(ans, st[l][j]);
          l = fa[l][j];
        }
      }
      if (l != r) {
        DEP(j, 20, 0) {
          if (fa[l][j] == fa[r][j]) continue;
          ans = std::max(ans, std::max(st[l][j], st[r][j]));
          l = st[l][j], r = st[r][j];
        }
        ans = std::max(st[l][0], st[r][0]);
      }
      std::cout << sum - ans << '\n';
    }
    return;
  }
  void main() {
    read(n, m, q);
    REP(i, 1, m) {
      read(ed[i].u, ed[i].v, ed[i].w);
      ed[i].u++, ed[i].v++;
      if (ed[i].w > 2)  f4 = 0;
    }
    std::sort(ed + 1, ed + m + 1, [](edge a, edge b) {
      return a.w < b.w;
    });
    d.init(n);
    int tot = n;
    sum = 0;
    REP(i, 1, m) {
      int u = ed[i].u, v = ed[i].v;
      u = d.find(u), v = d.find(v);
      if (u == v) continue;
      d.fa[u] = v;
      tot--;
      sum += ed[i].w;
      ve[u].pb({v, ed[i].w});
      ve[v].pb({u, ed[i].w});
      if (tot == 1) break;
    }
    // if (n <= 2000 and m <= 2000 and q <= 2000) {
    //   solve1();
    //   return;
    // }
    int slr = 0;
    REP(i, 1, q) {
      read(qy[i].l, qy[i].r);
      qy[i].l++, qy[i].r++;
      if (qy[i].r != qy[i].l + 1) f3 = 0;
      slr += qy[i].r - qy[i].l + 1;
      if (slr > 400000) f5 = 0;
      if (qy[i].l != 0) f6 = 0;
    }
    if (f3) {
      solve3();
      return;
    }
    return ;
  }
}

signed main()
{
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
  int T=1;
  // read(T);
  while(T--)
  {
    YZLK::main();
  }

  fclose(stdin);
  fclose(stdout);
  return 0;
}

/*

code by yqfff_qwq

交代码之前看一下

这是你的代码吗？这是你要交的题吗？

多测了吗？多测清空了吗？多测清空会超时吗？会出现其他问题吗？

数组开小了吗？模数正确吗？调试删干净了吗？

*/

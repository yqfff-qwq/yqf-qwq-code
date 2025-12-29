#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>
// using namespace std;

// #define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
#define MAX(a, b) (a) = max((a), (b))
#define MIN(a, b) (a) = min((a), (b))
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ll long long

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
  const int N = 5e6 + 10;
  const int M = 1e5 + 10;
  const int inf = 1e5;
  int n, m;
  int st[M][22];
  std::vector<int> ve[M];
  int dfn[M], tot;
  int ans[M];
  int get(int x, int y) {
    return dfn[x] < dfn[y] ? x : y;
  }
  void dfs1(int u, int fa) {
    st[dfn[u] = ++tot][0] = fa;
    for(auto v:ve[u]) {
      if (v == fa)  continue;
      dfs1(v, u);
    }
    return;
  }
  int lca(int x, int y) {
    if (x == y) return x;
    x = dfn[x], y = dfn[y];
    if (x > y)  std::swap(x, y);
    x++;
    int d = std::__lg(y - x + 1);
    return get(st[x][d], st[y - (1 << d) + 1][d]);
  }
  struct tree{
    #define mid ((l + r) >> 1)
    int ls[N], rs[N], rt[M], idx;
    int sum[N], s[N];
    void update(int u) {
      if (sum[ls[u]] < sum[rs[u]]) {
        sum[u] = sum[rs[u]];
        s[u] = s[rs[u]];
      }
      else {
        sum[u] = sum[ls[u]];
        s[u] = s[ls[u]];
      }
      return;
    }
    int merge(int u, int v, int l, int r) {
      if (!u) return v;
      if (!v) return u;
      if (l == r) {
        sum[u] += sum[v];
        return u;
      }
      ls[u] = merge(ls[u], ls[v], l, mid);
      rs[u] = merge(rs[u], rs[v], mid + 1, r);
      update(u);
      return u;
    }
    int add(int u, int l, int r, int p, int v) {
      if (!u) u = ++idx;
      if (l == r) {
        sum[u] += v;
        s[u] = p;
        return u;
      }
      if (p <= mid) ls[u] = add(ls[u], l, mid, p, v);
      else          rs[u] = add(rs[u], mid + 1, r, p, v);
      update(u);
      return u;
    }
  }tr;
  void dfs(int u, int fa) {
    for(auto v:ve[u]) {
      if (v == fa)  continue;
      dfs(v, u);
      tr.rt[u] = tr.merge(tr.rt[u], tr.rt[v], 1, inf);
    }
    ans[u] = tr.s[tr.rt[u]];
    if (!tr.sum[tr.rt[u]])  ans[u] = 0;
    return;
  }
  void main() {
    read(n, m);
    REP(i, 1, n - 1) {
      int u, v;
      read(u, v);
      ve[u].pb(v);
      ve[v].pb(u);
    }
    dfs1(1, 0);
    REP(j, 1, 20) {
      for(int i = 1;i + (1ll << j) - 1 <= n;i++) {
        st[i][j] = get(st[i][j - 1], st[i + (1ll << j - 1)][j - 1]);
      }
    }
    REP(i, 1, m) {
      int x, y, z;
      read(x, y, z);
      tr.rt[x] = tr.add(tr.rt[x], 1, inf, z, 1);
      tr.rt[y] = tr.add(tr.rt[y], 1, inf, z, 1);
      int lc = lca(x, y);
      tr.rt[lc] = tr.add(tr.rt[lc], 1, inf, z, -1);
      tr.rt[st[dfn[lc]][0]] = tr.add(tr.rt[st[dfn[lc]][0]], 1, inf, z, -1);
    }
    dfs(1, 0);
    REP(i, 1, n)  std::cout << ans[i] << "\n";
    return ;
  }
}

signed main()
{
  // freopen("c.in","r",stdin);
  // freopen("c.out","w",stdout);
  // std::cin.tie(nullptr) -> sync_with_stdio(false);
  int T=1;
//   read(T);
  while(T--) {
    YZLK::main();
  }

  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

/*

code by yqfff_qwq

交代码之前看一下

这是你的代码吗？这是你要交的题吗？

多测了吗？多测清空了吗？多测清空会超时吗？会出现其他问题吗？

数组开小了吗？模数正确吗？调试删干净了吗？

*/
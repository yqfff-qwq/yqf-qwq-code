#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>

#define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
#define MAX(a, b) (a) = max((a), (b))
#define MIN(a, b) (a) = min((a), (b))
#define pii std::pair<int, int>
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
  const int N = 2e5 + 10;
  int n;
  int cnt, sz[N], f[N];
  std::vector<int> ve[N];
  int a[N];
  bool vis[N];
  int d[N], s1[N], s2[N];//d：当前结点到重心的距离，s1：重心到当前结点的结点权值和，s2：重心到当前结点的定义前缀和
  int rt;
  struct tree{
    #define ls (u << 1)
    #define rs (ls | 1)
    #define mid ((l + r) >> 1)
    struct node{
      int k, b;
    }p[N];
    int tr[N];
    int cal(int id, int x) {
      return p[id].k * x + p[id].b;
    }
    void add(int u, int k, int b) {
      p[u] = {k, b};
      return;
    }
    void upd(int u, int l, int r, int x) {
      int &y = tr[u];
      if (cal(x, mid) > cal(y, mid))  std::swap(x, y);
      if (cal(x, l) > cal(y, l))      upd(ls, l, mid, x);
      if (cal(x, r) > cal(y, r))      upd(rs, mid + 1, r, x);
      return;
    }
    int query(int u, int l, int r, int p) {
      if (l == r) return cal(tr[u], p);
      int ans = cal(tr[u], p);
      if (p <= mid) ans = std::max(ans, query(ls, l, mid, p));
      else          ans = std::max(ans, query(rs, mid + 1, r, p));
      return ans;
    }
    #undef ls
    #undef rs
    #undef mid
  }tr;
  void size(int u, int fa) {
    cnt++;
    sz[u] = 1;
    for(auto v:ve[u]) {
      if (v == fa or vis[v])  continue;
      size(v, u);
      sz[u] += sz[v];
    }
    return;
  }
  void dp(int u, int fa) {
    f[u] = cnt - sz[u];
    for(auto v:ve[u]) {
      if (v == fa or vis[v])  continue;
      dp(v, u);
      f[u] = std::max(f[u], sz[v]);
    }
    if (f[u] < f[rt]) rt = u;
    return;
  }
  void dis(int u, int fa) {

    for(auto v:ve[u]) {
      if (v == fa or vis[v])  continue;
      d[v] = d[u] + 1;
      s1[v] = s1[u] + a[v];
      s2[v] = s2[u] + d[v] * a[v];
      dis(v, u);
    }
  }
  void solve(int u) {
    cnt = 0;
    size(u, u);
    rt = u;
    dp(u, u);
    d[rt] = 1;
    s1[rt] = s2[rt] = 0;
    for(auto v:ve[rt]) {
      if (vis[v]) continue;
      
    }
    return;
  }
  void main() {
    read(n);
    REP(i, 1, n - 1) {
      int u, v;
      read(u, v);
      ve[u].pb(v);
      ve[v].pb(u);
    }

    return ;
  }
}

signed main()
{
  // freopen("array.in","r",stdin);
  // freopen("array.out","w",stdout);
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
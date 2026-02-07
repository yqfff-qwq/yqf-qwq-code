#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>

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
  const int N = 5e5 + 10;
  int n, q;
  std::vector<int> ve[N];
  std::vector<int> qy[N];
  struct tree{
    #define ls (u << 1)
    #define rs (ls | 1)
    #define mid ((l + r) >> 1)
    int tr[N << 2], cnt[N << 2];
    void build(int u, int l, int r) {
      if (l == r) return;
      build(ls, l, mid);
      build(rs, mid + 1, r);
      return;
    }
    void upd(int u, int l, int r, int ql, int qr, int k) {
      if (ql <= l and r <= qr) {
        cnt[u] += k;
        if (cnt[u]) tr[u] = r - l + 1;
        else        tr[u] = tr[ls] + tr[rs];
        return;
      }
      if (ql <= mid)  upd(ls, l, mid, ql, qr, k);
      if (mid < qr)   upd(rs, mid + 1, r, ql, qr, k);
      if (!cnt[u])    tr[u] = tr[ls] + tr[rs];
      return;
    }
    #undef ls
    #undef rs
    #undef mid
  }tr;
  int ans[N];
  int dfn[N], low[N], idx;
  void Dfs(int u) {
    dfn[u] = ++idx;
    for(auto v:ve[u]) Dfs(v);
    low[u] = idx;
    return;
  }
  void dfs(int u) {
    for(auto v:qy[u]) {
      tr.upd(1, 1, n, dfn[u], low[u], 1);
      tr.upd(1, 1, n, dfn[v], low[v], 1);
    }
    ans[u] = tr.tr[1];
    for(auto v:ve[u]) dfs(v);
    for(auto v:qy[u]) {
      tr.upd(1, 1, n, dfn[u], low[u], -1);
      tr.upd(1, 1, n, dfn[v], low[v], -1);
    }
    return;
  }
  void main() {
    read(n, q);
    REP(i, 2, n) {
      int fa;
      read(fa);
      ve[fa].pb(i);
    }
    Dfs(1);
    while(q--) {
      int u, v;
      read(u, v);
      qy[u].pb(v);
      qy[v].pb(u);
    }
    dfs(1);
    tr.build(1, 1, n);
    REP(i, 1, n)  std::cout << std::max(0ll, ans[i] - 1) << ' ';
    return ;
  }
}

signed main()
{
  freopen("reward.in","r",stdin);
  freopen("reward.out","w",stdout);
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
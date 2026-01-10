#include <iostream>
#include <vector>
#include <cstring>
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
  const int N = 1e6 + 10;
  int n, q;
  int a[N];
  bool fl = 1;
  std::vector<int> ve[N];
  int fa[N];
  int query(int u, int d) {
    if (d < 0)  return 0;
    int ans = a[u];
    for(auto v:ve[u]) {
      ans += query(v, d - 1);
    }
    return ans;
  }
  void dfs(int u, int d, int x) {
    if (d < 0)  return;
    a[u] += x;
    for(auto v:ve[u]) {
      dfs(v, d - 1, x);
    }
    return;
  }
  struct tree{
    #define ls (u << 1)
    #define rs (ls | 1)
    #define mid ((l + r) >> 1)
    int tag[N << 2], tr[N << 2];
    void push_up(int u) {
      return tr[u] = tr[ls] + tr[rs], void();
    }
    void push_down(int u, int l, int r) {
      if (tag[u]) {
        tr[ls] += (mid - l + 1) * tag[u];
        tr[rs] += (r - mid) * tag[u];
        tag[ls] += tag[u];
        tag[rs] += tag[u];
        tag[u] = 0;
      }
      return;
    }
    void build(int u, int l, int r) {
      if (l == r) return;
      build(ls, l, mid);
      build(rs, mid + 1, r);
      push_up(u);
      return;
    }
    void modify(int u, int l, int r, int ql, int qr, int v) {
      if (ql <= l and r <= qr) {
        tr[u] += (r - l + 1) * v;
        tag[u] += v;
        return;
      }
      push_down(u, l, r);
      if (ql <= mid)  modify(ls, l, mid, ql, qr, v);
      if (mid < qr)   modify(rs, mid + 1, r, ql, qr, v);
      push_up(u);
      return;
    }
    int query(int u, int l, int r, int ql, int qr) {
      if (ql <= l and r <= qr)  return tr[u];
      push_down(u, l, r);
      int ans = 0;
      if (ql <= mid)  ans += query(ls, l, mid, ql, qr);
      if (mid < qr)   ans += query(rs, mid + 1, r, ql, qr);
      return ans;
    }
  }tr;
  void solve1() {
    int cnt = n + q;
    tr.build(1, 1, cnt);
    REP(i, 1, n)  tr.modify(1, 1, cnt, i, i, a[i]);
    REP(i, 1, q) {
      int op, x, d, v;
      read(op, x, d);
      if (op == 1) {
        read(v);
        tr.modify(1, 1, cnt, x, std::min(n, x + d), v);
      }
      else if (op == 2) {
        std::cout << tr.query(1, 1, cnt, x, std::min(n, x + d)) << '\n';
      }
      else {
        a[++n] = d;
        tr.modify(1, 1, cnt, n, n, a[n]);
      }
    }
    return;
  }
  void main() {
    read(n, q);
    REP(i, 1, n)  read(a[i]);
    REP(i, 2, n) {
      int ff;
      read(ff);
      ve[ff].pb(i);
      if (ff != i - 1)  fl = 0;
    }
    if (fl) {
      solve1();
      return;
    }
    while(q--) {
      int op, x, d, v;
      read(op, x, d);
      if (op == 1) {
        read(v);
        dfs(x, d, v);
      }
      else if (op == 2) {
        std::cout << query(x, d) << '\n';
      }
      else {
        a[++n] = d;
        ve[x].pb(n);
      }
    }
    return ;
  }
}

signed main()
{
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
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
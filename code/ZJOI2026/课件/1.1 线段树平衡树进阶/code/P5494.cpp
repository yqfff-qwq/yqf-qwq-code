#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>
// using namespace std;

#define int long long
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
  const int M = 2e5 + 10;
  const int inf = 1e5;
  int n, m;
  int b[M];
  std::vector<int> ve[M];
  struct tree{
    #define mid ((l + r) >> 1)
    int ls[M << 5], rs[M << 5], rt[M << 2], idx, tot;
    int rub[M << 5], tl;
    int sum[M << 5];
    int nd() {return tl ? rub[tl--] : ++idx;}
    void del(int &p) {
      ls[p] = rs[p] = sum[p] = 0;
      rub[++tl] = p;
      p = 0;
    }
    void push_up(int u) {
      sum[u] = sum[ls[u]] + sum[rs[u]];
      return;
    }
    void build(int &u, int l, int r) {
      if (!u) u = nd();
      if (l == r) {
        sum[u] = b[l];
        return;
      }
      build(ls[u], l, mid);
      build(rs[u], mid + 1, r);
      push_up(u);
      return;
    }
    void update(int &u, int l, int r, int p, int c) {
      if (!u) u = nd();
      if (l == r) return sum[u] += c, void();
      if (p <= mid) update(ls[u], l, mid, p, c);
      else          update(rs[u], mid + 1, r, p, c);
      push_up(u);
      return;
    }
    int merge(int u, int v, int l, int r) {
      if (!u or !v) return u + v;
      if (l == r) {
        sum[u] += sum[v];
        del(v);
        return u;
      }
      ls[u] = merge(ls[u], ls[v], l, mid);
      rs[u] = merge(rs[u], rs[v], mid + 1, r);
      push_up(u);
      del(v);
      return u;
    }
    void split(int &u, int &v, int l, int r, int ql, int qr) {
      if (r < ql or qr < l) return;
      if (!u) return;
      if (ql <= l and r <= qr) {
        v = u;
        u = 0;
        return;
      }
      if (!v) v = nd();
      if (ql <= mid) split(ls[u], ls[v], l, mid, ql, qr);
      if (mid < qr)  split(rs[u], rs[v], mid + 1, r, ql, qr);
      push_up(u);
      push_up(v);
      return;
    }
    int query(int u, int l, int r, int ql, int qr) {
      if (!u) return 0;
      if (ql <= l and r <= qr)  return sum[u];
      int ans = 0;
      if (ql <= mid) ans += query(ls[u], l, mid, ql, qr);
      if (mid < qr)  ans += query(rs[u], mid + 1, r, ql, qr);
      return ans;
    }
    int kth(int u, int l, int r, int k) {
      if (l == r) return l;
      int sz = sum[ls[u]];
      if (k <= sz)  return kth(ls[u], l, mid, k);
      else          return kth(rs[u], mid + 1, r, k - sz);
    }
  }tr;
  void main() {
    read(n, m);
    REP(i, 1, n)  read(b[i]);
    tr.build(tr.rt[++tr.tot], 1, n);
    while(m--) {
      int op, p, x, y;
      read(op);
      if (op == 0) {
        read(p, x, y);
        tr.split(tr.rt[p], tr.rt[++tr.tot], 1, n, x, y);
      }
      else if (op == 1) {
        read(x, y);
        tr.rt[x] = tr.merge(tr.rt[x], tr.rt[y], 1, n);
      }
      else if (op == 2) {
        read(p, x, y);
        tr.update(tr.rt[p], 1, n, y, x);
      }
      else if (op == 3) {
        read(p, x, y);
        std::cout << tr.query(tr.rt[p], 1, n, x, y) << "\n";
      }
      else {
        read(x, y);
        if (tr.sum[tr.rt[x]] < y) std::cout << "-1\n";
        else                      std::cout << tr.kth(tr.rt[x], 1, n, y) << "\n";
      }
    }
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
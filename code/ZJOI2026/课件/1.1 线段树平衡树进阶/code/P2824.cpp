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
  const int N = 1e5 + 10;
  int n, m;
  int a[N], b[N];
  struct nd{
    int op, l, r;
  }qy[N];
  int p;
  struct node{
    #define ls (u << 1)
    #define rs ((ls) | 1)
    #define mid ((l + r) >> 1)
    int sum[N << 2], tg[N << 2];
    void push_up(int u) {
      sum[u] = sum[ls] + sum[rs];
      return;
    }
    void push_down(int u, int l, int r) {
      if (tg[u] != -1) {
        tg[ls] = tg[u];
        tg[rs] = tg[u];
        sum[ls] = (tg[u] * (mid - l + 1));
        sum[rs] = (tg[u] * (r - mid));
        tg[u] = -1;
      }
      return;
    }
    void build(int u, int l, int r) {
      tg[u] = -1;
      if (l == r) {
        sum[u] = b[l];
        return;
      }
      build(ls, l, mid);
      build(rs, mid + 1, r);
      push_up(u);
      return;
    }
    int query(int u, int l, int r, int ql, int qr) {
      if (r < ql or qr < l) return 0;
      if (ql <= l and r <= qr)  return sum[u];
      push_down(u, l, r);
      int ans = 0;
      ans += query(ls, l, mid, ql, qr);
      ans += query(rs, mid + 1, r, ql, qr);
      return ans;
    }
    void modify(int u, int l, int r, int ql, int qr, int c) {
      if (ql > qr)  return;
      if (ql <= l and r <= qr) {
        tg[u] = c;
        sum[u] = c * (r - l + 1);
        return;
      }
      push_down(u, l, r);
      if (ql <= mid)  modify(ls, l, mid, ql, qr, c);
      if (mid < qr)   modify(rs, mid + 1, r, ql, qr, c);
      push_up(u);
      return;
    }
    int q(int u, int l, int r, int x) {
      if (l == r) return sum[u];
      push_down(u, l, r);
      if (x <= mid) return q(ls, l, mid, x);
      else          return q(rs, mid + 1, r, x);
    }
    #undef mid
  }tr;
  bool check(int x) {
    REP(i, 1, n)  b[i] = (a[i] >= x);
    tr.build(1, 1, n);
    REP(i, 1, m) {
      int cnt = tr.query(1, 1, n, qy[i].l, qy[i].r);
      // std::cout << qy[i].l << " " << qy[i].r << " " << cnt << "\n";
      // if (qy[i].r - qy[i].l + 1 < cnt)  {std::cout << "!!!\n";continue;}
      if (qy[i].op == 0) {
        tr.modify(1, 1, n, qy[i].r - cnt + 1, qy[i].r, 1);
        tr.modify(1, 1, n, qy[i].l, qy[i].r - cnt, 0);
      } else {
        tr.modify(1, 1, n, qy[i].l, qy[i].l + cnt - 1, 1);
        tr.modify(1, 1, n, qy[i].l + cnt, qy[i].r, 0);
      }
    }
    return tr.q(1, 1, n, p);
  }
  void main() {
    read(n, m);
    REP(i, 1, n)  read(a[i]);
    REP(i, 1, m)  read(qy[i].op, qy[i].l, qy[i].r);
    read(p);
    int l = 1, r = n, ans = 0;
    while(l <= r) {
      int mid = ((l + r) >> 1);
      if (check(mid)) ans = mid, l = mid + 1;
      else            r = mid - 1;
    }

    std::cout << ans << "\n";
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
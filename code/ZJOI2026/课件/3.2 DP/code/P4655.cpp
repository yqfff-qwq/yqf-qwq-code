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
#define K(_) (a[_].l)
#define X(_) (a[_+1].w)
#define B(_) (f[_])
#define Y(_) (f[_])

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
  const int inf = 1e18;
  const int N = 1e6 + 10;
  const int M = 1e6;
  int n, tot;
  int h[N], w[N], s[N];
  struct node{
    int k, b;
  }p[N];
  int f[N];
  struct tree{
    #define ls (u << 1)
    #define rs (ls | 1)
    #define mid ((l + r) >> 1)
    int tr[N << 2];
    int cal(int d, int x) {
      if (d == 0) return inf;
      return p[d].k * x + p[d].b;
    }
    void update(int u, int l, int r, int x) {
      int &y = tr[u];
      if (cal(x, mid) < cal(y, mid))  std::swap(x, y);
      if (cal(x, l) < cal(y, l))      update(ls, l, mid, x);
      if (cal(x, r) < cal(y, l))      update(rs, mid + 1, r, x);
      return;
    }
    int query(int u, int l, int r, int p) {
      if (l == r) return cal(tr[u], p);
      int ans = cal(tr[u], p);
      if (p <= mid) ans = std::min(ans, query(ls, l, mid, p));
      else          ans = std::min(ans, query(rs, mid + 1, r, p));
      return ans;
    }
    #undef ls
    #undef rs
    #undef mid
  }tr;
  void main() {
    read(n);
    REP(i, 1, n)  read(h[i]);
    REP(i, 1, n)  read(w[i]), s[i] = s[i - 1] + w[i];
    p[0] = {inf, inf};
    p[++tot] = {-2ll * h[1], h[1] * h[1] - s[1]};
    tr.update(1, 0, M, tot);
    REP(i, 2, n) {
      f[i] = h[i] * h[i] + s[i - 1] + tr.query(1, 0, M, h[i]);
      p[++tot] = {-2ll * h[i], f[i] + h[i] * h[i] - s[i]};
      tr.update(1, 0, M, tot);
    }
    std::cout << f[n] << '\n';
    return;
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
s[i]=\sum_{1}^{i} w[i]
f[i]=min(f[j]+s[i-1]-s[j]+(h[i]-h[j])^2)
f[i]=min(f[j]+s[i-1]-s[j]+(h[i]-h[j])^2)
f[i]=s[i-1]+h[i]^2+min(-2h[i]h[j]+f[j]-s[j]+h[j]^2)
f[i]=s[i-1]+h[i]^2+min(-2h[j]h[i]+f[j]-s[j]+h[j]^2)


f[i]=f[j]+s[i-1]-s[j]+(h[i]-h[j])^2
f[i]=f[j]+s[i-1]-s[j]+h[i]^2-2h[i]h[j]+h[j]^2
f[j]+h[j]^2-s[j]=2h[i]h[j]+f[i]-s[i-1]-h[i]^2
y=f[j]+h[j]^2-s[j]
k=2h[i]
x=h[j]
b=-s[i-1]+h[i]^2

*/


/*

code by yqfff_qwq

交代码之前看一下

这是你的代码吗？这是你要交的题吗？

多测了吗？多测清空了吗？多测清空会超时吗？会出现其他问题吗？

数组开小了吗？模数正确吗？调试删干净了吗？

*/
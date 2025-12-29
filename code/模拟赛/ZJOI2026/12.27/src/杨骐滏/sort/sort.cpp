#include <iostream>
#include <algorithm>
#include <cstring>

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
  const int N = 1e6 + 10;
  int a[N], b[N];
  int n, q;
  int st[N], tp;
  int r[N];
  int ans[N];
  bool fl = 0;
  struct node{
    int t, i, id;
  }qy[N];
  struct tree{
    int tr[N];
    int lowbit(int x) {return x & -x;}
    int query(int x) {
      int sum = 0;
      while(x) {
        sum += tr[x];
        x -= lowbit(x);
      }
      return sum;
    }
    void upd(int x, int v) {
      while(x <= n) {
        tr[x] += v;
        x += lowbit(x);
      }
      return;
    }
    int q(int v) {
      int x = 0, y = 0;
      DEP(i, std::__lg(n) + 1, 0) {
        if (x + (1ll << i) <= n and y + tr[x + (1ll << i)] < v) x = x + (1ll << i), y = y + tr[x];
      }
      return x + 1;
    }
    void update() {
      int p = q(n / 2 + 1), x = query(p), y = query(p - 1), ln = x - y, t = b[p];
      if (y == n / 2) return fl = 1, void();
      upd(p, -ln), upd(p, n / 2 - y);
      for(int i = t + n / 2 - y;i <= t + ln - 1;i = r[i]) {
        if (i <= t + ln - 1)  upd(a[i], std::min(r[i], t + ln) - i);
      }
      return;
    }
  }tr;
  void main() {
    read(n, q);
    REP(i, 1, n) {
      read(a[i]), b[a[i]] = i;
      while(tp and a[st[tp]] < a[i])  r[st[tp--]] = i;
      st[++tp] = i;
    }
    while(tp) r[st[tp--]] = n + 1;
    REP(i, 1, q)  read(qy[i].t, qy[i].i), qy[i].id = i;
    
    for(int i = 1;i <= n / 2;i = r[i])      tr.upd(a[i], std::min(r[i], n / 2 + 1) - i);
    for(int i = n / 2 + 1;i <= n;i = r[i])  tr.upd(a[i], r[i] - i);

    std::sort(qy + 1, qy + q + 1, [](node a, node b) {
      return a.t < b.t;
    });
    // REP(i, 1, n)  std::cout << r[i] << ' ';
    // puts("");
    qy[0].t = 1;
    REP(i, 1, q) {
      if (qy[i].t == 0) {ans[qy[i].id] = a[qy[i].i];qy[i].t = 1;continue;}
      REP(j, qy[i - 1].t + 1, qy[i].t) {
        if (fl) break;
        tr.update();
      }
      int p = tr.q(qy[i].i);
      ans[qy[i].id] = a[b[p] + qy[i].i - tr.query(p - 1) - 1];
    }
    REP(i, 1, q)  std::cout << ans[i] << '\n';
    return ;
  }
}

signed main()
{
  freopen("sort.in","r",stdin);
  freopen("sort.out","w",stdout);
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
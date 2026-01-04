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
  const int N = 3e5 + 10;
  const int inf = 1e10;
  int n, m, q;
  int a[N];
  int bk, bl[N];
  int dl[N], dr[N];
  int cnt[N], ans[N];
  int p[N], len;
  int s, mx;
  struct node{
    int l, r, id;
  }qy[N];
  bool cmp(node a, node b) {
    if (bl[a.l] == bl[b.l]) return a.r < b.r;
    return a.l < b.l;
  }
  void add(int x) {
    cnt[x]++;
    if (cnt[x] == mx)  s = std::min(s, p[x]);
    else if (cnt[x] > mx) {
      mx = cnt[x];
      s = p[x];
    }
    return;
  }
  void main() {
    read(n);
    q = n;
    bk = std::sqrt(n);
    REP(i, 1, n)  read(a[i]), p[++len] = a[i], bl[i] = (i - 1) / bk + 1;
    REP(i, 1, bl[n]) dl[i] = (i - 1) * bk + 1, dr[i] = std::min(i * bk, n);
    std::sort(p + 1, p + len + 1);
    len = std::unique(p + 1, p + len + 1) - p - 1;
    REP(i, 1, n)  a[i] = std::lower_bound(p + 1, p + len + 1, a[i]) - p;
    REP(i, 1, q) {
      int l, r;
      read(l, r);
      if (bl[l] == bl[r]) {
        int sum = inf, maxx = -inf;
        REP(j, l, r) {
          cnt[a[j]]++;
          if (cnt[a[j]] == maxx)  sum = std::min(sum, p[a[j]]);
          else if (cnt[a[j]] > maxx) {
            maxx = cnt[a[j]];
            sum = p[a[j]];
          }
        }
        REP(j, l, r)  cnt[a[j]]--;
        ans[i] = sum;
      } else  qy[++m] = {l, r, i};
    }
    std::sort(qy + 1, qy + m + 1, cmp);
    int R = 1;
    REP(i, 1, m) {
      if (bl[qy[i].l] != bl[qy[i - 1].l]) {
        REP(j, 1, len)  cnt[j] = 0;
        R = dr[bl[qy[i].l]];
        s = inf, mx = -inf;
      }
      // std::cout << dr[bl[qy[i].l]] << ' ' << qy[i].r << '\n';
      while(R < qy[i].r) {
        R++;
        add(a[R]);
      }
      int sum = s, maxx = mx;
      DEP(j, dr[bl[qy[i].l]], qy[i].l) {
        cnt[a[j]]++;
        if (cnt[a[j]] == maxx)  sum = std::min(sum, p[a[j]]);
        else if (cnt[a[j]] > maxx) {
          maxx = cnt[a[j]];
          sum = p[a[j]];
        }
      }
      DEP(j, dr[bl[qy[i].l]], qy[i].l)  cnt[a[j]]--;
      ans[qy[i].id] = sum;
    }
    REP(i, 1, q)  std::cout << ans[i] << '\n';
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

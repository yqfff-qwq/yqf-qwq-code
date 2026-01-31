#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>

// #define int long long
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
  const int N = 2e6 + 10;
  int n, m;
  int a[N];
  int b[N];
  int ans[N];
  bool check(int x) {
    int d = 0;
    REP(i, 2, n) {
      d = std::min(d + x, a[i]);
      if (d < a[i - 1]) return 0;
    }
    return m - d <= x;
  }
  bool ch(int x) {
    int d = 0;
    REP(i, 1, n - 1) {
      d += x;
      if (d > a[i + 1]) return 0;
      d = std::max(d, a[i]);
    }
    return m - d >= x;
  }
  void main() {
    read(m, n);
    REP(i, 1, n)  read(a[i]);
    int l = 1, r = m;
    int mx = 1;
    while(l <= r) {
      int mid = (l + r) >> 1;
      if (check(mid)) mx = mid, r = mid - 1;
      else            l = mid + 1;
    }
    l = 1, r = m;
    int mn = 1;
    while(l <= r) {
      int mid = (l + r) >> 1;
      if (ch(mid))  mn = mid, l = mid + 1;
      else          r = mid - 1;
    }
    REP(i, 1, n - 1)  b[i] = a[i + 1] - mn * i;
    b[n - 1] = std::min(b[n - 1], m - mn * n);
    DEP(i, n - 2, 1)  b[i] = std::min(b[i], b[i + 1]);
    int sum = 0;
    REP(i, 1, n - 1) {
      int p = std::min(b[i] - sum, mx - mn);
      sum += p;
      ans[i] = mn * i + sum;
    }
    ans[n] = m;
    REP(i, 0, n)  std::cout << ans[i] << ' ';
    puts("");
    return;
  }
}

signed main()
{
  freopen("synapse.in","r",stdin);
  freopen("synapse.out","w",stdout);
  int T=1;
  read(T);
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
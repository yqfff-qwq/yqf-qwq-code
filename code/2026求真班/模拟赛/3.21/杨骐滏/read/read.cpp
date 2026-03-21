#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>
#include <bitset>

#define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
#define MAX(a, b) (a) = std::max((a), (b))
#define MIN(a, b) (a) = std::min((a), (b))
#define pii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define uint unsigned long long
#define int long long
#define X(_) (_)
#define Y(_) (dp[_] + _ * _)
#define B(_) (dp[_] - _ * _)
#define K(_) (2 * _)

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
  int cal(int l, int r, int x) {
    if (r <= x) return x - l;
    if (x <= l) return r - x;
    return r - l + std::min(x - l, r - x);
  }
  bool check(int x) {
    int r = 1;
    REP(i, 1, n) {
      int l = r;
      while(r <= m and cal(b[l], b[r], a[i]) <= x) r++;
      if (r > m)  return 1;
    }
    return 0;
  }
  void main() {
		read(n, m);
    REP(i, 1, n)  read(a[i]);
    REP(i, 1, m)  read(b[i]);
    int l = 0, r = 2e10;
    while(l < r) {
      int mid = (l + r) >> 1;
      if (check(mid)) r = mid;
      else            l = mid + 1;
    }
    std::cout << l << '\n';
    return;
  }
}

signed main()
{
  freopen("read.in","r",stdin);
  freopen("read.out","w",stdout);
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

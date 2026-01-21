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
  const int N = 5e3 + 10;
  const int inf = 1e18;
  int n, k;
  int a[N];
  int b[N];
  ll f[2][N][3];//0 +- 1 + 2 -
  int ksm(int a, int b) {
    int s = 1;
    while(b) {
      if (b & 1)  s = s * a;
      a = a * a;
      b >>= 1;
    }
    return s;
  }
  void main() {
    read(n, k);
    REP(i, 1, n)  read(a[i]);
    REP(i, 1, k)  read(b[i]);
    memset(f, -0x3f, sizeof(f));
    f[0][0][0] = 0;
    REP(i, 1, n) {
      REP(j, 0, k)  f[i & 1][j][0] = f[i & 1][j][1] = f[i & 1][j][2] = -inf;
      REP(j, 0, k) {
        int p = i & 1;
        f[p][j][0] = std::max(f[p ^ 1][j][0], std::max(f[p ^ 1][j][1] - ksm(a[i], b[j]), f[p ^ 1][j][2] + ksm(a[i], b[j])));
        f[p][j][1] = f[p ^ 1][j][1];
        f[p][j][2] = f[p ^ 1][j][2];
        if (j > 0) {
          f[p][j][0] = std::max(f[p][j][0], f[p ^ 1][j - 1][0]);
          f[p][j][1] = std::max(f[p][j][1], f[p ^ 1][j - 1][0] + ksm(a[i], b[j]));
          f[p][j][2] = std::max(f[p][j][2], f[p ^ 1][j - 1][0] - ksm(a[i], b[j]));
        }
      }
    }
    std::cout << f[n & 1][k][0] << '\n';
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
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
  const int mod = 998244353;
  const int N = 4e5 + 10;
  const int M = 5e2 + 10;
  int n;
  char c[N];
  int a[N];
  int f[M][M];
  int ksm(int a, int b) {
    int s = 1;
    while(b) {
      if (b & 1)  s = s * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return s;
  }
  int inv[N], fac[N];
  void init() {
    inv[0] = fac[0] = 1;
    REP(i, 1, N - 10) fac[i] = fac[i - 1] * i % mod;
    inv[N - 10] = ksm(fac[N - 10], mod - 2);
    DEP(i, N - 11, 1) inv[i] = inv[i + 1] * (i + 1) % mod;
    return;
  }
  int C(int x, int y) {
    return fac[x] * inv[y] % mod * inv[x - y] % mod;
  }
  void main() {
    init();
    read(n);
    scanf("%s", c + 1);
    REP(i, 1, n)  a[i] = c[i] - '0';
    REP(i, 1, n + 1)  f[i][i - 1] = 1, f[i][i] = (a[i] != a[i - 1]);
    DEP(l, n, 1) {
      REP(r, l + 1, n) {
        REP(k, l, r) {
          if (a[k] != a[l - 1]) f[l][r] = (f[l][r] + f[l][k - 1] * f[k + 1][r] % mod * C(r - l, k - l) % mod) % mod;
        }
      }
    }
    std::cout << f[1][n] << '\n';
    return ;
  }
}

signed main()
{
  // freopen("sub.in","r",stdin);
  // freopen("sub.out","w",stdout);
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
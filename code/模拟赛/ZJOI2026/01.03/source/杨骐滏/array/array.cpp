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
  const int N = 4e4 + 10;
  const int mod = 998244353;
  int n, sum;
  int b[N];
  int s[N];
  int fac[N], inv[N];
  int f[2][N];
  int ksm(int a, int b) {
    int s = 1;
    while(b) {
      if (b & 1)  s = s * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return s;
  }
  void init() {
    fac[0] = inv[0] = 1;
    REP(i, 1, N - 10) fac[i] = fac[i - 1] * i % mod;
    inv[N - 10] = ksm(fac[N - 10], mod - 2);
    DEP(i, N - 11, 1) inv[i] = inv[i + 1] * (i + 1) % mod;
    return;
  }
  int C(int x, int y) {
    if (x < y)  return 0;
    return fac[x] * inv[y] % mod * inv[x - y] % mod;
  }

  void main() {
    read(n);
    REP(i, 1, n)  read(b[i]), s[i] = s[i - 1] + b[i];
    init();
    f[0][0] = 1;
    REP(i, 1, n) {
      int nw = i & 1, ls = nw ^ 1;
      std::memset(f[nw], 0, sizeof(f[nw]));
      REP(j, 0, s[i - 1] / 2) {
        int x = s[i - 1] - j * 2;
        int y = s[n] / 2 - j - x;
        REP(k, std::max(0ll, b[i] - y), std::min(b[i], x)) {
          f[nw][j + k] = (f[nw][j + k] + f[ls][j] * C(x, k) % mod * C(y, b[i] - k)) % mod;
        }
      }
    }
    int ans = 0;
    REP(i, 0, s[n] / 2) ans = (ans + f[n & 1][i]) % mod;
    std::cout << ans << '\n';
    return ;
  }
}

signed main()
{
  freopen("array.in","r",stdin);
  freopen("array.out","w",stdout);
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


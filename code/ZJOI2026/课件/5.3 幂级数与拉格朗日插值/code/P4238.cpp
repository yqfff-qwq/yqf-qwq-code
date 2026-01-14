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
  int ksm(int a, int b) {
    int s = 1;
    while(b) {
      if (b & 1)  s = s * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return s;
  }
  int f[N], g[N];
  int tr[N];
  const int inv = ksm(3, mod - 2);
  void ntt(int *f, int len, int op) {
    REP(i, 0, len - 1)  if (i < tr[i])  std::swap(f[i], f[tr[i]]);
    for(int l = 2;l <= len;l <<= 1) {
      int ln = l >> 1;
      int w0 = ksm(op == 1 ? 3 : inv, (mod - 1) / l);
      for(int j = 0;j < len;j += l) {
        int p = 1;
        REP(k, j, j + ln - 1) {
          int t = p * f[k + ln] % mod;
          f[k + ln] = f[k] - t;
          if (f[k + ln] < 0)  f[k + ln] += mod;
          f[k] = f[k] + t;
          if (f[k] >= mod)  f[k] -= mod;
          p = p * w0 % mod;
        }
      }
    }
    if (op == 1)  return;
    int invn = ksm(len, mod - 2);
    REP(i, 0, len - 1)  f[i] = f[i] * invn % mod;
    return;
  }
  void INV(int *g, int *f, int n) {
    if (n == 1) return g[0] = ksm(f[0], mod - 2), void();
    INV(g, f, (n + 1) >> 1);
    int c[N];
    int h = 1;
    while(h < n)  h <<= 1;
    REP(i, 0, h - 1)  tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? h >> 1 : 0);
    REP(i, 0, n - 1)  c[i] = f[i];
    REP(i, n, h - 1)  c[i] = 0;
    ntt(c, h, 1), ntt(g, h, 1);
    REP(i, 0, h - 1)  g[i] = g[i] * (2ll - g[i] * c[i] % mod + mod) % mod;
    ntt(g, h, -1);
    REP(i, n, h - 1)  g[i] = 0;
    return;
  }
  int n;
  void main() {
    read(n);
    REP(i, 0, n - 1)  read(f[i]);
    INV(g, f, n);
    REP(i, 0, n - 1)  std::cout << g[i] << ' ';
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
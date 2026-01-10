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
  std::mt19937 rd(time(0));
  ull n;
  ull p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  ull mul(ull x, ull y, ull mod)  {return (__int128)x * y % mod;}
  ull ksm(ull a, ull b, ull mod) {
    ull s = 1;
    while(b) {
      if (b & 1)  s = mul(s, a, mod);
      a = mul(a, a, mod);
      b >>= 1;
    }
    return s;
  }
  bool MR(ull x) {
    if (x == 1)       return 0;
    if ((x & 1) == 0) return (x == 2);
    if (x % 3 == 0)   return (x == 3);
    ull t = x - 1;
    int c = 0;
    while((t & 1) == 0) c++, t >>= 1;
    REP(i, 0, 11) {
      ull a = ksm(p[i], t, x);
      if (a == 1 or a == x - 1 or a == 0) continue;
      bool b = 0;
      REP(i, 1, c - 1) {
        a = mul(a, a, x);
        if (a == x - 1) {b = 1;break;}
        if (a == 1) return 0;
      }
      if (b == 0) return 0;
    }
    return 1;
  }
  ull Rho(ull x) {
    if (x == 4) return 2;
    if (MR(x))  return x;
    while(1) {
      ull c = rd() % (x - 1) + 1;
      auto f = [&](ull y) -> ull {return (mul(y, y, x) + c) % x;};
      auto gcd = [&](auto &&self, ull a, ull b) -> ull {
        return (b == 0 ? a : self(self, b, a % b));
      };
      ull l = 0, r = 0, p = 1, q;
      do {
        REP(i, 0, 127) {
          l = f(l), r = f(f(r));
          q = mul(p, llabs(l - r), x);
          if (l == r or q == 0) break;
          p = q;
        }
        ull d = gcd(gcd, p, x);
        if (d > 1)  return d;
      } while(l != r);
    }
  }
  ull query(ull x) {
    ull y = Rho(x);
    if (x == y) return x;
    return std::max(query(y), query(x / y));
  }
  void main() {
    read(n);
    if (MR(n))  return puts("Prime"), void();
    std::cout << query(n) << '\n';
    return ;
  }
}

signed main()
{
  // freopen("array.in","r",stdin);
  // freopen("array.out","w",stdout);
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
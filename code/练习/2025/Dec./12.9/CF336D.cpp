#include <iostream>
#include <algorithm>
#include <cstring>
// using namespace std;

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
  const int N = 2e5 + 10;
  const int mod = 1e9 + 7;
  int fac[N], inv[N];
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
    REP(i, 1, N - 10)   fac[i] = fac[i - 1] * i % mod;
    inv[N - 10] = ksm(fac[N - 10], mod - 2);
    DEP(i, N - 11, 1)   inv[i] = inv[i + 1] * (i + 1) % mod;
    return;
  }
  int C(int x, int y) {
    return fac[x] * inv[y] % mod * inv[x - y] % mod;
  }
  int n, m, g;
  void main() {
    init();
    read(n, m, g);
    int ans = 0;
    if (!n) return std::cout << (m == 1 ? g : g ^ 1), void();
    if (!m) return std::cout << (n & 1 ? g ^ 1 : g), void();
    for(int i = g;i <= n;i += 2) {
      ans = (ans + C(n + m - i - 1, m - 1)) % mod;
    }
    if (m == 1) {
      if (n & 1)  ans = (ans + (g ? -1 : 1) + mod) % mod;
      else        ans = (ans + (g ? 1 : -1) + mod) % mod;
    }
    std::cout << ans << "\n";
    return ;
  }
}

signed main()
{
  // freopen("c.in","r",stdin);
  // freopen("c.out","w",stdout);
  // std::cin.tie(nullptr) -> sync_with_stdio(false);
  int T=1;
//   read(T);
  while(T--) {
    YZLK::main();
  }

  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

/*

code by yqfff_qwq

交代码之前看一下

这是你的代码吗？这是你要交的题吗？

多测了吗？多测清空了吗？多测清空会超时吗？会出现其他问题吗？

数组开小了吗？模数正确吗？调试删干净了吗？

*/
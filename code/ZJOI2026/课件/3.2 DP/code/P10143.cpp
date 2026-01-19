#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>

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
  const int mod = 998244353;
  const int M = 210;
  const int N = 3e5 + 10;
  int C, n, T;
  int a[M], t[M];
  ll s[M];
  ll f[N];
  ll pw[N];
  void main() {
    read(C, n, T);
    REP(i, 1, n)  read(a[i]);
    REP(i, 1, n)  read(t[i]), s[i] = s[i - 1] + t[i];
    pw[0] = 1;
    REP(i, 1, n)  pw[i] = pw[i - 1] * 2 % mod;
    ll ans = 0;
    f[0] = 1;
    REP(i, 1, n) {
      int cnt = 0;
      DEP(j, T - t[i], 0) {
        cnt = (cnt + f[j]) % mod;
        f[j + t[i]] = (f[j + t[i]] + f[j]) % mod;
      }
      ans = (ans + (1ll * cnt * a[i] % mod * pw[n - i]) % mod) % mod;
    }
    memset(f, 0, sizeof(f));
    f[0] = 1;
    DEP(i, n, 1) {
      int cnt = 0;
      DEP(j, T - s[i], 0) cnt = (cnt + f[j]) % mod;
      ans = (ans + (1ll * cnt * a[i] % mod * pw[i - 1]) % mod) % mod;
      DEP(j, T - t[i], 0) f[j + t[i]] = (f[j + t[i]] + f[j]) % mod;
    }
    std::cout << ans << '\n';
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
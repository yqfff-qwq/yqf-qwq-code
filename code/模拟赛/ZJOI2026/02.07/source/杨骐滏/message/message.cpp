#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>

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
  const int mod = 1e9 + 7;
  const int N = 2e2 + 10;
  int n, m;
  int a[N];
  int fac[N], inv[N];
  int ans;
  bool f1 = 1, f2 = 1;
  int f[N][N];
  int ksm(int a, int b) {
    int s = 1;
    while(b) {
      if (b & 1)  s = s * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return s;
  }
  int C(int x, int y) {
    int sum = 1;
    REP(i, std::max(x - y + 1, y + 1), x)  sum = sum * i % mod;
    REP(i, 1, std::min(y, x - y)) sum = sum * ksm(i, mod - 2) % mod;      
    // x!/(y!(x-y)!)
    return sum;
  }

  void main() {
    read(n, m);
    REP(i, 1, m) {
      read(a[i]);
      if (a[i] == a[i - 1]) f1 = 0;
      if (a[i] != 1)        f2 = 0;
    }
    if (f1 == 1) {
      int ans = ksm(n, m);
      std::cout << ans << '\n';
      return;
    }
    else if (f2 == 1) {
      int ans = 1;
      f[m][1] = 1;
      DEP(i, m - 1, 0) {
        DEP(j, m + 1, 2) {
          REP(k, i + 1, m)  f[i][j] = (f[i][j] + f[k][j - 1]) % mod;  
        }
      }
      // REP(i, 0, m)
      //   REP(j, 1, std::min(m + 1, n))  std::cout << f[i][j] << " \n"[j == std::min(m + 1, n)];
      REP(j, 0, m) {
        REP(i, 1, std::min(m + 1, n)) {
          ans = (ans + C(n - 1, i - 1) * f[j][i] % mod);
          // std::cout << '[' << C(n - 1, i - 1) << ',' << f[j][i] << ']' << " \n"[i == n];
        }
      }
      std::cout << ans - 1 << '\n';
      return;
    }

    std::cout << ans << '\n';
    return ;
  }
}

signed main()
{
  freopen("message.in","r",stdin);
  freopen("message.out","w",stdout);
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
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
  const int N = 1e2 + 10;
  int n, k, m;
  int ksm(int a, int b) {
    int s = 1;
    while(b) {
      if (b & 1)  s = s * a % m;
      a = a * a % m;
      b >>= 1;
    }
    return s;
  }
  std::vector<int> operator *(std::vector<int> a, std::vector<int> b) {
    std::vector<int> c(k);
    REP(i, 0, k - 1) {
      REP(j, 0, k - 1)  c[(i + j) % k] = (c[(i + j) % k] + a[i] * b[j] % m) % m;
    }
    return c;
  }
  void main() {
		read(n, k, m);
    int ans = ksm(k, n);
    REP(s, 0, k - 1) {
      std::vector<int> a(k);
      REP(i, 0, k - 1)  a[i] = (i * 2 % k != s);
      std::vector<int> f(k);
      f[0] = 1;
      int p = n;
      while(p) {
        if (p & 1)  f = f * a;
        a = a * a;
        p >>= 1;
      }
      ans = (ans - f[s] + m) % m;
    }

    std::cout << ans << '\n';
    return;
  }
}

signed main()
{
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
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

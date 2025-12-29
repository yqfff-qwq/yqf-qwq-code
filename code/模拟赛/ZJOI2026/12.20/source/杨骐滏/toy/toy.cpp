#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

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
  const int N = 3e6 + 10;
  int n, a, b;
  char c[N];
  int dp[N];
  int p[N];
  int s[N];

  void main() {
    read(b, a, n);
    scanf("%s", c + 1);
    REP(i, 1, n)  s[i] = s[i - 1] + c[i] - '0';
    REP(i, 1, n - a + 1) {
      if (s[i + a - 1] - s[i - 1] < b)  return puts("IMPOSSIBLE"), void();
      int l = i, r = i + a - 1;
      while(l < r) {
        int mid = ((l + r + 1) >> 1);
        if (s[i + a - 1] - s[mid - 1] >= b) l = mid;
        else                                r = mid - 1;
      }
      p[i] = l;
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 0;
    REP(i, 1, n - a) {
      if (dp[i] == dp[0]) continue;
      dp[p[i]] = std::min(dp[p[i]], dp[i] + b);
    }
    int ans = dp[0];
    REP(i, 1, n - a + 1) {
      // std::cout << dp[i] << ' ' << p[i] << '\n';
      if (p[i] >= n - a + 1) {
        if (p[i] == p[n - a + 1]) ans = std::min(ans, dp[i]);
        else                      ans = std::min(ans, dp[i] + b);
      }
    }
    if (ans == dp[0]) return puts("IMPOSSIBLE"), void();
    std::cout << ans + n - a + b << '\n';
    
    return ;
  }
}

signed main()
{
  freopen("toy.in","r",stdin);
  freopen("toy.out","w",stdout);

  int T=1;
  // read(T);
  while(T--)
  {
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
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
  const int N = 1e6 + 10;
  int n, l;
  int a[N];
  int s[N];
  void main() {
    read(n, l);
    REP(i, 1, n)  read(a[i]);
    int mx = 0;
    REP(i, 1, n) {
      int sum = 0;
      for(int j = 1;a[i] / j >= j;j++) {
        if (a[i] % j == 0) {
          sum = std::max(sum, std::max(s[(j >= l ? j : 0)], s[(a[i] / j >= l ? a[i] / j : 0)]));
        }
      }
      sum++;
      mx = std::max(mx, sum);
      for(int j = 1;a[i] / j >= j;j++) {
        if (a[i] % j == 0) {
          if (j >= l)         s[j] = std::max(s[j], sum);
          if (a[i] / j >= l)  s[a[i] / j] = std::max(s[a[i] / j], sum);
        }
      }
    }
    std::cout << mx << '\n';
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

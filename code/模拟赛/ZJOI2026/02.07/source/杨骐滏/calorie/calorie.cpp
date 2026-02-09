#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>
#include <set>
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
  const int N = 5e3 + 10;
  const int mod = 998244353;
  int sum[N][N];
  int l[N], r[N];
  int a[N][N], s[N], d[N];
  int n, m;
  void main() {
    read(n, m);
    REP(i, 1, m - 1)  read(d[i]), d[i] += d[i - 1];
    REP(i, 1, m)  REP(j, 1, n)  read(a[i][j]);
    REP(j, 1, n) {
      int tl = 0;
      REP(i, 1, m) {
        l[i] = 0, r[i] = m + 1;
        while(tl and a[s[tl]][j] <= a[i][j])  r[s[tl--]] = i;
        l[i] = s[tl], s[++tl] = i;
      }
      REP(i, 1, m)  sum[l[i] + 1][i] += a[i][j], sum[l[i] + 1][r[i]] -= a[i][j], sum[i + 1][i] -= a[i][j], sum[i + 1][r[i]] += a[i][j];
    }
    REP(i, 1, m)  REP(j, 1, m)  sum[i][j] += sum[i - 1][j];
    REP(i, 1, m)  REP(j, 1, m)  sum[i][j] += sum[i][j - 1];
    int ans = -1e18;
    REP(i, 1, m)
      REP(j, i, m)  ans = std::max(ans, sum[i][j] - d[j - 1] + d[i - 1]);
    std::cout << ans << '\n';
    return ;
  }
}

signed main()
{
  freopen("calorie.in","r",stdin);
  freopen("calorie.out","w",stdout);
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

这是你的代码吗喵？这是你要交的题吗喵？

多测了吗喵？多测清空了吗喵？多测清空会超时吗喵？会出现其他问题吗喵？

数组开小了吗喵？模数正确吗喵？调试删干净了吗喵？

*/
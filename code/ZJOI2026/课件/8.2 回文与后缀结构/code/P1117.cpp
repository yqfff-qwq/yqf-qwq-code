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
  const int N = 2e6 + 10;
  char c[N];
  int n, ans;
  int fail[N];
  int len[N], s[N];
  int dp[N];
  int tot = 1;
  int tr[N][26];
  int getfail(int u, int i) {
    while(i - len[u] - 1 < 1 or c[i - len[u] - 1] != c[i])  u = fail[u];
    return u;
  }
  void main() {
    scanf("%s", c + 1);
    n = strlen(c + 1);
    int mx = 0;
    fail[0] = 1, len[1] = -1;
    REP(i, 1, n) {
      int p = getfail(mx, i);
      if (!tr[p][c[i] - 'a']) {
        fail[++tot] = tr[getfail(fail[p], i)][c[i] - 'a'];
        tr[p][c[i] - 'a'] = tot;
        len[tot] = len[p] + 2;
        s[tot] = s[fail[tot]] + 1;
      }
      mx = tr[p][c[i] - 'a'];
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

这是你的代码吗喵喵？这是你要交的题吗喵喵？

多测了吗喵喵？多测清空了吗喵喵？多测清空会超时吗喵喵？会出现其他问题吗喵喵？

数组开小了吗喵喵？模数正确吗喵喵？调试删干净了吗喵喵？

*/
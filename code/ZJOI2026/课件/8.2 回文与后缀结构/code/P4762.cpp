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
  int fail[N], f[N];
  int len[N], s[N];
  int dp[N];
  int tot = 1;
  int tr[N][5];
  int change(char ch) {
    if (ch == 'A')  return 1;
    if (ch == 'G')  return 2;
    if (ch == 'C')  return 3;
    if (ch == 'T')  return 4;
    return 100;
  }
  int getfail(int u, int i) {
    while(i - len[u] - 1 < 1 or c[i - len[u] - 1] != c[i])  u = fail[u];
    return u;
  }
  void clear() {
    fail[0] = 1, len[1] = -1;
    REP(i, 0, tot)  REP(j, 1, 4)  tr[i][j] = 0;
    tot = 1;
    return;
  }
  std::queue<int> q;
  void main() {
    scanf("%s", c + 1);
    n = strlen(c + 1);
    int mx = 0;
    clear();
    REP(i, 1, n) {
      int p = getfail(mx, i);
      int x = change(c[i]);
      if (!tr[p][x]) {
        fail[++tot] = tr[getfail(fail[p], i)][x];
        tr[p][x] = tot;
        len[tot] = len[p] + 2;
        if (len[tot] <= 2)  s[tot] = fail[tot];
        else {
          int q = s[p];
          while(c[i - len[q] - 1] != c[i] or ((len[q] + 2) << 1) > len[tot])  q = fail[q];  
          s[tot] = tr[q][x];
        }
      }
      mx = tr[p][x];
    }
    // REP(i, 1, tot)  std::cout << len[i] << ' ';
    // REP(i, 1, n)  std::cout << s[i] << ' ';
    // puts("");
    REP(i, 2, tot)  f[i] = len[i];
    REP(i, 1, 4)  if (tr[0][i]) q.push(tr[0][i]);
    ans = n;
    while(!q.empty()) {
      int x = q.front();
      q.pop();
      f[x] = std::min(f[x], f[s[x]] + 1 + len[x] / 2 - len[s[x]]);
      ans = std::min(ans, n - len[x] + f[x]);
      REP(i, 1, 4) {
        if (!tr[x][i])  continue;
        int y = tr[x][i];
        f[y] = std::min(f[y], f[x] + 1);
        q.push(y);
      }
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
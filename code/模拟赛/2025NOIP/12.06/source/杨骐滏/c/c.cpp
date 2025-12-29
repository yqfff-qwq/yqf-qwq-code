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
  const int N = 5e3 + 10;
  int T, n, k;
  int lh, lg;
  struct node{
    int x, y;
  }h[N], g[N];
  int f[N][N];
  int dp[N][N];
  int lst[N][N];//往后多少头牛能配对，因为不会交叉
  int nxh[N], nxg[N];//这头牛之后第一个不能跟它匹配的另一种品种的牛
  bool check(int i, int j) {
    return abs(h[i].x - g[j].x) <= k;
  }
  void solve1() {
    std::memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    REP(i, 0, lh) {
      REP(j, 0, lg) {
        if (i < lh) {
          if (j < lg) {
            if (abs(h[i + 1].x - g[j + 1].x) <= k)  f[i + 1][j + 1] = std::min(f[i + 1][j + 1], f[i][j]);
            f[i + 1][j] = std::min(f[i + 1][j], f[i][j] + h[i + 1].y);
            f[i][j + 1] = std::min(f[i][j + 1], f[i][j] + g[j + 1].y);
          } else {
            f[i + 1][j] = std::min(f[i + 1][j], f[i][j] + h[i + 1].y);
          }
        } else if (j < lg)  f[i][j + 1] = std::min(f[i][j + 1], f[i][j] + g[j + 1].y);
      }
    }
    std::cout << f[lh][lg] << "\n";
    return;
  }
  void solve2() {
    std::memset(dp, -0x3f, sizeof(dp));
    std::memset(f, -0x3f, sizeof(f));
    f[0][0] = dp[0][0] = 0;
    DEP(i, lh, 1) {
      DEP(j, lg, 1) {
        if (check(i, j))  lst[i][j] = lst[i + 1][j + 1] + 1;
        else              lst[i][j] = 0;
      }
    }

    int j = 1;
    REP(i, 1, lh) {
      while(j <= lg and (check(i, j) or g[j].x < h[i].x)) j++;
      nxh[i] = j;
    }
    j = 1;
    REP(i, 1, lg) {
      while(j <= lh and (check(j, i) or h[j].x < g[i].x)) j++;
      nxg[i] = j;
    }
    nxh[0] = nxg[0] = 1;

    REP(i, 0, lh) {
      REP(j, 0, lg) {
        int cnt = std::max(0ll, nxh[i] - j - 1);
        if (i + cnt <= lh and lst[i + 1][j + 1] >= cnt) dp[i + cnt][j + cnt] = std::max(dp[i + cnt][j + cnt], f[i][j]);//向后匹配使得未匹配的距离>k
        cnt = std::max(0ll, nxg[j] - i - 1);
        if (j + cnt <= lg and lst[i + 1][j + 1] >= cnt) f[i + cnt][j + cnt] = std::max(f[i + cnt][j + cnt], dp[i][j]);//向后匹配使得未匹配的距离>k
        

        if (i < lh and j < lg and check(i + 1, j + 1))    f[i + 1][j + 1] = std::max(f[i + 1][j + 1], f[i][j]), dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j]);
        if (i < lh) f[i + 1][j] = std::max(f[i + 1][j], f[i][j] + h[i + 1].y);//同一种牛牛不会被匹配
        if (j < lg) dp[i][j + 1] = std::max(dp[i][j + 1], dp[i][j] + g[j + 1].y);
      }
    }
    std::cout << std::max(f[lh][lg], dp[lh][lg]) << "\n";
    return;
  }
  void main() {
    std::cin >> T >> n >> k;
    char ch;
    REP(i, 1, n) {
      int x, y;
      std::cin >> ch >> x >> y;
      if (ch == 'H')  h[++lh] = {x, y};
      else            g[++lg] = {x, y};
    }
    if (T == 1) {
      solve1();
      return;
    } else {
      solve2();
      return;
    }

    return ;
  }
}

signed main()
{
  // freopen("c.in","r",stdin);
  // freopen("c.out","w",stdout);
  // std::cin.tie(nullptr) -> sync_with_stdio(false);
  int T=1;
  // read(T);
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
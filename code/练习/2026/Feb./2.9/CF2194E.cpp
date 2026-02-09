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
int tt, ttt;

namespace YZLK{
  const int N = 1e6 + 10;
  int n, m, mx;
  std::vector<int> a[N];
  std::vector<int> s1[N], s2[N], s[N];
  std::vector<pii> p;
  std::vector<int> pre[N], suf[N];
  int dx[3] = {0, -1};
  int dy[3] = {-1, 0};
  void main() {
    read(n, m);
    REP(i, 1, n) {
      a[i].clear(), s[i].clear(), s1[i].clear(), s2[i].clear(), pre[i].clear(), suf[i].clear();
    }
    REP(i, 1, n) {
      int x;
      REP(j, 0, m - 1) {
        read(x);
        a[i].pb(x);
        s1[i].pb(0), s2[i].pb(0), s[i].pb(0);
        pre[i].pb(-1e18), suf[i].pb(-1e18);
      }
    }
    REP(i, 1, n) {
      REP(j, 0, m - 1) {
        int x = -1e18;
        if (i > 1)  x = std::max(x, s1[i - 1][j]);
        if (j > 0)  x = std::max(x, s1[i][j - 1]);
        if (x == -1e18) x = 0;
        s1[i][j] = x + a[i][j];
      }
    }
    mx = s1[n][m - 1];
    DEP(i, n, 1) {
      DEP(j, m - 1, 0) {
        int x = -1e18;
        if (i < n)  x = std::max(x, s2[i + 1][j]);
        if (j < m - 1)  x = std::max(x, s2[i][j + 1]);
        if (x == -1e18) x = 0;
        s2[i][j] = x + a[i][j];
        s[i][j] = s1[i][j] + s2[i][j] - a[i][j];
      }
    }
    std::vector<int> d(m + 2, -1e18);
    REP(i, 1, n) {
      std::vector<int> su(m + 2, -1e18);
      DEP(j, m - 1, 0)  su[j] = std::max(su[j + 1], d[j + 1]); 
      REP(j, 0, m - 1)  pre[i][j] = su[j], d[j] = std::max(d[j], s[i][j]);
    }
    std::vector<int> l(n + 2, -1e18);
    REP(j, 0, m - 1) {
      std::vector<int> pr(n + 2, -1e18);
      DEP(i, n, 1)  pr[i] = std::max(pr[i + 1], l[i + 1]); 
      REP(i, 1, n)  suf[i][j] = pr[i], l[i] = std::max(l[i], s[i][j]);
    }
    p.clear();
    int x = n, y = m - 1;
    while(x != 1 or y != 0) {
      p.pb({x, y});
      REP(i, 0, 1) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 1 or yy < 0) continue;
        if (s1[xx][yy] + a[x][y] == s1[x][y]) {x = xx, y = yy;break;}
      }
    }
    // REP(i, 1, n)
    //   REP(j, 0, m - 1)  std::cout << pre[i][j] << " \n"[j == m - 1];
    // puts("");
    //   REP(i, 1, n)
    //   REP(j, 0, m - 1)  std::cout << suf[i][j] << " \n"[j == m - 1];
    p.pb({1, 0});
    int ans = 1e18;
    for(auto it:p) {
      auto [i, j] = it;
      int res = std::max(pre[i][j], suf[i][j]);
      int sum = mx - 2 * a[i][j];
      if (res > -5e17) sum = std::max(res, sum);
      ans = std::min(ans, sum);
    }
    std::cout << std::min(ans, mx) << '\n';
    return ;
  }
}

signed main()
{
  // freopen("array.in","r",stdin);
  // freopen("array.out","w",stdout);
  int T=1;
  read(T);
  ttt = T;
  while(T--)
  {
    tt++;
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
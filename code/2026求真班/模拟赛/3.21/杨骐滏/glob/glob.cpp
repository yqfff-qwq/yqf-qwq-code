#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>
#include <bitset>

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
  const int N = 4e4 + 10;
  std::vector<int> p[N];
  std::vector<int> ve[N];
  struct node{
    int x, y, s;
  }qy[N];
  bool vis[N];
  int n, m, rt;
  void dfs(int u, int fa) {
    for(auto i:p[u]) {
      if (qy[i].x == u) {
        if (vis[qy[i].y]) qy[i].s = 2;
      } else {
        if (vis[qy[i].x]) qy[i].s = 1;
      }
    }
    vis[u] = 1;
    for(auto v:ve[u]) {
      if (v == fa)  continue;
      dfs(v, u);
    }
    vis[u] = 0;
    return;
  }
  void main() {
    read(n);
    REP(i, 1, n) {
      int u, v;
      read(u, v);
      if (v == -1)  rt = u;
      else          ve[u].pb(v), ve[v].pb(u);
    }
    read(m);
    REP(i, 1, m) {
      read(qy[i].x, qy[i].y);
      p[qy[i].x].pb(i);
      p[qy[i].y].pb(i);
    }
    dfs(rt, 0);
    REP(i, 1, m)  std::cout << qy[i].s << '\n';
    return;
  }
}

signed main()
{
  freopen("glob.in","r",stdin);
  freopen("glob.out","w",stdout);
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

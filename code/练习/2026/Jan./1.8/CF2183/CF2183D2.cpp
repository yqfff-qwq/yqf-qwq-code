#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>

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
  const int N = 2e5 + 10;
  int n;
  std::vector<int> ve[N];
  int dep[N], cnt[N];
  bool vis[N];
  int f[N];
  void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    cnt[dep[u]]++;
    if (!vis[dep[u]]) f[dep[u]] = fa, vis[dep[u]] = 1;
    else {
      if (f[dep[u]] != fa)  f[dep[u]] = 0;
    }       
    for(auto v:ve[u]) {
      if (v == fa)  continue;
      dfs(v, u);
    }
    return;
  }
  void main() {
    read(n);
    REP(i, 1, n)  ve[i].clear(), dep[i] = cnt[i] = 0, f[i] = vis[i] = 0;
    REP(i, 1, n - 1) {
      int u, v;
      read(u, v);
      ve[u].pb(v);
      ve[v].pb(u);
    }
    dfs(1, 0);
    int sum = 0;
    REP(i, 1, n)  sum = std::max(sum, cnt[i] + (f[i] != 0));
    std::cout << sum << '\n';
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

这是你的代码吗？这是你要交的题吗？

多测了吗？多测清空了吗？多测清空会超时吗？会出现其他问题吗？

数组开小了吗？模数正确吗？调试删干净了吗？

*/
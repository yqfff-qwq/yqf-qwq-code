#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
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
#define X(_) (s[_])
#define Y(_) (f[_] + s[_] * s[_] - 2ll * s[_])
#define K(_) (2ll * s[_])
#define B(_) (f[_] - s[_] * s[_] - 2ll * s[_] - 1ll)

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
  const int N = 1e5 + 10;
  int n, m, e;
  int ans;
  int he[N], to[N], ne[N], tot;
  bool vis[N];
  int b[N];
  void add(int u, int v) {
    ne[++tot] = he[u];
    he[u] = tot;
    to[tot] = v;
    return;
  }
  bool dfs(int u) {
    for(int i = he[u];i;i = ne[i]) {
      int v = to[i];
      if (vis[v]) continue;
      vis[v] = 1;
      if (!b[v] or dfs(b[v])) {b[v] = u;return 1;}
    }
    return 0;
  }
  void main() {
    read(n, m, e);
    REP(i, 1, e) {
      int u, v;
      read(u, v);
      if (u > n or v > m) continue;
      add(u, v);
    }
    REP(i, 1, n) {
      memset(vis, 0, sizeof(vis));
      ans += dfs(i);
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
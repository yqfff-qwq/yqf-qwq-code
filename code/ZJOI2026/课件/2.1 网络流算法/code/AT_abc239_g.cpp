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
  const int inf = 1e18;
  int n, m, s, t, ans;
  int he[N], to[N], ne[N], c[N], tot = 1;
  int dis[N], pre[N], now[N];
  std::queue<int> q;
  void add(int u, int v, int w) {
    ne[++tot] = he[u];
    he[u] = tot;
    to[tot] = v;
    c[tot] = w;
    return;
  }
  bool bfs() {
    REP(i, 0, n)  dis[i] = inf;
    while(!q.empty()) q.pop();
    q.push(s);
    dis[s] = 0;
    now[s] = he[s];
    while(!q.empty()) {
      int p = q.front();
      q.pop();
      for(int i = he[p];i;i = ne[i]) {
        if (!c[i])  continue;
        int v = to[i];
        if (dis[v] > dis[p] + 1) {
          now[v] = he[v];
          dis[v] = dis[p] + 1;
          q.push(v);
        }
      }
    }
    return dis[t] != inf;
  }
  int dfs(int u, int sum) {
    if (u == t) return sum;
    int res = 0, k;
    for(int i = now[u];i and sum;i = ne[i]) {
      now[u] = i;
      if (!c[i])  continue;
      int v = to[i];
      if (dis[v] == dis[u] + 1) {
        k = dfs(v, std::min(sum, c[i]));
        c[i] -= k;
        c[i ^ 1] += k;
        res += k;
        sum -= k;
      }
    }
    return res;
  }
  void main() {
    read(n, m, s, t);
    REP(i, 1, m) {
      int u, v, w;
      read(u, v, w);
      add(u, v, w);
      add(v, u, 0);
    }
    while(bfs())  ans += dfs(s, inf);
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
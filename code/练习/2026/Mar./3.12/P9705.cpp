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
  const int M = 1e3 + 10;
  const int N = 2e6 + 10;
  const int inf = 1e18;
  int n, m, s, t;
  std::queue<int> q;
  int dis[N];
  int now[N];
  int he[N], ne[N << 1], to[N << 1], c[N << 1], tot = 1;
  void add(int u, int v, int w) {
    ne[++tot] = he[u];
    he[u] = tot;
    to[tot] = v;
    c[tot] = w;
    return;
  }
  bool bfs() {
    REP(i, 0, t)  dis[i] = inf;
    q.push(s);
    dis[s] = 0;
    now[s] = he[s];
    while(!q.empty()) {
      int p = q.front();
      q.pop();
      for(int i = he[p];i;i = ne[i]) {
        if (c[i] == 0)  continue;
        int v = to[i];
        if (dis[v] > dis[p] + 1) {
          now[v] = he[v];
          dis[v] = dis[p] + 1;
          q.push(v);
        }
        if (v == t) return 1;
      }
    }
    return 0;
  }
  int a[N], b[N];
	bool vis[M][M];
  int dfs(int u, int sum) {
    if (u == t) return sum;
    int res = 0;
    for(int i = now[u];i and sum;i = ne[i]) {
      int v = to[i];
      now[u] = i;
      if (c[i] and dis[u] + 1 == dis[v]) {
        int k = dfs(v, std::min(sum, c[i]));
        c[i] -= k;
        c[i ^ 1] += k;
        res += k;
        sum -= k;
      }
    }
    return res;
  }
  std::vector<int> ve[N];
  void main() {
		read(n);
    REP(i, 1, n)  read(a[i]);
    REP(i, 1, n)  read(b[i]);
    read(m);
    REP(i, 1, m) {
      int u, v;
      read(u, v);
      vis[u][v] = 1;
    }
    s = 2 * n + 1, t = s + 1;
    int l = tot;
    REP(i, 1, n) {
      REP(j, 1, n) {
        if (i == j or vis[i][j])  continue;
        add(i * 2, j * 2 - 1, 1);
        ve[i].pb(tot);
        add(j * 2 - 1, i * 2, 0);
      }
    }
    int r = tot;
    REP(i, 1, n) {
      add(s, i * 2, b[i]);
      add(i * 2, s, 0);
      add(i * 2 - 1, t, a[i]);
      add(t, i * 2 - 1, 0);
    }
    int ans = 0;
    while(bfs()) {
      ans += dfs(s, inf);
    }
    std::cout << ans << '\n';
    REP(i, 1, n) {
      for(auto v:ve[i]) {
        if (c[v] == 0)  std::cout << i << " " << (to[v] + 1) / 2 << '\n';
      }
    }
    return;
  }
}

signed main()
{
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
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

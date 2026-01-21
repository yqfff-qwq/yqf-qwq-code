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
  const int N = 2e5 + 10;
  const int inf = 1e12;
  int n, m, k;
  std::vector<pii> ve[N];
  int dis[N], dp[N];
  bool vis[N];
  struct node{
    int u, w;
    bool operator < (const node &e)const{
      return e.w < w;
    }
  };
  int d[N], he = 1, tl;
  std::priority_queue<node> q;
  void dij() {
    REP(i, 1, n)  vis[i] = 0;
    while(!q.empty()) {
      auto [u, ww] = q.top();
      q.pop();
      if (vis[u]) continue;
      vis[u] = 1;
      for(auto it:ve[u]) {
        int v = it.fi, w = it.se;
        if (dis[v] > dis[u] + w) {
          dis[v] = dis[u] + w;
          q.push({v, dis[v]});
        }
      }
    }
    return;
  }
  void main() {
    read(n, m, k);
    REP(i, 1, m) {
      int u, v, w;
      read(u, v, w);
      ve[u].pb({v, w});
      ve[v].pb({u, w});
    }
    REP(i, 2, n)  dis[i] = inf;
    q.push({1, 0});
    dij();
    REP(t, 1, k) {
      REP(i, 1, n)  dp[i] = dis[i];
      he = 1, tl = 0;
      d[++tl] = 0;
      REP(i, 1, n) {
        while(he < tl and (Y(d[tl]) - Y(d[tl - 1])) * (X(i) - X(d[tl])) >= (Y(i) - Y(d[tl])) * (X(d[tl]) - X(d[tl - 1]))) tl--;
        d[++tl] = i;
      }
      REP(i, 1, n) {
        while(he < tl and (Y(d[he + 1]) - Y(d[he])) <= (X(d[he + 1]) - X(d[he])) * K(i)) he++;
        int v = d[he];
        if (v == 0) continue;
        if (dis[i] > dp[v] + (i - v) * (i - v)) {
          dis[i] = dp[v] + (i - v) * (i - v);
          q.push({i, dis[i]});
        }
      }
      dij();
    }
    REP(i, 1, n)  std::cout << dis[i] << ' ';
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
dp[u]=dp[v]+(u-v)^2
dp[u]=dp[v]+u^2-2uv+v^2
-dp[v]-v^2=-2uv+u^2-dp[u]
dp[v]+v^2=2vu+dp[u]-u^2
*/

/*

code by yqfff_qwq

交代码之前看一下

这是你的代码吗？这是你要交的题吗？

多测了吗？多测清空了吗？多测清空会超时吗？会出现其他问题吗？

数组开小了吗？模数正确吗？调试删干净了吗？

*/

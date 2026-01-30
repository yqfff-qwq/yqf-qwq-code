#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>

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
  const int N = 1e6 + 10;
  const int M = 1e3 + 10;
  const int inf = 1e6;
  int n, m;
  int a[M][M], b[M][M];
  ll dis[N];
  bool vis[N];
  int cnt[N];
  std::vector<pii> ve[N];
  int q[N], he, tl;
  void init(int x) {
    REP(i, 0, x + 1)  ve[i].clear();
    return;
  }
  bool spfa() {
    he = 1, tl = 0;
    q[++tl] = 0;
    REP(i, 0, n + m + 2)  dis[i] = 1e9, cnt[i] = vis[i] = 0;
    dis[0] = 0;
    vis[0] = 1;
    while(he <= tl) {
      int u = q[he];
      he++;
      vis[u] = 0;
      cnt[u]++;
      if (cnt[u] == n + m + 1)  return 0;
      for(auto it:ve[u]) {
        int v = it.fi, w = it.se;
        if (dis[v] > dis[u] + w) {
          dis[v] = dis[u] + w;
          if (!vis[v]) {
            q[++tl] = v;
            vis[v] = 1;
          }
        }
      }
    }
    return 1;
  }
  void main() {
    read(n, m);
    REP(i, 1, n - 1)
      REP(j, 1, m - 1)  read(b[i][j]);
    init(n + m + 2);
    REP(i, 2, n) {
      REP(j, 2, m) {
        a[i][j] = b[i - 1][j - 1] - a[i][j - 1] - a[i - 1][j] - a[i - 1][j - 1];
      }
    }
    REP(i, 1, n) { 
      REP(j, 1, m) {
        int u = i, v = j + n;
        if ((i + j) & 1)  std::swap(u, v);
        ve[v].pb({u, inf - a[i][j]});
        ve[u].pb({v, a[i][j]});
      }
    }
    REP(i, 1, n + m)  ve[0].pb({i, 0});
    if (!spfa())  return puts("NO"), void();
    puts("YES");
    REP(i, 1, n) {
      REP(j, 1, m) {
        int sum = (dis[i] - dis[j + n]);
        if ((i + j) & 1)  sum *= -1;
        a[i][j] += sum;
        std::cout << a[i][j] << ' ';
      }
      puts("");
    }
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
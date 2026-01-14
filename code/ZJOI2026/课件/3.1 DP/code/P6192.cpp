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
  const int N = 1e3 + 100;
  int n, m, k;
  int he[N], to[N], ne[N], c[N], tot;
  int te[N];
  int f[N][N];
  bool vis[N];
  void add(int u, int v, int w) {
    ne[++tot] = he[u];
    to[tot] = v;
    c[tot] = w;
    he[u] = tot;
    return;
  }
  void main() {
    read(n, m, k);
    REP(i, 1, m) {
      int u, v, w;
      read(u, v, w);
      add(u, v, w);
      add(v, u, w);
    }
    memset(f, 0x3f, sizeof(f));
    REP(i, 1, k)  read(te[i]), f[te[i]][1ll << (i - 1)] = 0;
    REP(S, 1, (1ll << k) - 1) {
      for(int t = S;t;t = (t - 1) & S) {
        REP(i, 1, n)  f[i][S] = std::min(f[i][S], f[i][t] + f[i][S ^ t]);
      }
      std::priority_queue<pii, std::vector<pii>, std::greater<pii>> q;
      REP(i, 0, n)  vis[i] = 0;
      REP(i, 1, n)  if (f[i][S] != f[0][0]) q.push({f[i][S], i});
      while(!q.empty()) {
        auto t = q.top();
        q.pop();
        if (vis[t.se])  continue;
        vis[t.se] = 1;
        for(int i = he[t.se];i;i = ne[i]) {
          int v = to[i], w = c[i];
          if (f[v][S] > f[t.se][S] + w) {
            f[v][S] = f[t.se][S] + w;
            q.push({f[v][S], v});
          }
        }
      }
    }
    std::cout << f[te[1]][(1ll << k) - 1];
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
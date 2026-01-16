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
  const int M = 1e2 + 10;
  int n, m, k;
  int he[N], to[N], ne[N], c[N], d[N], tot;
  int te[N];
  int f[M][N][M];
  bool vis[M][M];
  struct node{
    int u, w, v;
    bool operator < (const node &e)const{
      return e.w < w;
    }
  };
  void add(int u, int v, int w1, int w2) {
    ne[++tot] = he[u];
    to[tot] = v;
    c[tot] = w1;
    d[tot] = w2;
    he[u] = tot;
    return;
  }
  void main() {
    read(n, m, k);
    memset(f, 0x3f, sizeof(f));
    REP(i, 1, k) {
      read(te[i]);
      f[te[i]][1ll << (i - 1)][0] = 0;
    }
    REP(i, 1, m) {
      int u, v, w1, w2;
      read(u, v, w1, w2);
      add(v, u, w1, w2);
    }
    REP(S, 1, (1ll << k) - 1) {
      REP(u, 1, n) {
        for(int t = (S - 1) & S;t;t = (t - 1) & S) {
          for(int i = 0, j = 0;i + j <= m;i++) {
            while(j <= m and f[u][S ^ t][j] > f[u][t][i]) j++;
            if (i + j <= m) f[u][S][i + j] = std::min(f[u][S][i + j], f[u][t][i]);
          }
        }
        REP(i, 1, m)  f[u][S][i] = std::min(f[u][S][i], f[u][S][i - 1]);
      }
      memset(vis, 0, sizeof(vis));
      std::priority_queue<node> q;
      REP(i, 1, n) {
        REP(j, 0, m)  if (f[i][S][j] < f[0][0][0]) q.push({i, f[i][S][j], j});
      }
      while(!q.empty()) {
        auto t = q.top();
        q.pop();
        if (vis[t.u][t.v]) continue;
        vis[t.u][t.v] = 1;
        for(int i = he[t.u];i;i = ne[i]) {
          int v = to[i], a = c[i], b = d[i];
          if (f[v][S][t.v] > f[t.u][S][t.v] + a and !vis[v][t.v])                     f[v][S][t.v] = f[t.u][S][t.v] + a, q.push({v, f[v][S][t.v], t.v});
          if (t.v < m and f[v][S][t.v + 1] > f[t.u][S][t.v] + b and !vis[v][t.v + 1]) f[v][S][t.v + 1] = f[t.u][S][t.v] + b, q.push({v, f[v][S][t.v + 1], t.v + 1});
        }
      }
    }
    int ans = 1e9;
    REP(i, 0, m) {
      std::cout << (ans = std::min(ans, f[1][(1ll << k) - 1][i])) << ' '; 
    }
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
#include <iostream>
#include <vector>
#include <cstring>

#define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
#define MAX(a, b) (a) = max((a), (b))
#define MIN(a, b) (a) = min((a), (b))
#define pii pair<int, int>
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
  const int N = 1e2 + 10;
  int n, mod;
  int a[N];
  int f[N][N][2];
  int sz[N];
  int c[N][N];
  int d[N][N];
  int dp[N][N][N];
  int nxt[N][N][2];
  void add(int &x, int y) {x = (x + y) % mod;}
  std::vector<int> ve[N];
  void dfs(int u, int fa = 0) {
    for(auto v:ve[u]) if (v != fa)  dfs(v, u);
    memset(f, 0, sizeof(f));
    memset(c, 0, sizeof(c));
    f[0][0][0] = 1;
    f[0][0][1] = a[u];
    for(auto v:ve[u]) {
      if (v == fa)  continue;
      REP(i, 0, sz[u] + sz[v])
        REP(j, 0, sz[u] + sz[v])  nxt[i][j][0] = nxt[i][j][1] = 0;
      REP(i, 0, sz[u])
        REP(j, 0, sz[u] - i) {
          int v1 = f[i][j][0], v2 = f[i][j][1];
          if (!v1 and !v2)  continue;
          REP(p, 0, sz[v])
            REP(q, 0, sz[v] - p) {
              int vl= dp[v][p][q];
              if (!vl)  continue;
              if (v1) {
                add(nxt[i + p][j + q][0], v1 * vl % mod);
                if (p)  add(nxt[i + p - 1][j + q][0], v1 * vl % mod * p % mod);
                if (q)  add(nxt[i + p][j + q - 1][1], v1 * vl % mod * q % mod);
              }
              if (v2) {
                add(nxt[i + p][j + q][1], v2 * vl % mod);
                if (p)  add(nxt[i + p - 1][j + q][1], v2 * vl % mod * p % mod);
              }
            }
        }
      REP(i, 0, sz[u] + sz[v])
        REP(j, 0, sz[u] + sz[v])  f[i][j][0] = nxt[i][j][0], f[i][j][1] = nxt[i][j][1];
      sz[u] += sz[v];    
    }
    REP(i, 0, sz[u])
      REP(j, 0, sz[u])  dp[u][i][j] = f[i][j][1];
    sz[u] = 1;
    c[1][0] = 1, c[0][1] = a[u];
    for(auto v:ve[u]) {
      if (v == fa)  continue;
      REP(i, 0, sz[u] + sz[v])
        REP(j, 0, sz[u] + sz[v])  d[i][j] = 0;
      REP(i, 0, sz[u])
        REP(j, 0, sz[u] - i) {
          int v1 = c[i][j];
          if (!v1)  continue;
          REP(p, 0, sz[v])
            REP(q, 0, sz[v] - p) {
              int vl = dp[v][p][q];
              if (!vl) continue;
              add(d[i + p][j + q], v1 * vl % mod);
            }
        }
      REP(i, 0, sz[u] + sz[v])
        REP(j, 0, sz[u] + sz[v])  c[i][j] = d[i][j];
      sz[u] += sz[v];
    }
    REP(i, 0, sz[u])
      REP(j, 0, sz[u])  add(dp[u][i][j], c[i][j]);
    return;
  }
  void main() {
    read(n, mod);
    REP(i, 1, n)  read(a[i]);
    REP(i, 1, n - 1) {
      int u, v;
      read(u, v);
      ve[u].pb(v), ve[v].pb(u);
    }
    dfs(1);
    std::cout << dp[1][0][0] << "\n";
    return ;
  }
}

signed main()
{
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);

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
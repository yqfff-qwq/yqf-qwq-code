#include <iostream>
#include <vector>
#include <cstring>
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
  const int N = 5e2 + 10;
  const int M = 2e5 + 10;
  int n, m, len;
  int f[N][N], g[N][N];
  struct node{
    int u, v, w;
  }d[M];
  int s[N];
  void main() {
    read(n, m);
    memset(g, 0x3f, sizeof(g));
    memset(f, 0x3f, sizeof(f));
    REP(i, 1, m) {
      int u, v, w;
      read(u, v, w);
      g[u][v] = std::min(g[u][v], w);
      g[v][u] = std::min(g[v][u], w);
      f[u][v] = f[v][u] = 1;
    }
    REP(i, 1, n)  f[i][i] = g[i][i] = 0;
    REP(k, 1, n) {
      REP(i, 1, n) {
        if (i == k) continue;
        REP(j, 1, n) {
          if (i == j or k == j) continue;
          f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
        }
      }
    }
    REP(i, 1, n) {
      REP(j, 1, i - 1) {
        if (g[i][j] != g[0][0]) d[++len] = {i, j, g[i][j]};
      }
    }
    std::sort(d + 1, d + len + 1, [](node a, node b) {
      return a.w > b.w;
    });
    memset(s, 0x3f, sizeof(s));
    s[1] = 0;
    REP(i, 1, len) {
      int u = d[i].u, v = d[i].v, w = d[i].w;
      REP(j, 1, n) {
        s[j] = std::min(s[j], s[v] + (f[u][j] + 1) * w);
        s[j] = std::min(s[j], s[u] + (f[v][j] + 1) * w);
      }
    }
    // REP(i, 1, n)  std::cout << s[i] << " \n"[i == n];
    std::cout << s[n] << '\n';
    return ;
  }
}

signed main()
{
  freopen("fly.in","r",stdin);
  freopen("fly.out","w",stdout);
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
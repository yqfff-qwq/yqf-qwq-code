#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>

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
  int n, m;
  char c[N];
  int he[N], ne[N], to[N], tot;
  int nxt[N];
  int st[N][21];
  int dfn[N], tim;
  int get(int u, int v) {return (dfn[u] < dfn[v] ? u : v);}
  void dfs(int u, int fa) {
    st[dfn[u] = ++tim][0] = fa;
    for(int i = he[u];i;i = ne[i]) {
      int v = to[i];
      dfs(v, u);
    }
    return;
  }
  void add(int u, int v) {
    ne[++tot] = he[u];
    he[u] = tot;
    to[tot] = v;
    return;
  }
  int lca(int u, int v) {
    if (u == v) return u;
    u = dfn[u], v = dfn[v];
    if (u > v)  std::swap(u, v);
    u++;
    int k = std::__lg(v - u + 1);
    return get(st[u][k], st[v - (1ll << k) + 1][k]);
  }
  void main() {
    scanf("%s", c + 1);
    n = strlen(c + 1);
    for(int i = 2, j = 0;i <= n;i++) {
      while(c[i] != c[j + 1] and j) j = nxt[j];
      if (c[i] == c[j + 1]) j++;
      nxt[i] = j;
    }
    REP(i, 1, n)  add(nxt[i], i);
    dfs(0, 0);
    REP(j, 1, 20) {
      for(int i = 1;(i + (1ll << j) - 1) <= tim;i++) {
        st[i][j] = get(st[i][j - 1], st[i + (1ll << (j - 1))][j - 1]);
      }
    }
    read(m);
    REP(i, 1, m) {
      int p, q;
      read(p, q);
      int lc = lca(p, q);
      if (lc == p or lc == q) lc = st[dfn[lc]][0];
      std::cout << lc << '\n';
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

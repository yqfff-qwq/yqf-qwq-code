#include <iostream>
#include <algorithm>
#include <cstring>
// using namespace std;

// #define int long long
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
  const int N = 2e6 + 10;
  int n;
  int he[N], to[N], ne[N], c[N], tot;
  int dis[N];
  int vis[N * 10];
  void add(int u, int v, int w) {
    ne[++tot] = he[u];
    he[u] = tot;
    to[tot] = v;
    c[tot] = w;
    return;
  }
  int dep[N], sz[N], L[N], R[N], d[N], son[N], idx;
  int ans[N];
  void dfs1(int u, int fa) {
    dep[u] = dep[fa] + 1;
    sz[u] = 1;
    L[u] = ++idx;
    d[idx] = u;
    for(int i = he[u];i;i = ne[i]) {
      int v = to[i];
      dis[v] = dis[u] ^ c[i];
      dfs1(v, u);
      sz[u] += sz[v];
      if (sz[son[u]] < sz[v]) son[u] = v;
    }
    R[u] = idx;
    return;
  }
  void dfs2(int u, bool kp) {
    for(int i = he[u];i;i = ne[i]) {
      int v = to[i];
      if (v == son[u])  continue;
      dfs2(v, 0);
      ans[u] = std::max(ans[u], ans[v]);
    }
    if (son[u]) {
      dfs2(son[u], 1);
      ans[u] = std::max(ans[u], ans[son[u]]);
    }

    if(vis[dis[u]])   ans[u] = std::max(ans[u], vis[dis[u]] - dep[u]);
    REP(i, 0, 21)     if(vis[dis[u] ^ (1 << i)]) ans[u] = std::max(ans[u], vis[dis[u] ^ (1 << i)] - dep[u]);
    vis[dis[u]] = std::max(dep[u] , vis[dis[u]]) ;

    for(int i = he[u];i;i = ne[i]) {
      int v = to[i];
      if (v == son[u])  continue;
      REP(j, L[v], R[v]) {
        int k = d[j]; 
        if(vis[dis[k]])              ans[u] = std::max(ans[u], vis[dis[k]] + dep[k] - 2 * dep[u]); 
        REP(p, 0, 21)
          if(vis[dis[k] ^ (1 << p)]) ans[u] = std::max(ans[u], vis[dis[k] ^ (1 << p)] + dep[k] - 2 * dep[u]); 
      }
      REP(j, L[v], R[v])  vis[dis[d[j]]] = std::max(vis[dis[d[j]]], dep[d[j]]);
    }
    if (!kp)  REP(i, L[u], R[u])  vis[dis[d[i]]] = 0;
    return;
  }
  void main() {
    std::cin >> n;
    REP(i, 2, n) {
      int f;
      char c;
      std::cin >> f >> c;
      add(f, i, (1ll <<  (c - 'a')));
    }
    dfs1(1, 1);
    dfs2(1, 1);
    REP(i, 1, n)  std::cout << ans[i] << " ";
    return ;
  }
}

signed main()
{
  // freopen("c.in","r",stdin);
  // freopen("c.out","w",stdout);
  std::cin.tie(nullptr) -> sync_with_stdio(false);
  int T=1;
  // read(T);
  while(T--) {
    YZLK::main();
  }

  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

/*

code by yqfff_qwq

交代码之前看一下

这是你的代码吗？这是你要交的题吗？

多测了吗？多测清空了吗？多测清空会超时吗？会出现其他问题吗？

数组开小了吗？模数正确吗？调试删干净了吗？

*/
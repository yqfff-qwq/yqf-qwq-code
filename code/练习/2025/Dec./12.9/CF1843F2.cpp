#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
// using namespace std;

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
  const int N = 2e5 + 10;
  int n, tot = 1;
  int d[N];
  std::vector<int> ve[N];
  struct node{
    int u, v, w;
  }qy[N];
  int len;


  int dep[N];
  int fa[N][21];
  int mxp[N][21];//表示一段最大的前缀
  int mnp[N][21];//表示一段最小的前缀
  int mxf[N][21];//表示一段最大的后缀
  int mnf[N][21];//表示一段最小的后缀
  int mx[N][21], mn[N][21];

  int s[N][21];

  void dfs1(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    mxp[u][0] = d[u];
    mnp[u][0] = d[u];
    mxf[u][0] = d[u];
    mnf[u][0] = d[u];
    mx[u][0] = mn[u][0] = d[u];
    s[u][0] = d[u];

    for(int i = 1;(1ll << i) <= dep[u];i++) {
      fa[u][i] = fa[fa[u][i - 1]][i - 1];
      s[u][i] = s[u][i - 1] + s[fa[u][i - 1]][i - 1];
      mxp[u][i] = std::max(mxp[fa[u][i - 1]][i - 1], s[fa[u][i - 1]][i - 1] + mxp[u][i - 1]);
      mnp[u][i] = std::min(mnp[fa[u][i - 1]][i - 1], s[fa[u][i - 1]][i - 1] + mnp[u][i - 1]);
      mxf[u][i] = std::max(mxf[u][i - 1], s[u][i - 1] + mxf[fa[u][i - 1]][i - 1]);
      mnf[u][i] = std::min(mnf[u][i - 1], s[u][i - 1] + mnf[fa[u][i - 1]][i - 1]);
      mx[u][i] = std::max(std::max(mx[u][i - 1], mx[fa[u][i - 1]][i - 1]), mxp[u][i - 1] + mxf[fa[u][i - 1]][i - 1]);
      mn[u][i] = std::min(std::min(mn[u][i - 1], mn[fa[u][i - 1]][i - 1]), mnp[u][i - 1] + mnf[fa[u][i - 1]][i - 1]);
      // std::cout << u << " " << i << "\n";
      // std::cout << mxp[u][i] << " " << mnp[u][i] << " " << mxf[u][i] << " " << mnf[u][i] << " " << mx[u][i] << " " << mn[u][i] << "\n";
    }
    for(auto v:ve[u]) {
      dfs1(v, u);
    }
    return;
  }

  int query(int x, int y, int k) {
    if (dep[x] < dep[y])  std::swap(x, y);
    int uxp = 0, unp = 0, vxp = 0, vnp = 0;
    int sx = 0, sn = 0;

    // std::cout << dep[x] << " " << dep[y] << "\n";

    while(dep[x] > dep[y]) {
      int p = std::__lg(dep[x] - dep[y]);

      // std::cout << x << " " << dep[x] << "\n";
      // std::cout << std::__lg(1) << "\n";
      // std::cout << dep[x] << " " << dep[y] << " " << p << "\n";

      // std::cout << p << " " << x << "\n";

      sx = std::max(sx, mx[x][p]);
      sn = std::min(sn, mn[x][p]);
      sx = std::max(sx, uxp + mxf[x][p]);
      sn = std::min(sn, unp + mnf[x][p]);
      uxp = std::max(uxp + s[x][p], mxp[x][p]);
      unp = std::min(unp + s[x][p], mnp[x][p]);
      
      // std::cout << x << " " << mxp[x][p] << "\n";


      x = fa[x][p];
      // std::cout << x << " " << dep[x] << "\n";
    }
    if (x == y) {
      sx = std::max(sx, mx[x][0]);
      sn = std::min(sn, mn[x][0]);
      sx = std::max(sx, uxp + d[x]);
      sn = std::min(sn, unp + d[x]);
      if (k < 0)  return std::min(sn, 0ll);
      else        return std::max(sx, 0ll);
    }


    // std::cout << unp << "\n";
    // std::cout << x << " " << std::__lg(dep[x]) << "\n";

    for(int p = std::__lg(dep[x]); p >= 0;p--) {
      if (fa[x][p] != fa[y][p]) {
        sx = std::max(sx, mx[x][p]);
        sn = std::min(sn, mn[x][p]);
        sx = std::max(sx, uxp + mxf[x][p]);
        sn = std::min(sn, unp + mnf[x][p]);
        uxp = std::max(uxp + s[x][p], mxp[x][p]);
        unp = std::min(unp + s[x][p], mnp[x][p]);

        sx = std::max(sx, mx[y][p]);
        sn = std::min(sn, mn[y][p]);
        sx = std::max(sx, vxp + mxf[y][p]);
        sn = std::min(sn, vnp + mnf[y][p]);
        vxp = std::max(vxp + s[y][p], mxp[y][p]);
        vnp = std::min(vnp + s[y][p], mnp[y][p]);
        x = fa[x][p];
        y = fa[y][p];
      }
    }

    int p = 0;
    sx = std::max(sx, mx[x][p]);
    sn = std::min(sn, mn[x][p]);
    sx = std::max(sx, uxp + mxf[x][p]);
    sn = std::min(sn, unp + mnf[x][p]);
    uxp = std::max(uxp + s[x][p], mxp[x][p]);
    unp = std::min(unp + s[x][p], mnp[x][p]);

    sx = std::max(sx, mx[y][p]);
    sn = std::min(sn, mn[y][p]);
    sx = std::max(sx, vxp + mxf[y][p]);
    sn = std::min(sn, vnp + mnf[y][p]);
    vxp = std::max(vxp + s[y][p], mxp[y][p]);
    vnp = std::min(vnp + s[y][p], mnp[y][p]);
    
    // std::cout << unp << " " << vnp << "\n";

    x = fa[x][p];
    y = fa[y][p];

    sx = std::max(sx, mx[x][0]);
    sn = std::min(sn, mn[x][0]);
    sx = std::max(sx, std::max(uxp, 0ll) + std::max(0ll, vxp) + d[x]);
    sn = std::min(sn, std::min(unp, 0ll) + std::min(0ll, vnp) + d[x]);
    
    if (k < 0)  return std::min(sn, 0ll);
    else        return std::max(sx, 0ll);
  }

  void main() {
    std::cin >> n;
    tot = 1;
    len = 0;
    d[tot] = 1;
    REP(i, 1, n)  ve[i].clear();
    REP(i, 1, n) {
      REP(j, 0, 20) fa[i][j] = mxp[i][j] = mnp[i][j] = mxf[i][j] = mnf[i][j] = mx[i][j] = mn[i][j] = s[i][j] = 0;
    }

    
    REP(i, 1, n) {
      char op;
      int x, y, z;
      std::cin >> op >> x >> y;
      if (op == '?') {
        std::cin >> z;
        qy[++len] = {x, y, z};
      } else {
        d[++tot] = y;
        ve[x].pb(tot);
      }
    }
    
    dfs1(1, 0);

    REP(i, 1, len) {
      int ans = query(qy[i].u, qy[i].v, qy[i].w);

      // std::cout << ans << "\n";
      if (abs(ans) >= abs(qy[i].w)) puts("YES");
      else                          puts("NO");
    }


    return ;
  }
}

signed main()
{
  // freopen("c.in","r",stdin);
  // freopen("c.out","w",stdout);

  std::cin.tie(nullptr) -> sync_with_stdio(false);
  int T=1;
  std::cin >> T;
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
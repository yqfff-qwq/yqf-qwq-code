#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
 
// #define int long long
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
  const int N = 1e5 + 10;
  int n, m;
  int a[N];
  int bl[N], bk;
  std::vector<int> ve[N];
  std::vector<int> p;
  int ans[N], sum;
  int L[N], R[N];
  int dfn[N];
  int dep[N];
  int st[N][20];
  int idx;
  int cnt[N];
  bool vis[N];
  struct node{
    int x, y, id, lc;
  }qy[N];
  bool cmp(node a, node b) {
    if (bl[a.x] == bl[b.x]) {
      if (bl[a.x] & 1)  return a.y > b.y;
      return a.y < b.y;
    }
    return a.x < b.x; 
  }
  void dfs(int u, int ff) {
    dep[u] = dep[ff] + 1;
    st[u][0] = ff;
    L[u] = ++idx;
    dfn[idx] = u;
    for(auto v:ve[u]) {
      if (v == ff)  continue;
      dfs(v, u);
    }
    R[u] = ++idx;
    dfn[idx] = u;
    return;
  }
  int lca(int x, int y) {
    if (dep[x] < dep[y])  std::swap(x, y);
    DEP(i, 16, 0) if (dep[st[x][i]] >= dep[y])  x = st[x][i];
    if (x == y) return x;
    DEP(i, 16, 0) if (st[x][i] != st[y][i]) x = st[x][i], y = st[y][i];
    return st[x][0];
  }
  void upd(int x) {
    vis[x] ^= 1;
    if (vis[x]) {
      cnt[a[x]]++;
      if (cnt[a[x]] == 1) sum++;
    }
    else {
      cnt[a[x]]--;
      if (!cnt[a[x]])     sum--;
    }
    // std::cout << x << ' ' << sum << '\n';
    return;
  }
  void main() {
    read(n, m);
    bk = 2 * n / sqrt(m * 2.0 / 3.0);
    REP(i, 1, n)  read(a[i]), bl[i] = (i - 1) / bk + 1, p.pb(a[i]);
    REP(i, n + 1, 2 * n)  bl[i] = (i - 1) / bk + 1;  
    std::sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    REP(i, 1, n)  a[i] = lower_bound(p.begin(), p.end(), a[i]) - p.begin();
    REP(i, 1, n - 1) {
      int u, v;
      read(u, v);
      ve[v].pb(u);
      ve[u].pb(v);
    }
    dfs(1, 0);
    REP(j, 1, 16) {
      for(int i = 1;i <= n;i++) {
        st[i][j] = st[st[i][j - 1]][j - 1];
      }
    }
    // REP(i, 1, n)  std::cout << L[i] << ' ' << R[i] << '\n';
    REP(i, 1, m) {
      int x, y;
      read(x, y);
      if (L[x] > L[y])  std::swap(x, y);
      int lc = lca(x, y);
      qy[i] = {x == lc ? L[x] : R[x], L[y], i, lc};
    }
    std::sort(qy + 1, qy + m + 1, cmp);
    int l = 1, r = 0;
    REP(i, 1, m) {
      while(l > qy[i].x)  upd(dfn[--l]);
      while(r < qy[i].y)  upd(dfn[++r]);
      while(l < qy[i].x)  upd(dfn[l++]);
      while(r > qy[i].y)  upd(dfn[r--]);
      ans[qy[i].id] = sum + !(cnt[a[qy[i].lc]]);
    }
    REP(i, 1, m) std::cout << ans[i] << '\n';
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
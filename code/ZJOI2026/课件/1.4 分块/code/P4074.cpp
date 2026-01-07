#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
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
  const int N = 2e5 + 10;
  int n, m, q;
  int a[N], b[N], c[N];
  int bl[N], bk;
  std::vector<int> ve[N];
  int ans[N], sum;
  int L[N], R[N];
  int dfn[N];
  int dep[N];
  int st[N][20];
  int idx;
  int cnt[N];
  bool vis[N];
  int l1, l2;
  struct node{
    int x, y, id, t, lc;
  }qy[N];
  pii d[N];
  bool cmp(node a, node b) {
    if (bl[a.x] == bl[b.x]) {
      if (bl[a.y] == bl[b.y])  return a.t < b.t;
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
    DEP(i, 18, 0) if (dep[st[x][i]] >= dep[y])  x = st[x][i];
    if (x == y) return x;
    DEP(i, 18, 0) if (st[x][i] != st[y][i]) x = st[x][i], y = st[y][i];
    return st[x][0];
  }
  void upd(int x) {
    vis[x] ^= 1;
    if (vis[x]) {
      cnt[c[x]]++;
      sum += a[c[x]] * b[cnt[c[x]]];
    }
    else {
      sum -= a[c[x]] * b[cnt[c[x]]];
      cnt[c[x]]--;
    }
    // std::cout << x << ' ' << sum << '\n';
    return;
  }
  void main() {
    read(n, m, q);
    bk = pow(2 * n, 2.0 / 3.0);
    REP(i, 1, m)  read(a[i]);
    REP(i, 1, n)  read(b[i]), bl[i] = (i - 1) / bk + 1;
    REP(i, n + 1, 2 * n)  bl[i] = (i - 1) / bk + 1;  
    REP(i, 1, n - 1) {
      int u, v;
      read(u, v);
      ve[v].pb(u);
      ve[u].pb(v);
    }
    REP(i, 1, n)  read(c[i]);
    dfs(1, 0);
    REP(j, 1, 18) {
      for(int i = 1;i <= n;i++) {
        st[i][j] = st[st[i][j - 1]][j - 1];
      }
    }
    // REP(i, 1, n)  std::cout << L[i] << ' ' << R[i] << '\n';
    REP(i, 1, q) {
      int op, x, y;
      read(op, x, y);
      if (op) {
        if (L[x] > L[y])  std::swap(x, y);
        int lc = lca(x, y);
        l1++;
        qy[l1] = {x == lc ? L[x] : R[x], L[y], l1, l2, lc};
      } else d[++l2] = {x, y};
    }
    // std::cout << l1 << '\n';
    std::sort(qy + 1, qy + l1 + 1, cmp);
    int l = 1, r = 0, t = 0;
    REP(i, 1, l1) {
      while(l > qy[i].x)  upd(dfn[--l]);
      while(r < qy[i].y)  upd(dfn[++r]);
      while(l < qy[i].x)  upd(dfn[l++]);
      while(r > qy[i].y)  upd(dfn[r--]);
      while(t < qy[i].t) {
        t++;
        if (l <= L[d[t].fi] and L[d[t].fi] <= r)  upd(d[t].fi);
        if (l <= R[d[t].fi] and R[d[t].fi] <= r)  upd(d[t].fi);
        std::swap(d[t].se, c[d[t].fi]);
        if (l <= L[d[t].fi] and L[d[t].fi] <= r)  upd(d[t].fi);
        if (l <= R[d[t].fi] and R[d[t].fi] <= r)  upd(d[t].fi);
      }
      while(t > qy[i].t) {
        if (l <= L[d[t].fi] and L[d[t].fi] <= r)  upd(d[t].fi);
        if (l <= R[d[t].fi] and R[d[t].fi] <= r)  upd(d[t].fi);
        std::swap(d[t].se, c[d[t].fi]);
        if (l <= L[d[t].fi] and L[d[t].fi] <= r)  upd(d[t].fi);
        if (l <= R[d[t].fi] and R[d[t].fi] <= r)  upd(d[t].fi);
        t--;
      }
      if (qy[i].lc != dfn[qy[i].x]) {
        upd(qy[i].lc);
        ans[qy[i].id] = sum;
        upd(qy[i].lc);
      } 
      else  ans[qy[i].id] = sum;
    }
    REP(i, 1, l1) std::cout << ans[i] << '\n';
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
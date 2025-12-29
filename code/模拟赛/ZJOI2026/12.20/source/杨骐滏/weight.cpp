#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

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
  const int N = 3e5 + 10;
  const int mod = 998244353;
  int n, t;
  int w[N];
  int he[N], to[N << 1], ne[N << 1], tot;
  int sx[N], fa[N], sz[N];
  int top[N], L[N], R[N], dfn[N], idx;
  int son[N], ans[N];
  void add(int u, int v) {
    ne[++tot] = he[u], he[u] = tot, to[tot] = v;
    return;
  }
  void dfs(int u, int ff) {
    sx[u] = sx[ff] ^ w[u], fa[u] = ff, sz[u] = 1;
    for(int i = he[u];i;i = ne[i]) {
      int v = to[i];
      if (v == ff)  continue;
      dfs(v, u);
      sz[u] += sz[v];
      if (sz[v] > sz[son[u]]) son[u] = v;
    }
    return;
  }
  std::vector<int> vh[N], vl[N];
  void DFS(int u, int tp) {
    top[u] = tp;
    L[u] = ++idx;
    dfn[idx] = u;
    if (son[u]) DFS(son[u], tp);
    for(int i = he[u];i;i = ne[i]) {
      int v = to[i];
      if (v == fa[u] or v == son[u])  continue;
      DFS(v, u);
    }
    R[u] = idx;
    return;
  }
  struct trie{
    int ch[N * 32][2], sz[N * 32], idx = 1, rt = 1;
    void insert(int x, int v) {
      int u = 1;
      DEP(i, 31, 0) {
        if (!ch[u][(x >> i) & 1]) ch[u][(x >> i) & 1] = ++idx, ch[idx][0] = ch[idx][1] = sz[idx] = 0;
        u = ch[u][(x >> i) & 1];
        sz[u] += v;
      }
      return;
    }
    int query(int x) {
      int u = 1, ans = 0;
      DEP(i, 31, 0) {
        int d = (x >> i) & 1;
        if ((t >> i) & 1) ans += sz[ch[u][d]];//跟d一样相当于这一位变为0了
        u = ch[u][d ^ ((t >> i) & 1)];//前面这些位都相等
      }
      return ans;
    }
  }tr;
  void dfs1(int u) {
    for(int i = he[u];i;i = ne[i]) {
      int v = to[i];
      if (v == son[u] or v == fa[u])  continue;
      dfs1(v);
      for(auto it:vl[v])  ans[it] -= tr.query(sx[it] ^ w[u]);
      REP(j, L[v], R[v])  tr.insert(sx[dfn[j]], -1);
    }
    if (son[u]) dfs1(son[u]);
    tr.insert(sx[u], 1);
    for (int i = he[u];i;i = ne[i]) {
      int v = to[i];
      if (v == fa[u] or v == son[u])  continue;
      REP(j, L[v], R[v])  tr.insert(sx[dfn[j]], 1);
    }
    for (int i = he[u];i;i = ne[i]) {
      int v = to[i];
      if (v == fa[u] or v == son[u])  continue;
      for(auto it:vl[v])  ans[it] += tr.query(sx[it] ^ w[u]);
    }
    ans[u] += tr.query(sx[u] ^ w[u]);
    return;
  }
  void dfs2(int u, bool tg) {
    if (tg) {
      int p = u;
      while(p) {
        for(int i = he[p];i;i = ne[i]) {
          int v = to[i];
          if (v == fa[p] or v == son[p])  continue;
          REP(j, L[v], R[v])  tr.insert((sx[dfn[j]] ^ w[p]), 1); 
        }
        tr.insert((sx[p] ^ w[p]), 1);
        for(auto it:vh[p])  ans[it] += tr.query(sx[it]);
        p = son[p];
      }
      tr.ch[1][0] = tr.ch[1][1] = 0, tr.idx = 1;
    }
    for(int i = he[u];i;i = ne[i]) {
      int v = to[i];
      if (v == fa[u])  continue;
      dfs2(v, (v != son[u]));
    }
    return;
  }
  void main() {
    read(n);
    REP(i, 1, n - 1) {
      int u, v;
      read(u, v);
      add(u, v);
      add(v, u);
    }
    REP(i, 1, n)  read(w[i]);
    read(t);
    dfs(1, 0);
    DFS(1, 1);
    int sum = 1, s = 1;
    REP(i, 1, n)  sum = sum * n % mod;
    REP(i, 1, n) {
      int x = i, la = 0;
      while(x) {
        if (la) vl[la].pb(i);
        if (top[x] != x)  vh[fa[x]].pb(i);
        la = top[x];
        x = fa[top[x]];
      }
    }
    dfs1(1);
    tr.idx = 1;
    tr.ch[1][0] = tr.ch[1][1] = 0;
    dfs2(1, 1);
    REP(i, 1, n)  s = s * ans[i] % mod;
    sum = (sum + mod - s) % mod;
    std::cout << sum << '\n';
    return ;
  }
}

signed main()
{
  freopen("weight.in","r",stdin);
  freopen("weight.out","w",stdout);

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
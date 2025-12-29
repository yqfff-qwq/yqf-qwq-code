#include<bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

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
  int n, m, rt, p;
  int a[N], b[N];
  int he[N], to[N << 1], ne[N << 1], tot;
  int sz[N], son[N], fa[N], dep[N];
  int top[N], dfn[N], tim;
  void add(int u, int v) {
    ne[++tot] = he[u];
    he[u] = tot;
    to[tot] = v;
    return;
  }
  struct tree{
    #define ls (u << 1)
    #define rs ((ls) | 1)
    #define mid ((l + r) >> 1)
    int s[N << 2], tag[N << 2];
    void upd(int u, int k, int ln) {
      s[u] = (s[u] + k * ln % p) % p;
      tag[u] = (tag[u] + k) % p;
      return;
    }
    void push_up(int u) {
      return s[u] = (s[ls] + s[rs]) % p, void();
    }
    void push_down(int u, int l, int r) {
      if (tag[u]) {
        upd(ls, tag[u], (mid - l + 1));
        upd(rs, tag[u], (r - mid));
        tag[u] = 0;
      }
      return;
    }
    void build(int u, int l, int r) {
      tag[u] = s[u] = 0;
      if (l == r) {
        s[u] = a[l];
        return;
      }
      build(ls, l, mid);
      build(rs, mid + 1, r);
      push_up(u);
      return;
    }
    void modify(int u, int l, int r, int ql, int qr, int k) {
      if(ql <= l and r <= qr){
        upd(u, k, (r - l + 1));
        return ;
      }
	    push_down(u, l, r);
	    if (ql <= mid) modify(ls, l, mid, ql, qr, k);
	    if (qr > mid)  modify(rs, mid + 1, r, ql, qr, k);
	    push_up(u);
      return;
    }
    int query(int u, int l, int r, int ql, int qr){
      if(ql <= l and r <= qr) return s[u];
      push_down(u, l, r);
      int ans = 0;
      if(ql <= mid) ans += query(ls, l, mid, l, r), ans %= p;//
      if(qr > mid)  ans += query(rs, mid + 1, r, l, r), ans %= p;//
      return ans % p;
    }
    void son_modify(int x, int y, int z){
      while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        modify(1, 1, n, dfn[top[x]], dfn[x], z);
        x = fa[top[x]];
      }
      if (dep[x] > dep[y])  swap(x,y);
      modify(1, 1, n, dfn[x], dfn[y], z);
    }
    int son_query(int x, int y) {
      int ans = 0;
      while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])  swap(x, y);
        ans += query(1, 1, n, dfn[top[x]], dfn[x]) % p;//%p
        ans %= p;
        x = fa[top[x]];
      }
      if(dep[x] > dep[y]) swap(x,y);
      ans += query(1, 1, n, dfn[x], dfn[y]);
      return ans % p;
    }
  }tr;
  void main() {
    read(n, m, rt, p);
    REP(i, 1, n)  read(b[i]);
    REP(i, 1, n - 1) {
      int u, v;
      read(u, v);
      add(u, v);
      add(v, u);
    }
    auto dfs1 = [&](auto &&self, int u, int f) -> void{
      sz[u] = 1;
      dep[u] = dep[f] + 1;
      fa[u] = f;
      for(int i = he[u];i;i = ne[i]) {
        int v = to[i];
        if (v == f)  continue;
        self(self, v, u);
        sz[u] += sz[v];
        if (!son[u] or sz[v] > sz[son[u]])  son[u] = v;
      }
    };
    dfs1(dfs1, rt, 0);
    auto dfs2 = [&](auto &&self, int u, int tp) -> void{
      top[u] = tp;
      dfn[u] = ++tim;
      a[tim] = b[u];
      if (son[u]) self(self, son[u], tp);
      for(int i = he[u];i;i = ne[i]) {
        int v = to[i];
        if (v == fa[u] or v == son[u])  continue;
        self(self, v, v);
      }
    };
    dfs2(dfs2, rt, rt);
    tr.build(1, 1, n);
    while(m--){
      int op, x, y, z;
      read(op, x);
      if(op==1){
        read(y, z);
        tr.son_modify(x, y, z);
      }
      else if(op == 2) {
        read(y);
        cout << tr.son_query(x, y) % p << '\n';//%p
      }
      else if (op == 3) {
        read(z);
        tr.modify(1, 1, n, dfn[x], dfn[x] + sz[x] - 1, z);
      }
      else{
        cout<<tr.query(1, 1, n, dfn[x], dfn[x] + sz[x] - 1) % p << '\n';//%p
      }
    }

    return;
  }
}

signed main()
{
    // freopen("XXX.in","r",stdin);
    // freopen("XXX.out","w",stdout);

    int T=1;
    // read(T);
    while(T--)
    {
        YZLK::main();
    }

//    fclose(stdin);
//    fclose(stdout);
    return 0;
}
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <random>

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
#define pcnt __builtin_popcount

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
  int dep[N], dfn[N], tim;
  int fa[N], top[N], son[N], sz[N];
  std::vector<int> ve[N];
  int a[N], b[N];
  void dfs1(int u, int f) {
    fa[u] = f;
    dep[u] = dep[f] + 1;
    sz[u] = 1;
    for(auto v:ve[u]) {
      if (v == f) continue;
      dfs1(v, u);
      sz[u] += sz[v];
      if (sz[v] > sz[son[u]]) son[u] = v;
    }
    return;
  }
  void dfs2(int u, int tp) {
    top[u] = tp;
    dfn[u] = ++tim;
    b[tim] = a[u];
    if (son[u]) dfs2(son[u], tp);
    for(auto v:ve[u]) {
      if (v == fa[u] or v == son[u])  continue;
      dfs2(v, v);
    }
    return;
  }
  struct tree{
    #define ls (u << 1)
    #define rs (ls | 1)
    #define mid ((l + r) >> 1)
    int tr[N << 2], tag[N << 2];
    void push_up(int u) {
      tr[u] = (tr[ls] + tr[rs]) % p;
      return;
    }
    void push_down(int u, int l, int r) {
      if (tag[u]) {
        tr[ls] = (tr[ls] + tag[u] * (mid - l + 1) % p) % p;
        tr[rs] = (tr[rs] + tag[u] * (r - mid) % p) % p;
        tag[ls] = (tag[ls] + tag[u]) % p;
        tag[rs] = (tag[rs] + tag[u]) % p;
        tag[u] = 0;
      }
      return;
    }
    void build(int u, int l, int r) {
      if (l == r) {
        tr[u] = b[l];
        return;
      }
      build(ls, l, mid);
      build(rs, mid + 1, r);
      push_up(u);
      return;
    }
    void modify(int u, int l, int r, int ql, int qr, int k) {
      if (ql <= l and r <= qr) {
        tr[u] = (tr[u] + (r - l + 1) * k % p) % p;
        tag[u] = (tag[u] + k) % p;
        return;
      }
      push_down(u, l, r);
      if (ql <= mid)  modify(ls, l, mid, ql, qr, k);
      if (mid < qr)   modify(rs, mid + 1, r, ql, qr, k);
      push_up(u);
      return;
    }
    int query(int u, int l, int r, int ql, int qr) {
      if (ql <= l and r <= qr)  return tr[u];
      push_down(u, l, r);
      int sum = 0;
      if (ql <= mid)  sum = query(ls, l, mid, ql, qr);
      if (mid < qr)    sum += query(rs, mid + 1, r, ql, qr);
      return sum % p;
    }
    void road_modify(int x, int y, int z) {
      while(top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])  std::swap(x, y);
        modify(1, 1, n, dfn[top[x]], dfn[x], z);
        x = fa[top[x]];
      }
      if (dep[x] > dep[y])  std::swap(x, y);
      modify(1, 1, n, dfn[x], dfn[y], z);
      return;
    }
    int road_query(int x, int y) {
      int ans = 0;
      while(top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])  std::swap(x, y);
        ans = (ans + query(1, 1, n, dfn[top[x]], dfn[x])) % p;
        x = fa[top[x]];
      }
      if (dep[x] > dep[y])  std::swap(x, y);
      ans = (ans + query(1, 1, n, dfn[x], dfn[y])) % p;
      return ans;
    }
  }tr;
  void main() {
    read(n, m, rt, p);
    REP(i, 1, n)  read(a[i]);
    REP(i, 1, n - 1) {
      int u, v;
      read(u, v);
      ve[u].pb(v);
      ve[v].pb(u);
    }
    dfs1(rt, 0);
    dfs2(rt, rt);
    tr.build(1, 1, n);
    while(m--) {
      int op, x, y, z;
      read(op, x);
      if (op == 1) {
        read(y, z);
        tr.road_modify(x, y, z);
      }
      else if (op == 2) {
        read(y);
        std::cout << tr.road_query(x, y) << '\n';
      }
      else if (op == 3) {
        read(z);
        tr.modify(1, 1, n, dfn[x], dfn[x] + sz[x] - 1, z);
      }
      else {
        std::cout << tr.query(1, 1, n, dfn[x], dfn[x] + sz[x] - 1) % p << '\n';
      }
    }
    return ;
	}
}

signed main()
{
	// freopen("c.in","r",stdin);
	// freopen("c.out","w",stdout);
	// std::cin.tie(nullptr) -> sync_with_stdio(false);
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
//
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <random>
#include <bitset>

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
	const int N = 4e4 + 10;
  const int B = 7e2;
  int n, m, ans;
  int a[N];
  std::bitset<N> b[60][60];
  std::vector<int> pp;
  std::vector<int> ve[N];
  int st[N][20], tim, f[N];
  int dfn[N], idx, dep[N];
  int mxd[N];
  int id[N];
  int dp[N], F[N];
  int sta[N], top;
  std::bitset<N> tt;
  int get(int x, int y) {
    return dfn[x] < dfn[y] ? x : y;
  }
  void dfs(int u, int fa) {
    st[dfn[u] = ++tim][0] = fa;
    f[u] = fa;
    dep[u] = dep[fa] + 1;
    mxd[u] = dep[u];
    for(auto v:ve[u]) {
      if (v == fa)  continue;
      dfs(v, u);
      mxd[u] = std::max(mxd[u], mxd[v]);
    }
    if (mxd[u] - dep[u] >= B) id[u] = ++idx, mxd[u] = dep[u];
    return;
  }
  int lca(int u, int v) {
    if (u == v) return u;
    u = dfn[u], v = dfn[v];
    if (u > v)  std::swap(u, v);
    u++;
    int d = std::__lg(v - u + 1);
    return get(st[u][d], st[v - (1ll << d) + 1][d]);
  }
  void dfs2(int u) {
    for(auto v:ve[u]) {
      if (v == f[u])  continue;
      if (id[v]) {
        int x = id[sta[top]], y = id[v];
        for(int d = v;d != sta[top];d = f[d]) b[x][y].set(a[d]);
        tt = b[x][y];
        REP(i, 1, top - 1) {
          std::bitset<N> &bt = b[id[sta[i]]][y];
          bt = b[id[sta[i]]][x];
          bt |= tt;
        }
        F[v] = sta[top];
        dp[v] = dp[sta[top]] + 1;
        sta[++top] = v;
      }
      dfs2(v);
      if (id[v])  top--;
    }
    return;
  }
  void main() {
    read(n, m);
    REP(i, 1, n)  read(a[i]), pp.pb(a[i]);
    std::sort(pp.begin(), pp.end());
    pp.erase(unique(pp.begin(), pp.end()), pp.end());
    REP(i, 1, n)  a[i] = lower_bound(pp.begin(), pp.end(), a[i]) - pp.begin();
    REP(i, 1, n - 1) {
      int u, v;
      read(u, v);
      ve[u].pb(v);
      ve[v].pb(u);
    }
    dfs(1, 0);
    REP(j, 1, 19) {
      for(int i = 1;i + (1ll << j) - 1 <= n;i++) {
        st[i][j] = get(st[i][j - 1], st[i + (1ll << (j - 1))][j - 1]);
      }
    }
    if (!id[1]) id[1] = ++idx;
    top = 1;
    sta[top] = 1;
    dp[top] = 1;
    dfs2(1);
    while(m--) {
      int u, v;
      read(u, v);
      u ^= ans;
      tt.reset();
      int lc = lca(u, v);
      while(u != lc and !id[u]) tt.set(a[u]), u = f[u];
      while(v != lc and !id[v]) tt.set(a[v]), v = f[v];
      if (u != lc) {
        int p = u;
        while(dep[F[p]] >= dep[lc]) p = F[p];
        if (u != p) tt |= b[id[p]][id[u]];
        while(p != lc)  tt.set(a[p]), p = f[p];
      }
      if (v != lc) {
        int p = v;
        while(dep[F[p]] >= dep[lc]) p = F[p];
        if (v != p) tt |= b[id[p]][id[v]];
        while(p != lc)  tt.set(a[p]), p = f[p];
      }
      tt.set(a[lc]);
      ans = tt.count();
      std::cout << ans << '\n';
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
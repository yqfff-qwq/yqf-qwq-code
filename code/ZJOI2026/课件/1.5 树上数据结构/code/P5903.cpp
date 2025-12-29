#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <random>

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
  #define ui unsigned int
  ui s;

  inline ui get(ui x) {
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return s = x; 
  }
	const int N = 5e5 + 10;
  int n, q;
  int dep[N], d[N];
  int fa[N][21], top[N], son[N];
  std::vector<int> ve[N], g1[N], g2[N];
  int p[N];
  int a[N], b[N];
  void dfs1(int u, int f) {
    fa[u][0] = f;
    dep[u] = d[u] = dep[f] + 1;
    REP(i, 1, 20) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for(auto v:ve[u]) {
      dfs1(v, u);
      if (d[v] > d[son[u]]) son[u] = v, d[u] = d[v];
    }
    return;
  }
  void dfs2(int u, int tp) {
    top[u] = tp;
    if (u == tp) {
      for(int i = 0, v = u;i <= d[u] - dep[u];i++)  g1[u].pb(v), v = fa[v][0];
      for(int i = 0, v = u;i <= d[u] - dep[u];i++)  g2[u].pb(v), v = son[v];
    }
    if (son[u]) dfs2(son[u], tp);
    for(auto v:ve[u]) {
      if (v == son[u])  continue;
      dfs2(v, v);
    }
    return;
  }
  int query(int x, int k) {
    if (!k) return x;
    x = fa[x][p[k]];
    k -= (1ll << p[k]);
    k -= (dep[x] - dep[top[x]]);
    x = top[x];
    return k < 0 ? g2[x][-k] : g1[x][k];
  }
  void main() {
    read(n, q, s);
    p[0] = -1;
    REP(i, 1, n) {
      int ff;
      read(ff);
      ve[ff].pb(i);
      p[i] = p[i >> 1] + 1;
    }
    int rt = ve[0][0];
    dfs1(rt, 0);
    dfs2(rt, rt);
    ll ans = 0, sum = 0;
    REP(i, 1, q) {
      int x, k;
      x = (get(s) ^ sum) % n + 1;
      k = (get(s) ^ sum) % dep[x];
      // std::cout << x << ' ' << k << '\n';
      ans = ans ^ (1ll * i * (sum = query(x, k)));
    }
    std::cout << ans << '\n';
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
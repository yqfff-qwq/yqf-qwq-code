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
#define pii std::pair<int, int>
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
  int n, m;
	std::vector<int> ve[N];
	std::vector<pii> qy[N];
	int c[N], ans[N];
	int sz[N], son[N];
	int d[N], cnt[N];
	void dfs1(int u, int fa) {
		sz[u] = 1;
		for(auto v:ve[u]) {
			if (v == fa)	continue;
			dfs1(v, u);
			sz[u] += sz[v];
			if (sz[son[u]] < sz[v])	son[u] = v;
		}
		return;
	}
	void solve(int u, int fa, int s) {
    if (s == -1)		d[cnt[c[u]]] += s;
    cnt[c[u]] += s;
    if (s == 1)			d[cnt[c[u]]] += s;
    for(auto v:ve[u]) {
      if(v == fa)	continue;
      solve(v, u, s);
    }
}
	void dfs(int u, int fa, bool fl) {
		for(auto v:ve[u]) {
			if (v == fa or v == son[u])	continue;
			dfs(v, u, 0);
		}
		if (son[u])	dfs(son[u], u, 1);
		solve(u, fa, 1);
		for(auto it:qy[u]) {
			ans[it.se] = d[it.fi];
		}
		if (!fl)	solve(u, fa, -1);
		return;
	}

  void main() {
    read(n, m);
		REP(i, 1, n)	read(c[i]);
		REP(i, 1, n - 1) {
			int u, v;
			read(u, v);
			ve[u].pb(v);
			ve[v].pb(u);
		}
		REP(i, 1, m) {
			int v, k;
			read(v, k);
			qy[v].pb({k, i});
		}
		dfs1(1, 0);
		dfs(1, 0, 1);
		REP(i, 1, m)	std::cout << ans[i] << '\n';
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
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
	const int mod = 201314;
  const int N = 1e5 + 10;
  int n, m;
	std::vector<int> ve[N];
	int sz[N], dep[N], fa[N];
	int son[N], top[N];
	int dfn[N], tim;
	int ans[N];
	struct nd{
		int z, id, op;
	};
	std::vector<nd> qy[N];
	void dfs1(int u, int f) {
		fa[u] = f;
		dep[u] = dep[f] + 1;
		sz[u] = 1;
		for(auto v:ve[u]) {
			if (v == f)	continue;
			dfs1(v, u);
			sz[u] += sz[v];
			if (sz[v] > sz[son[u]])	son[u] = v;
		}
		return;
	}
	void dfs2(int u, int tp) {
		top[u] = tp;
		dfn[u] = ++tim;
		if (son[u])	dfs2(son[u] , tp);
		for(auto v:ve[u]) {
			if (v == fa[u] or v == son[u])	continue;
			dfs2(v, v);
		}
		return;
	}
	struct tree{
		#define ls (u << 1)
		#define rs (ls | 1)
		#define mid ((l + r) >> 1)
		int tr[N << 2], tag[N << 2];

		void add(int &x, int y) {
			x = (x + y) % mod;
			return;
		}
		void push_up(int u) {
			tr[u] = tr[ls] + tr[rs];
			return;
		}
		void push_down(int u, int l, int r) {
			if (tag[u]) {
				add(tr[ls], (mid - l + 1) * tag[u] % mod);
				add(tr[rs], (r - mid) * tag[u] % mod);
				add(tag[ls], tag[u]);
				add(tag[rs], tag[u]);
				tag[u] = 0;
			}
			return;
		}
		void build(int u, int l, int r) {
			if (l == r)	{
				tr[u] = tag[u] = 0;
				return;
			}
			build(ls, l, mid);
			build(rs, mid + 1, r);
			push_up(u);
			return;
		}
		void modify(int u, int l, int r, int ql, int qr, int k) {
			if (ql <= l and r <= qr) {
				add(tag[u], k);
				add(tr[u], (r - l + 1) * k % mod);
				return;
			}
			push_down(u, l, r);
			if (ql <= mid)	modify(ls, l, mid, ql, qr, k);
			if (mid < qr)		modify(rs, mid + 1, r, ql, qr, k);
			push_up(u);
			return;
		}
		int query(int u, int l, int r, int ql, int qr) {
			if (ql <= l and r <= qr)	return tr[u];
			push_down(u, l, r);
			int sum = 0;
			if (ql <= mid)	sum = query(ls, l, mid, ql, qr);
			if (mid < qr)		add(sum, query(rs, mid + 1, r, ql, qr));
			return sum;
		}
		void modify(int x, int y, int z) {
			while(top[x] != top[y]) {
				if (dep[top[x]] < dep[top[y]])	std::swap(x, y);
				modify(1, 1, n, dfn[top[x]], dfn[x], z);
				x = fa[top[x]];
			}
			if (dep[x] > dep[y])	std::swap(x, y);
			modify(1, 1, n, dfn[x], dfn[y], z);
			return;
		}
		int query(int x, int y) {
			int sum = 0;
			while(top[x] != top[y]) {
				if (dep[top[x]] < dep[top[y]])	std::swap(x, y);
				add(sum, query(1, 1, n, dfn[top[x]], dfn[x]));
				x = fa[top[x]];
			}
			if (dep[x] > dep[y])	std::swap(x, y);
			add(sum, query(1, 1, n, dfn[x], dfn[y]));
			return sum;
		}
	}tr;
  void main() {
    read(n, m);
		REP(i, 2, n) {
			int f;
			read(f);
			f++;
			ve[f].pb(i);
		}
		dfs1(1, 0);
		dfs2(1, 1);	
		REP(i, 1, m) {
			int l, r, z;
			read(l, r, z);
			l++, r++, z++;
			qy[l - 1].pb({z, i, -1});
			qy[r].pb({z, i, 1});
		}
		tr.build(1, 1, n);
		REP(i, 1, n) {
			tr.modify(1, i, 1);
			for(auto it:qy[i]) {
				int sum = tr.query(1, it.z);
				ans[it.id] = (ans[it.id] + it.op * sum) % mod;
			}
		}
		REP(i, 1, m)	std::cout << (ans[i] + mod) % mod << '\n';
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
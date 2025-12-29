#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

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
#define pdi std::pair<double, int>

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
  const int inf = 1e12;
  #define mid ((l + r) >> 1)
	const int N = 2e5 + 20;
  const int Len = 2e5 + 20;
  const int del = 1e5 + 10;
  int dp[N];
  int cmp(int x, int y) {
    if (x > y)  return 1;
    if (x < y)  return -1;
    return 0;
  }
  std::vector<int> ve[N];
  struct node{
    int k, b;
  }p[N];
  int tr[N << 2];
  int rt[N];
  int ls[N << 2], rs[N << 2];
  int a[N], b[N];
  int tot;
  int cal(int id, int d) {
    // std::cout << p[id].b << " " << p[id].k << " " << d << "\n";
    return p[id].b + p[id].k * d;
  }
  void add(int u, int k, int b) {
    p[u] = {k, b};
    return;
  }
  void upd(int &u, int l, int r, int x) {//修改完整覆盖段
    if (!u) return u = ++tot, tr[u] = x, void();
    // std::cout << tr[u] << ' ' << u << ' ' << l << ' ' << r << ' ' << x << "\n";
    int &y = tr[u];
    int op = cmp(cal(x, mid), cal(y, mid));
    if (op == -1) std::swap(x, y);
    int bl = cmp(cal(x, l), cal(y, l)), br = cmp(cal(x, r), cal(y, r));
    if (bl == -1) upd(ls[u], l, mid, x);
    if (br == -1) upd(rs[u], mid + 1, r, x);  
    return;
  }

  int query(int u, int l, int r, int d) {
    if (!u)             return inf;
    if (r < d or l > d) return inf;
    int ans = cal(tr[u], d);
    // std::cout << tr[u] << ' ' << u << '\n';
    if (l == r) return ans;
    return std::min(std::min(query(ls[u], l, mid, d), query(rs[u], mid + 1, r, d)), ans);
  }
  int merge(int u, int v, int l, int r) {
    if (!u or !v) return u | v;
    upd(u, l, r, tr[v]);
    ls[u] = merge(ls[u], ls[v], l, mid);
    rs[u] = merge(rs[u], rs[v], mid + 1, r);
    return u;
  }
  int n;
  void dfs(int u, int fa) {
    for(auto v:ve[u]) {
      if (v == fa)  continue;
      dfs(v, u);
      rt[u] = merge(rt[u], rt[v], 1, Len);
    }
    dp[u] = query(rt[u], 1, Len, a[u] + del);
    if (dp[u] == inf) dp[u] = 0;
    add(u, b[u], dp[u] - b[u] * del);
    upd(rt[u], 1, Len, u);
    return;
  }
  void main() {
    read(n);
    REP(i, 1, n)  read(a[i]);
    REP(i, 1, n)  read(b[i]);
    REP(i, 1, n - 1) {
      int u, v;
      read(u, v);
      ve[u].pb(v);
      ve[v].pb(u);
    }
    dfs(1, 0);
    REP(i, 1, n)  std::cout << dp[i] << ' ';

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
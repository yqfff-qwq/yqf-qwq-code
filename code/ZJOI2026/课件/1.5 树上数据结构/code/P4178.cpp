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
  const int N = 4e4 + 10;
  const int M = 4e4 + 10;
  int n, m, rt;
  int ans;
	std::vector<pii> ve[N];
  struct tree{
    int tr[N];
    int lowbit(int x) {return x & -x;}
    void add(int x, int k) {
      x++;
      while(x <= M - 1) {
        tr[x] += k;
        x += lowbit(x);
      }
      return;
    }
    int query(int x) {
      x++;
      int sum = 0;
      while(x) {
        sum += tr[x];
        x -= lowbit(x);
      }
      return sum;
    }
  }tr;
  int cnt, sz[N];
  bool vis[N];
  int f[N], d[N];
  int len, p[N];
  int rub[N], tl;
  int size(int u, int fa) {
    cnt++, sz[u] = 1;
    for(auto v:ve[u]) {
      if (v.fi == fa or vis[v.fi]) continue;
      sz[u] += size(v.fi, u);
    }
    return sz[u];
  }
  void dp(int u, int fa) {
    f[u] = cnt - sz[u];
    for(auto v:ve[u]) {
      if (v.fi == fa or vis[v.fi])  continue;
      f[u] = std::max(f[u], sz[v.fi]);
      dp(v.fi, u);
    }
    if (f[u] < f[rt]) rt = u;
    return;
  }
  void dis(int u, int fa) {
    rub[++tl] = d[u];
    for(auto v:ve[u]) {
      if (v.fi == fa or vis[v.fi])  continue;
      d[v.fi] = d[u] + v.se;
      dis(v.fi, u);
    }
    return;
  }
  void calc(int u) {
    cnt = 0, size(u, u);
    rt = u;
    dp(u, u);
    tr.add(0, 1);
    rub[++tl] = 0;
    for(auto v:ve[rt]) {
      if (vis[v.fi])  continue;
      int i = tl;
      d[v.fi] = v.se;
      dis(v.fi, rt);
      for(int j = i + 1;j <= tl;j++) {
        if (m >= rub[j])  ans += tr.query(m - rub[j]);
        // std::cout << ans << '\n';
      }
      while(++i <= tl) {
        if (rub[i] < M) tr.add(rub[i], 1);
      }
    }

    while(tl) {
      if (rub[tl] < M)  tr.add(rub[tl], -1);
      tl--;
    }
    vis[rt] = 1;
    for(auto v:ve[rt]) {
      if (vis[v.fi])  continue;
      calc(v.fi);
    }
    return;
  }
  void main() {
    read(n);
    REP(i, 1, n - 1) {
      int u, v, w;
      read(u, v, w);
      ve[u].pb({v, w});
      ve[v].pb({u, w});
    }
    read(m);
    calc(1);
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
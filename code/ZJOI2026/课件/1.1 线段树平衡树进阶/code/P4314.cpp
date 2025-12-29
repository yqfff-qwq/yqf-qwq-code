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
  const int inf = 1e12;
  void cmax(int &x, int y)  {x = std::max(x, y);}
  struct node{
    #define ls (u << 1)
    #define rs ((ls) | 1)
    #define mid ((l + r) >> 1)
    int ans[N << 2], ansh[N << 2];
    bool vis[N << 2];
    int sum[N << 2], vl[N << 2];
    int sumh[N << 2], vlh[N << 2];
    void push_up(int u) {
      ans[u] = std::max(ans[ls], ans[rs]);
      ansh[u] = std::max(ansh[ls], ansh[rs]);
      return;
    }

    void dsum(int u, int k, int mxk) {
      if (vis[u]) {
        cmax(vlh[u], vl[u] + mxk);//当作覆盖看
        cmax(ansh[u], ans[u] + mxk);
        ans[u] += k;
        vl[u] += k;
      }
      else {//上一次也还是加
        cmax(sumh[u], sum[u] + mxk);
        cmax(ansh[u], ans[u] + mxk);
        ans[u] += k;
        sum[u] += k;
      }
      return;
    }
    void dvl(int u, int k, int mxk) {
      if (vis[u]) {//直接覆盖
        cmax(vlh[u], mxk);
        cmax(ansh[u], mxk);
      }
      else {//上一次是加
        vis[u] = 1;
        vlh[u] = mxk;
        cmax(ansh[u], mxk);
      }
      ans[u] = vl[u] = k;
      return;
    }

    void push_down(int u) {
      dsum(ls, sum[u], sumh[u]);
      dsum(rs, sum[u], sumh[u]);
      sum[u] = sumh[u] = 0;
      if (vis[u]) {
        dvl(ls, vl[u], vlh[u]);
        dvl(rs, vl[u], vlh[u]);

        vis[u] = 0;
        vl[u] = vlh[u] = 0;
      }
      return;
    }

    void build(int u, int l, int r) {
      if (l == r) {
        std::cin >> ans[u];
        ansh[u] = ans[u];
        return;
      }
      build(ls, l, mid);
      build(rs, mid + 1, r);
      push_up(u);
      return;
    }
    int query(int u, int l, int r, int ql, int qr) {
      if (ql <= l and r <= qr)  return ans[u];
      push_down(u);
      int ans = -inf;
      if (ql <= mid)  ans = query(ls, l, mid, ql, qr);
      if (mid < qr)   cmax(ans, query(rs, mid + 1, r, ql, qr));
      return ans;
    }
    int q(int u, int l, int r, int ql, int qr) {
      if (ql <= l and r <= qr)  return ansh[u];
      push_down(u);
      int ans = -inf;
      if (ql <= mid)  ans = q(ls, l, mid, ql, qr);
      if (mid < qr)   cmax(ans, q(rs, mid + 1, r, ql, qr));
      return ans;
    }
    void add(int u, int l, int r, int ql, int qr, int k) {
      if (ql <= l and r <= qr) {
        dsum(u, k, k);
        return;
      }
      push_down(u);
      if (ql <= mid)  add(ls, l, mid, ql, qr, k);
      if (mid < qr)   add(rs, mid + 1, r, ql, qr, k);
      push_up(u);
      return;
    }
    void f(int u, int l, int r, int ql, int qr, int k) {
      if (ql <= l and r <= qr) {
        dvl(u, k, k);
        return;
      }
      push_down(u);
      if (ql <= mid)  f(ls, l, mid, ql, qr, k);
      if (mid < qr)   f(rs, mid + 1, r, ql, qr, k);
      push_up(u);
      return;
    }

  }tr;
  
  int t, e;
  void main() {
    std::cin >> t;
    tr.build(1, 1, t);
    std::cin >> e;
    char op;
    int x, y, z;
    while(e--) {
      std::cin >> op >> x >> y;
      if (op == 'Q') {
        std::cout << tr.query(1, 1, t, x, y) << "\n";
      }
      if (op == 'A') {
        std::cout << tr.q(1, 1, t, x, y) << "\n";
      }
      if (op == 'P') {
        std::cin >> z;
        tr.add(1, 1, t, x, y, z);
      }
      if (op == 'C') {
        std::cin >> z;
        tr.f(1, 1, t, x, y, z);
      }
    }
    return ;
	}
}

signed main()
{
	// freopen("c.in","r",stdin);
	// freopen("c.out","w",stdout);
	std::cin.tie(nullptr) -> sync_with_stdio(false);
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
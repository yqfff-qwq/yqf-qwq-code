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
  const int mod = 39989;
  const int md = 1e9;
  #define ls (u << 1)
  #define rs ((ls) | 1)
  #define mid ((l + r) >> 1)
	const int N = 1e5 + 10;
  const double eps = 1e-9;
  int cmp(double x, double y) {
    if (x - y > eps)  return 1;
    if (y - x > eps)  return -1;
    return 0;
  }
  struct node{
    double k, b;
  }p[N];
  int tr[N << 2];
  int tot;
  double cal(int id, int d) {
    return p[id].b + p[id].k * (d * 1.0);
  }
  void add(int x0, int y0, int x1, int y1) {
    tot++;
    if (x0 == x1) p[tot].k = 0, p[tot].b = std::max(y0, y1);
    else          p[tot].k = 1.0 * (y1 - y0) / (x1 - x0), p[tot].b = y0 - p[tot].k * x0;
    return;
  }
  void upd(int u, int l, int r, int x) {//修改完整覆盖段
    int &y = tr[u];
    int op = cmp(cal(x, mid), cal(y, mid));
    if (op == 1 or (op == 0 and x < y)) std::swap(x, y);
    int bl = cmp(cal(x, l), cal(y, l)), br = cmp(cal(x, r), cal(y, r));
    if (bl == 1 or (bl == 0 and x < y)) upd(ls, l, mid, x);
    if (br == 1 or (br == 0 and x < y)) upd(rs, mid + 1, r, x);  
    return;
  }

  void update(int u, int l, int r, int ql, int qr, int x) {
    if (ql <= l and r <= qr) {
      upd(u, l, r, x);
      return;
    }
    if (ql <= mid) update(ls, l, mid, ql, qr, x);
    if (mid < qr)  update(rs, mid + 1, r, ql, qr, x);
    return;
  }
  pdi cmax(pdi x, pdi y) {
    if (cmp(x.fi, y.fi) == -1)      return y;
    else if (cmp(x.fi, y.fi) == 1)  return x;
    else                            return x.se < y.se ? x : y;  
  }

  pdi query(int u, int l, int r, int d) {
    if (r < d or l > d) return {0, 0};
    double ans = cal(tr[u], d);
    if (l == r) return {ans, tr[u]};
    return cmax({ans, tr[u]}, cmax(query(ls, l, mid, d), query(rs, mid + 1, r, d)));
  }
  int n;
  int lans;
  void main() {
    read(n);
    REP(i, 1, n) {
      int op, x0, y0, x1, y1;
      read(op, x0);
      if (op == 0) {
        x0 = (x0 + lans - 1 + mod) % mod + 1;
        lans = query(1, 1, mod, x0).se;
          std::cout << lans << "\n";
      } else {
          read(y0, x1, y1);
        x0 = (x0 + lans - 1 + mod) % mod + 1;
        y0 = (y0 + lans - 1 + md) % md + 1;
        x1 = (x1 + lans - 1 + mod) % mod + 1;
        y1 = (y1 + lans - 1 + md) % md + 1;
        if (x0 > x1)  std::swap(x0, x1), std::swap(y0, y1);
        add(x0, y0, x1, y1);
        update(1, 1, mod, x0, x1, tot);
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
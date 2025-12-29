#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

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
  int a[N];
  int n, m;
  void cmax(int &x, int y) {x = std::max(x, y);}
  struct node{
    #define ls (u << 1)
    #define rs ((ls) | 1)
    #define mid ((l + r) >> 1)
    int mx[N << 2], mn[N << 2], sum[N << 2], tg[N << 2];
    void push_up(int u, int l, int r) {
      mx[u] = std::max(mx[ls], mx[rs]) + tg[u];
      mn[u] = std::min(mn[ls], mn[rs]) + tg[u];
      sum[u] = sum[ls] + sum[rs] + tg[u] * (r - l + 1);
      return;
    }
    void upd(int u, int l, int r, int c) {
      sum[u] += c * (r - l + 1);
      mx[u] += c;
      mn[u] += c;
      tg[u] += c;
      return;
    }
    void build(int u, int l, int r) {
      if (l == r) {
        mx[u] = mn[u] = sum[u] = a[l];
        return;
      }
      build(ls, l, mid);
      build(rs, mid + 1, r);
      push_up(u, l, r);
      return;
    }
    void add(int u, int l, int r, int ql, int qr, int c) {
      if (ql <= l and r <= qr) {
        upd(u, l, r, c);
        return;
      }
      if (ql <= mid)  add(ls, l, mid, ql, qr, c);
      if (mid < qr)   add(rs, mid + 1, r, ql, qr, c);
      push_up(u, l, r);
      return;
    }
    void sqr(int u, int l, int r, int ql, int qr, int w) {
      if (u >= 4e5) return;
      if (ql <= l and r <= qr) {
        int c1 = std::sqrt(mn[u] + w), c2 = std::sqrt(mx[u] + w);
        if (mx[u] == mn[u]) {
          upd(u, l, r, -(mn[u] + w - c1));
          return;
        }
        else if (mx[u] - mn[u] == 1 and c2 - c1 == 1) {
          upd(u, l, r, -(mn[u] + w - c1));
          return;
        }
      }
      w += tg[u];
      if (ql <= mid)  sqr(ls, l, mid, ql, qr, w);
      if (mid < qr)   sqr(rs, mid + 1, r, ql, qr, w);
      push_up(u, l, r);
      return;
    }
    int query(int u, int l, int r, int ql, int qr, int w) {
      if (ql <= l and r <= qr) return sum[u] + w * (r - l + 1);
      int ans = 0;
      w += tg[u];
      if (ql <= mid)  ans = query(ls, l, mid, ql, qr, w);
      if (mid < qr)   ans += query(rs, mid + 1, r, ql, qr, w);
      return ans;
    }
  }tr;
  void main() {
    read(n, m);
    REP(i, 1, n)  read(a[i]);
    tr.build(1, 1, n);
    // REP(i, 1, n * 4)  std::cout << tr.mx[i] << " " << tr.mn[i] << "\n";
    REP(i, 1, m) {
      int op, l, r, x;
      read(op, l, r);
      if (op == 1) {
        read(x);
        tr.add(1, 1, n, l, r, x);
      }
      else if (op == 2) {
        tr.sqr(1, 1, n, l, r, 0);
      }
      else {
        std::cout << tr.query(1, 1, n, l, r, 0) << "\n";
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
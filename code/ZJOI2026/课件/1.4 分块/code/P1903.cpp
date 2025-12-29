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
  const int M = 1e6 + 10;
	const int N = 2e5 + 10;
  int n, m;
  int a[N];
  int p[N];
  int cnt[M];
  int ans[N];
  struct node{
    int l, r, id, t;
  }q[N];
  pii d[N];
  int l1, l2;
  int bk;
  int sum;
  bool cmp(node a, node b) {
    if (p[a.l] == p[b.l]) {
      if (p[a.r] == p[b.r]) return a.t < b.t;
      return a.r < b.r;
    }
    return a.l < b.l;
  }
  void add(int x) {
    cnt[x]++;
    if (cnt[x] == 1)  sum++;
    return;
  }
  void del(int x) {
    cnt[x]--;
    if (cnt[x] == 0)  sum--;
    return;
  }
  void main() {
    read(n, m);
    bk = pow(n, 2.0 / 3.0);
    REP(i, 1, n)  read(a[i]), p[i] = (i - 1) / bk + 1;
    REP(i, 1, m) {
      char op;
      int x, y;
      std::cin >> op;
      read(x, y);
      if (op == 'Q') {
        q[++l1] = {x, y, l1, l2};
      }
      else  d[++l2] = {x, y};
    }
    std::sort(q + 1, q + l1 + 1, cmp);
    int l = 1, r = 0, tim = 0;
    REP(i, 1, l1) {
      while(l > q[i].l)   add(a[--l]);
      while(r < q[i].r)   add(a[++r]);
      while(l < q[i].l)   del(a[l++]);
      while(r > q[i].r)   del(a[r--]);
      while(tim < q[i].t) {
        tim++;
        if (l <= d[tim].fi and d[tim].fi <= r) {
          del(a[d[tim].fi]);
          add(d[tim].se);
        }
        std::swap(a[d[tim].fi], d[tim].se);
      }
      while(tim > q[i].t) {
        if (l <= d[tim].fi and d[tim].fi <= r) {
          del(a[d[tim].fi]);
          add(d[tim].se);
        }
        std::swap(a[d[tim].fi], d[tim].se);
        tim--;
      }
      ans[q[i].id] = sum;
    }
    REP(i, 1, l1)  std::cout << ans[i] << '\n';
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
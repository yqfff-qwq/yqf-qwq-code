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
	const int N = 1e6 + 10;
  const int inf = 2147483647;
  int n, m;
  int a[N];
  struct tree{
    int lowbit(int x) {return x & -x;}
    int rt[N];
    struct node{
      int ls, rs;
      int s;
    }tr[N << 5];
    int ltr[N], rtr[N], l1, l2;
    int idx;
    int nd(int u) {
      tr[++idx] = tr[u];
      tr[idx].s++;
      return idx;
    }
    void push_up(int u) {
      tr[u].s = tr[tr[u].ls].s + tr[tr[u].rs].s;
      return;
    }
    int build(int u, int l, int r) {
      u = ++idx;
      if (l == r) return idx;
      int mid = (l + r) >> 1;
      tr[u].ls = build(tr[u].ls, l, mid);
      tr[u].rs = build(tr[u].rs, mid + 1, r);
      return u;
    }
    int update(int u, int l, int r, int p, int v) {
      u = nd(u);
      if (l == r) {
        tr[u].s += v;
        return u;
      }
      int mid = (l + r) >> 1;
      if (p <= mid) tr[u].ls = update(tr[u].ls, l, mid, p, v);
      else          tr[u].rs = update(tr[u].rs, mid + 1, r, p, v);
      push_up(u);
      return u;
    }
    void add(int x, int k) {
      int p = a[x];
      while(x <= n) {
        update(rt[x], 1, n, p, k);
        x += lowbit(x);
      }
      return;
    }
    int qy(int l, int r, int k) {
      if (l == r) {
        return l;
      }
      int mid = (l + r) >> 1;
      int sum = 0;
      REP(i, 1, l1) sum -= tr[tr[ltr[i]].ls].s;
      REP(i, 1, l2) sum += tr[tr[rtr[i]].ls].s;
      if (k <= sum) {
        REP(i, 1, l1) ltr[i] = tr[ltr[i]].ls;
        REP(i, 1, l2) rtr[i] = tr[rtr[i]].ls;
        return qy(l, mid, k);
      }
      else {
        REP(i, 1, l1) ltr[i] = tr[ltr[i]].rs;
        REP(i, 1, l2) rtr[i] = tr[rtr[i]].rs;
        return qy(mid + 1, r, k - sum);
      }
    }
    int query(int l, int r, int p) {
      if (l == r) {
        return l;
      }
      int mid = (l + r) >> 1;
      int sum = 0;
      if (p <= mid) {
        REP(i, 1, l1) ltr[i] = tr[ltr[i]].ls;
        REP(i, 1, l2) rtr[i] = tr[rtr[i]].ls;
        return query(l, mid, p);
      }
      else {
        REP(i, 1, l1) sum -= tr[tr[ltr[i]].ls].s, ltr[i] = tr[ltr[i]].rs;
        REP(i, 1, l2) sum += tr[tr[rtr[i]].ls].s, rtr[i] = tr[rtr[i]].rs;
        return sum + query(mid + 1, r, p);
      }
    }
    void init(int l, int r, int k) {
      l1 = l2 = 0;
      l--;
      while(l) {
        ltr[++l1] = l;
        l -= lowbit(l);
      }
      while(r) {
        rtr[++l2] = r;
        r -= lowbit(r);
      }
      return;
    }
    int kth(int l, int r, int k) {
      init(l, r, k);
      return qy(1, n, k);
    }
    int get_rank(int l, int r, int k) {
      init(l, r, k);
      return query(1, n, k);
    }
    

  }tr;
  void main() {
    
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
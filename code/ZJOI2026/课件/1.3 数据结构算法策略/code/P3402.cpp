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
	const int N = 3e5 + 10;
  int n, m;
  struct tree{
    #define mid ((l + r) >> 1)
    int rt[N], idx;
    struct node{
      int ls, rs, fa, dep;
    }tr[N * 20];
    int nd(int u) {
      tr[++idx] = tr[u];
      return idx;
    }
    int build(int u, int l, int r) {
      u = ++idx;
      if (l == r) {tr[u].fa = l; return u;}
      tr[u].ls = build(tr[u].ls, l, mid);
      tr[u].rs = build(tr[u].rs, mid + 1, r);
      return u;
    }
    int q(int u, int l, int r, int x) {
      if (l == r)   return u;
      if (x <= mid) return q(tr[u].ls, l, mid, x);
      else          return q(tr[u].rs, mid + 1, r, x);
    }
    int find(int root, int u) {
      int fa = q(rt[root], 1, n, u);
      if (tr[fa].fa == u) return fa;
      return find(root, tr[fa].fa);
    }
    int mg(int u, int l, int r, int x, int f) {
      int v = nd(u);
      if (l == r) {
        tr[v].fa = f;
        return v;
      }
      if (x <= mid) tr[v].ls = mg(tr[u].ls, l, mid, x, f);
      else          tr[v].rs = mg(tr[u].rs, mid + 1, r, x, f);
      return v;
    }
    int add(int u, int l, int r, int x) {
      int v = nd(u);
      if (l == r) {
        tr[v].dep++;
        return v;
      }
      if (x <= mid) tr[v].ls = add(tr[v].ls, l, mid, x);
      else          tr[v].rs = add(tr[v].rs, mid + 1, r, x);
      return v;
    }
    void merge(int u, int a, int b) {
      rt[u] = rt[u - 1];
      a = find(u, a), b = find(u, b);
      if (tr[a].fa != tr[b].fa) {
        if (tr[a].dep > tr[b].dep)  std::swap(a, b);
        rt[u] = mg(rt[u], 1, n, tr[a].fa, tr[b].fa);
        if (tr[a].dep == tr[b].dep) rt[u] = add(rt[u], 1, n, tr[b].fa);
      }
      return;
    }
    bool check(int u, int a, int b) {
      a = find(u, a), b = find(u, b);
      if (tr[a].fa == tr[b].fa) return 1;
      return 0;
    }
  }tr;
  void main() {
    read(n, m);
    tr.rt[0] = tr.build(1, 1, n);
    REP(i, 1, m) {
      int op, a, b;
      read(op, a);
      if (op == 1) {
        read(b);
        tr.merge(i, a, b);
      }
      else if (op == 2) tr.rt[i] = tr.rt[a];
      else if (op == 3) {
        read(b);
        tr.rt[i] = tr.rt[i - 1];
        if (tr.check(i, a, b))  std::cout << 1 << '\n';
        else                    std::cout << 0 << '\n';
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
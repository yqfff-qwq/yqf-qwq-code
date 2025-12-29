#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define pb push_back
#define fi first
#define se second
#define ll long long
#define RAP(i,a)      for(auto (i)=(a).begin();(i)!=(a).end();(i)++)
#define REP(i,a,b)    for(int (i)=(a);(i)<=(b);(i)++)
#define DEP(i,a,b)    for(int (i)=(a);(i)>=(b);(i)--)
#define REPc(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define DEPc(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define ADD(a,b) (a)=((a)+(b))%mod
#define SUB(a,b) (a)=((a)-(b)+mod)%mod
#define MUL(a,b) (a)=(((a)%mod)*((b)%mod))%mod
#define MAX(a,b) (a)=max((a),(b))
#define MIN(a,b) (a)=min((a),(b))
#define ALL(a)   (a).begin(),(a).end()
#define SZ(a)    ((int)a.size())
#define ppc(x)   __builtin_popcount(x)
#define pii pair<int,int>
void read() {  }
template < typename T, typename... T2 >
inline void read(T &x, T2 &... oth)
{
	x = 0;
	int ch = getchar(), f = 0;
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		f = 1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	if (f)
	x = -x;
	read(oth...);
}

namespace YZLK{
  mt19937 rd(time(0));
  const int N = 4e6 + 10;
  const int M = 3e5 + 10;
  const int mod = 1e9 + 7;
  int lans;
  ll a[M];
  int n, q;
  struct tree {
    struct FHQ {
      int ls, rs, key;
      ll sz, val;
      ll sum;//左右儿子、键值、子树大小、值
      bool tf;
      ll tv;
      ll tc;//filp,val,cover
    }tr[N];
    int rt;
    int T1, T2, T3, T4, T5, idx;
    int bd(int v) {  //新建结点
      tr[++idx] = {0, 0, (int)rd(), 1, v, v, 0, 0, -1};
      return idx;
    }
    int cpy(int x) {
      int y = bd(0);
      tr[y] = tr[x];
      return y;
    }
    int build(int l = 1, int r = n) {
      if (l > r)  return 0;
      int mid = (l + r) >> 1;
      int p = bd(a[mid]);
      tr[p].ls = build(l, mid - 1);
      tr[p].rs = build(mid + 1, r);
      push_up(p);
      return p;
    }
    void push_up(int u) {
      tr[u].sz = (tr[tr[u].ls].sz + tr[tr[u].rs].sz + 1);
      tr[u].sum = (tr[tr[u].ls].sum + tr[tr[u].rs].sum + tr[u].val) % mod;
    }
    void push_down(int u) {   //维护子树信息
      if (!tr[u].tv and !tr[u].tf and tr[u].tc == -1) return;
      if (tr[u].ls) tr[u].ls = cpy(tr[u].ls);
      if (tr[u].rs) tr[u].rs = cpy(tr[u].rs);
      if (tr[u].tf) {
        swap(tr[u].ls, tr[u].rs);
        if (tr[u].ls)   tr[tr[u].ls].tf ^= 1;
        if (tr[u].rs)   tr[tr[u].rs].tf ^= 1;
        tr[u].tf = 0;
      }
      if (~tr[u].tc) {
        if (tr[u].ls) {
          tr[tr[u].ls].tc = tr[u].tc;
          tr[tr[u].ls].tv = 0;
          tr[tr[u].ls].val = tr[u].tc;
          tr[tr[u].ls].sum = (tr[u].tc * tr[tr[u].ls].sz) % mod;
        }
        if (tr[u].rs) {
          tr[tr[u].rs].tc = tr[u].tc;
          tr[tr[u].rs].tv = 0;
          tr[tr[u].rs].val = tr[u].tc;
          tr[tr[u].rs].sum = (tr[u].tc * tr[tr[u].rs].sz) % mod;
        }
        tr[u].tc = -1;
      }
      if (tr[u].tv) {
        if (tr[u].ls) {
          tr[tr[u].ls].tv = (tr[tr[u].ls].tv + tr[u].tv) % mod;
          tr[tr[u].ls].val = (tr[tr[u].ls].val + tr[u].tv) % mod;
          tr[tr[u].ls].sum = (tr[tr[u].ls].sum + tr[u].tv * tr[tr[u].ls].sz % mod) % mod;
        }
        if (tr[u].rs) {
          tr[tr[u].rs].tv = (tr[tr[u].rs].tv + tr[u].tv) % mod;
          tr[tr[u].rs].val = (tr[tr[u].rs].val + tr[u].tv) % mod;
          tr[tr[u].rs].sum = (tr[tr[u].rs].sum + tr[u].tv * tr[tr[u].rs].sz % mod) % mod;
        }
        tr[u].tv = 0;
      }
      return ;
    }
    void split(int u, int k, int &x, int &y) {  //分裂   x，y :某个树的儿子
      if(!u) {
        x = y = 0;
        return ;
      }
      push_down(u);
      int tmp = tr[tr[u].ls].sz + 1;
      if(tmp > k) {
        y = cpy(u);
        split(tr[y].ls, k, x, tr[y].ls);
        push_up(y);
      } else {
        x = cpy(u);
        split(tr[x].rs, k - tmp, tr[x].rs, y);
        push_up(x);
      }
      return ;
    }
    int merge(int x, int y) {   //合并   （大根堆）
      if (!x or !y) return x + y;
      if ((rd() % (tr[x].sz + tr[y].sz)) < tr[x].sz) {
        push_down(x);
        int nw = cpy(x);
        tr[nw].rs = merge(tr[nw].rs, y);
        push_up(nw);
        return nw;
      } else {
        push_down(y);
        int nw = cpy(y);
        tr[nw].ls = merge(x, tr[nw].ls);
        push_up(nw);
        return nw;
      }
    }
    void insert(int p, int v) {    //插入
      split(rt, p, T1, T2);
      rt = merge(merge(T1, build(v)), T2);
      return ;
    }
    void erase(int v) {
      split(rt, v, T1, T2);
      split(T1, v - 1, T1, T3);
      rt = merge(T1, T2);
      return;
    }
    void reverse(int l, int r) {
      split(rt, l - 1, T1, T2);
      split(T2, r - l + 1, T2, T3);
      T2 = cpy(T2);
      tr[T2].tf ^= 1;
      rt = merge(T1, merge(T2, T3));
      return;
    }
    int query(int l, int r) {
      split(rt, l - 1, T1, T2);
      split(T2, r - l + 1, T2, T3);
      int ans = tr[T2].sum;
      rt = merge(T1, merge(T2, T3));
      return ans;
    }
    void exchange(int l1, int r1, int l2, int r2) {
      if (l1 > l2)  swap(l1, l2), swap(r1, r2);
      split(rt, l1 - 1, T1, T2);
      split(T2, r1 - l1 + 1, T2, T3);
      split(T3, r2 - r1, T3, T4);
      split(T3, l2 - r1 - 1, T3, T5);
      rt = merge(T1, merge(T5, merge(T3, merge(T2, T4))));
      return;
    }
    void copy(int l1, int r1, int l2, int r2) {
      bool f = 0;
      if (l1 > l2)  swap(l1, l2), swap(r1, r2), f = 1;
      split(rt, l1 - 1, T1, T2);
      split(T2, r1 - l1 + 1, T2, T3);
      split(T3, r2 - r1, T3, T4);
      split(T3, l2 - r1 - 1, T3, T5);
      if (f == 1) T2 = T5;
      rt = merge(T1, merge(T2, merge(T3, merge(T2, T4))));
      return;
    }
    void cover(int l, int r, int k) {
      split(rt, l - 1, T1, T2);
      split(T2, r - l + 1, T2, T3);
      T2 = cpy(T2);
      tr[T2].tv = 0;
      tr[T2].tc = k;
      tr[T2].val = k;
      tr[T2].sum = k * tr[T2].sz % mod;
      rt = merge(T1, merge(T2, T3));
      return;
    }
    void add(int l, int r, int k) {
      split(rt, l - 1, T1, T2);
      split(T2, r - l + 1, T2, T3);
      T2 = cpy(T2);
      tr[T2].tv = (tr[T2].tv + k) % mod;
      tr[T2].val = (tr[T2].val + k) % mod;
      tr[T2].sum = (tr[T2].sum + k * tr[T2].sz % mod) % mod;
      rt = merge(T1, merge(T2, T3));
      return;
    }
    void get(int u) {
      if (!u) return;
      push_down(u);
      get(tr[u].ls);
      a[++n] = tr[u].val;
      get(tr[u].rs);
    }
  }tr;
  void main() {
    read(n, q);
    REP(i, 1, n)  read(a[i]);
    tr.rt = tr.build();
    REP(i, 1, q) {
      int op, l, r, k, l2, r2;
      read(op);
      if (op == 1) {
        read(l, r);
        l ^= lans;
        r ^= lans;
        lans = tr.query(l, r) % mod;
        std::cout << lans << '\n';
      }
      else if (op == 2) {
        read(l, r, k);
        l ^= lans;
        r ^= lans;
        k ^= lans;
        tr.cover(l, r, k);
      }
      else if (op == 3) {
        read(l, r, k);
        l ^= lans;
        r ^= lans;
        k ^= lans;
        tr.add(l, r, k);
      }
      else if (op == 4) {
        read(l, r, l2, r2);
        l ^= lans;
        r ^= lans;
        l2 ^= lans;
        r2 ^= lans;
        tr.copy(l, r, l2, r2);
      }
      else if (op == 5) {
        read(l, r, l2, r2);
        l ^= lans;
        r ^= lans;
        l2 ^= lans;
        r2 ^= lans;
        tr.exchange(l, r, l2, r2);
      }
      else if (op == 6) {
        read(l, r);
        l ^= lans;
        r ^= lans;
        tr.reverse(l, r);
      }
      if (tr.idx > 3500000) {
        n = 0;
        tr.get(tr.rt);
        tr.rt = tr.idx = 0;
        tr.rt = tr.build();
      }
    }
    n = 0;
    tr.get(tr.rt);
    REP(i, 1, n)  std::cout << a[i] << ' ';
    return ;
  }
}
signed main()
{
 	//freopen("XXX.in","r",stdin);
	//freopen("XXX.out","w",stdout);
    int T = 1;
    // read(T);
    while(T--) {
        YZLK::main();
    }
    //fclose(stdin);
	//fclose(stdout);
	return 0;
}
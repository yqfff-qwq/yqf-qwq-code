#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
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
  const int N = 2e7 + 10;
  const int inf = 1e9;
  int lans;
  struct tree {
    struct FHQ {
      int ls, rs, key, sz, val, sum;//左右儿子、键值、子树大小、值
      bool tag;
    }tr[N];
    int rt[N];
    int T1, T2, T3, idx;
    int build(int v) {  //新建结点
      tr[++idx] = {0, 0, (int)rd(), 1, v, v, 0};
      return idx;
    }
    int cpy(int x) {
      int y = build(0);
      tr[y] = tr[x];
      return y;
    }
    void push_up(int u) {
      tr[u].sz = (tr[tr[u].ls].sz + tr[tr[u].rs].sz + 1);
      tr[u].sum = (tr[tr[u].ls].sum + tr[tr[u].rs].sum + tr[u].val);
    }
    void push_down(int u) {   //维护子树信息
      if (tr[u].tag) {
        if (tr[u].ls) tr[u].ls = cpy(tr[u].ls);
        if (tr[u].rs) tr[u].rs = cpy(tr[u].rs);
        swap(tr[u].ls, tr[u].rs);
        if (tr[u].ls)   tr[tr[u].ls].tag ^= 1;
        if (tr[u].rs)   tr[tr[u].rs].tag ^= 1;
        tr[u].tag = 0;
      }
      return ;
    }
    void split(int u, int k, int &x, int &y) {  //分裂   x，y :某个树的儿子
      // cout << "split\n";
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
      if (tr[x].key > tr[y].key) {
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
    void insert(int &rt, int p, int v) {    //插入
      split(rt, p, T1, T2);
      rt = merge(merge(T1, build(v)), T2);
      return ;
    }
    void erase(int &rt, int v) {
      split(rt, v, T1, T2);
      split(T1, v - 1, T1, T3);
      rt = merge(T1, T2);
      return;
    }
    void reverse(int &rt, int l, int r) {
      split(rt, l - 1, T1, T2);
      split(T2, r - l + 1, T2, T3);
      tr[T2].tag ^= 1;
      rt = merge(T1, merge(T2, T3));
      return;
    }
    int query(int &rt, int l, int r) {
      split(rt, l - 1, T1, T2);
      split(T2, r - l + 1, T2, T3);
      int ans = tr[T2].sum;
      rt = merge(T1, merge(T2, T3));
      return ans;
    }
  }tr;
  int n;
  void main() {
    read(n);
    tr.rt[0] = 0;
    REP(i, 1, n) {
      int v, op, l, r;
      read(v, op);
      tr.rt[i] = tr.rt[v];
      if (op == 1) {
        read(l, r);
        l ^= lans;
        r ^= lans;
        // std::cout << v << " " << op << ' ' << l << ' ' << r << '\n';
        tr.insert(tr.rt[i], l, r);
      }
      else if (op == 2) {
        read(l);
        l ^= lans;
        // std::cout << v << " " << op << ' ' << l << ' ' << r << '\n';
        tr.erase(tr.rt[i], l);
      }
      else if (op == 3) {
        read(l, r);
        l ^= lans;
        r ^= lans;
        // std::cout << v << " " << op << ' ' << l << ' ' << r << '\n';
        tr.reverse(tr.rt[i], l, r);
      }
      else {
        read(l, r);
        l ^= lans;
        r ^= lans;
        // std::cout << v << " " << op << ' ' << l << ' ' << r << '\n';
        lans = tr.query(tr.rt[i], l, r);
        std::cout << lans << '\n';
        // lans = 0;
      }
    }
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
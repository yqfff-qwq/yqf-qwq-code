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
  int ans[N];
  int n, m;
  int a[N], p[N], tot, len;
  struct node{
    int op, l, r, k, id;
  }qy[N], t[N];
  struct tree{
    int tr[N];
    int lowbit(int x) {return x & -x;}
    void upd(int x, int y) {
      while(x <= n) {
        tr[x] += y;
        x += lowbit(x);
      }
      return;
    }
    int query(int x) {
      int sum = 0;
      while(x) {
        sum += tr[x];
        x -= lowbit(x);
      }
      return sum;
    }
    int query(int l, int r) {
      return query(r) - query(l - 1);
    }
  }tr;
  void solve(int l, int r, int L, int R) {
    if (l > r or L > R) return;
    if (l == r) {
      // std::cout << l << ' ' << r << ' ' << L << ' ' << R << '\n';
      REP(i, L, R)  if (!qy[i].op) ans[qy[i].id] = l;
      return;
    }
    int mid = (l + r) >> 1;
    int sl = L - 1, sr = R + 1;
    REP(i, L, R) {
      if (!qy[i].op) {
        int s = tr.query(qy[i].l, qy[i].r);
        if (s >= qy[i].k) t[++sl] = qy[i];
        else              qy[i].k -= s, t[--sr] = qy[i];
      }
      else if (qy[i].k > mid) t[--sr] = qy[i];
      else  t[++sl] = qy[i], tr.upd(qy[i].l, qy[i].op);
    }
    REP(i, L, R) {
      if (qy[i].op and qy[i].k <= mid)  tr.upd(qy[i].l, -qy[i].op);
    }
    REP(i, L, sl) qy[i] = t[i];
    REP(i, sr, R) qy[i] = t[R + sr - i];
    solve(l, mid, L, sl);
    solve(mid + 1, r, sr, R);
    return;
  }
  void main() {
    read(n, m);
    REP(i, 1, n) {
      read(a[i]);
      p[++tot] = a[i];
      qy[++len] = (node){1, i, 0, a[i], 0};
    }
    char ch[2];
    REP(i, 1, m) {
      scanf("%s", ch);
      if (ch[0] == 'Q') {
        len++;
        read(qy[len].l, qy[len].r, qy[len].k);
        qy[len].id = i;
        qy[len].op = 0;
      } else {
        len++;
        read(qy[len].l, qy[len].k);
        len++;
        qy[len] = qy[len - 1];
        qy[len - 1].k = a[qy[len].l];
        p[++tot] = qy[len].k;
        a[qy[len].l] = qy[len].k;
        qy[len].op = 1;
        qy[len - 1].op = -1;
      }
    }
    std::sort(p + 1, p + tot + 1);
    tot = std::unique(p + 1, p + tot + 1) - p - 1;
    REP(i, 1, len) {
      if (!qy[i].op)  continue;
      qy[i].k = std::lower_bound(p + 1, p + tot + 1, qy[i].k) - p;
    }
    solve(1, tot, 1, len);
    REP(i, 1, m)  if (ans[i]) std::cout << p[ans[i]] << '\n';
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
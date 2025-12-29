<<<<<<< HEAD
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <random>
#include <map>

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
	const int mod = 1e9 + 7;
  const int N = 1e5 + 10;
  int seed, vmax, n, m;
  int a[N];
  int ksm(int a, int b, int md) {
    int s = 1;
    while(b) {
      if (b & 1)  s = s * a % md;
      a = a * a % md;
      b >>= 1;
    }
    return s;
  }
  int rnd() {
    int ss = seed;
    seed = (seed * 7 + 13) % mod;
    return ss;
  }
  struct ODT{
    std::map<int, int> mp;
    void init() {mp[1] = -1, mp[n + 1] = -1;return;}
    void split(int x) {
      auto it = prev(mp.upper_bound(x));
      mp[x] = it -> se;
      return;
    }
    void assign(int l, int r, int v) {//r是区间右端点+1
      r++;
      split(l), split(r);
      auto it = mp.find(l);
      while(it -> fi != r)  it = mp.erase(it);
      mp[l] = v;
      return;
    }
    void update(int l, int r, int c) {
      r++;
      split(l), split(r);
      auto it = mp.find(l);
      while(it -> fi != r) {
        it -> se += c;
        it = next(it);
      }
      return;
    }
    int kth(int l, int r, int k) {
      r++;
      split(l), split(r);
      auto it = mp.find(l);
      std::vector<pii> ve; 
      while(it -> fi != r) {
        ve.pb({it -> se, next(it) -> fi - it -> fi});
        it = next(it);
      }
      std::sort(ve.begin(), ve.end());
      for(auto it:ve) {
        if (k <= it.se) return it.fi;
        k -= it.se;
      }
      return -1;
    }
    int query(int l, int r, int x, int md) {
      r++;
      split(l), split(r);
      auto it = mp.find(l);
      int sum = 0;
      while(it -> fi != r) {
        sum = (sum + ksm(it -> se % md , x, md) * (next(it) -> fi - it -> fi) % md) % md;
        it = next(it);
      }
      return sum;
    }
  }tr;
  void main() {
    read(n, m, seed, vmax);
    tr.init();
    REP(i, 1, n)  a[i] = rnd() % vmax + 1, tr.mp[i] = a[i];
    REP(i, 1, m) {
      int op, l, r, x, y;
      op = (rnd() % 4) + 1;
      l = (rnd() % n) + 1;
      r = (rnd() % n) + 1;
      if (l > r)  std::swap(l, r);
      if (op == 3)  x = (rnd() % (r - l + 1)) + 1;
      else          x = (rnd() % vmax) + 1;
      // std::cout << op << ' ' << l << ' ' << r << '\n'; 
      if (op == 4) {
        y = (rnd() % vmax) + 1;
        std::cout << tr.query(l, r, x, y) << '\n';
      }
      else if (op == 3) {
        std::cout << tr.kth(l, r, x) << '\n';
      } else if (op == 2) {
        tr.assign(l, r, x);
      } else {
        tr.update(l, r, x);
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
=======
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <random>
#include <map>

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
	const int mod = 1e9 + 7;
  const int N = 1e5 + 10;
  int seed, vmax, n, m;
  int a[N];
  int ksm(int a, int b) {
    int s = 1;
    while(b) {
      if (b & 1)  s = s * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return s;
  }
  int rnd() {
    int ss = seed;
    seed = (seed * 7 + 13) % mod;
    return ss;
  }
  struct BIT{
    int tr[N];
    int lowbit(int x) {return x & -x;}
    void add(int x, int v) {
      x++;
      while(x <= n) {
        tr[x - 1] += v;
        x += lowbit(x);
      }
      return;
    }
    void add(int l, int r, int v) {
      add(l, v);
      add(r, -v);
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
  };
  struct ODT{
    int n;
    std::vector<int> lazy;
    std::map<int, int> mp;
    BIT bt;
    ODT(int x)  {n = x;mp[-1] = 0;}
    void split(int x) {
      auto it = prev(mp.upper_bound(x));
      mp[x] = it -> se;
      return;
    }
    void assign(int l, int r, int v) {
      split(l), split(r);
      auto it = mp.find(l);
      while(it -> fi != r)  it = mp.erase(it);
      mp[l] = v;
      return;
    }
    void update(int l, int r, int c) {
      split(l), split(r);
      auto it = mp.find(l);
      while(it -> fi != r) {
        bt.add(it -> fi, next(it) -> fi, lazy[it -> se] - lazy[c]);
        it = next(it);
      }
      return;
    }
    void add(int x, int v) {
      lazy[x] += v;
    }
    int query(int x) {
      split(x);
      return bt.query(x) + lazy[mp[x]];
    }
  };
  void main() {
    read(n, m, seed, vmax);
    REP(i, 1, n)  a[i] = rnd() % vmax + 1;
    REP(i, 1, m) {
      int op, l, r, x, y;
      op = (rnd() % 4) + 1;
      l = (rnd() % n) + 1;
      r = (rnd() % n) + 1;
      if (l > r)  std::swap(l, r);
      if (op == 3)  x = (rnd() % (r - l + 1)) + 1;
      else          x = (rnd() % vmax) + 1;
      if (op == 4) {
        y = (rnd() % vmax) + 1;
        

      }
      else if (op == 3) {

      } else if (op == 2) {
        
      } else {
        
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
>>>>>>> cca8a7931a55d5e2ebc4018d53386bee36bffaad
*/
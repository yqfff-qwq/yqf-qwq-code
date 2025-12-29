#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>

// using namespace std;
// #define int long long
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
	const int N = 2e5 + 10;
  int n, q;
  std::map<pii, int> mp;
  bool ans[N];
  struct DSU {
    int fa[N << 1], dep[N << 1];
    void init(int x) {
      REP(i, 0, 2 * x)  fa[i] = i, dep[i] = 1;
      return;
    }
    int find(int x) {
      return (x == fa[x] ? x : find(fa[x]));
    }
    bool merge(int u, int v, std::stack<int> &st) {
      int x = find(u), y = find(v);
      if (x == y) return 0;
      if (dep[x] < dep[y])  std::swap(x, y);
      fa[y] = x;
      dep[x] = std::max(dep[x], dep[y] + 1);
      st.push(y);
      return 1;
    }
    void rb(std::stack<int> &st) {
      while(!st.empty()) {
        int x = st.top();
        st.pop();
        fa[x] = x;
      }
      return;
    }
  }d;
  int len;
  struct edge{
    int u, v;
  }ed[N];
  struct tree{
    #define mid ((l + r) >> 1)
    #define ls (u << 1)
    #define rs (ls | 1)
    std::vector<int> tr[N << 2];
    void update(int u, int l, int r, int ql, int qr, int id) {
      if (ql <= l and r <= qr) {
        tr[u].pb(id);
        return;
      }
      if (ql <= mid)  update(ls, l, mid, ql, qr, id);
      if (mid < qr)   update(rs, mid + 1, r, ql, qr, id);
      return;
    }
    void solve(int u, int l, int r) {
      if (r < l)  return;
      std::stack<int> st;
      for(auto v:tr[u]) {
        if (d.find(ed[v].u) == d.find(ed[v].v)) {
          REP(i, l, r)  ans[i] = 0;
          d.rb(st);
          return;
        }
        d.merge(ed[v].u, ed[v].v + n, st);
        d.merge(ed[v].u + n, ed[v].v, st);
      }
      if (l != r) {
        solve(ls, l, mid);
        solve(rs, mid + 1, r);
      }
      d.rb(st);
      return;
    }
  }tr;
  
  void main() {
    read(n, q);
    d.init(n);
    REP(i, 1, q)  ans[i] = 1;
    REP(i, 1, q) {
      int x, y;
      read(x, y);
      if (mp[{x, y}]) {
        int id = mp[{x, y}];
        ed[++len] = {x, y};
        tr.update(1, 1, q, id, i - 1, len);
        mp[{x, y}] = 0;
      }
      else {
        mp[{x, y}] = i;
      }
    }
    for(auto it:mp) {
      if (it.se) {
        ed[++len] = {it.fi.fi, it.fi.se};
        tr.update(1, 1, q, it.se, q, len);
      }
    }
    tr.solve(1, 1, q);
    REP(i, 1, q)  std::cout << (ans[i] ? "YES" : "NO") << '\n';
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
#include <stack>
#include <map>
#include <vector>
#include <algorithm>

// using namespace std;
// #define int long long
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
	const int N = 2e5 + 10;
  int n, q;
  std::map<pii, int> mp;
  bool ans[N];
  struct DSU {
    int fa[N << 1], dep[N << 1];
    void init(int x) {
      REP(i, 0, 2 * x)  fa[i] = i, dep[i] = 1;
      return;
    }
    int find(int x) {
      return (x == fa[x] ? x : find(fa[x]));
    }
    bool merge(int u, int v, std::stack<int> &st) {
      int x = find(u), y = find(v);
      if (x == y) return 0;
      if (dep[x] < dep[y])  std::swap(x, y);
      fa[y] = x;
      dep[x] = std::max(dep[x], dep[y] + 1);
      st.push(y);
      return 1;
    }
    void rb(std::stack<int> &st) {
      while(!st.empty()) {
        int x = st.top();
        st.pop();
        fa[x] = x;
      }
      return;
    }
  }d;
  int len;
  struct edge{
    int u, v;
  }ed[N];
  struct tree{
    #define mid ((l + r) >> 1)
    #define ls (u << 1)
    #define rs (ls | 1)
    std::vector<int> tr[N << 2];
    void update(int u, int l, int r, int ql, int qr, int id) {
      if (ql <= l and r <= qr) {
        tr[u].pb(id);
        return;
      }
      if (ql <= mid)  update(ls, l, mid, ql, qr, id);
      if (mid < qr)   update(rs, mid + 1, r, ql, qr, id);
      return;
    }
    void solve(int u, int l, int r) {
      if (r < l)  return;
      std::stack<int> st;
      for(auto v:tr[u]) {
        if (d.find(ed[v].u) == d.find(ed[v].v)) {
          REP(i, l, r)  ans[i] = 0;
          d.rb(st);
          return;
        }
        d.merge(ed[v].u, ed[v].v + n, st);
        d.merge(ed[v].u + n, ed[v].v, st);
      }
      if (l != r) {
        solve(ls, l, mid);
        solve(rs, mid + 1, r);
      }
      d.rb(st);
      return;
    }
  }tr;
  
  void main() {
    read(n, q);
    d.init(n);
    REP(i, 1, q)  ans[i] = 1;
    REP(i, 1, q) {
      int x, y;
      read(x, y);
      if (mp[{x, y}]) {
        int id = mp[{x, y}];
        ed[++len] = {x, y};
        tr.update(1, 1, q, id, i - 1, len);
        mp[{x, y}] = 0;
      }
      else {
        mp[{x, y}] = i;
      }
    }
    for(auto it:mp) {
      if (it.se) {
        ed[++len] = {it.fi.fi, it.fi.se};
        tr.update(1, 1, q, it.se, q, len);
      }
    }
    tr.solve(1, 1, q);
    REP(i, 1, q)  std::cout << (ans[i] ? "YES" : "NO") << '\n';
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
>>>>>>> 7d4fbf53e767400be529a299cebbd25d899fdf19
*/
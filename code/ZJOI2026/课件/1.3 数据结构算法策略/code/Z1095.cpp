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
  const int N = 5e5 + 10;
  int n, m, t;
  int a[N];
  int ls;
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
  }tr;
  void main() {
    read(n, m, t);
    tr.init();
    REP(i, 1, n)  read(a[i]), tr.mp[i] = a[i];
    REP(i, 1, m) {
      int op, l, r, x;
      read(op, l, r, x);
      l = (ls ^ l), r = (ls ^ r), x = (ls ^ x);
      if (op == 1)  tr.assign(l, r, x);
      else          ls = tr.kth(l, r, x), std::cout << ls << '\n', ls = ls * t;
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
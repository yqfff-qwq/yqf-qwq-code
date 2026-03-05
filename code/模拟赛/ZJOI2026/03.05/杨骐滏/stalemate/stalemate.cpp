#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>

#define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
#define MAX(a, b) (a) = std::max((a), (b))
#define MIN(a, b) (a) = std::min((a), (b))
#define pii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define uint unsigned long long
#define int long long
#define X(_) (_)
#define Y(_) (dp[_] + _ * _)
#define B(_) (dp[_] - _ * _)
#define K(_) (2 * _)

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
  const int mod = 998244353;
  const int N = 1e3 + 10;
  int n, m, q;
  struct node{
    int x, y;
  }a[N];
  int cnt[N];
  int c[N];
  int h[N];
  std::vector<int> s;
  struct dsu{
    int fa[N];
    void init(int x) {
      REP(i, 0, x)  fa[i] = i;
      return;
    }
    int find(int x) {
      return (fa[x] == x ? fa[x] : fa[x] = find(fa[x]));
    }
  }d;
	void main() {
		read(n, m, q);
    REP(i, 1, m)  read(a[i].x, a[i].y);
    REP(t, 0, (1ll << m) - 1) {
      d.init(n);
      REP(i, 1, n)  c[i] = 0;
      s.clear();
      REP(i, 1, m) {
        if ((t >> (i - 1)) & 1) {
          s.pb(a[i].x);
          s.pb(a[i].y);
          c[a[i].x]++, c[a[i].y]++;
          int u = d.find(a[i].x), v = d.find(a[i].y);
          if (u != v) d.fa[u] = v;
        }
      }
      std::sort(s.begin(), s.end());
      s.erase(unique(s.begin(), s.end()), s.end());
      bool flag = 1;
      if (s.empty())  continue;
      int i = s[0];
      for(auto j:s) {
        if (d.find(j) != d.find(i)) {flag = 0;break;}
      }
      if (!flag)  continue;
      int tot = 0;
      REP(i, 1, n)  tot += (c[i] >= 2);
      cnt[tot]++;
    }
    while(q--) {
      REP(i, 1, n)  read(h[i]);
      int ans = 0;
      REP(i, 1, n)  ans = (ans + h[i] * cnt[i]) % mod;
      std::cout << ans << '\n';
    }
		return;
  }
}

signed main()
{
  freopen("stalemate.in","r",stdin);
  freopen("stalemate.out","w",stdout);
  int T=1;
  read(T);
  while(T--)
  {
    YZLK::main();
  }

  fclose(stdin);
  fclose(stdout);
  return 0;
}

/*

code by yqfff_qwq

交代码之前看一下

这是你的代码吗？这是你要交的题吗？

多测了吗？多测清空了吗？多测清空会超时吗？会出现其他问题吗？

数组开小了吗？模数正确吗？调试删干净了吗？

*/

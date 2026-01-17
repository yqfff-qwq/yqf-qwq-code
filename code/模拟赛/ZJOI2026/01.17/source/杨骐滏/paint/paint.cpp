#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

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
  const int N = 1e2 + 10;
  int n, m;
  bool flag = 1;
  int ans = 0;
  struct nd{
    int a, x, b, y;
  };
  struct node{
    int y, a, x;
  };
  std::vector<node> ve[N];
  std::vector<nd> vv;
  std::vector<int> pp;
  int s[N];
  void dfs(int t) {
    if (t == n + 1) return ans++, void();
    int fl = 7;
    for(auto it:ve[t]) {
      if (s[it.a] == it.x) {
        fl = fl & (7 ^ (1ll << it.y));
      }
    }
    REP(i, 0, 2) {
      if ((fl >> i) & 1) {
        s[t] = i;
        dfs(t + 1);
      }
    }
    return;
  }
  int ksm(int a, int b) {
    int s = 1;
    while(b) {
      if (b & 1)  s = s * a;
      a = a * a;
      b >>= 1;
    }
    return s;
  }
  int vis[N];
  void ds(int t, int c) {
    if (t == n + 1) {
      ans += ksm(2, n - c);
      return;
    }
    ds(t + 1, c);
    if (!vis[t]) {
      for(auto it:ve[t]) {
        vis[it.a]++;
      }
      ds(t + 1, c + 1);
      for(auto it:ve[t]) {
        vis[it.a]--;
      }
    }
    return;
  }
  void main() {
    read(n, m);
    REP(i, 1, m) {
      int a, x, b, y;
      read(a, x, b, y);
      vv.pb({a, x, b, y});
      if (x or y) flag = 0;
      pp.pb(a);
      pp.pb(b);
    }
    if (flag) {
      for(auto it:vv) {
        ve[it.a].pb({it.x, it.b, it.y});
      }
      ds(1, 0);
      std::cout << ans << '\n';
      return;
    }
    std::sort(pp.begin(), pp.end());
    pp.erase(std::unique(pp.begin(), pp.end()), pp.end());
    for(auto it:vv) {
      it.a = lower_bound(pp.begin(), pp.end(), it.a) - pp.begin() + 1;
      it.b = lower_bound(pp.begin(), pp.end(), it.b) - pp.begin() + 1;
      ve[it.b].pb({it.y, it.a, it.x});
    }
    int sum = ksm(3ll, n - pp.size());
    dfs(1);
    std::cout << ans * sum << '\n';
    return ;
  }
}

signed main()
{
  freopen("paint.in","r",stdin);
  freopen("paint.out","w",stdout);
  int T=1;
  // read(T);
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
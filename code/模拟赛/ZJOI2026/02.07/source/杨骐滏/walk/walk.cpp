#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>

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
  const int N = 5e5 + 10;
  int n;
  std::vector<pii> ve[N];
  int w[N];
  int a[N], b[N];
  int ans = 0;

  void dfs(int u, int sum) {
    b[u] = w[u];
    ans += w[u] * sum;
    for(auto it:ve[u]) {
      a[it.fi] += it.se;
      dfs(it.fi, sum + it.se);
      b[u] += b[it.fi];
      a[u] += a[it.fi];
    }
    return;
  }
  struct node{
    int a, b;
  }c[N];
  int len;
  void ds(int u) {
    len = 0;
    for(auto it:ve[u])  c[++len] = {a[it.fi], b[it.fi]};
    std::sort(c + 1, c + len + 1, [](node x, node y) {
      return y.b * x.a < y.a * x.b;
    });
    int sum = 0;
    REP(i, 1, len) {
      ans += sum * c[i].b;
      sum += c[i].a;
    }
    for(auto it:ve[u])  ds(it.fi);
    return;
  }
  void main() {
    read(n);
    REP(i, 2, n) {
      int fa, v;
      read(fa, v);
      ve[fa].pb({i, v});
    }
    REP(i, 1, n)  read(w[i]);
    dfs(1, 0);
    ds(1);
    std::cout << ans << '\n';
    return ;
  }
}

signed main()
{
  freopen("walk.in","r",stdin);
  freopen("walk.out","w",stdout);
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
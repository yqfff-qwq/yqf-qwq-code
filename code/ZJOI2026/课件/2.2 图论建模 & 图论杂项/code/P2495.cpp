#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
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
#define ull unsigned long long
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
  const int N = 1e6 + 10;
  int n;
  int dfn[N], idx;
  int st[N], tl;
  int dep[N], sz[N];
  int fa[N], son[N];
  int h[N], len, tot;
  struct node{
    int to, ne, c;
  }e[N], ve[N];
  int he[N];
  void dfs1(int u, int f) {
    sz[u] = 1;
    fa[u] = f;
    dep[u] = dep[f] + 1;
    for(int i = he[u];i;i = e[i].ne) {
      int v = e[i].to;
      if (v == f) continue;
      dfs1(v, f);
      sz[u] += sz[v];
      if (sz[u] > )
    }
    return;
  }
  void build() {
    std::sort(h + 1, h + len + 1, [](int a, int b){
      return dfn[a] < dfn[b];
    });
    st[++tl] = 1;

    return;
  }
  void main() {
    read(n);
    REP(i, 1, n) {
      int u, v, w;
      read(u, v, w);
      read(v, u, w);
    }
    dfs1(1, 0);
    return ;
  }
}

signed main()
{
  // freopen("array.in","r",stdin);
  // freopen("array.out","w",stdout);
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
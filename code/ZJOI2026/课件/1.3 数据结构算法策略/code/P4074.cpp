#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
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
  const int N = 1e5 + 10;
  int n, m, q;
  int a[N], b[N], c[N];
  int bl[N], bk;
  std::vector<int> ve[N];
  int ans[N], l1, l2;
  int L[N], R[N];
  int dfn[N];
  int idx;
  struct node{
    int x, y, id, t;
  }qy[N];
  pii d[N];
  bool cmp(node a, node b) {
    if (bl[a.x] == bl[b.x]) return a.y < b.y;
    return a.x < b.x; 
  }
  void dfs(int u, int ff) {
    
    L[u] = ++idx;
    dfn[idx] = u;
    for(auto v:ve[u]) {
      if (v == ff)  continue;
      dfs(v, u);
    }
    R[u] = ++idx;
    dfn[idx] = u;
    return;
  }
  void main() {
    read(n, m, q);
    bk = sqrt(n);
    REP(i, 1, m)  read(a[i]);
    REP(i, 1, n)  read(b[i]), bl[i] = (i - 1) / bk + 1;
    REP(i, 1, n - 1) {
      int u, v;
      read(u, v);
      ve[v].pb(u);
      ve[u].pb(v);
    }
    REP(i, 1, n)  read(c[i]);
    REP(i, 1, q) {
      int op, x, y;
      read(op, x, y);
      if (op) {
        l1++;
        qy[l1] = {x, y, l1, l2};
      }
      else  d[++l2] = {x, y};
    }
    REP(i, 1, l1) std::cout << ans[i] << '\n';
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
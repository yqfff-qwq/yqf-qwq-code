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
  const int mod = 1e9 + 7;
  const int N = 5e3 + 10;
  int n, m;
  int a[N], b[N];
  int t;
  int cnt = 0;
  int d[N];
  int vis[N], tot;
  int c[N];
  bool cmp(int a, int b) {
    int x = a, y = b;
    for(int i = x, j = y;i <= n and j <= n;i++, j++) {
      if (d[i] < d[j])  return 1;
      if (d[i] > d[j])  return 0;
    }
    return x > y;
  }
  void dfs(int p) {
    if (p > n) {
      if (tot != t) return;
      std::sort(c + 1, c + n + 1, cmp);
      bool flag = 1;
      REP(i, 1, n)  if (c[i] != a[i]) {flag = 0;break;}
      cnt += flag;
      return;
    }
    if (t - tot > n - p + 1)  return;
    REP(i, 1, t) {
      vis[i]++;
      if (vis[i] == 1)  tot++;
      d[p] = i;
      dfs(p + 1);
      vis[i]--;
      if (!vis[i])      tot--;
    }
    return;
  }
  void main() {
    read(n, m);
    REP(i, 1, n)  a[i] = c[i] = i;
    REP(i, 1, m) {
      int op, x, y;
      read(op, x, y);
      if (op == 0) {
        for(int j = 1, k = x;k <= y;j++, k++) b[j] = a[k];
        for(int j = y, k = x - 1;k >= 1;j--, k--) a[j] = a[k];
        for(int j = 1, k = x;k <= y;j++, k++) a[j] = b[j];
      }
      else {
        for(int j = x, k = y;j <= k;j++, k--) std::swap(a[j], a[k]);
      }
    }
    for(t = 1;t <= n;t++){
      REP(i, 1, n)  vis[i] = 0;
      tot = 0, dfs(1);
    }
    std::cout << cnt << '\n';
    return ;
  }
}

signed main()
{
  freopen("sa.in","r",stdin);
  freopen("sa.out","w",stdout);
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
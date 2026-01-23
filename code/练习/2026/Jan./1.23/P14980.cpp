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
#define MAX(a, b) (a) = max((a), (b))
#define MIN(a, b) (a) = min((a), (b))
#define pii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ull unsigned long long
#define ll long long
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
  const int N = 2e5 + 10;
  int n, m;
  int f[N];
  struct node{
    int fi, se, th;
  }q[N];
  int vis[N];
  int a[N];
  struct dsu{
    int fa[N], sz[N], d[N];
    void init(int x) {
      REP(i, 0, x)  fa[i] = i, sz[i] = 1;
      return;
    }
    int find(int u) {
      return (fa[u] == u ? fa[u] : fa[u] = find(fa[u]));
    }
    bool merge(int x, int y) {
      x = find(x), y = find(y);
      if (x == y) return 0;
      // if (sz[x] < sz[y])  std::swap(x, y);
      fa[y] = x;
      sz[x] += sz[y];
      d[y] = x;
      return 1;
    }
  }p;
  int cg(char c) {
    if (c == 'C')       return 1;
    else if (c == 'O')  return 2;
    else                return 3;
  }
  int s[4][N];
  void main() {
    read(n);
    REP(i, 1, n)  read(f[i]);
    p.init(n);
    read(m);
    char ch[2];
    REP(i, 1, m) {
      read(q[i].fi);
      if (!a[q[i].fi])  a[q[i].fi] = i;
      scanf("%s", ch);
      q[i].se = cg(ch[0]);
      q[i].th = vis[q[i].fi];
      vis[q[i].fi] = q[i].se;
    }
    REP(i, 1, n) {
      if (!vis[i])  p.merge(f[i], i);
    }
    REP(i, 1, n) {
      if (p.find(i) == i) {
        p.d[i] = vis[i];
        s[vis[i]][m] += p.sz[i];
      }
    }
    DEP(i, m, 2) {
      s[1][i - 1] = s[1][i];
      s[2][i - 1] = s[2][i];
      s[3][i - 1] = s[3][i];
      if (a[q[i].fi] != i) {
        s[p.d[q[i].fi]][i - 1] -= p.sz[q[i].fi];
        p.d[q[i].fi] = q[i].th;
        s[p.d[q[i].fi]][i - 1] += p.sz[q[i].fi];
      } else {
        s[p.d[q[i].fi]][i - 1] -= p.sz[q[i].fi];
        p.d[q[i].fi] = 0;
        bool b = p.merge(f[q[i].fi], q[i].fi);
        // std::cout << i << ' ' << p.find(q[i].fi) << ' ' << q[i].fi << '\n';
        if (b)  s[p.d[p.find(q[i].fi)]][i - 1] += p.sz[q[i].fi];
      }
    }

    REP(i, 1, m)  std::cout << s[1][i] << ' ' << s[2][i] << ' ' << s[3][i] << '\n';
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

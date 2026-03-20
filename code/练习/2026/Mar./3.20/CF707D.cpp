#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>
#include <bitset>

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
  const int N = 1e3 + 10;
  const int M = 1e5 + 10;
  int n, m, q;
  int s[M];
  struct node{
    int op, x, y;
  }qy[M];
  std::bitset<N> f[N];
  std::bitset<N> all;
  std::vector<int> ve[M];
  void dfs(int u, int ans) {
    int op = qy[u].op, x = qy[u].x, y = qy[u].y, d = 0;
    std::bitset<N> p;
    if (op == 1) {
      d = f[x][y];
      if (d == 0) ans++;
      f[x][y] = 1;
    } else if (op == 2) {
      d = f[x][y];
      if (d == 1)  ans--;
      f[x][y] = 0;
    } else if (op == 3) {
      p = f[x];
      ans += (m - 2 * p.count());
      f[x] ^= all;
    }
    s[u] = ans;
    for(auto v:ve[u]) {
      dfs(v, ans);
    }
    if (op <= 2)  f[x][y] = d;
    else if (op == 3) f[x] = p;
    return;
  }
  void main() {
		read(n, m, q);
    REP(i, 1, m)  all.set(i);
    REP(i, 1, q) {
      read(qy[i].op, qy[i].x);
      if (qy[i].op <= 2)  read(qy[i].y);
      if (qy[i].op == 4)  ve[qy[i].x].pb(i);
      else                ve[i - 1].pb(i);
    }
    dfs(0, 0);
    REP(i, 1, q)  std::cout << s[i] << '\n';
    return;
  }
}

signed main()
{
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
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

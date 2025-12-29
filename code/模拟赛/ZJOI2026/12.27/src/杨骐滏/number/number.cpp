#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
#define MAX(a, b) (a) = max((a), (b))
#define MIN(a, b) (a) = min((a), (b))
#define pii pair<int, int>
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
  const int N = 20 + 5;
  int n, m;
  int a[N];
  bool v[N];
  int b[N], ln;
  int f[N][2][2];
  void init(int x) {
    ln = 0;
    if (x == 0) b[++ln] = 0;
    while(x)    b[++ln] = x % 10, x = x / 10;
    return;
  }
  int dfs(int p, bool lim, bool z) {
    if (p == 0) return 1;
    if (~f[p][lim][z]) return f[p][lim][z];
    int ans = 0;
    for(int i = z, d = (lim ? b[p] : 9);i <= d;i++) {
      if (v[i]) continue;
      ans = ans + dfs(p - 1, (lim and i == d), 0);
    }
    return f[p][lim][z] = ans;
  }
  int query() {
    int sum = 0;
    sum += dfs(ln, 1, (ln > 1));
    // std::cout << sum << '\n';
    DEP(i, ln - 1, 2) sum += dfs(i, 0, 1);
    if (ln > 1)       sum += dfs(1, 0, 0);
    return sum;
  }
  void main() {
    memset(f, -1, sizeof(f));
    read(n, m);
    REP(i, 0, 10) v[i] = 0;
    REP(i, 1, m)  read(a[i]), v[a[i]] = 1;
    init(n);
    std::cout << query() << '\n';
    return ;
  }
}

signed main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
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
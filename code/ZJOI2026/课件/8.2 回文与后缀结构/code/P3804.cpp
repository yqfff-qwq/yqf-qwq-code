#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>
#include <map>

// #define int long long
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
  const int N = 2e6 + 10;
  struct node{
    int len, fa;
    std::map<char, int> nxt;
  };
  node st[N];
  int sz, last;
  ll f[N];
  void init() {
    st[0].len = 0;
    st[0].fa = -1;
    sz = last = 0;
    return;
  }
  void build(char c) {
    int tot = ++sz;
    f[sz] = 1;
    st[tot].len = st[last].len + 1;
    int p = last;
    while(p != -1 and !st[p].nxt.count(c))  st[p].nxt[c] = tot, p = st[p].fa;
    if (p == -1) {
      st[tot].fa = 0;
    }
    else {
      int q = st[p].nxt[c];
      if (st[p].len + 1 == st[q].len) {
        st[tot].fa = q;
      }
      else {
        int cl = ++sz;
        st[cl] = st[q];
        st[cl].len = st[p].len + 1;
        while(p != -1 and st[p].nxt[c] == q) {
          st[p].nxt[c] = cl;
          p = st[p].fa;
        }
        st[q].fa = st[tot].fa = cl;
      }
    }
    last = tot;
    return;
  }
  ll ans;
  int he[N], to[N], ne[N], tot;
  void add(int u, int v) {
    ne[++tot] = he[u];
    he[u] = tot;
    to[tot] = v;
  }
  char c[N];
  void dfs(int u) {
    for(int i = he[u];i;i = ne[i]) {
      dfs(to[i]);
      f[u] += f[to[i]];
    }
    if (f[u] != 1) ans = std::max(ans, f[u] * st[u].len);
    return;
  }
  void main() {
    init();
    scanf("%s", c + 1);
    int len = strlen(c + 1);
    REP(i, 1, len)  build(c[i]);
    REP(i, 1, sz) add(st[i].fa, i);
    dfs(0);
    std::cout << ans << '\n';
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

这是你的代码吗喵喵？这是你要交的题吗喵喵？

多测了吗喵喵？多测清空了吗喵喵？多测清空会超时吗喵喵？会出现其他问题吗喵喵？

数组开小了吗喵喵？模数正确吗喵喵？调试删干净了吗喵喵？

*/
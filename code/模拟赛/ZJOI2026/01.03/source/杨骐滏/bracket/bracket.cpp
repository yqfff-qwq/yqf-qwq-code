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
  const int N = 1e3 + 10;
  int n;
  int p[N];
  int h[N], tl;
  bool vis[N];
  std::vector<int> d[N];
  int s[N];
  
  void main() {
    read(n);
    REP(i, 1, n)  read(p[i]);
    REP(i, 1, n) {
      if (vis[i])  continue;
      h[++tl] = i;
      d[i].pb(i);
      int x = p[i];
      vis[i] = 1;
      while(x != i) {
        vis[x] = 1;
        d[i].pb(x);
        x = p[x];
      }
      if (d[i].size() == 2) {
        s[std::min(d[i][0], d[i][1])] = 1;
        s[std::max(d[i][0], d[i][1])] = -1;
        tl--;
      }
    }
    REP(i, 0, (1ll << tl) - 1) {
      REP(j, 1, tl) {
        int t = (i >> (j - 1)) & 1;
        for(auto v:d[h[j]]) {
          s[v] = (t == 1 ? 1 : -1);
          t ^= 1;
        }
      }
      int sum = 0;
      REP(j, 1, n) {
        sum += s[j];
        if (sum < 0)  break;
      }
      if (sum == 0) {
        REP(j, 1, n)  std::cout << (s[j] == 1 ? '(' : ')');
        return;
      }
    }

    return ;
  }
}

signed main()
{
  freopen("bracket.in","r",stdin);
  freopen("bracket.out","w",stdout);
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
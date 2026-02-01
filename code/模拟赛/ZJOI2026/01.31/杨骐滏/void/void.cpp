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
  const int N = 2e6 + 10;
  int n, m;
  int d[N];
  std::vector<int> ans;
  std::vector<int> ve[N];
  void main() {
    read(n, m);
    ans.clear();
    REP(i, 1, n)  ve[i].clear(), d[i] = 0;
    REP(i, 1, m) {
      int u, v;
      read(u, v);
      d[u]++, d[v]++;
    }
    REP(i, 1, n) {
      if (d[i] & 1) ans.pb(i);
    }
    if (ans.empty())  std::cout << "1 2\n";
    else  std::cout << ans[0] << ' ' << ans[1] << '\n';
    return ;
  }
}


signed main()
{
  freopen("void.in","r",stdin);
  freopen("void.out","w",stdout);
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

这是你的代码吗喵？这是你要交的题吗喵？

多测了吗喵？多测清空了吗喵？多测清空会超时吗喵？会出现其他问题吗喵？

数组开小了吗喵？模数正确吗喵？调试删干净了吗喵？

*/
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
  const int N = 1e3 + 10;
  int n;
  int a[N];
  struct node{
    int x, y, z;
  };
  std::map<node, int> mp;
  int dfs(int x, int y, int z, int op) {
    if (mp[{x, y, z}] != 0) {
      return (mp[{x, y, z}] == -1 ? 0 : mp[{x, y, z}]);
    }
    int flag = 0;
    if (flag == 0)  mp[{x, y, z}] = -1;
    else            mp[{x, y, z}] = flag;
    return flag;
  }
  void main() {
    read(n);
    REP(i, 1, n)  read(a[i]);
    std::sort(a + 1, a + n + 1);
    int cnt = 0;
    REP(i, 1, n)
      REP(j, i + 1, n)
        REP(k, j + 1, n) {
          cnt += dfs(a[i], a[j], a[k], 1);
        }
    std::cout << cnt << '\n';
    return ;
  }
}

signed main()
{
  freopen("game.in","r",stdin);
  freopen("game.out","w",stdout);
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
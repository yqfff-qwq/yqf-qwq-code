#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
// using namespace std;

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
  const int N = 2e3 + 10;
  const int M = 1e6 + 10;
  int n, m;
  struct node{
    int x, y;
  }a[N], b[N];
  int f[M];
  int lmx;
  void main() {
    read(n, m);
    REP(i, 1, n)  read(a[i].x, a[i].y);
    REP(i, 1, m)  read(b[i].x, b[i].y);
    REP(i, 1, n) {
      REP(j, 1, m) {
        if (a[i].y > b[j].y)  continue;
        lmx = std::max(lmx, b[j].y - a[i].y);
        f[b[j].y - a[i].y] = std::max(b[j].x - a[i].x + 1, f[b[j].y - a[i].y]);
      }
    }
    int ans = lmx + 1;
    int mx = 0;//相当于这些点都没有走出范围，那么要取步数最大的
    DEP(i, lmx, 0) {
      mx = std::max(mx, f[i]);
      ans = std::min(ans, i + mx);
    }
    std::cout << ans << "\n";
    return ;
  }
}

signed main()
{
  // freopen("c.in","r",stdin);
  // freopen("c.out","w",stdout);
  // std::cin.tie(nullptr) -> sync_with_stdio(false);
  int T=1;
//   read(T);
  while(T--) {
    YZLK::main();
  }

  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

/*

code by yqfff_qwq

交代码之前看一下

这是你的代码吗？这是你要交的题吗？

多测了吗？多测清空了吗？多测清空会超时吗？会出现其他问题吗？

数组开小了吗？模数正确吗？调试删干净了吗？

*/
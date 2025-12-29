#include <iostream>
#include <algorithm>
#include <cstring>
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
  const int N = 3e5 + 10;
  int n, c;
  int a[N], s[N];

  void main() {
    read(n, c);
    REP(i, 1, n)  read(a[i]), s[i] = s[i - 1] + a[i];
    int sx = 0, sn = 0;
    int mx = 0, mn = 0;
    REP(i, 1, n) {
      sx = std::max(sx, s[i] - mn);
      sn = std::min(sn, s[i] - mx);
      mx = std::max(mx, s[i]);
      mn = std::min(mn, s[i]);
    }
    int ans = s[n];
    ans = std::max(ans, s[n] + sx * (c - 1));
    ans = std::max(ans, s[n] + sn * (c - 1));
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
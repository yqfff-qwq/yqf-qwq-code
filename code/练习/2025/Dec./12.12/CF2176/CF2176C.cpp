#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <vector>
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
  const int N = 2e5 + 10;
  int n;
  int a[N];
  std::vector<int> c1, c2;
  void main() {
    read(n);
    c1.clear();
    c2.clear();
    REP(i, 1, n) {
      read(a[i]);
      if (a[i] & 1) c1.pb(a[i]);
      else          c2.pb(a[i]);
    }
    std::sort(c1.begin(), c1.end());
    std::sort(c2.begin(), c2.end());
    int l1 = c1.size(), l2 = c2.size();
    if (!l1) {
      REP(i, 1, n)  std::cout << 0 << " ";
      puts("");
      return;
    }
    if (!l2) {
      REP(i, 1, n) {
        if (i & 1)  std::cout << c1[l1 - 1] << " ";
        else        std::cout << 0 << ' ';  
      }
      puts("");
      return;
    }
    int ans = c1[l1 - 1];
    std::cout << ans << " ";
    DEP(i, l2 - 1, 0) {
      ans += c2[i];
      std::cout << ans << " ";
    }
    REP(i, 1, l1 - 1) {
      if (i == l1 - 1) {
        std::cout << 0 << ' ';
        continue;
      }
      std::cout << ans - c2[0] << " ";
      std::cout << ans << " ";
      i++;
    }
    puts("");
    return ;
  }
}

signed main()
{
  // freopen("c.in","r",stdin);
  // freopen("c.out","w",stdout);
  // std::cin.tie(nullptr) -> sync_with_stdio(false);
  int T=1;
  read(T);
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
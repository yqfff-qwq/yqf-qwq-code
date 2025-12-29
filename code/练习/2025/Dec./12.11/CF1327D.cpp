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
  const int N = 2e5 + 10;
  int n;
  int p[N], c[N];
  bool vis[N];
  int ans;
  std::vector<int> d, l;
  void init() {
    d.clear();
    int len = l.size();
    for(int i = 1;i <= len / i;i++) {
      if (len % i)  continue;
      d.pb(i);
      if (i * i != len) d.pb(len / i);
    }
    sort(d.begin(), d.end());
    return;
  }
  void solve() {
    init();
    for(auto s:d) {
      // std::cout << s << " ";
      for(int i = 0;i < s;i++) {
        bool vis = 1;
        for(int j = i;j < l.size();j += s) {
          // std::cout << l[j] <<" ";
          if (l[j] != l[i]) {vis = 0;break;}
        }
        if (vis)  {ans = std::min(ans, s);return;}
      }
    }
    // puts("");
    return;
  }
  void main() {
    read(n);
    ans = n;
    REP(i, 1, n)  read(p[i]), vis[i] = 0;
    REP(i, 1, n)  read(c[i]);
    REP(i, 1, n) {
      if (vis[i])  continue;
      l.clear();
      int j = i;
      while(!vis[j]) {
        l.pb(c[j]);
        vis[j] = 1;
        j = p[j];
      }
      solve();
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
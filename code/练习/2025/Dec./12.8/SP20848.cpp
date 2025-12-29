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
  const int N = 20;
  int a[N];
  int f[N][2][N];
  int dfs(int p, bool l, int d) {
    if (!p) return !d;
    if (~f[p][l][d] and !l) return f[p][l][d];
    int ans = 0;
    for(int i = 0, n = l ? a[p] : 9;i <= n;i++) {
      ans += dfs(p - 1, l and i == n, i ^ d);
    }
    return f[p][l][d] = ans;
  }
  int q(int x) {
    int ln = 0;
    memset(f, -1, sizeof(f));
    while(x) {
      a[++ln] = x % 10;
      x /= 10;
    }
    int ans = dfs(ln, 1, 0);
    // DEP(i, ln - 1, 0) {
    //   ans += dfs(i, 1, 0, 0);
    // }
    return ans;
  }
  void main() {
    int x, y;
    read(x, y);
    int sum = q(y) - q(x - 1);
    std::cout << y - x + 1 - sum << " " << sum << "\n";
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
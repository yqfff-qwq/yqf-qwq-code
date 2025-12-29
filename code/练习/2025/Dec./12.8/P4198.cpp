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
  const int N = 1e5 + 10;
  const double eps = 1e-9;
  int n, m;
  double a[N];
  struct tree{
    #define ls (u << 1)
    #define rs ((ls) | 1)
    #define mid ((l + r) >> 1)
    double d[N << 2];
    int s[N << 2];
    int pu(int u, int l, int r, double lx) {
      if (d[u] - lx < eps)    return 0;
      if (a[l] - lx > eps)    return s[u];
      if (l == r)             return (d[u] - lx) > eps;
      if (d[ls] - lx < eps)   return pu(rs, mid + 1, r, lx);
      else                    return pu(ls, l, mid, lx) + s[u] - s[ls];
    }
    void push_up(int u) {
      d[u] = std::max(d[ls], d[rs]);
      return;
    }
    void update(int u, int l, int r, int p, int x) {
      if (l == r) {
        d[u] = (double)((x * 1.0) / (p * 1.0));
        s[u] = 1;
        return;
      }
      if (p <= mid) update(ls, l, mid, p, x);
      else          update(rs, mid + 1, r, p, x);
      push_up(u);
      s[u] = s[ls] + pu(rs, mid + 1, r, d[ls]);
      return;
    }
  }tr;
  void main() {
    read(n, m);
    REP(i, 1, m) {
      int x, y;
      read(x, y);
      a[x] = (double)((y * 1.0) / (x * 1.0));
      tr.update(1, 1, n, x, y);
      std::cout << tr.s[1] << "\n";
    }
    return ;
  }
}

signed main()
{
  // freopen("c.in","r",stdin);
  // freopen("c.out","w",stdout);
  // std::cin.tie(nullptr) -> sync_with_stdio(false);
  int T=1;
  // read(T);
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
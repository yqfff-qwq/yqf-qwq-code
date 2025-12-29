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
  const int N = 5e2 + 10;
  int n;
  struct node{
    int k, d;
  }a[N];
  void Min(node &a, node b) {
    if (a.k >= b.k)  a.k = b.k, a.d = b.d;
    return;
  }
  void Max(node &a, node b) {
    if (a.k < b.k)  a.k = b.k, a.d = b.d;
    return;
  }
  void main() {
    read(n);
    REP(i, 1, n)  read(a[i].k), a[i].d = i;
    std::sort(a + 1, a + n + 1, [](node a, node b){
      return a.k < b.k;
    });
    int sum = 0;
    int ans = -1, x = 0, y = 0;
    node mn, mx;
    mn = {n, 0}, mx = {-1, 0};
    REP(i, 1, n) {
      sum += a[i].k;
      Max(mx, a[i]);
      Min(mn, a[i]);
      if (sum == i * (i - 1) / 2) {
        if (mx.d != mn.d) {
            if (mx.k - mn.k > ans) {
            ans = mx.k - mn.k;
            x = mx.d, y = mn.d;
          }
        }
        mx = {-1, 0};
        mn = {n, 0};
      }
    }

    std::cout << "! " << x << " " << y << std::endl;
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
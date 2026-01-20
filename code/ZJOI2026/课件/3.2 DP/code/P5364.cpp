#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>

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
#define K(_) (a[_].l)
#define X(_) (a[_+1].w)
#define B(_) (f[_])
#define Y(_) (f[_])

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
  const int mod = 1e9 + 7;
  int n, k;
  int km(int a, int b) {
    int s = 1;
    while(b) {
      if (b & 1)  s = s * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return s;
  }
  struct node {
    int n, m;
    int a[13][13];
    node(int nn, int mm) {
      n = nn;
      m = mm;
      memset(a, 0, sizeof(a));
    }
  };
  node operator *(const node& x, const node& y) {
    node z(x.n, y.m);
    REP(k, 1, x.m) {
      REP(i, 1, x.n) {
        REP(j, 1, y.m) {
          z.a[i][j] = (z.a[i][j] + (x.a[i][k] * y.a[k][j]) % mod) % mod;
        }
      }
    }
    return z;
  }
  node ksm(node a,int b) {
    node s(a.n, a.m);
    REP(i, 1, a.n)  s.a[i][i] = 1;
    while(b) {
      if(b & 1) s = s * a;
      a = a * a;
      b >>= 1;
    }
    return s;
  }
  void main() {
    read(n, k);
    node a(k + 2 ,k + 2);
    node c(k + 2, k + 2);
    a.a[1][1] = 2, a.a[1][2] = 1;
    DEP(i, k + 2, 2) {
      DEP(j, k + 2, i) {
        if (j == k + 2 or j == i) a.a[i][j] = 1;
        else  a.a[i][j] = (a.a[i + 1][j] + a.a[i + 1][j + 1]) % mod;
      }
    }
    // REP(i, 1, k + 2) {
    //   REP(j, 1, k + 2)  std::cout << a.a[i][j] << " \n"[j == k + 2];
    // }
    int ans = 0;
    c = ksm(a, n - 2);
    node b(k + 2, 1);
    b.a[1][1] = 1;
    REP(i, 2, k + 2)  b.a[i][1] = km(2ll, (k + 2 - i));
    b = c * b;
    ans = (mod - b.a[1][1]);
    b = a * b;
    ans = (ans + b.a[1][1]) % mod;
    std::cout << ans << '\n';
    return ;
  }
}

signed main()
{
  // freopen("array.in","r",stdin);
  // freopen("array.out","w",stdout);
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
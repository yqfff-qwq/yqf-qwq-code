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
#define X(_) (s[_])
#define Y(_) (f[_] + s[_] * s[_] - 2ll * s[_])
#define K(_) (2ll * s[_])
#define B(_) (f[_] - s[_] * s[_] - 2ll * s[_] - 1ll)
/*
f[i]=f[j]+(s[i]-s[j]+1)^2
f[i]=f[j]+(s[i]-s[j])^2+2(s[i]-s[j])+1
f[i]=f[j]+s[i]^2-2s[i]s[j]+s[j]^2+2s[i]-2s[j]+1
-f[i]=-f[j]-s[i]^2+2s[i]s[j]-s[j]^2-2s[i]+2s[j]-1
f[j]+s[j]^2-2s[j]=2s[i]s[j]+f[i]-s[i]^2-2s[i]-1
y=f[j]+s[j]^2-2s[j]
k=2s[i]
x=s[j]
b=f[i]-s[i]^2-2s[i]-1
*/

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
  int n, m;
  int a[N], s[N];
  int f[N], g[N];
  int q[N], he, tl;
  long double cal(int x, int y) {
    return (long double)(Y(y) - Y(x)) / (X(y) - X(x));
  }
  void check(int x) {
    // REP(i, 0, n)  f[i] = 1e18, g[i] = 0;
    memset(f, 0x3f, sizeof(f));
    memset(g, 0, sizeof(g));
    he = 1, tl = 0;
    q[++tl] = 0;
    f[0] = 0;
    REP(i, 1, n) {
      while(he < tl and cal(q[he], q[he + 1]) < K(i)) he++;
      // while(he < tl and (Y(q[he + 1]) - Y(q[he])) < K(i) * (X(q[he + 1]) - X(q[he]))) he++;
      f[i] = f[q[he]] + (s[i] - s[q[he]] + 1) * (s[i] - s[q[he]] + 1) + x;
      g[i] = g[q[he]] + 1;
      // while(he < tl and cal(q[tl - 1], q[tl]) > cal(q[tl], i))  tl--;
      while(he < tl and (Y(q[tl]) - Y(q[tl - 1])) * (X(i) - X(q[tl])) > (Y(i) - Y(q[tl])) * (X(q[tl]) - X(q[tl - 1])))  tl--;
      q[++tl] = i;
    }
    return;
  }
  void main() {
    read(n, m);
    REP(i, 1, n)  read(a[i]), s[i] = s[i - 1] + a[i];
    int l = 0, r = 1e18, ans = 0;
    while(l <= r) {
      int mid = (l + r) >> 1;
      check(mid);
      if (g[n] <= m)  ans = mid, r = mid - 1;
      else            l = mid + 1;
    }
    check(ans);
    // std::cout << f[n] << '\n';
    std::cout << f[n] - m * ans << '\n';
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
f[i]=f[j]+(s[i]-s[j]+1)^2
f[i]=f[j]+(s[i]-s[j])^2+2(s[i]-s[j])+1
f[i]=f[j]+s[i]^2-2s[i]s[j]+s[j]^2+2s[i]-2s[j]+1
-f[i]=-f[j]-s[i]^2+2s[i]s[j]-s[j]^2-2s[i]+2s[j]-1
f[j]+s[j]^2-2s[j]=2s[i]s[j]+f[i]-s[i]^2-2s[i]-1
*/

/*

code by yqfff_qwq

交代码之前看一下

这是你的代码吗？这是你要交的题吗？

多测了吗？多测清空了吗？多测清空会超时吗？会出现其他问题吗？

数组开小了吗？模数正确吗？调试删干净了吗？

*/
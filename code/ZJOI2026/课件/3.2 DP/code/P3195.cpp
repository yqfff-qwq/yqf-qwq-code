#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>

// #define int long long
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
#define X(_) (b[_])
#define Y(_) (f[_] + 1ll * b[_] * b[_])
#define B(_) (f[_] - 1ll * a[_] * a[_])
#define K(_) (2ll * a[_])

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
  const int N = 5e4 + 10;
  int n, L;
  ll c[N], a[N], b[N];
  ll f[N];
  int q[N], he = 1, tl;
  void main() {
    read(n, L);
    REP(i, 1, n)  read(c[i]), c[i] += c[i - 1], a[i] = c[i] + i, b[i] = c[i] + i + L + 1;
    b[0] = L + 1;
    f[0] = 0;
    q[++tl] = 0;
    REP(i, 1, n) {
      while(he < tl and (Y(q[he + 1]) - Y(q[he])) <= 1ll * K(i) * (X(q[he + 1]) - X(q[he]))) he++;
      f[i] = f[q[he]] + (a[i] - b[q[he]]) * (a[i] - b[q[he]]);
      while(he < tl and 1ll * (Y(q[tl]) - Y(q[tl - 1])) * (X(i) - X(q[tl])) >= 1ll * (Y(i) - Y(q[tl])) * (X(q[tl]) - X(q[tl - 1]))) tl--;
      q[++tl] = i;
    }
    std::cout << f[n] << '\n';
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
a[i]=c[i]+i;
b[i]=c[i]+i+L+1;
f[i]=min(f[j]+(c[i]-c[j]+i-j-1-L)^2)
f[i]=min(f[j]+(a[i]-b[j])^2);
f[i]=f[j]+a[i]^2+b[j]^2-2*a[i]*b[j];
f[j]+b[j]^2=2*a[i]*b[j]+f[i]-a[i]^2;
y=f[j]+b[j]^2
k=2*a[i]
x=b[j]
b=f[i]-a[i]^2
y=kx+b
*/

/*

code by yqfff_qwq

交代码之前看一下

这是你的代码吗？这是你要交的题吗？

多测了吗？多测清空了吗？多测清空会超时吗？会出现其他问题吗？

数组开小了吗？模数正确吗？调试删干净了吗？

*/

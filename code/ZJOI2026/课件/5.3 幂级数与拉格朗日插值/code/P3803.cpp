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
  const int N = 4e6 + 10;
  const double Pi = acos(-1);
  struct CP {
    double x, y;
    CP (double xx = 0, double yy = 0) {x = xx, y = yy;}
    CP operator + (CP const &B) const{
      return CP(x + B.x, y + B.y);
    }
    CP operator - (CP const &B) const{
      return CP(x - B.x, y - B.y);
    }
    CP operator * (CP const &B) const{
      return CP(x * B.x - y * B.y, x * B.y + y * B.x);
    }
    CP operator / (CP const &B) const{
      double t = (B.x * B.x + B.y * B.y);
      return CP((x * B.x + y * B.y) / t, (y * B.x - x * B.y) / t);
    }
  }f[N], g[N];
  int tr[N];
  void fft(CP *f, int len, int op) {
    REP(i, 0, len - 1)  if (i < tr[i])  std::swap(f[i], f[tr[i]]);
    for(int l = 2;l <= len;l <<= 1) {
      int ln = l >> 1;
      CP w0(cos(2.0 * Pi / l), sin(2.0 * Pi / l));
      w0.y *= op;
      for(int j = 0;j < len;j += l) {
        CP p(1, 0);
        REP(k, j, j + ln - 1) {
          CP t = p * f[k + ln];
          f[k + ln] = f[k] - t;
          f[k] = f[k] + t;
          p = p * w0;
        }
      }
    }
    return;
  }
  int n, m, h = 1;
  void main() {
    scanf("%d%d", &n, &m);
    REP(i, 0, n)  scanf("%lf", &f[i].x);
    REP(i, 0, m)  scanf("%lf", &g[i].x);
    m += n;
    while(h <= m)  h <<= 1;
    REP(i, 0, h - 1)  tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? h >> 1 : 0);
    fft(f, h, 1), fft(g, h, 1);
    REP(i, 0, h - 1)  f[i] = f[i] * g[i];
    fft(f, h, -1);
    REP(i, 0, m)  printf("%d ", (int)(f[i].x / (h * 1.0) + 0.49));
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
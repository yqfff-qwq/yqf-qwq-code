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
  const int N = 5e4 + 10;
  int n, m;
  struct node{
    ll w, l;
  }b[N], a[N];
  int q[N], he = 1, tl;
  ll f[N];
  void main() {
    read(n);
    REP(i, 1, n)  read(b[i].w, b[i].l);
    std::sort(b + 1, b + n + 1, [](node a, node b){
      return a.w == b.w ? a.l > b.l : a.w > b.w;
    });
    ll mx = 0;
    REP(i, 1, n) {
      if (b[i].l > mx)  a[++m] = b[i];
      mx = std::max(mx, b[i].l);
    }
    q[++tl] = 0;
    REP(i, 1, m) {
      // std::cout << a[i].w << ' ' << a[i].l << '\n';
      // std::cout << X(q[he]) << ' ' << Y(q[he]) << ' ' << X(q[he + 1]) << ' ' << Y(q[he + 1]) << '\n';
      while(he < tl and (Y(q[he + 1]) - Y(q[he])) <= 1ll * K(i) * (X(q[he]) - X(q[he + 1]))) he++;
      f[i] = f[q[he]] + a[i].l * a[q[he] + 1].w;
      while(he < tl and 1ll * (Y(q[tl]) - Y(q[tl - 1])) * (X(i) - X(q[tl])) <= 1ll * (Y(i) - Y(q[tl])) * (X(q[tl]) - X(q[tl - 1]))) tl--;
      q[++tl] = i;
    }
    // REP(i, 1, n)  std::cout << f[i] << " \n"[i == n];
    std::cout << f[m] << '\n';
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
f[i]=f[j]+w[j+1]*l[i]
f[j]=l[i]*w[j+1]+f[i]
k=l[i]
x=w[j+1]
b=f[i]
y=f[j]
*/

/*

code by yqfff_qwq

交代码之前看一下

这是你的代码吗？这是你要交的题吗？

多测了吗？多测清空了吗？多测清空会超时吗？会出现其他问题吗？

数组开小了吗？模数正确吗？调试删干净了吗？

*/
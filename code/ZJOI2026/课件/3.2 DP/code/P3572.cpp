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
  const int N = 1e6 + 10;
  int n, m;
  int a[N], k[N];
  ll f[N];
  int q[N], he = 1, tl;
  void main() {
    read(n);
    REP(i, 1, n)  read(a[i]);
    read(m);
    REP(i, 1, m)  read(k[i]);
    REP(j, 1, m) {
      he = 1, tl = 0;
      q[++tl] = 1;
      REP(i, 2, n) {
        while(he <= tl and i - q[he] > k[j]) he++;
        f[i] = f[q[he]] + (a[i] >= a[q[he]]);
        while(he <= tl and (f[i] < f[q[tl]] or (f[i] == f[q[tl]] and a[i] >= a[q[tl]])))  tl--;
        q[++tl] = i;
      }
      std::cout << f[n] << '\n';
    }
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
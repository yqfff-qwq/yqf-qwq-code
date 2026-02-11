#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>
#include <map>

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
  const int N = 1e5 + 10;
  int n;
  ll a[N];
  ll p[N];
  void insert(ll x) {
    DEP(i, 60, 0) {
      if ((x >> i) & 1) {
        if (!p[i])  {p[i] = x;break;}
        x ^= p[i];
      }
    }
    return;
  }
  void main() {
    read(n);
    REP(i, 1, n) {
      read(a[i]);
      insert(a[i]);
    }
    ll ans = 0;
    DEP(i, 60, 0) {
      if ((ans ^ p[i]) > ans)  ans ^= p[i];
    }
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

这是你的代码吗喵喵？这是你要交的题吗喵喵？

多测了吗喵喵？多测清空了吗喵喵？多测清空会超时吗喵喵？会出现其他问题吗喵喵？

数组开小了吗喵喵？模数正确吗喵喵？调试删干净了吗喵喵？

*/
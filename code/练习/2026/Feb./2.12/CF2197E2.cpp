#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>
#include <set>
#include <map>

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
  const int N = 40;
  int n, m;
  int sz[N];
  int a[N], b[N];
  std::vector<int> ve[N];
  int l1, l2, k;
  void guess() {
    std::cout << "! " << m << '\n';
    REP(u, 1, n) {
      for(auto v:ve[u]) std::cout << u << ' ' << v << '\n';
    }
    fflush(stdout);
    return;
  }
  bool query(int x) {
    if (x == 1) {
      l1 = l2;
      REP(i, 1, l2) a[i] = b[i];
      l2 = b[1] = 1;
    }
    else {
      l1 = l2;
      REP(i, 1, l2) a[i] = b[i];
      std::cout << "? " << x << std::endl;
      read(l2);
      REP(i, 1, l2) read(b[i]);
    }
    return l2 != 0;
  }
  void main() {
    read(n);
    k = 1;
    while(query(k)) {
      ve[b[l2 - 1]].pb(b[l2]);
      if (l2 != 1)  m++;
      if (!sz[b[l2]]) {
        REP(i, 1, l2) sz[b[i]] += 1;
        k += 1;
      }
      else {
        REP(i, 1, l2 - 1) sz[b[i]] += sz[b[l2]];
        k += sz[b[l2]];
      }
    }

    guess();
    REP(i, 0, n) {
      a[i] = b[i] = sz[i] = 0;
      std::vector<int>().swap(ve[i]);
    }
    m = l1 = l2 = k = 0;
    return ;
  }
}

signed main()
{
  // freopen("array.in","r",stdin);
  // freopen("array.out","w",stdout);
  int T=1;
  read(T);
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

这是你的代码吗喵？这是你要交的题吗喵？

多测了吗喵？多测清空了吗喵？多测清空会超时吗喵？会出现其他问题吗喵？

数组开小了吗喵？模数正确吗喵？调试删干净了吗喵？

*/
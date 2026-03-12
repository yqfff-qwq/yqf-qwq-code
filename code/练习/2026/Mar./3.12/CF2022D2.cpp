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
#define MAX(a, b) (a) = std::max((a), (b))
#define MIN(a, b) (a) = std::min((a), (b))
#define pii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define uint unsigned long long
#define int long long
#define X(_) (_)
#define Y(_) (dp[_] + _ * _)
#define B(_) (dp[_] - _ * _)
#define K(_) (2 * _)

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
  int query(int x, int y) {
    int a;
    std::cout << "? " << x << ' ' << y << std::endl;
    read(a);
    return a;
  }
  int solve() {
    if (n == 3) {
      if (query(1, 2) == query(2, 1)) return 3;
      else if (query(1, 3) == query(3, 1))  return 2;
      return 1;
    }
    if (n & 1) {
      int a = query(1, 2), b = query(2, 3);
      int c = a + b + query(3, 1);
      if (c == 2 or c == 0) {
        if (a == query(2, 1)) return 3;
        else if (b == query(3, 2))  return 1;
        return 2;
      }
      for(int i = 4;i + 2 <= n;i += 2) {
        if (query(i, i + 1) == query(i + 1, i)) continue;
        if (query(i, 1) == query(1, i)) return i + 1;
        return i;
      }
      if (query(n - 1, 1) == query(1, n - 1)) return n;
      return n - 1;
    } else {
      for(int i = 1;i < n - 2;i += 2) {
        if (query(i, i + 1) == query(i + 1, i)) continue;
        if (query(i, n) == query(n, i)) return i + 1;
        return i;
      }
      if (query(n - 1, 1) == query(1, n - 1)) return n;
      return n - 1;
    }
  }
	void main() {
		read(n);
    int s = solve();
    std::cout << "! " << s << std::endl;
    return;
  }
}

signed main()
{
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
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

这是你的代码吗？这是你要交的题吗？

多测了吗？多测清空了吗？多测清空会超时吗？会出现其他问题吗？

数组开小了吗？模数正确吗？调试删干净了吗？

*/

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
#define MAX(a, b) (a) = max((a), (b))
#define MIN(a, b) (a) = min((a), (b))
#define pii std::pair<int, int>
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
  const int N = 2e5 + 10;
  int n, m;
  int x[N], y[N];
  bool cmp(int a, int b){return a > b;}
  void main() {
    read(n, m);
    int s1 = 0, s2 = 0;
    REP(i, 1, n - 1)  read(x[i]), s1 += x[i];
    REP(i, 1, m - 1)  read(y[i]), s2 += y[i];
    std::sort(x + 1, x + n, cmp);
    std::sort(y + 1, y + m, cmp);
    int l = 1, r = 1;
    int sum = s1 + s2;
    while(l <= n - 1 and r <= m - 1) {
      if (x[l] >= y[r]) {
        s1 -= x[l];
        l++;
        sum += s2;
      }
      else {
        s2 -= y[r];
        r++;
        sum += s1;
      }
    }
    std::cout << sum << '\n';
    return ;
  }
}

signed main()
{
  freopen("guiltiness.in","r",stdin);
  freopen("guiltiness.out","w",stdout);
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
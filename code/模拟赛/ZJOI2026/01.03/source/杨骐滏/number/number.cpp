#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

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
  const int N = 1e6 + 10;
  bool vis[N];
  int p[N], len;
  void init() {
    REP(i, 2, N - 10) {
      if (!vis[i])  p[++len] = i;
      for(int j = 1;j <= len and p[j] * i <= N - 10;j++) {
        vis[i * p[j]] = 1;
        if (i % p[j] == 0)  break;
      }
    }
    return;
  }
  int pw(int x) {return x * x * x * x * x;}
  int n;
  void main() {
    read(n);
    for(int i = 1;i <= len and pw(p[i]) <= n;i++) {
      if (n % p[i] == 0) {
        n /= p[i];
        if (n % p[i]) return puts("no"), void();
        while(n % p[i] == 0) n /= p[i];
      }
    }
    if (n > 1) {
      bool fl = 0;
      int t = std::sqrt(n);
      if (t * t == n) fl = 1;
      t = pow(n, 0.33333333);
      if (t * t * t == n) fl = 1;
      t++;
      if (t * t * t == n) fl = 1;
      if (!fl)  return puts("no"), void();
    }
    puts("yes");
    return ;
  }
}

signed main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  YZLK::init();
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
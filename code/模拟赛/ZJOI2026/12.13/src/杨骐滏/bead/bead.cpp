#include <iostream>

#define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
#define MAX(a, b) (a) = max((a), (b))
#define MIN(a, b) (a) = min((a), (b))
#define pii pair<int, int>
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
  const int N = 1e5 + 10;
  const int mod = 998244353;
  int n, m;
  int a[N];
  int f[N], pw[N];
  int cnt[N];
  void main() {
    read(n, m);
    pw[0] = 1;
    REP(i, 1, n) {
      pw[i] = pw[i - 1] * 2 % mod;
    }
    REP(i, 1, n) {
      int x;
      read(x);
      a[x]++;
    }
    REP(i, 1, m) {
      int t = 0;
      for(int j = i;j <= m;j += i)  t += a[j];
      f[i] = pw[t] - 1;
    }
    int ans = 0;
    DEP(i, m, 1) {
      for(int j = i + i;j <= m;j += i)  f[i] = (f[i] - f[j] + mod) % mod;
      ans = (ans + f[i] * i % mod) % mod;
    }

    std::cout << ans % mod << "\n";
    return ;
  }
}

signed main()
{
  freopen("bead.in","r",stdin);
  freopen("bead.out","w",stdout);

  int T=1;
  // read(T);
  while(T--)
  {
      YZLK::main();
  }

  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

/*

code by yqfff_qwq

交代码之前看一下

这是你的代码吗？这是你要交的题吗？

多测了吗？多测清空了吗？多测清空会超时吗？会出现其他问题吗？

数组开小了吗？模数正确吗？调试删干净了吗？

*/
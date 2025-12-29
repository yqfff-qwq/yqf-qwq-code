#include <iostream>
#include <algorithm>
#include <cstring>
// using namespace std;

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
  const int mod = 998244353;
  const int N = 1e6 + 10;
  int ksm(int a, int b) {
    int s = 1;
    while(b) {
      if (b & 1)  s = s * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return s;
  }
  int inv;
  int n;
  int f[N], g[N];
  void main() {
    read(n);
    inv = ksm(n, mod - 2);
	  DEP(i, n - 1, 1) {
      int p = i * inv % mod;
      f[i] = ((g[i + 1] * (1 - p + mod) % mod + f[i + 1] * p % mod * (1 - p + mod) + p * p % mod + mod) % mod * ksm(1 - p * p % mod + mod, mod - 2) % mod + mod) % mod;
      g[i] = ((f[i + 1] * (1 - p + mod) % mod + (f[i] + 1) * p) % mod + mod) % mod;
    }  
	  std::cout << f[1] << " " << g[1] << "\n";
    return ;
  }
}

signed main()
{
  // freopen("c.in","r",stdin);
  // freopen("c.out","w",stdout);
  // std::cin.tie(nullptr) -> sync_with_stdio(false);
  int T=1;
//   read(T);
  while(T--) {
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
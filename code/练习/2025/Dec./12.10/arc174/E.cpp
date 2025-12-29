#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
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
  const int N = 3e5 + 10;
  const int mod = 998244353;
  int n, k;
  int fac[N], inv[N];
  int a[N];
  struct tree{
    int tr[N];
    int lowbit(int x) {return x & -x;}
    void add(int x, int k) {
      while(x <= n) {
        tr[x] += k;
        tr[x] = (tr[x] + mod) % mod;
        x += lowbit(x);
      }
      return;
    }
    int query(int x) {
      int ans = 0;
      while(x) {
        ans += tr[x];
        ans = ans % mod;
        x -= lowbit(x);
      }
      return ans;
    }
  }tr, sum;
  int t[N];
  int vis[N];
  int ksm(int a, int b) {
    int s = 1;
    while(b) {
      if (b & 1)  s = s * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return s;
  }
  void init() {
    fac[0] = inv[0] = 1;
    REP(i, 1, N - 10)   fac[i] = fac[i - 1] * i % mod;
    inv[N - 10] = ksm(fac[N - 10], mod - 2);
    DEP(i, N - 11, 1)   inv[i] = inv[i + 1] * (i + 1) % mod;
    return;
  }
  int A(int x, int y) {
    return fac[x] * inv[x - y] % mod;
  }
  void main() {
    init();
    read(n, k);
    REP(i, 1, k)  read(a[i]);
    REP(i, 1, k) {
      tr.add(a[i], 1);
      t[i] = tr.query(n) - tr.query(a[i]);
    }

    int ans = (A(n, k) - A(n - 1, k) + mod) % mod;
    int ss = 0;
    REP(i, 1, k) {
      ss = (ss + (n - a[i] - t[i] + mod) * A(n - i, k - i) % mod + mod) % mod;
    }
    ans -= ss;
    ss = 0;
    // std::cout << ans << " " << ss << "\n";
    // ans = (ans - ss + mod) % mod;
    REP(i, 1, k) {
      sum.add(i, (n - a[i] - t[i]) * A(n - i - 1, k - i) % mod);
      ss = (ss + (n - a[i] - t[i]) * A(n - i - 1, k - i) % mod) % mod;
    }

    REP(i, 1, k)  vis[a[i]] = i;
    std::sort(a + 1, a + k + 1);

    int idx = 1;
    REP(i, 1, n) {
      int x = 0;
      while(idx <= k and i > a[idx]) {
        ss = (ss - A(n - vis[a[idx]] - 1, k - vis[a[idx]]) + mod) % mod;
        sum.add(vis[a[idx]], -A(n - vis[a[idx]] - 1, k - vis[a[idx]]));
        idx++;
      }
      if (vis[i]) {
        x = sum.query(k) - sum.query(vis[i]);
        ss = (ss - x + mod) % mod;
      }
      std::cout << (ans + ss + mod) % mod << "\n";
      ss = (ss + x + mod) % mod;
    }
    return ;
  }
}

signed main()
{
  // freopen("c.in","r",stdin);
  // freopen("c.out","w",stdout);
  // std::cin.tie(nullptr) -> sync_with_stdio(false);
  int T=1;
  // read(T);
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
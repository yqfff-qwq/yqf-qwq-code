#include<bits/stdc++.h>
// #include <iostream>
using namespace std;

#define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

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
int id;
namespace YZLK{
  const int mod = 998244353;
  const int N = 1e5 + 10;
	int inv[N], fac[N];
  int pw[N];
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
    inv[0] = fac[0] = pw[0] = 1;
    REP(i, 1, N - 10) fac[i] = fac[i - 1] * i % mod, pw[i] = pw[i - 1] * 2 % mod;
    inv[N - 10] = ksm(fac[N - 10], mod - 2);
    DEP(i, N - 11, 1) inv[i] = inv[i + 1] * (i + 1) % mod;
    return;
  }
  int C(int x, int y) {
    // cout << x << " " << y << '\n';
    if (x < y)  return 0;
    return fac[x] * inv[y] % mod * inv[x - y] % mod;
  }
  int n, m;
  int a[N];
  void main() {
    read(n, m);
    REP(i, 1, n)  read(a[i]);
    sort(a + 1, a + n + 1);
    int ans = pw[n];
    // int sum = 0;
    REP(i, 1, n) {
      int p = 0;
      REP(j, i + 1, n) {
        if (a[i] == a[j] or (m - 2 - (n - j)) < 0)  continue;
        if (a[j] >= a[i] * 2) break;
        while(p < n and a[p + 1] + a[i] < a[j]) p++;
        ans = (ans - C(n - i - 1, m - 2 - (n - j)) * pw[p] % mod + mod) % mod;
        // sum = (sum + C(n - i - 1, m - 2 - (n - j)) * pw[p] % mod) % mod;
      }
    }

    // cout << (pw[n] - sum + mod) % mod << "\n";
    cout << ans << "\n";
    return;
  }
}

signed main()
{
  // freopen("sale.in","r",stdin);
  // freopen("sale.out","w",stdout);
  YZLK::init();
  int T=1;
  read(id, T);
  while(T--) {
    YZLK::main();
  }

//    fclose(stdin);
//    fclose(stdout);
    return 0;
}
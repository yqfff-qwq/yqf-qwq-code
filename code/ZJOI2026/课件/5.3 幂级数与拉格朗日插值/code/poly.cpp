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
  const ll mod = 998244353;
  const ll g1 = 3, g2 = 332748118;
  const ll N = 4e6 + 10;
  int fac[N], inv[N];
  
  void add(ll &x, ll y) {x += y;if (x >= mod) x -= mod;}
  ll ksm(ll a, ll b = mod - 2) {ll s = 1;while(b) {if (b & 1)  s = s * a % mod;a = a * a % mod;b >>= 1;}return s;}
  ll C(int x, int y) {if (x < 0 or y < 0 or x < y)return 0;return fac[x] * inv[y] % mod * inv[x - y] % mod;}
  void init(ll x) {
    fac[0] = inv[0] = 1;
    REP(i, 1, x)  fac[i] = fac[i - 1] * i % mod;
    inv[x] = ksm(fac[x]);
    DEP(i, x - 1, 1)  inv[i] = inv[i + 1] * (i + 1) % mod;
  }
  void ntt(int *f, int len, int op) {

    return;
  }
  void main() {
    
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
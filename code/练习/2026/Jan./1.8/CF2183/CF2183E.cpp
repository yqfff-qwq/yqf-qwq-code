#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
 
// #define int long long
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
  const int N = 3e3 + 10;
  const int mod = 998244353;
  int n, m;
  int a[N];
  std::vector<int> g[N];
  int dp[N][N];
  void init() {
    REP(i, 1, N - 10) {
      for(int j = i;j <= N - 10;j += i) g[j].pb(i);
    }
    return;
  }
  void add(int &x, int y) {
    x += y;
    if (x >= mod) x -= mod;
    return;
  }
  void main() {
    read(n, m);
    REP(i, 1, n)  read(a[i]);
    if (a[1] > 1) return puts("0"), void();
    dp[1][1] = 1;
    REP(i, 2, n) {
      REP(j, 1, m) {
        dp[i][j] = 0;
        for(auto k:g[j]) {
          add(dp[i][j], dp[i - 1][j - k]);
        }
      }
      if (a[i]) REP(j, 1, m)  if (a[i] != j)  dp[i][j] = 0;
    }
    int ans = 0;
    REP(i, 1, m)  add(ans, dp[n][i]);
    std::cout << ans << '\n';
    return ;
  }
}
 
signed main()
{
  // freopen("array.in","r",stdin);
  // freopen("array.out","w",stdout);
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
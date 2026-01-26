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
  const int mod = 1e9 + 7;
  const int N = 5e3 + 10;
  int n, m;
  int L[N], R[N];
  int p1[N], p2[N], p3[N], p4[N];
  int s[N];
  struct node{
    int l, r, c;
  }a[N];
  int f[N][N];
  int sum[N];
  void del(int &a, int b) {
    a -= b;
    if (a < 0)  a += mod;
    return;
  }
  void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return;
  }
  void upd(int i, int l, int r) {
    l = std::min(l, R[i] + 1);
    while(L[i] < l) {
      int v = f[i][L[i]];
      del(s[i], v);
      del(s[L[i]], v);
      f[i][L[i]++] = 0;
    }
    r = std::max(r, L[i]);
    while(R[i] >= r) {
      int v = f[i][R[i]];
      del(s[i], v);
      del(s[R[i]], v);
      f[i][R[i]--] = 0;
    }
  }
  void main() {
    read(n, m);
    REP(i, 0, n)  s[i] = p2[i] = p4[i] = L[i] = 0, p1[i] = p3[i] = R[i] = i;
    REP(i, 1, m) {
      int l, r, x;
      read(l, r, x);
      if (x == 1) p1[r] = std::min(p1[r], l);
      if (x == 2) p2[r] = std::max(p2[r], l), p3[r] = std::min(p3[r], l);
      if (x == 3) p4[r] = std::max(p4[r], l);
    }
    REP(i, 0, n)  REP(j, 0, n)  f[i][j] = 0;
    f[0][0] = 3, s[0] = 6;
    REP(i, 1, n) {
      REP(j, 0, i - 2)  f[i - 1][j] = s[j], add(s[i - 1], s[j]), add(s[j], s[j]);
      REP(j, 0, p2[i] - 1)  upd(j, 0, 0);
      REP(j, p2[i], p1[i] - 1)  upd(j, p4[i], p3[i]);
      REP(j, p1[i], i - 1)  upd(j, 0, 0);
    }
    int ans = 0;
    REP(i, 0, n)  REP(j, 0, n)  ans = (ans + f[i][j]) % mod;
    std::cout << ans << '\n';
    return ;
  }
}

signed main()
{
  freopen("color.in","r",stdin);
  freopen("color.out","w",stdout);
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

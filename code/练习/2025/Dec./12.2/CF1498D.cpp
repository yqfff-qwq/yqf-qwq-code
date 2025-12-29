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
namespace YZLK{
  const int N = 1e5 + 10;
  const int inf = 1e18;
  int n, m;
  int f[N], g[N];
  void main() {
    read(n, m);
    REP(i, 1, m)  f[i] = inf;
    REP(j, 1, n) {
      int t, x, y;
      read(t, x, y);
      double xx = x * 1.0 / 100000.0;
      REP(i, 1, m)  g[i] = (f[i] == inf ? f[i] : 0);
      if (t == 1) {
        REP(i, 0, m) {
          int k = ceil(i + xx);
          if (k <= m and g[i] != inf) g[k] = min(g[k], g[i] + 1);
        }
      }
      else {
        REP(i, 1, m) {
          int k = ceil(i * x * 1.0 / 100000.0);
          if (k <= m and g[i] != inf) g[k] = min(g[k], g[i] + 1);
        }
      }
      REP(i, 1, m)  if (f[i] == inf and g[i] <= y) f[i] = j;
    }
    REP(i, 1, m)  cout << (f[i] == inf ? -1 : f[i]) << " ";
    return;
  }
}

signed main()
{
  // freopen("query.in","r",stdin);
  // freopen("query.out","w",stdout);
  int T=1;
//   read(T);
  while(T--) {
    YZLK::main();
  }

//    fclose(stdin);
//    fclose(stdout);
    return 0;
}
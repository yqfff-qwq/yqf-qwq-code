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
  int a[N];
  int b[N], p[N];
  int ln;
  struct tree{
    #define ls (u << 1)
    #define rs ((ls) | 1)
    #define mid ((l + r) >> 1)
    int sz[N << 2], tr[N << 2], d[N << 2];
    
    void up(int u) {
      sz[u] = sz[ls] + sz[rs];
      tr[u] = tr[ls] + tr[rs];
      return;
    }
    void update(int u, int l, int r, int x, int c, int k) {
      // cout << u << " " << l << ' ' << r << " " << x << "\n";
      if (l == r) return sz[u] += c, tr[u] += k, d[u] = k, void();
      if (x <= mid) update(ls, l, mid, x, c, k);
      else          update(rs, mid + 1, r, x, c, k);
      up(u);
      return;
    }
    int query(int u, int l, int r, int k) {
      // cout << u << " " << l << " " << r << " " << k << " " << tr[u] << " " << tr[ls] << " " << sz[u] << " " << sz[ls] << "\n";
      if (l == r)       return min(k, sz[u]) * d[u];
      if (sz[ls] > k)   return query(ls, l, mid, k);
      else              return tr[ls] + query(rs, mid + 1, r, k - sz[ls]);
    }
  }tr1, tr2;
  int n, len, k;
  void main() {
    read(n, len);
    REP(i, 1, n)  read(a[i]), b[i] = p[i] = a[i];
    read(k);
    sort(p + 1, p + n + 1);
    ln = unique(p + 1, p + n + 1) - p - 1;
    REP(i, 1, n)  b[i] = lower_bound(p + 1, p + ln + 1, b[i]) - p;
    int ans = 0, sum = 0;
    REP(i, 1, n) {
      if (a[i] < 0)       tr1.update(1, 1, ln, b[i], 1, abs(a[i]));
      else if (a[i] > 0)  tr2.update(1, 1, ln, ln - b[i] + 1, 1, a[i]);
      sum += a[i];
      if (i > len) {
        sum -= a[i - len];
        if (a[i - len] < 0)       tr1.update(1, 1, ln, b[i - len], -1, a[i - len]);
        else if (a[i - len] > 0)  tr2.update(1, 1, ln, ln - b[i - len] + 1, -1, -a[i - len]);
      }
      if (i < len)  continue;
      // cout << tr1.query(1, 1, ln, k) << " " << tr2.query(1, 1, ln, k) << "\n";
      ans = max(ans, sum + 2 * tr1.query(1, 1, ln, k));
      ans = max(ans, abs(sum - 2 * tr2.query(1, 1, ln, k)));
    }
    cout << ans << "\n";
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
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
  const int N = 1e6 + 10;
  const int inf = 1e7;
  int n, m, k;
  struct node{
    int u, v, w, c;
  }a[N], b[N];
  struct dsu{
    int fa[N];
    void init(int x) {
      REP(i, 0, x + 1)  fa[i] = i;
      return;
    }
    int find(int x) {
      return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    bool merge(int u, int v) {
      int x = find(u), y = find(v);
      if (x == y) return 0;
      fa[x] = y;
      return 1;
    }
  }d;
  int cnt, sum;
  void check(int x) {
    cnt = sum = 0;
    REP(i, 1, m) {
      b[i] = a[i];
      if (a[i].c == 0)  b[i].w = a[i].w + x;
      else              b[i].w = a[i].w;
    }
    std::sort(b + 1, b + m + 1,[](node a, node b){
      return a.w == b.w ? a.c < b.c : a.w < b.w;
    });
    d.init(n);
    int tot = 0;
    REP(i, 1, m) {
      if (tot == n - 1) break;
      if (d.merge(b[i].u, b[i].v)) {
        tot++;
        sum += b[i].w;
        if (!b[i].c)  cnt++;
      } 
    }
    return;
  }
  void main() {
    int ans = 0;
    read(n, m, k);
    REP(i, 1, m)  read(a[i].u, a[i].v, a[i].w, a[i].c), a[i].u++, a[i].v++;
    int l = -110, r = 110;
    while(l <= r) {
      int mid = (l + r) >> 1;
      check(mid);
      if (cnt >= k) {
        l = mid + 1;
        ans = sum - k * mid;
      }
      else  r = mid - 1;
    }
    std::cout << ans << "\n";
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
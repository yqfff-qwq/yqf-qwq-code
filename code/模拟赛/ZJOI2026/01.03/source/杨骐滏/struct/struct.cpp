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
  const int N = 1e6 + 10;
  int n, m;
  int a[N];
  struct tree{
    int tr[N];
    int lowbit(int x) {return x & -x;}
    void add(int x, int k) {
      while(x <= n) {
        tr[x] += k;
        x += lowbit(x);
      }
      return;
    }
    int query(int x) {
      int sum = 0;
      while(x) {
        sum += tr[x];
        x -= lowbit(x);
      }
      return sum;
    }
    void upd(int l, int r, int k) {
      add(l, k);
      add(r + 1, -k);
    }
  }tr;
  int len;
  struct node{
    int p, l, r, v;
  }d[N];
  int nxt[N], he[N];
  void main() {
    read(n, m);
    REP(i, 1, n)  read(a[i]);
    REP(i, 0, n + 2)  he[i] = n + 1;
    DEP(i, n, 1) {
      nxt[i] = he[a[i]];
      he[a[i]] = i;
    }
    REP(i, 1, n + 1) {
      auto md = [&](int l1, int r1, int l2, int r2) -> void {
        int mnl = l1 + 1, mxl = std::min(r1 - 1, l2);
        int mnr = std::max(i + 1, r2), mxr = r1 - 1;
        
      };
      if (he[i] <= n) {
        
      }
      else {
        for(int ls = 0, nw = he[i - 1];nw;i = nw, nw = nxt[nw]) {
          md(ls, nw, n + 1, 0);
        }
      }
    }

    std::sort(d + 1, d + len + 1, [](node a, node b){
      return a.p < b.p;
    });
    for(int i = 1,j = 1;i <= m;i++) {
      int l, r;
      read(l, r);
      for(;j <= len and d[j].p <= r;j++)  tr.upd(d[j].l, d[j].r, d[j].v);
      std::cout << n + 1 - tr.query(l) << '\n';
    }
    return ;
  }
}

signed main()
{
  freopen("struct.in","r",stdin);
  freopen("struct.out","w",stdout);
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

/*

code by yqfff_qwq

交代码之前看一下

这是你的代码吗？这是你要交的题吗？

多测了吗？多测清空了吗？多测清空会超时吗？会出现其他问题吗？

数组开小了吗？模数正确吗？调试删干净了吗？

*/

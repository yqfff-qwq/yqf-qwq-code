#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
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
  const int N = 2e5 + 10;
  int n, k, m;
  int ans[N], cnt[N];
  struct node{
    int a, b, c, id, cnt;
  }a[N], b[N];
  bool cmp1(node a, node b) {
    if (a.a == b.a) {
      if (a.b == b.b) return a.c < b.c;
      return a.b < b.b;
    }
    return a.a < b.a;
  }
  bool cmp2(node a, node b) {
    return a.b < b.b; 
  }
  struct tree{
    int tr[N];
    int lowbit(int x) {return x & -x;}
    void add(int x, int v) {
      while(x <= N - 10) {
        tr[x] += v;
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
  }tr;
  void cdq(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    std::sort(b + l, b + mid + 1, cmp2);
    std::sort(b + mid + 1, b + r + 1, cmp2);
    int i = l, j = mid + 1;
    for(;j <= r;j++) {
      while(i <= mid and b[i].b <= b[j].b)  tr.add(b[i].c, b[i].cnt), i++;
      cnt[b[j].id] += tr.query(b[j].c);
    }
    REP(p, l, i - 1)  tr.add(b[p].c, -b[p].cnt);
    return;
  }
  void main() {
    read(n, k);
    REP(i, 1, n)  read(a[i].a, a[i].b, a[i].c), a[i].id = i;
    std::sort(a + 1, a + n + 1, cmp1);
    REP(i, 1, n) {
      if (a[i].a == a[i - 1].a and a[i].b == a[i - 1].b and a[i].c == a[i - 1].c) {
        b[m].cnt++;
        continue;
      }
      b[++m] = a[i];
      b[m].cnt = 1;
    }
    // std::cout << m << '\n';
    // REP(i, 1, m)  std::cout << b[i].a << ' ' << b[i].b << ' ' << b[i].c << ' ' << b[i].cnt << '\n';
    cdq(1, m);
    // REP(i, 1, n)  std::cout << cnt[i] << '\n';
    REP(i, 1, m)  ans[cnt[b[i].id] + b[i].cnt - 1] += b[i].cnt;
    REP(i, 0, n - 1)  std::cout << ans[i] << '\n';
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

/*

code by yqfff_qwq

交代码之前看一下

这是你的代码吗？这是你要交的题吗？

多测了吗？多测清空了吗？多测清空会超时吗？会出现其他问题吗？

数组开小了吗？模数正确吗？调试删干净了吗？

*/
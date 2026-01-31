#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>

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
  const int N = 2e7 + 10;
  const int M = 1e6 + 10;
  int n;
  int a[M];
  int cnt = 0;
  struct trie{
    int ch[N][2], tot = 1;
    int sz[N];
    int rt = 1;
    void insert(int x) {
      int u = rt;
      DEP(i, 30, 0) {
        int k = (x >> i) & 1;
        if (!ch[u][k])  ch[u][k] = ++tot;
        u = ch[u][k];
        sz[u]++;
      }
      return;
    }
    void clear() {
      REP(i, 0, tot)  ch[i][0] = ch[i][1] = sz[i] = 0;
      tot = 1;
      return;
    }
    bool check(int x, int y) {
      int u = rt;
      DEP(i, 30, 0) {
        int c = (x >> i) & 1, d = (y >> i) & 1;
        if (c == d) {u = ch[u][c];continue;}
        if (sz[ch[u][c]] > 1 or sz[ch[u][d]] > 1) return 0;
        return 1;
      }
      return 1;
    }

  }tr;
  void main() {
    read(n);
    tr.clear();
    int cnt = 0;
    REP(i, 1, n)  read(a[i]), tr.insert(a[i]);
    std::sort(a + 1, a + n + 1);
    cnt = 0;
    REP(i, 1, n - 1)  cnt += tr.check(a[i], a[i + 1]);
    std::cout << cnt << '\n';
    return;
  }
}

signed main()
{
  freopen("starlight.in","r",stdin);
  freopen("starlight.out","w",stdout);
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


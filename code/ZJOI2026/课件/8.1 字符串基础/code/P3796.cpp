#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>

#define int long long
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
#define X(_) (_)
#define Y(_) (dp[_] + _ * _)
#define B(_) (dp[_] - _ * _)
#define K(_) (2 * _)

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
  struct node{
    int son[26], cnt, fail;
    void clear() {
      memset(son, 0, sizeof(son));
      fail = cnt = 0;
      return;
    }
  }tr[N];
  int tot = 1;
  int vis[N];
  void insert(char *c, int d) {
    int u = 1, len = strlen(c + 1);
    REP(i, 1, len) {
      int k = c[i] - 'a';
      if (!tr[u].son[k])  tr[u].son[k] = ++tot;
      u = tr[u].son[k];
    }
    tr[u].cnt = d;
    return;
  }
  std::queue<int> q;
  void getfail() {
    REP(i, 0, 25) tr[0].son[i] = 1;
    q.push(1);
    tr[1].fail = 0;
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      REP(i, 0, 25) {
        int v = tr[u].son[i];
        int fl = tr[u].fail;
        if (!v) {tr[u].son[i] = tr[fl].son[i];continue;}
        tr[v].fail = tr[fl].son[i];
        q.push(v);
      }
    }
    return;
  }
  void query(char *c) {
    int u = 1, len = strlen(c + 1);
    REP(i, 1, len) {
      int v = c[i] - 'a';
      int k = tr[u].son[v];
      while(k > 1) {
        vis[tr[k].cnt]++;
        k = tr[k].fail;
      }
      u = tr[u].son[v];
    }
    return;
  }
  char c[N];
  char s[160][N];
  int n;
  void clear() {
    REP(i, 0, tot)  tr[i].clear();
    REP(i, 0, n)  vis[i] = 0;
    tot = 1;
  }
  void main() {
    clear();
    REP(i, 1, n) {
      scanf("%s", s[i] + 1);
      insert(s[i], i);
    }
    getfail();
    scanf("%s", c + 1);
    query(c);
    int mx = 0, ans = 0;
    REP(i, 1, n) {
      if (vis[i] > mx)  ans = vis[i], mx = vis[i];
    }
    std::cout << ans << '\n';
    REP(i, 1, n) {
      if (vis[i] == ans)  printf("%s\n", s[i] + 1);
    }
    return ;
  }
}

signed main()
{
  // freopen("array.in","r",stdin);
  // freopen("array.out","w",stdout);
  int T=1;
  // read(T);
  while(std::cin >> YZLK::n and YZLK::n)
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

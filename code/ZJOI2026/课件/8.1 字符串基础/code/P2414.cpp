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
  const int N = 1e5 + 10;
  struct node{
    int son[26], d, fail, fa, ans;
    int sn[26];
  }tr[N];
  struct Node{
    int x, y, id, ans;
  }qy[N];
  int ql[N], qr[N];
  std::vector<int> ve[N];
  int idx, nd[N];
  int ans[N];
  int tot = 1;
  int dfn[N], low[N], tim;
  struct tree{
    int tr[N];
    int lowbit(int x) {return x & -x;}
    void add(int x, int k) {
      while(x <= tim) tr[x] += k, x += lowbit(x);
      return;
    }
    int query(int x) {
      int sum = 0;
      while(x)  sum += tr[x], x -= lowbit(x);
      return sum;
    }
  }b;
  int vis[N];
  int mp[N], in[N];
  std::queue<int> q;
  void getfail() {
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
        in[tr[v].fail]++;
        q.push(v);
      }
    }
    return;
  }
  void dfs(int u) {
    dfn[u] = ++tim;
    for(auto v:ve[u]) dfs(v);
    low[u] = tim;
    return;
  }
  void DFS(int u) {
    b.add(dfn[u], 1);
    if (tr[u].d) {
      REP(i, ql[tr[u].d], qr[tr[u].d]) {
        qy[i].ans = b.query(low[nd[qy[i].x]]) - b.query(dfn[nd[qy[i].x]] - 1);
      }
    }
    REP(i, 0, 25) {
      if (tr[u].sn[i])  DFS(tr[u].sn[i]);
    }
    b.add(dfn[u], -1);
    return;
  }
  char c[N], cc[N];
  int n;
  void main() {
    scanf("%s", cc + 1);
    int len = strlen(cc + 1);
    int u = 1;
    REP(i, 1, len) {
      if ('a' <= cc[i] and cc[i] <= 'z') {
        if (!tr[u].son[cc[i] - 'a'])  tr[u].son[cc[i] - 'a'] = ++tot, tr[tot].fa = u;
        u = tr[u].son[cc[i] - 'a'];
      }
      if (cc[i] == 'B') u = tr[u].fa;
      if (cc[i] == 'P') nd[++idx] = u, tr[u].d = idx;
    }
    REP(i, 0, 25) tr[0].son[i] = 1;
    REP(i, 0, tot) {
      REP(j, 0, 25) tr[i].sn[j] = tr[i].son[j];
    }
    getfail();
    REP(i, 1, tot)  ve[tr[i].fail].pb(i);
    dfs(0);
    read(n);
    REP(i, 1, n) {
      read(qy[i].x, qy[i].y);
      qy[i].id = i;
    }
    std::sort(qy + 1, qy + n + 1, [](Node a, Node b) {
      return a.y < b.y;
    });
    int now = 1;
    for(int i = 1;i <= n;i = now) {
      ql[qy[i].y] = i;
      while(qy[now].y == qy[i].y) now++;
      qr[qy[i].y] = now - 1;
    }
    DFS(0);
    REP(i, 1, n)  ans[qy[i].id] = qy[i].ans;
    REP(i, 1, n)  std::cout << ans[i] << '\n';
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

这是你的代码吗喵喵？这是你要交的题吗喵喵？

多测了吗喵喵？多测清空了吗喵喵？多测清空会超时吗喵喵？会出现其他问题吗喵喵？

数组开小了吗喵喵？模数正确吗喵喵？调试删干净了吗喵喵？

*/
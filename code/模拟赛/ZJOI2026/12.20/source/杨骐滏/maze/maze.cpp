#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
#define MAX(a, b) (a) = max((a), (b))
#define MIN(a, b) (a) = min((a), (b))
#define fi first
#define se second
#define pb push_back
#define ll long long
#define pii std::pair<int, int>

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
  const int N = 2e3 + 10;
  char c[N][N];
  int n, m, k, t;
  int sx, sy, tx, ty;
  int dx[10] = {1, 0, -1, 0}, dy[10] = {0, 1, 0, -1};
  int d[N][N];
  bool vis[N][N];
  std::queue<pii> q1, q2;
  void solve(int x, int y) {
    // std::cout << x << ' ' << y << '\n';
    vis[x][y] = 1;
    REP(k, 0, 3) {
      int xx = x + dx[k];
      int yy = y + dy[k];
      if (xx < 1 or xx > n or yy < 1 or yy > m or c[xx][yy] == '#') continue;
      if (d[x][y] + 1 < d[xx][yy]) {
        d[xx][yy] = d[x][y] + 1;
        q2.push({xx, yy});
      }
    }
    REP(xx, x - k, x + k) {
      int p = k - abs(x - xx);
      if (xx < 1 or xx > n)   continue;
      REP(yy, y - p, y + p) {
        if (yy < 1 or yy > m) continue;
        if (c[xx][yy] == '#') continue;
        if (d[x][y] + t < d[xx][yy]) {
          d[xx][yy] = d[x][y] + t;
          q1.push({xx, yy});
        }
      }
    }
    return;
  }
  void main() {
    memset(d, 0x3f, sizeof(d));
    read(n, m, k, t);
    REP(i, 1, n) {
      scanf("%s", c[i] + 1);
    }
    REP(i, 1, n)
      REP(j, 1, m) {
        if (c[i][j] == 'S') sx = i, sy = j;
        if (c[i][j] == 'T') tx = i, ty = j;
      }
    d[sx][sy] = 0;
    q1.push({sx, sy});
    while(!q1.empty() or !q2.empty()) {
      // std::cout << 111 << '\n';
      // std::cout << q1.size() << ' ' << q2.size() << '\n';
      while(!q1.empty() and vis[q1.front().fi][q1.front().se]) q1.pop();
      while(!q2.empty() and vis[q2.front().fi][q2.front().se]) q2.pop();
      if (q1.empty()) {
        if (q2.empty()) break;
        auto t = q2.front();
        q2.pop();
        solve(t.fi, t.se);
        vis[t.fi][t.se] = 1;
      }
      else {
        // std::cout << 333 << '\n';
        if (q2.empty()) {
          auto t = q1.front();
          q1.pop();
          solve(t.fi, t.se);
          vis[t.fi][t.se] = 1;
        }
        else {
          auto t1 = q1.front();
          auto t2 = q2.front();
          // std::cout << t1.fi << ' ' << t1.se << ' ' << t2.fi << ' ' << t2.se << '\n';
          if (d[t1.fi][t1.se] <= d[t2.fi][t2.se]) {
            q1.pop();
            vis[t1.fi][t1.se] = 0;
            solve(t1.fi, t1.se);
          }
          else {
            q2.pop();
            vis[t2.fi][t2.se] = 0;
            solve(t2.fi, t2.se);
          }
        }
      }
    }


    std::cout << (d[tx][ty] == d[0][0] ? -1 : d[tx][ty]) << '\n';
    return ;
  }
}

signed main()
{
  freopen("maze.in","r",stdin);
  freopen("maze.out","w",stdout);

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
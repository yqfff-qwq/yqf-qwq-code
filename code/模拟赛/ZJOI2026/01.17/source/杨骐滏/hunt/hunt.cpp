#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>

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
  const int N = 5e5 + 10;
  int n;
  struct node{
    int x, y, z;
  }a[N];
  int vis[N];
  struct cmpx{
    int d;
    bool operator <(const cmpx &e)const{
      return a[e.d].x < a[d].x;
    }
  };
  std::priority_queue<cmpx> qx;
  struct cmpy{
    int d;
    bool operator <(const cmpy &e)const{
      return a[e.d].y < a[d].y;
    }
  };
  std::priority_queue<cmpy> qy;
  struct cmpz{
    int d;
    bool operator <(const cmpz &e)const{
      return a[e.d].z < a[d].z;
    }
  };
  std::priority_queue<cmpz> qz;
  int dis(int d, int x, int y, int z) {
    return std::max(abs(a[d].x - x), std::max(abs(a[d].y - y), abs(a[d].z - z)));
  }
  void main() {
    read(n);
    REP(i, 1, n)  read(a[i].x, a[i].y, a[i].z);
    REP(i, 1, n)  qx.push({i}), qy.push({i}), qz.push({i});
    int x, y, z, ans = 0;
    REP(i, 1, n) {
      x = qx.top().d;
      while(vis[x]) qx.pop(), x = qx.top().d;
      y = qy.top().d;
      while(vis[y]) qy.pop(), y = qy.top().d;
      z = qz.top().d;
      while(vis[z]) qz.pop(), z = qz.top().d;
      int px = a[x].x, py = a[y].y, pz = a[z].z;
      int dx = dis(x, px, py, pz), dy = dis(y, px, py, pz), dz = dis(z, px, py, pz);
      if (dx <= dy and dx <= dz)  vis[x] = 1, ans = std::max(ans, (dx + 1) >> 1);
      else if (dy <= dx and dy <= dz) vis[y] = 1, ans = std::max(ans, (dy + 1) >> 1);
      else                        vis[z] = 1, ans = std::max(ans, (dz + 1) >> 1);
    }
    std::cout << ans << '\n';
    return ;
  }
}

signed main()
{
  freopen("hunt.in","r",stdin);
  freopen("hunt.out","w",stdout);
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
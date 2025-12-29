#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
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
  const int N = 1e5 + 10;
  int k, n;
  int c[N];
  std::map<std::string, int> mp;
  int idx;
  std::priority_queue<int> q[N][2];
  void main() {
    std::string s, t;
    read(k, n);
    REP(i, 1, k) {
      std::cin >> s;
      int x;
      read(x);
      t = s;
      reverse(t.begin(), t.end());
      if (s == t) {
        if (!mp[s]) mp[s] = ++idx;
        c[mp[s]] = 0;
        q[mp[s]][0].push(x);
      }
      else {
        int op = 0;
        if (t < s)  swap(s, t), op = 1;
        if (!mp[s]) mp[s] = ++idx;
        c[mp[s]] = 1;
        q[mp[s]][op].push(x);
      }
    }
    int ans = 0, mx = 0, mn = 0;
    REP(i, 1, idx) {
      if (!c[i]) {
        while(q[i][0].size() >= 2) {
          int x = q[i][0].top();
          q[i][0].pop();
          int y = q[i][0].top();
          q[i][0].pop();
          if (x + y > 0)  ans = ans + x + y, mn = std::min(std::min(x, y), mn);
          else            {mx = std::max(mx, std::max(x, y));break;}
        }
        if (!q[i][0].empty()) {
          int x = q[i][0].top();
          q[i][0].pop();
          mx = std::max(mx, x);
        }
      }
      else {
        while(!q[i][0].empty() and !q[i][1].empty()) {
          int x = q[i][0].top(), y = q[i][1].top();
          q[i][0].pop();
          q[i][1].pop();
          if (x + y > 0)  ans = ans + x + y;
          else            break;
        }
      }
    }
    std::cout << ans + std::max(mx, -mn) << "\n";
    return ;
  }
}

signed main()
{
  // freopen("c.in","r",stdin);
  // freopen("c.out","w",stdout);
  // std::cin.tie(nullptr) -> sync_with_stdio(false);
  int T=1;
//   read(T);
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
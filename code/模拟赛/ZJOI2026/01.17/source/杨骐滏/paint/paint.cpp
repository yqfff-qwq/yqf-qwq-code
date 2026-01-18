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
  const int N = (1ll << 23);
  int n, m;
  int st[22][3][3], p[N], lg[N];
  int f[22], dp[N];
  int lowbit(int x) {return x & -x;}
  void main() {
    read(n, m);
    REP(i, 1, m) {
      int u, v, x, y;
      read(u, x, v, y);
      u--;
      v--;
      st[u][x][y] |= (1 << v);
      st[v][y][x] |= (1 << u);
    }
    lg[0] = -1;
    REP(i, 1, (1 << n) - 1) {
      lg[i] = lg[i >> 1] + 1;
      p[i] = lg[lowbit(i)];
    }
    dp[0] = 1;
    REP(i, 1, (1 << n) - 1) {
      int x = p[i];
      REP(t, 0, 1){
        int vis = (1 << x);
        bool fl = false;
        f[x] = t;
        std::queue<int> q;
        q.push(x);
        while(!q.empty()) {
          int u = q.front();
          q.pop();
          REP(o, 0, 1){
            for(int j = i & st[u][f[u]][o ^ 1]; j; j -= (j & -j)) {
              int v = p[j];
              if (!((vis >> v) & 1)) {
                f[v] = o;
                q.push(v);
                vis |= (1 << v);
              }
              else if (f[v] != o)  {fl = 1;break;}
            }
            if (fl) break;
          }
          if (fl) break;
        }
        if (!fl)   dp[i] += dp[i ^ vis];
      }
    }
    int ans = 0;
    REP(s, 0, (1 << n) - 1) {
      bool fl = 0;
      int sum = ((1 << n) - 1) ^ s;
      int vis = 0;
      std::queue<int> q;
      REP(i, 0, n - 1) {
        if ((s >> i) & 1) {
          if (st[i][2][2] & s) {fl = 1;break;}
          REP(o, 0, 1) {
            for(int j = sum & st[i][2][o ^ 1]; j; j -= (j & -j)) {
              int v = p[j];
              if (!((vis >> v) & 1)) {
                f[v] = o;
                q.push(v);
                vis |= (1 << v);
              }
              else if (f[v] != o) {fl = 1;break;}
            }
            if (fl)   break;
          }
        }
        if (fl) break;
      }
      if (fl)  continue;
      while(!q.empty()) {
        int u = q.front();
        q.pop();
        REP(o, 0, 1){
          for(int j = sum & st[u][f[u]][o^1]; j; j -= (j & -j)) {
            int v = p[j];
            if (!((vis >> v) & 1)) {
              f[v] = o;
              q.push(v);
              vis |= (1 << v);
            }
            else if (f[v] != o) {fl = 1;break;}
          }
          if (fl) break;
        }
        if (fl) break;
      }
      
      if (!fl)  ans += dp[sum ^ vis];
    }
    std::cout << ans << '\n';
  }
}

signed main(){
  freopen("paint.in", "r", stdin);
  freopen("paint.out", "w", stdout);
  
  int T = 1;
  // read(T);
  while(T--){
    YZLK::main();
  }
  
  fclose(stdin);
  fclose(stdout);
  return 0;
}
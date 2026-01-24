#include <iostream>
#include <vector>
#include <cstring>
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
  const int mod = 1e9 + 7;
  const int N = 3e2 + 10;
  int n, m;
  struct node{
    int l, r, c;
  }a[N];
  int f[N][N][N];
  void main() {
    read(n, m);
    REP(i, 1, m)  read(a[i].l, a[i].r, a[i].c);
    std::sort(a + 1, a + m + 1);
    f[1][0][0] = 3;
    int p = 1;
    REP(i, 1, n) {
      while(p <= m and a[p].r <= i) {
        REP(j, 0, i - 1) {
           REP(k, 0, (j ? j - 1 : 0)) {
            if (a[p].c == 1 && a[p].l <= j)                 f[i][j][k] = 0;
            if (a[p].c == 2 && (a[p].l <= k || j < a[p].l)) f[i][j][k] = 0;
            if (a[p].c == 3 && k < a[p].l)                  f[i][j][k] = 0;
          }
        }
        p++;
      }
      if (i == n) break;
      REP(j, 0, i - 1) {
        REP(k, 0, (i ? i - 1 : 0)) {
          if (!f[i][j][k])  continue;
          f[i + 1][j][k] = (f[i + 1][j][k] + f[i][j][k]) % mod;
          f[i + 1][i][k] = (f[i + 1][i][k] + f[i][j][k]) % mod;
          f[i + 1][i][j] = (f[i + 1][i][j] + f[i][j][k]) % mod;
        }
      }
    }
    int ans = 0;
    REP(i, 0, n - 1) {
      REP(k, 0, (i ? i - 1 : 0))  ans = (ans + f[n][i][k]) % mod;
    }
    std::cout << ans << '\n';
    return ;
  }
}

signed main()
{
  freopen("color.in","r",stdin);
  freopen("color.out","w",stdout);
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


/*
    while (p <= m && a[p].r <= i) { //只要当前这个限制 r = i 那么剔除不合法状态
			for (int j = 0; j < i; j++) {
				int limit = j ? j - 1 : 0;
				for (int k = 0; k <= limit; k++) {
					if (a[p].cnt == 1 && a[p].l <= j) //上面列出的三种不合法的 (i, j, k)
						f[i][j][k] = 0;
					if (a[p].cnt == 2 && (a[p].l <= k || j < a[p].l))
						f[i][j][k] = 0;
					if (a[p].cnt == 3 && k < a[p].l)
						f[i][j][k] = 0;
				}
			}
			++p;
		}
		if (i == n) break; //如果 i = n 那么下面就不需要继续递推了
		for (int j = 0; j < i; j++) {
			int limit = j ? j - 1 : 0;
			for (int k = 0; k <= limit; k++) {
				if (!f[i][j][k]) continue;
				f[i + 1][j][k] = (f[i + 1][j][k] + f[i][j][k]) % mod; //上面讲的三种转移方式
				f[i + 1][i][k] = (f[i + 1][i][k] + f[i][j][k]) % mod;
				f[i + 1][i][j] = (f[i + 1][i][j] + f[i][j][k]) % mod;
			}
		}

*/
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
#define MAX(a, b) (a) = std::max((a), (b))
#define MIN(a, b) (a) = std::min((a), (b))
#define pii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define uint unsigned long long
#define int long long
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
  const int inf = 1e18;
  int n;
  char ch[N];
  int a[N], b[N], c[N], d[N];
  int mn[N];
	void main() {
		read(n);
    scanf("%s", ch + 1);
    bool flag = 1;
		REP(i, 1, n) a[i] = ch[i] - '0';
    scanf("%s", ch + 1);
		REP(i, 1, n) {
      b[i] = ch[i] - '0';
      if (!b[i] and a[i]) flag = 0;
		}
    REP(i, 1, n)  read(c[i]);
    if (!flag)  return puts("-1"), void();
		a[n + 1] = b[n + 1] = 0;
    mn[n + 1] = inf;
		DEP(i, n, 1) {
      if (b[i])   mn[i] = std::min(mn[i + 1], c[i]);
			else        mn[i] = inf;
		}
    int ans = 0;
		REP(i, 1, n) {
			if (a[i] or !b[i]) continue;
			int r = i;
			while (b[r + 1] && !a[r + 1]) r++;
      int s = 0, sum  = inf, w = mn[r + 1];
      if (a[i - 1]) d[i - 1] = 0;
      else          d[i - 1] = inf;
      DEP(j, r, i) {
        w = std::min(w, c[j]);
        d[j] = c[j] + w * (j - i);
      }
      REP(j, i, r)  d[j] = std::min(d[j], d[j - 1]);
      w = mn[r + 1];
      DEP(j, r, i) {
        sum = std::min(sum, s + c[j] + d[j]);
			  w = std::min(w, c[j]);
        s += w;
      }
      ans += std::min(s, sum);
      i = r;
		}
		std::cout << ans << '\n';
		return;
  }
}

signed main()
{
  freopen("pom.in","r",stdin);
  freopen("pom.out","w",stdout);
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

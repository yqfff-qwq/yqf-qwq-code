#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

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
#define pcnt __builtin_popcount

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
	const int N = 4e5 + 10;
	int n, m;
	struct node{
    int x, y;
  }a[N], b[N];
  int q[N], len;
  int w[2][N];
  int d[N];
  int s1[2][N], s2[2][N];
  int c[2][N];
  int r[2], s[2];
  void update(int x, int y, int d, int k) {
    int t = x & 1;
    s1[t][++s[t]] = x;
    s2[t][s[t]] = y;
    w[t][++r[t]] = x;
    w[t][++r[t]] = y;
    if (d == 0) c[t][s[t]] = q[k + 1] - q[k];//两者相对距离不变
    else        c[t][s[t]] = 1;
    return;
  }
  void main() {
    len = 0;
		q[++len] = 0;
    read(n);
    REP(i, 1, n)  read(a[i - 1].y, a[i].x), a[i].x += a[i - 1].x, q[++len] = a[i].x;
    read(m);
    REP(i, 1, m)  read(b[i - 1].y, b[i].x), b[i].x += b[i - 1].x, q[++len] = b[i].x;
    std::sort(q + 1, q + len + 1);
    len = std::unique(q + 1, q + len + 1) - q - 1;
    a[len].y = b[len].y = 0;
    q[len + 1] = q[len] + 1;
    int dis = 3e18;
    r[0] = r[1] = s[0] = s[1] = 0;
    int la = 0, lb = 0, fa, fb;
    
    REP(i, 1, len) {
      if (a[la].x == q[i])  fa = a[la++].y;//判断当前处于什么运动状态
      else                  fa = a[la - 1].y;
      if (b[lb].x == q[i])  fb = b[lb++].y;
      else                  fb = b[lb - 1].y;
      int x, y, t = q[i + 1] - q[i];
      if (fa == fb) {//同进退
        update(dis, dis + 2, 0, i);
      } else if (fa - 1 == fb) {
        x = dis;
        y = dis + t;
        dis += t;
        update(x, (t & 1) + y, 1, i);
        update(x + 1, y + 1 - (t & 1), 1, i);
      } else if(fa + 1 == fb) {
        x = dis - (t - 1);
        y = dis + 1;
        dis -= t;
        update(x, (t & 1) + y, 1, i);
        update(x + 1, y + 1 - (t & 1), 1, i);
      } else if(fa - 2 == fb) {
        x = dis;
        y = dis + t * 2;
        dis += t * 2;
        update(x, y, 1, i);
      } else if (fa + 2 and fb) {
        x = dis - 2 * t + 2;
        y = dis + 2;
        dis -= t * 2;
        update(x, y, 1, i);
      }
    }


    int ans = 0;
    REP(j, 0, 1) {
      std::sort(w[j] + 1, w[j] + r[j] + 1);
      r[j] = std::unique(w[j] + 1, w[j] + r[j] + 1) - w[j] - 1;
      REP(i, 1, r[j]) d[i] = 0;
      REP(i, 1, s[j]) {
        int x = std::lower_bound(w[j] + 1, w[j] + r[j] + 1, s1[j][i]) - w[j];
        int y = std::lower_bound(w[j] + 1, w[j] + r[j] + 1, s2[j][i]) - w[j];//找到对应位置
        d[x] += c[j][i];
        d[y] -= c[j][i];//前缀和
      }

      REP(i, 1, r[j]) d[i] += d[i - 1], ans = std::max(ans, d[i]);
    }
    std::cout << ans << "\n";
    return ;
	}
}

signed main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	// std::cin.tie(nullptr) -> sync_with_stdio(false);
	int T=1;
	read(T);
	while(T--) {
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
//
*/
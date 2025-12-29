#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <random>
#include <map>

// using namespace std;
// #define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
#define MAX(a, b) (a) = max((a), (b))
#define MIN(a, b) (a) = min((a), (b))
#define pii std::pair<int, int>
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
  const int N = 2e5 + 10;
  const int M = 4e4 + 10;
  int n, m;
  struct node{
    int l, r, t;
  }b[N];
  int ans[N];
  int a[N], h[N], w[N], p[N], s[N], len;
  int f[202][M];
  void solve(int l, int r, int L, int R) {
    if (l > r or L > R) return;
    int mid = (l + r) >> 1;
    REP(j, 0, 200)  f[j][mid] = 0;
    REP(i, mid + 1, r) {
      REP(j, 0, h[i] - 1) f[j][i] = f[j][i - 1];
      REP(j, h[i], 200)   f[j][i] = std::max(f[j][i - 1], f[j - h[i]][i - 1] + w[i]);
    }
    REP(i, h[mid], 200)   f[i][mid] = w[mid];
    DEP(i, mid - 1, l) {
      REP(j, 0, h[i] - 1) f[j][i] = f[j][i + 1];
      REP(j, h[i], 200) {
        f[j][i] = std::max(f[j][i + 1], f[j - h[i]][i + 1] + w[i]);
      }
    }
    int td = L - 1, u;
    len = 0;
    REP(i, L, R) {
      u = p[i];
      if (b[u].r <= mid)      p[++td] = u;
      else if (mid < b[u].l)  s[++len] = u;
      else {
        int sum = 0;
        REP(i, 0, b[u].t) sum = std::max(sum, f[i][b[u].l] + f[b[u].t - i][b[u].r]);
        ans[u] = sum;
      }
    }
    REP(i, 1, len) p[td + i] = s[i];
    R = td + len;
    solve(l, mid, L, td);
    solve(mid + 1, r, td + 1, R);
    return;
  }
  
  void main() {
    read(n, m);
    REP(i, 1, n)  read(h[i]);
    REP(i, 1, n)  read(w[i]);
    REP(i, 1, m) {
      read(b[i].l, b[i].r, b[i].t);
      if (b[i].l == b[i].r) {
        if (b[i].t >= h[b[i].l])  ans[i] = w[b[i].l];
      }
      else  p[++len] = i;
    }
    solve(1, n, 1, len);
    REP(i, 1, m)  std::cout << ans[i] << '\n';
    return ;
	}
}

signed main()
{
	// freopen("c.in","r",stdin);
	// freopen("c.out","w",stdout);
	// std::cin.tie(nullptr) -> sync_with_stdio(false);
	int T=1;
	// read(T);
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
//
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <random>

// using namespace std;
// #define int long long
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
	const int N = 2e5 + 10;
  const int M = 400;
  int n, m;
  int a[N];
  int f[M][M];
  void main() {
    std::cin >> n >> m;
    int B = sqrt(n);
    REP(i, 1, n)  std::cin >> a[i];
    REP(i, 1, n) {
      REP(j, 1, B)  f[j][i % j] += a[i];
    }
    char ch;
    int x, y;
    REP(i, 1, m) {
      std::cin >> ch >> x >> y;
      if (ch == 'A') {
        if (x <= B) {
          std::cout << f[x][y] << '\n';
        }
        else {
          int sum = 0;
          for(int j = y;j <= n;j += x) {
            sum += a[j];
          }
          std::cout << sum << '\n';
        }
      } else {
        REP(i, 1, B)  f[i][x % i] += y - a[x];
        a[x] = y;
      }
    }
    return ;
	}
}

signed main()
{
	// freopen("c.in","r",stdin);
	// freopen("c.out","w",stdout);
	std::cin.tie(nullptr) -> sync_with_stdio(false);
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
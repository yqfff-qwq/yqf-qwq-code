#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <random>
#include <map>

// using namespace std;
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
  int n, m;
  int ans[N];
  int a[N], b[N], p[N], len;
  struct tree{
    #define ls (u << 1)
    #define rs ((ls) | 1)
    #define mid ((l + r) >> 1)
    int s[22][N], p[22][N], tr[N];
    void build(int u, int l, int r, int d) {
      if (l == r) return b[l] = u, void();
      int sum = 0, pre = 0;
      p[d][mid] = s[d][mid] = sum = pre = a[mid];
      sum = std::max(sum, 0ll);
      DEP(i, mid - 1, l) {
        pre += a[i], sum += a[i];
        s[d][i] = std::max(s[d][i + 1], pre);
        p[d][i] = std::max(p[d][i + 1], sum);
        sum = std::max(0ll, sum);
      }
      p[d][mid + 1] = s[d][mid + 1] = sum = pre = a[mid + 1];
      sum = std::max(sum, 0ll);
      REP(i, mid + 2, r) {
        pre += a[i], sum += a[i];
        s[d][i] = std::max(s[d][i - 1], pre);
        p[d][i] = std::max(p[d][i - 1], sum);
        sum = std::max(0ll, sum);
      }
      build(ls, l, mid, d + 1);
      build(rs, mid + 1, r, d + 1);
      return;
    }
    int query(int l, int r) {
      if (l == r) return a[l];
      int d = std::__lg(b[l]) - std::__lg(b[l] ^ b[r]);
      return std::max(std::max(p[d][l], p[d][r]), s[d][l] + s[d][r]);
    }
  }tr;
  
  void main() {
    read(n);
    len = 2;
    while(len < n)  len <<= 1;
    REP(i, 1, n)  read(a[i]);
    tr.build(1, 1, len, 1);
    read(m);
    REP(i, 1, m) {
      int l, r;
      read(l, r);
      std::cout << tr.query(l, r) << '\n';
    }
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
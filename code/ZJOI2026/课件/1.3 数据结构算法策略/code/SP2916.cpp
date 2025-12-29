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
    int s[22][N], p[22][N], tr[N], f[22][N], g[22][N];
    /*
    f:最大前/后缀
    g:最大后/前缀
    s:前/后缀和
    p:最大子段和
    */
    void build(int u, int l, int r, int d) {
      if (l == r) return b[l] = u, void();
      int sum = 0, pre = 0;
      f[d][mid] = g[d][mid] = p[d][mid] = s[d][mid] = sum = pre = a[mid];
      sum = std::max(sum, 0ll);
      DEP(i, mid - 1, l) {
        pre += a[i], sum += a[i];
        s[d][i] = pre;
        p[d][i] = std::max(p[d][i + 1], sum);
        f[d][i] = std::max(f[d][i + 1], pre);
        g[d][i] = sum;
        sum = std::max(0ll, sum);
      }
      f[d][mid + 1] = g[d][mid + 1] = p[d][mid + 1] = s[d][mid + 1] = sum = pre = a[mid + 1];
      sum = std::max(sum, 0ll);
      REP(i, mid + 2, r) {
        pre += a[i], sum += a[i];
        s[d][i] = pre;
        p[d][i] = std::max(p[d][i - 1], sum);
        f[d][i] = std::max(f[d][i - 1], pre);
        g[d][i] = sum;
        sum = std::max(0ll, sum);
      }
      build(ls, l, mid, d + 1);
      build(rs, mid + 1, r, d + 1);
      return;
    }
    int qs(int l, int r) {//查询区间和
      if (l > r)  return 0;
      if (l == r) return a[l];
      int d = std::__lg(b[l]) - std::__lg(b[l] ^ b[r]);
      return s[d][l] + s[d][r];
    }
    int qp(int l, int r) {//查询前缀最大子段和
      if (l > r)  return 0;
      if (l == r) return a[l];
      int d = std::__lg(b[l]) - std::__lg(b[l] ^ b[r]);
      return std::max(s[d][l] + f[d][r], g[d][l]);
    }
    int qf(int l, int r) {//查询后缀最大子段和
      if (l > r)  return 0;
      if (l == r) return a[l];
      int d = std::__lg(b[l]) - std::__lg(b[l] ^ b[r]);
      return std::max(g[d][r], f[d][l] + s[d][r]);
    }
    int qm(int l, int r) {//查询区间最大子段和
      if (l > r)  return 0;
      if (l == r) return a[l];
      int d = std::__lg(b[l]) - std::__lg(b[l] ^ b[r]);
      return std::max(std::max(p[d][l], p[d][r]), f[d][l] + f[d][r]);
    }
    int query(int l1, int r1, int l2, int r2) {
      int sum = 0;
      if (r1 < l2)  return qs(r1 + 1, l2 - 1) + qf(l1, r1) + qp(l2, r2);//中间部分加上前半部分后缀最大+后半部分前缀最大
      sum = l1 < l2 ? std::max(qm(l2, r1), qf(l1, l2) + qp(l2, r2) - a[l2]) : qm(l2, r1);//前半部分后缀最大+后半部分前缀最大减去重复部分以及重复部分的最大值/包含关系的最大值
      if (r2 > r1)  sum = std::max(sum, qf(l1, r1) + qp(r1, r2) - a[r1]);//前半部分后缀最大+后半部分前缀最大减去重复部分
      return sum;
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
      int l1, r1, l2, r2;
      read(l1, r1, l2, r2);
      std::cout << tr.query(l1, r1, l2, r2) << '\n';
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
	read(T);
	while(T--) {
		YZLK::main();
	}
	
	// fclose(stdin);
	// fclose(stdout);
	return 0;
}
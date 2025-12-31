#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <random>
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define REP(i,l,r) for(int i=l;i<=r;i++)
#define DEP(i,r,l) for(int i=r;i>=l;i--)
#define MAX(a, b) (a) = max((a), (b))
#define MIN(a, b) (a) = min((a), (b))
#define pii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
// #define ll long long
#define ull unsigned long long
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
  const int N = 1e6 + 10;
  const ull mk = std::mt19937_64(time(nullptr))();
  ull hash(ull x) {
    x ^= mk;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    x ^= mk;
    return x;
  }
  std::map<ull, int> mp;
  vector<int> ve[N];
  int h[N];
  int f[N];
  int n, m, rt;
  void gethash(int u) {
    h[u] = 1;
    for(auto v:ve[u]) {
      gethash(v);
      h[u] += hash(h[v]);
    }
    return;
  }
  void dp(int u) {
    for(auto v:ve[u]) {
      f[v] = h[v] + hash(f[u] - hash(h[v]));
      dp(v);
    }
    return;
  }
  void main() {
    read(m);
    REP(j, 1, m) {
      read(n);
      rt = 0;
      REP(i, 1, n) {
        int fa;
        read(fa);
        if (fa == 0)  rt = i;
        else          ve[fa].pb(i);
      }
      gethash(rt);
      f[rt] = h[rt];
      dp(rt);
      ull s = 1;
      REP(i, 1, n)  s += hash(f[i]);
      if (!mp.count(s)) mp[s] = j;
      std::cout << mp[s] << '\n';
      REP(i, 1, n)  ve[i].clear();
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

*/
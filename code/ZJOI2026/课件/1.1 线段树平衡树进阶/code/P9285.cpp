#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

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
#define pdi std::pair<double, int>

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
  const int N = 5e4 + 10;
  int n, q;
  int a[N];
  std::multiset<int> st, s[N];
  void main() {
    read(n);
    REP(i, 1, n)  read(a[i]), st.insert(i), s[i].insert(a[i]);
    st.insert(n + 1);
    read(q);
    auto merge = [&](std::multiset<int>&x, std::multiset<int>&y) -> void{
      if (x.size() < y.size())  x.swap(y);
      for(auto it:y)  x.insert(it);
      std::multiset<int>().swap(y);
      return;
    };
    while(q--) {
      int op, l, r;
      read(op, l, r);
      if (op == 1) {
        auto it = st.lower_bound(l);
        if (it == st.end()) continue;
        it++;
        auto itl = it;
        int t = 0;
        while(it != st.end()) {
          if ((*it) > r)  break;
          merge(s[l], s[*it]);
          it++;
          t++;
        }
        if (t >= 3) {
          st.erase(itl, it);
          int d = l - 1;
          for (auto u:s[l]) {
            a[++d] = u;
          }
        }
        else {
          it = itl;
          while(it != st.end()) {
            if ((*it) > r)  break;
            auto it1 = it;
            it1++;
            std::inplace_merge(a + l, a + (*it), a + (*it1));
            it++;
          }
          st.erase(itl, it);
        }
      } else {
        int ans = 0;
        int mx = 0;
        REP(i, l, r) {
          if (mx > a[i])  ans = std::max(ans, a[i] * mx);
          mx = std::max(mx, a[i]);
        }
        std::cout << ans << '\n';
      }
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
#include <iostream>
#include <algorithm>
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
  const int N = 1e3 + 10;
  int n;
  int a[N];
  std::set<int> st;
  void main() {
    read(n);
    REP(i, 1, n)  read(a[i]);
    int mn = 1e18;
    DEP(i, n - 1, 1) {
      int sum = 0;
      REP(j, i + 1, n) {
        sum += a[j];
        st.insert(sum);
      }
      sum=0;
      DEP(j, i, 1) {
        sum += a[j];
        auto p = st.lower_bound(sum);
        if (p != st.end())    mn = std::min(mn, * p - sum);
        if (p != st.begin())  mn = std::min(mn, sum - *prev(p));
      }
    }
    std::cout << mn << "\n";
    return ;
  }
}

signed main()
{
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);

  int T=1;
  // read(T);
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

*/
#include <iostream>
#include <algorithm>
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
  const int N = 3e5 + 10;
  int n;
  int a[N], b[N], s[N];
  bool c[N];
  int c1, c2, d1, d2;
  void main() {
    read(n);
    REP(i, 1, n)  read(a[i]);
    REP(i, 1, n)  read(b[i]);
    REP(i, 1, n - 1)  c[i] = (a[i] < a[i + 1]);
    std::sort(b + 1, b + n + 1);
    if (c[1])     d1++, d2++;
    else          c1++, c2++;
    if (c[n - 1]) c1++, c2++;
    else          d1++, d2++;
    REP(i, 2, n - 1) {
      if (c[i - 1] and !c[i]) c1++;
      if (!c[i - 1] and c[i]) d1++;
      // std::cout << c1 << " " << c2 << " " << d1 << " " << d2 << "\n";
    }
    int ans = 0;
    REP(i, 1, d1)           ans -= 2 * b[i];
    DEP(i, d1, d1 - d2 + 1) ans += b[i];
    DEP(i, n, n - c1 + 1)   ans += 2 * b[i];
    REP(i, n - c1 + 1, n - c1 + c2) ans -= b[i];
    // REP(i, 1, n - 1)  std::cout << c[i] << " \n"[i == n - 1];
    std::cout << ans << "\n";
    // std::cout << c1 << " " << c2 << " " << d1 << " " << d2 << "\n";
    
    int l = d1, r = n - c1 + 1;
    if (c[1])     s[1] = b[l--];
    else          s[1] = b[r++];
    if (c[n - 1]) s[n] = b[r++];
    else          s[n] = b[l--];
    REP(i, 2, n - 1) {
      if (c[i - 1] and !c[i]) s[i] = b[r++];
      if (!c[i - 1] and c[i]) s[i] = b[l--];
    }

    int idx = d1 + 1;
    REP(i, 1, n - 1) {
      if (s[i + 1]) continue;
      if (c[i]) s[i + 1] = b[idx++];
    }
    DEP(i, n - 1, 2) {
      if (s[i]) continue;
      if (!c[i])  s[i] = b[idx++];
    }

    REP(i, 1, n)  std::cout << s[i] << " ";
    return ;
  }
}

signed main()
{
  freopen("b.in","r",stdin);
  freopen("b.out","w",stdout);

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